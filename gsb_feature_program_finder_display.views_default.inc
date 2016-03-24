<?php
/**
 * @file
 * gsb_feature_program_finder_display.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function gsb_feature_program_finder_display_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ee_program_finder';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'EE Program Comparison';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'EE Program Comparison';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'flipped';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_instance_date' => 'field_instance_date',
    'field_time_commitment' => 'field_time_commitment',
    'field_program_location_category' => 'field_program_location_category',
    'field_application_deadlines' => 'field_application_deadlines',
    'field_tuition' => 'field_tuition',
    'field_overview_teaser' => 'field_overview_teaser',
    'field_key_program_topics' => 'field_key_program_topics',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_instance_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_time_commitment' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_program_location_category' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_application_deadlines' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tuition' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_overview_teaser' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_key_program_topics' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['flipped_table_header_first_field'] = 0;
  $handler->display->display_options['style_options']['column_class_special'] = 0;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['relationships']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['relationships']['field_program_target_id']['field'] = 'field_program_target_id';
  /* Relationship: Content: Program Format &amp; Location (field_program_location) */
  $handler->display->display_options['relationships']['field_program_location_value']['id'] = 'field_program_location_value';
  $handler->display->display_options['relationships']['field_program_location_value']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['relationships']['field_program_location_value']['field'] = 'field_program_location_value';
  $handler->display->display_options['relationships']['field_program_location_value']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['relationships']['field_program_location_value']['delta'] = '-1';
  /* Relationship: Content: Program Format &amp; Location (field_program_location) */
  $handler->display->display_options['relationships']['field_program_location_value_1']['id'] = 'field_program_location_value_1';
  $handler->display->display_options['relationships']['field_program_location_value_1']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['relationships']['field_program_location_value_1']['field'] = 'field_program_location_value';
  $handler->display->display_options['relationships']['field_program_location_value_1']['delta'] = '-1';
  /* Relationship: Content: Deadlines (field_application_deadlines) */
  $handler->display->display_options['relationships']['field_application_deadlines_value']['id'] = 'field_application_deadlines_value';
  $handler->display->display_options['relationships']['field_application_deadlines_value']['table'] = 'field_data_field_application_deadlines';
  $handler->display->display_options['relationships']['field_application_deadlines_value']['field'] = 'field_application_deadlines_value';
  $handler->display->display_options['relationships']['field_application_deadlines_value']['relationship'] = 'field_application_deadlines_node';
  $handler->display->display_options['relationships']['field_application_deadlines_value']['delta'] = '-1';
  /* Relationship: Field collection item: Entity with the Deadlines (field_application_deadlines) */
  $handler->display->display_options['relationships']['field_application_deadlines_node_1']['id'] = 'field_application_deadlines_node_1';
  $handler->display->display_options['relationships']['field_application_deadlines_node_1']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_application_deadlines_node_1']['field'] = 'field_application_deadlines_node';
  $handler->display->display_options['relationships']['field_application_deadlines_node_1']['relationship'] = 'field_application_deadlines_value';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_instance_date']['id'] = 'field_instance_date';
  $handler->display->display_options['fields']['field_instance_date']['table'] = 'field_data_field_instance_date';
  $handler->display->display_options['fields']['field_instance_date']['field'] = 'field_instance_date';
  $handler->display->display_options['fields']['field_instance_date']['label'] = '';
  $handler->display->display_options['fields']['field_instance_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_instance_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_instance_date']['settings'] = array(
    'format_type' => 'day_month_and_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Time Commitment */
  $handler->display->display_options['fields']['field_time_commitment']['id'] = 'field_time_commitment';
  $handler->display->display_options['fields']['field_time_commitment']['table'] = 'field_data_field_time_commitment';
  $handler->display->display_options['fields']['field_time_commitment']['field'] = 'field_time_commitment';
  $handler->display->display_options['fields']['field_time_commitment']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['field_time_commitment']['label'] = '';
  $handler->display->display_options['fields']['field_time_commitment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_time_commitment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_time_commitment']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_time_commitment']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Field collection item: Location Category */
  $handler->display->display_options['fields']['field_program_location_category']['id'] = 'field_program_location_category';
  $handler->display->display_options['fields']['field_program_location_category']['table'] = 'field_data_field_program_location_category';
  $handler->display->display_options['fields']['field_program_location_category']['field'] = 'field_program_location_category';
  $handler->display->display_options['fields']['field_program_location_category']['relationship'] = 'field_program_location_value_1';
  $handler->display->display_options['fields']['field_program_location_category']['label'] = '';
  $handler->display->display_options['fields']['field_program_location_category']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_program_location_category']['alter']['text'] = '<div>Date & Location</div>[field_instance_date]
[field_time_commitment]
[field_program_location_category]';
  $handler->display->display_options['fields']['field_program_location_category']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_program_location_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_location_category']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_program_location_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_program_location_category']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Field: Publication Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['relationship'] = 'field_application_deadlines_value';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_date']['alter']['text'] = '<div>Application Deadlines</div>
