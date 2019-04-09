<?php

$plugin = array(
    'title' => t('GSB: Program List'),
    'category' => t('Custom Content & Features'),
    'single' => TRUE,
    'all contexts' => TRUE,
    'admin info' => 'gsb_feature_program_finder_display_gsb_program_list_admin_info',
    'edit form' => 'gsb_feature_program_finder_display_gsb_program_list_edit_form'
);


function sortBy_field($field, &$array, $direction = 'asc') {
    usort($array, create_function('$item_1, $item_2', '
		$item_1 = $item_1["' . $field . '"];
		$item_2 = $item_2["' . $field . '"];

		if ($item_1 == $item_2)
		{
			return 0;
		}

		return ($item_1 ' . ($direction == 'desc' ? '>' : '<') .' $item_2) ? -1 : 1;
	'));

    return true;
}

/**
 * 'admin info' callback for panel pane.
 */
function gsb_feature_program_finder_display_gsb_program_list_admin_info($subtype, $conf, $contexts) {

}


/**
 * Implements hook_PLUGIN_content_type_render().
 */

function gsb_feature_program_finder_display_gsb_all_programs_content_type_render($subtype, $conf, $panel_args, $context, $incoming) {
    drupal_add_js(libraries_get_path('sticky-master') . '/jquery.sticky.js');
    drupal_add_js(drupal_get_path('module', 'gsb_feature_program_finder_display') . '/js/gsb_feature_program_finder.js');
    drupal_add_js(libraries_get_path('jquery-multicheckbox') . '/jquery.multicheckbox.js');
    drupal_add_css(libraries_get_path('jquery-multicheckbox') . '/jquery.multicheckbox.css');
    $select = db_select('node','n');
    $select->fields('n', array('title', 'nid'));
    $select->condition('n.status', 1);
    $select->condition('n.type', 'program_instance');
    //Program Title
    $select->leftJoin('field_data_field_program', 'p', 'n.nid = p.entity_id AND p.deleted = 0');
    $select->leftJoin('node', 'n2', 'n2.nid = p.field_program_target_id');
    $select->addField('n2', 'title', 'program_title');
    $select->addField('n2', 'nid', 'program_nid');
    //Program Category
    $select->leftJoin('field_data_field_program_category', 'pc', 'n2.nid = pc.entity_id AND pc.deleted = 0');
    $select->leftJoin('taxonomy_term_data', 'ttd_pc', 'pc.field_program_category_tid = ttd_pc.tid');
    $select->addField('ttd_pc', 'tid', 'program_category_tid');
    $select->addField('ttd_pc', 'name', 'program_category');
    //Detail Page and URL
    $select->leftJoin('field_data_field_program_detail', 'pd', 'n2.nid = pd.entity_id AND pd.deleted = 0');
    $select->addField('pd', 'field_program_detail_value', 'program_detail_page');
    $select->leftJoin('field_data_field_link_single', 'pu', 'n2.nid = pu.entity_id AND pu.deleted = 0');
    $select->addField('pu', 'field_link_single_url', 'link_url');
    $select->addField('pu', 'field_link_single_attributes', 'link_url_attributes');
    //Program Teaser
    $select->leftJoin('field_data_field_overview_intro', 'ot', 'n2.nid = ot.entity_id AND ot.deleted = 0');
    $select->addField('ot', 'field_overview_intro_value', 'program_teaser');
    //Dates
    $select->leftJoin('field_data_field_instance_date', 'dt', 'n.nid = dt.entity_id AND dt.deleted = 0');
    $select->addField('dt', 'field_instance_date_value', 'start_date');
    $select->addField('dt', 'field_instance_date_value2', 'end_date');
    //Text Date
    $select->leftJoin('field_data_field_instance_text', 'tdt', 'n.nid = tdt.entity_id AND tdt.deleted = 0');
    $select->addField('tdt', 'field_instance_text_value', 'text_date');
    //Date Option
    $select->leftJoin('field_data_field_instance_date_text_select', 'dts', 'n.nid = dts.entity_id AND dts.deleted = 0');
    $select->addField('dts', 'field_instance_date_text_select_value', 'date_select');
    //Time Commitment
    $select->leftJoin('field_data_field_time_commitment', 'tc', 'n2.nid = tc.entity_id AND tc.deleted = 0');
    $select->addField('tc', 'field_time_commitment_tid', 'time_commitment');
    //Topics
    $select->leftJoin('field_data_field_key_program_topics', 'pt', 'n2.nid = pt.entity_id AND pt.deleted = 0');
    $select->leftJoin('taxonomy_term_data', 'ttd_pt', 'pt.field_key_program_topics_tid = ttd_pt.tid');
    $select->addField('ttd_pt', 'tid', 'program_topics_tid');
    $select->addField('ttd_pt', 'name', 'program_topics');

    //All Topics
    $select->leftJoin('field_data_field_program_topics', 'at', 'n2.nid = at.entity_id AND at.deleted = 0');
    $select->leftJoin('taxonomy_term_data', 'ttd_at', 'at.field_program_topics_tid = ttd_at.tid');
    $select->addField('ttd_at', 'tid', 'program_all_topics_tid');
    $select->addField('ttd_at', 'name', 'all_program_topics');

    //Career Level
    $select->leftJoin('field_data_field_career_level', 'cl', 'n2.nid = cl.entity_id AND cl.deleted = 0');
    $select->leftJoin('taxonomy_term_data', 'ttd_cl', 'cl.field_career_level_tid = ttd_cl.tid');
    $select->addField('ttd_cl', 'tid', 'career_level_tid');
    $select->addField('ttd_cl', 'name', 'career_levels');

    //Location
    $select->leftJoin('field_data_field_program_location', 'pl', 'n.nid = pl.entity_id');
    $select->leftJoin('field_data_field_program_location_category', 'loc', 'pl.field_program_location_value = loc.entity_id AND loc.deleted = 0');
    $select->leftJoin('taxonomy_term_data', 'ttd_loc', 'loc.field_program_location_category_tid = ttd_loc.tid');
    $select->addField('ttd_loc', 'tid', 'program_location_category_tid');
    $select->addField('ttd_loc', 'name', 'program_locations');
    $select->leftJoin('field_data_field_program_format', 'pf', 'pl.field_program_location_value = pf.entity_id AND pf.deleted = 0');
    $select->leftJoin('taxonomy_term_data', 'ttd_pf', 'pf.field_program_format_tid = ttd_pf.tid');
    $select->addField('ttd_pf', 'name', 'program_formats');
    $select->leftJoin('field_data_field_program_location_link', 'lnl', 'pl.field_program_location_value = lnl.entity_id AND lnl.deleted = 0');
    $select->addField('lnl', 'field_program_location_link_title', 'location_name');
    $select->addField('lnl', 'field_program_location_link_url', 'location_link_url');
    $select->addField('lnl', 'field_program_location_link_attributes', 'location_link_window');

    //Instance Label
    $select->leftJoin('field_data_field_instance_label', 'il', 'n.nid = il.entity_id AND il.deleted = 0');
    $select->addField('il', 'field_instance_label_value', 'instance_label');

    // Display on Finder
    $select->join('field_data_field_display_on_finder', 'dof', "n.nid = dof.entity_id AND dof.entity_type = 'node' AND dof.deleted = '0'");
    $select->fields('dof', array('field_display_on_finder_value'));

    // Application State
    $select->join('field_data_field_application_state', 'das', "n.nid = das.entity_id AND das.entity_type = 'node' AND das.deleted = '0'");
    $select->addField('das', 'field_application_state_value', 'application_state');
    $select->condition(db_or()->condition('das.field_application_state_value', array('2', '1'), 'IN')->condition(db_and()->condition('das.field_application_state_value', '3')->condition('dof.field_display_on_finder_value', '1')));


    $today = date("Y-m-d");
    $select->condition(db_or()->condition('dt.field_instance_date_value', $today, '>')->isNotNull('tdt.field_instance_text_value'));
    $select->orderBy('start_date','ASC');
    $select->orderBy('text_date','ASC');
    $select->orderBy('program_title','ASC');

    $query = $select->execute();

    $items = array();
    $dp_items = array();
    $career_levels = array();
    $program_topics = array();
    $all_program_topics = array();
    $program_locations = array();
    $program_formats = array();
    $program = array();
    while ($result = $query->fetchObject()) {
        if (!empty($result->career_levels) || $result->program_category == 'Degree Program') {
            $nid = $result->nid;
            $program[$nid]['title'] = $result->title;
            $program[$nid]['program_title'] = $result->program_title;

            if (empty($program[$nid]['program_topic'])){
                $program[$nid]['program_topic'] = array();
            }
            if (!in_array($result->program_topics, $program[$nid]['program_topic'])) {
                $program[$nid]['program_topic'][] = $result->program_topics;
            }
            if (empty($program[$nid]['all_program_topic'])){
                $program[$nid]['all_program_topic'] = array();
            }
            if (!in_array($result->all_program_topics, $program[$nid]['all_program_topic'])) {
                $program[$nid]['all_program_topic'][] = $result->all_program_topics;
            }
            if (empty($program[$nid]['career_level'])){
                $program[$nid]['career_level'] = array();
            }
            if (!in_array($result->career_levels, $program[$nid]['career_level'])) {
                $program[$nid]['career_level'][] = $result->career_levels;
            }
            if (empty($program[$nid]['program_location'])){
                $program[$nid]['program_location'] = array();
            }
            if (!in_array($result->program_locations, $program[$nid]['program_location'])) {
                $program[$nid]['program_location'][] = $result->program_locations;
            }

            $time_commitment = '';
            if ($result->time_commitment) {
                $time_commitment = taxonomy_term_load($result->time_commitment);
                $time_commitment = $time_commitment->name;
            }

            $program[$nid]['program_format'] = $result->program_formats;
            $program[$nid]['location_name'] = $result->location_name;
            $program[$nid]['program_teaser'] = $result->program_teaser;
            $program[$nid]['start_date'] = ($result->start_date);
            $program[$nid]['end_date'] = $result->end_date;
            $program[$nid]['text_date'] = $result->text_date;
            $program[$nid]['date_select'] = $result->date_select;
            $program[$nid]['program_nid'] = $result->program_nid;
            $program[$nid]['program_detail_page'] = $result->program_detail_page;
            $program[$nid]['link_url'] = $result->link_url;
            $program[$nid]['link_url_attributes'] = $result->link_url_attributes;
            $program[$nid]['program_category'] = $result->program_category;
            $program[$nid]['time_commitment'] = $time_commitment;
            $program[$nid]['instance_label'] = $result->instance_label;
            $program[$nid]['location_link_url'] = $result->location_link_url;
            $program[$nid]['location_link_window'] = $result->location_link_window;
            $program[$nid]['application_state'] = $result->application_state;
        }
    }

    foreach ($program as $nid => $data) {
        $data['nid'] = $nid;
        if ($data['program_category'] == 'Degree Program') {
            $degree_title_fragments = explode(' ', $data['program_title']);
            $dp_parameters = array(
                'data' => theme('program_isotope_item', $data),
                'item-id' => $nid,
                'sort_title' => ($degree_title_fragments[0] == 'Stanford') ? $degree_title_fragments[1] : $degree_title_fragments[0],
                'sort' => array(
                    'title' => $data['title'],
                ),
            );
	    array_push($dp_items, $dp_parameters);
        }
        else {

            // Convert back to desired date format
            if ($data['date_select'] == 'Text') {
                $date = '99999999';
            }
            else {
                if (!empty($data['start_date'])) {
                    $date = date('Ymd', strtotime($data['start_date']));
                }
                else {
                    $date = '99999999';
                }
            }

            $title_fragments = explode(' ' , $data['program_title']);
            if ($title_fragments[0] === 'The' || $title_fragments[0] === 'A') {
                array_splice($title_fragments, 0, 1);
                $program_title = implode($title_fragments, ' ');
            } else {
                $program_title = $data['program_title'];
            }
            $parameters = array(
                'data' => theme('program_isotope_item', $data),
                'item-id' => $nid,
                'sort' => array(
                    'application_state' => $data['application_state'],
                    'start_date' => $date,
                    'program_title' => $program_title,
                ),
                'filters' => array(
                    'daterange' => array($date),
                ),
            );

            if (!empty($data['all_program_topic'])) {
                $parameters['filters']['program_topic'] = $data['all_program_topic'];
            }

            if (!empty($data['career_level'])) {
                $parameters['filters']['career_level'] = $data['career_level'];
            }

            if (!empty($data['program_location'])) {
                $parameters['filters']['program_location'] = $data['program_location'];
            }

            array_push($items, $parameters);		
        }
    }

    // Get all Program Topics
    $program_topics_query = db_select('taxonomy_term_data', 'ttd');
    $program_topics_query->fields('ttd', array('tid', 'name'));
    $program_topics_query->leftJoin('taxonomy_vocabulary', 'tv', 'tv.vid = ttd.vid');
    $program_topics_query->condition('tv.machine_name', 'program_topic');
    $program_topics_query->orderBy('ttd.weight', 'ASC');
    $program_topics_results = $program_topics_query->execute();

    while ($program_topic = $program_topics_results->fetchAssoc()) {
        $key = drupal_html_class($program_topic['name']);
        $program_topics[$key] = $program_topic['name'];
    }

    // Get all career levels
    $career_level_query = db_select('taxonomy_term_data', 'ttd');
    $career_level_query->fields('ttd', array('tid', 'name'));
    $career_level_query->leftJoin('taxonomy_vocabulary', 'tv', 'tv.vid = ttd.vid');
    $career_level_query->condition('tv.machine_name', 'career_level');
    $career_level_query->orderBy('ttd.weight', 'ASC');
    $career_level_results = $career_level_query->execute();

    while ($career_level = $career_level_results->fetchAssoc()) {
        $key = drupal_html_class($career_level['name']);
        $career_levels[$key] = $career_level['name'];
    }

    // Get all Locations
    $location_query = db_select('taxonomy_term_data', 'ttd');
    $location_query->fields('ttd', array('tid', 'name'));
    $location_query->leftJoin('taxonomy_vocabulary', 'tv', 'tv.vid = ttd.vid');
    $location_query->condition('tv.machine_name', 'program_location');
    $location_query->orderBy('ttd.weight', 'ASC');
    $location_results = $location_query->execute();

    while ($program_location = $location_results->fetchAssoc()) {
        $key = drupal_html_class($program_location['name']);
        $program_locations[$key] = $program_location['name'];
    }
    sortBy_field('sort_title',   $dp_items);
    $degree_programs =  theme('program_isotope_degree_item',array('full_time_programs' => $dp_items));
    $options = array(
        'filters' => array(
            'program_topic' => array(
                'type' => 'checkboxes',
                'title' => t('Topics'),
                'options' => $program_topics,
            ),
            'date_range' => array(
                'type' => 'date range',
                'title' => t('Date Range'),
                'date_from_title' => t('Date From (Format: YYYYMMDD)'),
                'date_to_title' => t('Date To (Format: YYYYMMDD)'),
                'default' => '',
            ),
            'program_location' => array(
                'type' => 'checkboxes',
                'title' => t('Location'),
                'options' => $program_locations,
            ),
            'career_level' => array(
                'type' => 'checkboxes',
                'title' => t('Career Level'),
                'options' => $career_levels,
            ),
            'search' => array(
                'type' => 'search',
                'placeholder' => t('Search by Keyword'),
            ),
            'submit' => array(
                'type' => 'submit',
                'title' => t('Search'),
            )
        ),
        'settings' => array(
            'lazyLoad' => TRUE,
            'title' => t('All Upcoming Programs'),
            'filterTitle' => t('Results for'),
            'header' => '<div id="edit-sort-toggle" class="tabs isotopify-filter-sort-toggle"
                    data-isotopify-additional-sort-start_date=["program_title"] 
                    data-isotopify-additional-sort-program_title=["start_date"]>
                    Sort by: 
                    <span class="tab-link" data-value="program_title" data-tab="tab-1">
                    Title
                    </span><span class="divider"> | </span>
                    <span class="tab-link current" data-value="start_date" data-tab="tab-2">
                    Start Date
                    </span>
                    </div>
                    <form id="form-compare" name="form-compare" action="/programs/compare/">',
            'footer' => $degree_programs .'<input type="submit" value="Compare" id="submit2" /></form>',
            'no_results' => empty($conf['no_result_text']) ? "" : $conf['no_result_text'],
        ),
        'id' => 'program_list',
    );

    $wrapper_data = array('programs' => isotopify_prepare($items, $options));
    $output = theme('program_isotope_item_wrapper',$wrapper_data);
    drupal_add_js(drupal_get_path('module', 'gsb_feature_program_finder_display') . '/js/gsb_program_show_hide.js');
    return (object) array(
        'content' => array(
            '#markup' => $output,
        ),
    );
}

/**
 * 'Edit form' callback for the content type.
 */
function gsb_feature_program_finder_display_gsb_program_list_edit_form($form, &$form_state) {

    $conf = $form_state['conf'];
    $form['override_title']['#access'] = FALSE;
    $form['override_title_text']['#access'] = FALSE;
    $form['override_title_heading']['#access'] = FALSE;
    $form['override_title_markup']['#access'] = FALSE;


    $defaults = array(
        'value' => $conf['no_result_text'],
        'format' => filter_default_format(),
    );

    $no_result_text = variable_get('no_result_text', $defaults);
    $form['no_result_text'] = array(
        '#type' => 'text_format',
        '#title' => t('No Result Text'),
        '#required' => FALSE,
        '#default_value' => $no_result_text['value'],
    );

    return $form;
}
function gsb_feature_program_finder_display_form_gsb_feature_program_finder_display_gsb_program_list_edit_form_alter(&$form, &$form_state, $form_id) {

    if ($form['#form_id'] == 'gsb_feature_program_finder_display_gsb_program_list_edit_form' ) {
        $form['#after_build'][] = 'gsb_feature_program_finder_display_gsb_edit_form_alter';
    }
}
// afterbuild function
function gsb_feature_program_finder_display_gsb_edit_form_alter($form) {

    $form['no_result_text']['format']['#access'] = FALSE;
    return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function  gsb_feature_program_finder_display_gsb_program_list_edit_form_submit($form, &$form_state) {

    $form_state['conf']['no_result_text'] = $form_state['values']['no_result_text']['value'];
}
