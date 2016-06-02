<?php

$plugin = array(
  'title' => t('Faculty: Program Category'),
  'category' => t('Customizable Content Lists'),
  'single' => TRUE,
  'all contexts' => TRUE,
  'admin info' => 'gsb_feature_program_finder_display_faculty_teaching_list_admin_info',
  'render callback' => 'gsb_feature_program_finder_display_faculty_teaching_list_content_type_render',
  'edit form' => 'gsb_feature_program_finder_display_faculty_teaching_list_edit_form',
  'defaults' => array('program_category' => '', 'keywords' => '')
);

/**
 * 'admin info' callback for panel pane.
 */
function gsb_feature_program_finder_display_faculty_teaching_list_admin_info($subtype, $conf, $contexts) {
  
}

/**
 * Implements hook_PLUGIN_content_type_render().
 */
function gsb_feature_program_finder_display_faculty_teaching_list_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
  // use the following to get the list of programs with the list of keywords(field_tag) and the list of program categories(field_program_category)
  $terms = explode(',', $conf['keywords']);
  foreach ($terms as $term) {
    $tid = taxonomy_get_term_by_name($term, 'tag');
    if (!empty($tid)) {
      $tag_ids[key($tid)] = key($tid);
    }
  }

  $category_ids = $conf['program_category'];
  // Get all program instance nodes based on category and tags
  $query = db_select('node', 'nodepi');
  $query->fields('nodepi', array('nid'));
  $query->fields('nodep', array('nid'));
  $query->fields('fid', array('field_instance_date_value'));
  $query->join('field_data_field_program', 'fp', "nodepi.nid = fp.entity_id AND fp.entity_type = 'node' AND fp.deleted = '0'");
  $query->join('node', 'nodep', 'fp.field_program_target_id = nodep.nid');
  $query->join('field_data_field_instance_date', 'fid', "nodepi.nid = fid.entity_id AND fid.entity_type = 'node' AND fid.deleted = '0'");
  $query->join('field_data_field_display_on_finder', 'dof', "nodepi.nid = dof.entity_id AND dof.entity_type = 'node' AND dof.deleted = '0'");

  if (!empty($tag_ids)) {
    $query->leftJoin('field_data_field_tag', 'ft', "nodep.nid = ft.entity_id AND ft.entity_type = 'node'");
    $query->condition('ft.field_tag_tid', $tag_ids, 'IN');
  }
  if (!empty($category_ids)) {
    $query->leftJoin('field_data_field_program_category', 'fpc', "nodep.nid = fpc.entity_id AND fpc.entity_type = 'node'");
    $query->condition('fpc.field_program_category_tid', $category_ids, 'IN');
  }

  $query->condition('nodep.status', '1');
  $query->condition('nodepi.status', '1');
  $query->condition('nodep.type', 'program');
  $query->condition('nodepi.type', 'program_instance');
  $query->condition('dof.field_display_on_finder_value', '1');
  $query->orderBy('nodep.nid', 'ASC');
  $results = $query->execute();

  $program = array();
  $program_instance = array();
  $instance_date_value = array();
  // Select only the upcoming program instance
  foreach ($results as $record) {
    $found_key = array_search($record->nodep_nid, $program);
    if (is_bool($found_key) && !$found_key) {
      $program[] = $record->nodep_nid;
      $program_instance[] = $record->nid;
      $instance_date_value[] = $record->field_instance_date_value;
    }
    else {
      if ($record->field_instance_date_value < $instance_date_value[$found_key]) {
        $program_instance[$found_key] = $record->nid;
        $instance_date_value[$found_key] = $record->field_instance_date_value;
      }
    }
  }

  // Get the faculty information
  $items = array();
  $faculty_node_ids = array();
  $view_mode = 'faculty_teaching_programs';
  foreach ($program_instance as $key => $program_instance_nid) {
    $instance_wrapper = entity_metadata_wrapper('node', $program_instance_nid);
    $faculty_fields = array(
      'field_faculty_directors',
      'field_faculty_1',
      'field_faculty_2',
    );
    foreach ($faculty_fields as $faculty_field) {
      foreach ($instance_wrapper->$faculty_field as $key => $fci) {
        $view = $fci->view();
        $id = $fci->getIdentifier();
        $content = array();
        // Is it entity reference faculty?
        if (isset($view['field_collection_item'][$id]['field_person_fac_single_ref'])) {
          $faculty_node_id = key($view['field_collection_item'][$id]['field_person_fac_single_ref'][0]['node']);
          // Add only unique faculty
          if (empty($faculty_node_ids[$faculty_node_id])) {
            $faculty_node_ids[$faculty_node_id] = $faculty_node_id;
            $faculty_node = entity_load('node', array($faculty_node_id));
            $entity_array = entity_view('node', $faculty_node, $view_mode);
            $content = drupal_render($entity_array);
            $faculty[$id]['nid'] = $faculty_node_id;
            $faculty[$id]['last_name'] = $faculty_node[$faculty_node_id]->field_last_name['und'][0]['value'];
          }
        }
/*         else {
          // Faculty added using other option
          $faculty_other_entity = $view['field_collection_item'][$id]['#entity'];
          $faculty_name = $faculty_other_entity->field_other_name['und'][0]['value'];
          if (empty($faculty_node_name[$faculty_name]) && !empty($faculty_name)) {
            $faculty_fc = entity_load('field_collection_item', array($faculty_other_entity->item_id));
            $entity_array = entity_view('field_collection_item', $faculty_fc, $view_mode);
            $content = drupal_render($entity_array);
            $faculty[$id]['nid'] = $faculty_other_entity->item_id;
            $faculty_node_name[$faculty_name] = $faculty_name;
          }
        } */
        if (!empty($content)){
          $faculty[$id]['content'] = $content;
          $parameters = array(
            'data' => theme('faculty_isotope_item', $faculty[$id]),
            'item-id' => $faculty[$id]['nid'],
            'sort' => array(
               'last_name' => $faculty[$id]['last_name'],
             ),
            'filters' => array(),
          );
          $items[] = $parameters;
        }
      }
    }
  }

  usort($items, "comparer");
  $options = array(
    'filters' => array(
/*       'search' => array(
        'type' => 'search',
        'placeholder' => t('search by name or keyword'),
      ),
      'submit' => array(
        'type' => 'submit',
        'title' => t('Search'),
      ), */

    ),
    'settings' => array(
      'callback' => '/faculty-search',
      'lazyLoad' => TRUE,
      'title' => t(''),
      'filterTitle' => t('Results for'),
    ),
    'id' => 'faculty_teaching_list',
  );

  $wrapper_data = array('faculty' => isotopify_prepare($items, $options));
  $output = theme('faculty_isotope_item_wrapper', $wrapper_data);

  return (object) array(
    'content' => array(
      '#markup' => $output,
    ),
  );
}