[field_date]';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Tuition */
  $handler->display->display_options['fields']['field_tuition']['id'] = 'field_tuition';
  $handler->display->display_options['fields']['field_tuition']['table'] = 'field_data_field_tuition';
  $handler->display->display_options['fields']['field_tuition']['field'] = 'field_tuition';
  $handler->display->display_options['fields']['field_tuition']['label'] = '';
  $handler->display->display_options['fields']['field_tuition']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tuition']['alter']['text'] = '<div>Tuition(additional expenses may occur)</div>
[field_tuition]';
  $handler->display->display_options['fields']['field_tuition']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tuition']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_tuition']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Who Should Attend? */
  $handler->display->display_options['fields']['field_event_who_attend']['id'] = 'field_event_who_attend';
  $handler->display->display_options['fields']['field_event_who_attend']['table'] = 'field_data_field_event_who_attend';
  $handler->display->display_options['fields']['field_event_who_attend']['field'] = 'field_event_who_attend';
  $handler->display->display_options['fields']['field_event_who_attend']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['field_event_who_attend']['label'] = '';
  $handler->display->display_options['fields']['field_event_who_attend']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_event_who_attend']['alter']['text'] = '<div>Who Should Attend?</div>
[field_event_who_attend]';
  $handler->display->display_options['fields']['field_event_who_attend']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_who_attend']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_event_who_attend']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  $handler->display->display_options['fields']['field_event_who_attend']['delta_offset'] = '0';
  /* Field: Content: Awarded Upon Completion */
  $handler->display->display_options['fields']['field_awarded_upon_completion']['id'] = 'field_awarded_upon_completion';
  $handler->display->display_options['fields']['field_awarded_upon_completion']['table'] = 'field_data_field_awarded_upon_completion';
  $handler->display->display_options['fields']['field_awarded_upon_completion']['field'] = 'field_awarded_upon_completion';
  $handler->display->display_options['fields']['field_awarded_upon_completion']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['field_awarded_upon_completion']['label'] = '';
  $handler->display->display_options['fields']['field_awarded_upon_completion']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_awarded_upon_completion']['alter']['text'] = '<div>Awarded Upon Completion</div>
[field_awarded_upon_completion]';
  $handler->display->display_options['fields']['field_awarded_upon_completion']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_awarded_upon_completion']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Key Topics */
  $handler->display->display_options['fields']['field_key_program_topics']['id'] = 'field_key_program_topics';
  $handler->display->display_options['fields']['field_key_program_topics']['table'] = 'field_data_field_key_program_topics';
  $handler->display->display_options['fields']['field_key_program_topics']['field'] = 'field_key_program_topics';
  $handler->display->display_options['fields']['field_key_program_topics']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['field_key_program_topics']['label'] = '';
  $handler->display->display_options['fields']['field_key_program_topics']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_key_program_topics']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_key_program_topics']['alter']['text'] = '[field_key_program_topics]';
  $handler->display->display_options['fields']['field_key_program_topics']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_key_program_topics']['type'] = 'gsb_field_formatter_path_term_separator';
  $handler->display->display_options['fields']['field_key_program_topics']['settings'] = array(
    'path_prefix' => 'taxonomy/term/',
    'tid_or_name' => 'tid',
    'separator' => '',
    'limit_depth' => 0,
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  $handler->display->display_options['fields']['field_key_program_topics']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div>Key Topics</div>
[field_key_program_topics]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Program Lead Name */
  $handler->display->display_options['fields']['field_program_director_name']['id'] = 'field_program_director_name';
  $handler->display->display_options['fields']['field_program_director_name']['table'] = 'field_data_field_program_director_name';
  $handler->display->display_options['fields']['field_program_director_name']['field'] = 'field_program_director_name';
  $handler->display->display_options['fields']['field_program_director_name']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['field_program_director_name']['label'] = '';
  $handler->display->display_options['fields']['field_program_director_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_program_director_name']['alter']['text'] = '<div>Contact</div>
[field_program_director_name]';
  $handler->display->display_options['fields']['field_program_director_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_director_name']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_program_director_name']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_program_director_name']['settings'] = array(
    'view_mode' => 'program_director',
    'links' => 0,
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Download';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = '/exec-ed/programs/download-brochure?pid=[nid]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = '$param = "";
 foreach ($_GET as $key => $value) {
 if ($key != \'q\') {
  $param == "" ? $param = $value : $param .= "+" . $value;
}
}
return $param;';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = TRUE;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program_instance' => 'program_instance',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'compare');
  $handler->display->display_options['path'] = 'ee-program-comparison';
  $export['ee_program_finder'] = $view;

  return $export;
}
