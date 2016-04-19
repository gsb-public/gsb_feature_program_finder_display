<?php

$plugin = array(
  'title' => t('Faculty: Program Category + search'),
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
  $programs = array();
  $terms = explode(',', $conf['keywords']);
  foreach ($terms as $term) {
    $tid = taxonomy_get_term_by_name($term, 'tag');
    $tag_ids[key($tid)] = key($tid);
  }

  $category_ids = $conf['program_category'];

  $query = db_select('node', 'n');
  $query->fields('n', array('nid', 'status', 'type', 'created'));

  if (!empty($tag_ids)) {
    $query->innerJoin('field_data_field_tag', 't', "n.nid = t.entity_id AND t.entity_type = 'node'");
    $query->fields('t', array('field_tag_tid'));
    $query->condition('t.field_tag_tid', $tag_ids, 'IN');
  }

  if (!empty($category_ids)) {
    $query->innerJoin('field_data_field_program_category', 'pc', "n.nid = pc.entity_id AND pc.entity_type = 'node'");
    $query->fields('pc', array('field_program_category_tid'));
    $query->condition('pc.field_program_category_tid', $category_ids, 'IN');
  }

  if (!empty($_GET['search'])) {
    $select->leftJoin('field_data_field_search_field', 'sf', 'n.nid = sf.entity_id AND sf.deleted = 0');
    $select->condition('sf.field_search_field_value', '%' . $_GET['search'] . '%', 'LIKE');
  }

  $query->condition('n.type', 'program');
  $query->condition('n.status', '1');

  $results = $query->execute();
  foreach ($results as $record) {
    $programs[$record->nid] = (empty($programs[$record->nid])) ? 1 : $programs[$record->nid] + 1;
  }

  $items = array();
  foreach ($programs as $program_nid => $program) {
    $query = db_select('node', 'n');
    $query->fields('n', array('nid', 'status', 'type'));
    $query->join('field_data_field_program', 'fp', "n.nid = fp.entity_id AND fp.entity_type = 'node' AND fp.deleted = '0'");
    $query->fields('fp', array('entity_id', 'entity_type', 'deleted', 'field_program_target_id'));
    $query->join('node', 'nodefp', 'fp.field_program_target_id = nodefp.nid');
    $query->fields('nodefp', array('nid'));
    $query->join('field_data_field_instance_date', 'fid', "n.nid = fid.entity_id AND fid.entity_type = 'node' AND fid.deleted = '0'");
    $query->fields('fid', array('field_instance_date_value'));
    $query->join('field_data_field_display_on_finder', 'dof', "n.nid = dof.entity_id AND dof.entity_type = 'node' AND dof.deleted = '0'");
    $query->fields('dof', array('field_display_on_finder_value'));
    $query->condition('nodefp.nid', $program_nid);
    $query->condition('n.status', '1');
    $query->condition('n.type', 'program_instance');
    $query->condition('dof.field_display_on_finder_value', '1');
    $query->orderBy('fid.field_instance_date_value', 'ASC');
    $query->range(0, 1);
    $results = $query->execute();

    foreach ($results as $record) {
      $instance_wrapper = entity_metadata_wrapper('node', $record->nid);
      $fd_items = _gsb_feature_program_finder_display_faculty_info($instance_wrapper->field_faculty_directors);
      $f1_items = _gsb_feature_program_finder_display_faculty_info($instance_wrapper->field_faculty_1);
      $f2_items = _gsb_feature_program_finder_display_faculty_info($instance_wrapper->field_faculty_2);
    }
    $items = array_merge($items, $fd_items,  $f1_items, $f2_items); 
  }

  $items = array_unique($items, SORT_REGULAR);
  $options = array(
    'filters' => array(
      'search' => array(
        'type' => 'search',
        'placeholder' => t('search by name or keyword'),
      ),
      'submit' => array(
        'type' => 'submit',
        'title' => t('Search'),
      ),
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
    '#multiple' => true,
    '#options' => _gsb_feature_program_finder_display_fetch_by_machine('program_category'),
    '#default_value' => $conf['program_category'],
    '#required' => TRUE,
  );

  $form['keywords'] = array(
    '#type' => 'textfield',
    '#title' => t('Keyword(s)'),
    '#required' => TRUE,
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

function _gsb_feature_program_finder_display_faculty_info($field_faculty_instance) {
  $faculty = '';
  $items = array();
  foreach ($field_faculty_instance as $key => $fci) {
    $view = $fci->view();
    $id = $fci->getIdentifier();

    if (isset($view['field_collection_item'][$id]['field_person_fac_single_ref'])) {
      $fac_node = $view['field_collection_item'][$id]['field_person_fac_single_ref'][0]['node'];
      $program_instance = entity_load('node', array(key($fac_node)));
      $entity_array = entity_view('node', $program_instance, 'teaser');
      $content = drupal_render($entity_array);
      $faculty[$id]['content'] = $content;
      $faculty[$id]['nid'] = key($fac_node);

      $parameters = array(
        'data' => theme('faculty_isotope_item', $faculty[$id]),
        'item-id' => key($fac_node),
        'sort' => array(),
        'filters' => array(),
      );
      $items[] = $parameters;
    }
  }
  return $items;
}