/**
* 'Edit form' callback for the content type.
*/
function gsb_feature_program_finder_display_faculty_teaching_list_edit_form($form, &$form_state) {

  $conf = $form_state['conf'];
  $form['override_title']['#access'] = FALSE;
  $form['override_title_text']['#access'] = FALSE;
  $form['override_title_heading']['#access'] = FALSE;
  $form['override_title_markup']['#access'] = FALSE;

  $form['program_category'] = array(
    '#title' => t('Program Category'),
    '#type' => 'select',
    '#multiple' => TRUE,
    '#options' => _gsb_feature_program_finder_display_fetch_by_machine('program_category'),
    '#default_value' => $conf['program_category'],
    '#required' => FALSE,
  );

  $form['keywords'] = array(
    '#type' => 'textfield',
    '#title' => t('Keyword(s)'),
    '#required' => FALSE,
    '#default_value' => $conf['keywords'],
    '#autocomplete_path' => 'taxonomy/autocomplete/field_tag',
    '#maxlength' => 1024,
  );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function gsb_feature_program_finder_display_faculty_teaching_list_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Fetch program category taxonomy term data.
 */
function _gsb_feature_program_finder_display_fetch_by_machine($machine_name) {
  $vocab = taxonomy_vocabulary_machine_name_load($machine_name);
  $tree = taxonomy_get_tree($vocab->vid);
  foreach ($tree as $key => $term) {
    $terms[$term->tid] = $term->name;
  }
  return $terms;
}

// sorting the array using the usort function and a "callback that you define"
function comparer($a, $b) {
  return ($a["sort"]["last_name"] <= $b["sort"]["last_name"]) ? -1 : 1;
}
