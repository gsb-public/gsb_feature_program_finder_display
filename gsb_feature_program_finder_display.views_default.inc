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
  $handler->display->display_options['title'] = 'Program Comparison';
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
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = TRUE;
  $handler->display->display_options['footer']['area']['content'] = '* Other expenses may apply. Some programs may offer fellowships, scholarships, or discounts.';
  $handler->display->display_options['footer']['area']['format'] = 'gsb_wysiwyg_text';
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
  /* Field: Content: Instance Label */
  $handler->display->display_options['fields']['field_instance_label']['id'] = 'field_instance_label';
  $handler->display->display_options['fields']['field_instance_label']['table'] = 'field_data_field_instance_label';
  $handler->display->display_options['fields']['field_instance_label']['field'] = 'field_instance_label';
  $handler->display->display_options['fields']['field_instance_label']['label'] = '';
  $handler->display->display_options['fields']['field_instance_label']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_instance_label']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_instance_label']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_instance_label']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
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
  /* Field: Content: Text */
  $handler->display->display_options['fields']['field_instance_text']['id'] = 'field_instance_text';
  $handler->display->display_options['fields']['field_instance_text']['table'] = 'field_data_field_instance_text';
  $handler->display->display_options['fields']['field_instance_text']['field'] = 'field_instance_text';
  $handler->display->display_options['fields']['field_instance_text']['label'] = '';
  $handler->display->display_options['fields']['field_instance_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_instance_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_instance_text']['settings'] = array(
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
  /* Field: Field collection item: Format */
  $handler->display->display_options['fields']['field_program_format']['id'] = 'field_program_format';
  $handler->display->display_options['fields']['field_program_format']['table'] = 'field_data_field_program_format';
  $handler->display->display_options['fields']['field_program_format']['field'] = 'field_program_format';
  $handler->display->display_options['fields']['field_program_format']['relationship'] = 'field_program_location_value_1';
  $handler->display->display_options['fields']['field_program_format']['label'] = '';
  $handler->display->display_options['fields']['field_program_format']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program_format']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_format']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_program_format']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Field collection item: Program Location */
  $handler->display->display_options['fields']['field_program_location_link']['id'] = 'field_program_location_link';
  $handler->display->display_options['fields']['field_program_location_link']['table'] = 'field_data_field_program_location_link';
  $handler->display->display_options['fields']['field_program_location_link']['field'] = 'field_program_location_link';
  $handler->display->display_options['fields']['field_program_location_link']['relationship'] = 'field_program_location_value_1';
  $handler->display->display_options['fields']['field_program_location_link']['label'] = '';
  $handler->display->display_options['fields']['field_program_location_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program_location_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_program_location_link']['alter']['text'] = '| [field_program_location_link]';
  $handler->display->display_options['fields']['field_program_location_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_location_link']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_program_location_link']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_program_location_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_program_location_link']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_program_location_link']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Global: Custom text (Instance) */
  $handler->display->display_options['fields']['nothing_4']['id'] = 'nothing_4';
  $handler->display->display_options['fields']['nothing_4']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_4']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_4']['ui_name'] = 'Global: Custom text (Instance)';
  $handler->display->display_options['fields']['nothing_4']['label'] = '';
  $handler->display->display_options['fields']['nothing_4']['alter']['text'] = '<span class="views-field-field-instance-label">[field_instance_label]</span>
<span class="views-field-field-instance-date">[field_instance_date]</span>
<span class="views-field-field-instance-text">[field_instance_text]</span>
<div class="views-field-field-time-commitment">[field_time_commitment]</div>
<div class="views-field-field-program-location">[field_program_format] [field_program_location_link]</div>';
  $handler->display->display_options['fields']['nothing_4']['element_label_colon'] = FALSE;
  /* Field: Content: Tuition or Program Fee */
  $handler->display->display_options['fields']['field_tuition']['id'] = 'field_tuition';
  $handler->display->display_options['fields']['field_tuition']['table'] = 'field_data_field_tuition';
  $handler->display->display_options['fields']['field_tuition']['field'] = 'field_tuition';
  $handler->display->display_options['fields']['field_tuition']['label'] = '';
  $handler->display->display_options['fields']['field_tuition']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tuition']['alter']['text'] = '<div class="title">Tuition or Program Fee*</div>
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
  /* Field: Content: Intro */
  $handler->display->display_options['fields']['field_overview_intro']['id'] = 'field_overview_intro';
  $handler->display->display_options['fields']['field_overview_intro']['table'] = 'field_data_field_overview_intro';
  $handler->display->display_options['fields']['field_overview_intro']['field'] = 'field_overview_intro';
  $handler->display->display_options['fields']['field_overview_intro']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['field_overview_intro']['label'] = '';
  $handler->display->display_options['fields']['field_overview_intro']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_overview_intro']['alter']['text'] = '<div class="title">Overview</div>
[field_overview_intro]';
  $handler->display->display_options['fields']['field_overview_intro']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_overview_intro']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Intro */
  $handler->display->display_options['fields']['field_key_benefits_intro']['id'] = 'field_key_benefits_intro';
  $handler->display->display_options['fields']['field_key_benefits_intro']['table'] = 'field_data_field_key_benefits_intro';
  $handler->display->display_options['fields']['field_key_benefits_intro']['field'] = 'field_key_benefits_intro';
  $handler->display->display_options['fields']['field_key_benefits_intro']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['field_key_benefits_intro']['label'] = '';
  $handler->display->display_options['fields']['field_key_benefits_intro']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_key_benefits_intro']['alter']['text'] = '<div class="title">Key Benefits</div>
[field_key_benefits_intro]';
  $handler->display->display_options['fields']['field_key_benefits_intro']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_key_benefits_intro']['settings'] = array(
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
  $handler->display->display_options['fields']['field_event_who_attend']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_event_who_attend']['multi_type'] = 'ul';
  /* Field: Global: Custom text (Who should attend) */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Global: Custom text (Who should attend)';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<div class="title">Who Should Attend</div>
[field_event_who_attend] ';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  /* Field: Content: Awarded Upon Completion */
  $handler->display->display_options['fields']['field_awarded_upon_completion']['id'] = 'field_awarded_upon_completion';
  $handler->display->display_options['fields']['field_awarded_upon_completion']['table'] = 'field_data_field_awarded_upon_completion';
  $handler->display->display_options['fields']['field_awarded_upon_completion']['field'] = 'field_awarded_upon_completion';
  $handler->display->display_options['fields']['field_awarded_upon_completion']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['field_awarded_upon_completion']['label'] = '';
  $handler->display->display_options['fields']['field_awarded_upon_completion']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_awarded_upon_completion']['alter']['text'] = '<div class="title">Awarded Upon Completion</div>
[field_awarded_upon_completion]';
  $handler->display->display_options['fields']['field_awarded_upon_completion']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_awarded_upon_completion']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Deadlines */
  $handler->display->display_options['fields']['field_application_deadlines']['id'] = 'field_application_deadlines';
  $handler->display->display_options['fields']['field_application_deadlines']['table'] = 'field_data_field_application_deadlines';
  $handler->display->display_options['fields']['field_application_deadlines']['field'] = 'field_application_deadlines';
  $handler->display->display_options['fields']['field_application_deadlines']['label'] = '';
  $handler->display->display_options['fields']['field_application_deadlines']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_application_deadlines']['alter']['text'] = 'Application Deadline(s)
[field_application_deadlines] ';
  $handler->display->display_options['fields']['field_application_deadlines']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_deadlines']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_application_deadlines']['settings'] = array(
    'view_mode' => 'teaser',
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  $handler->display->display_options['fields']['field_application_deadlines']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_deadlines']['multi_type'] = 'ul';
  /* Field: Global: Custom text (Application Deadline) */
  $handler->display->display_options['fields']['nothing_3']['id'] = 'nothing_3';
  $handler->display->display_options['fields']['nothing_3']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_3']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_3']['ui_name'] = 'Global: Custom text (Application Deadline)';
  $handler->display->display_options['fields']['nothing_3']['label'] = '';
  $handler->display->display_options['fields']['nothing_3']['alter']['text'] = '<div class="title">Application Deadline</div>
[field_application_deadlines]';
  $handler->display->display_options['fields']['nothing_3']['element_label_colon'] = FALSE;
  /* Field: Content: All Topics */
  $handler->display->display_options['fields']['field_program_topics']['id'] = 'field_program_topics';
  $handler->display->display_options['fields']['field_program_topics']['table'] = 'field_data_field_program_topics';
  $handler->display->display_options['fields']['field_program_topics']['field'] = 'field_program_topics';
  $handler->display->display_options['fields']['field_program_topics']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['field_program_topics']['label'] = '';
  $handler->display->display_options['fields']['field_program_topics']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program_topics']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_program_topics']['alter']['text'] = '[field_program_topics]';
  $handler->display->display_options['fields']['field_program_topics']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_topics']['type'] = 'gsb_field_formatter_path_term_separator';
  $handler->display->display_options['fields']['field_program_topics']['settings'] = array(
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
  $handler->display->display_options['fields']['field_program_topics']['delta_offset'] = '0';
  /* Field: Field collection item: Program Location */
  $handler->display->display_options['fields']['field_program_location_link_1']['id'] = 'field_program_location_link_1';
  $handler->display->display_options['fields']['field_program_location_link_1']['table'] = 'field_data_field_program_location_link';
  $handler->display->display_options['fields']['field_program_location_link_1']['field'] = 'field_program_location_link';
  $handler->display->display_options['fields']['field_program_location_link_1']['relationship'] = 'field_program_location_value_1';
  $handler->display->display_options['fields']['field_program_location_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_program_location_link_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program_location_link_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_program_location_link_1']['alter']['text'] = '[field_program_location_link_1-url]';
  $handler->display->display_options['fields']['field_program_location_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_location_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_program_location_link_1']['type'] = 'link_url';
  $handler->display->display_options['fields']['field_program_location_link_1']['settings'] = array(
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
  $handler->display->display_options['fields']['field_program_location_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program_location_category']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_program_location_category']['alter']['text'] = '[field_program_location_category]';
  $handler->display->display_options['fields']['field_program_location_category']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_program_location_category']['alter']['path'] = '[field_program_location_link_1]';
  $handler->display->display_options['fields']['field_program_location_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_location_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_program_location_category']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Global: Custom text (Explore More) */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Custom text (Explore More)';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="title">Explore More</div>
[field_program_topics]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Program Contact Link */
  $handler->display->display_options['fields']['field_program_contact_link']['id'] = 'field_program_contact_link';
  $handler->display->display_options['fields']['field_program_contact_link']['table'] = 'field_data_field_program_contact_link';
  $handler->display->display_options['fields']['field_program_contact_link']['field'] = 'field_program_contact_link';
  $handler->display->display_options['fields']['field_program_contact_link']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['field_program_contact_link']['label'] = '';
  $handler->display->display_options['fields']['field_program_contact_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program_contact_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_contact_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_program_contact_link']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Program Lead Name */
  $handler->display->display_options['fields']['field_program_director_name']['id'] = 'field_program_director_name';
  $handler->display->display_options['fields']['field_program_director_name']['table'] = 'field_data_field_program_director_name';
  $handler->display->display_options['fields']['field_program_director_name']['field'] = 'field_program_director_name';
  $handler->display->display_options['fields']['field_program_director_name']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['field_program_director_name']['label'] = '';
  $handler->display->display_options['fields']['field_program_director_name']['exclude'] = TRUE;
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
  /* Field: Global: Custom text (Contact) */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Global: Custom text (Contact)';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="title">Contact</div>
[field_program_director_name]
<div class="mba-admission-link">[field_program_contact_link]</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Content: APower ID */
  $handler->display->display_options['fields']['field_apower_id']['id'] = 'field_apower_id';
  $handler->display->display_options['fields']['field_apower_id']['table'] = 'field_data_field_apower_id';
  $handler->display->display_options['fields']['field_apower_id']['field'] = 'field_apower_id';
  $handler->display->display_options['fields']['field_apower_id']['label'] = '';
  $handler->display->display_options['fields']['field_apower_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_apower_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_apower_id']['alter']['text'] = 'Download Brochure';
  $handler->display->display_options['fields']['field_apower_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_apower_id']['alter']['path'] = '/exec-ed/programs/download-brochure?pid=[nid]';
  $handler->display->display_options['fields']['field_apower_id']['alter']['prefix'] = '<div id="apower-pdf">';
  $handler->display->display_options['fields']['field_apower_id']['alter']['suffix'] = '</div>';
  $handler->display->display_options['fields']['field_apower_id']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_apower_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_apower_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_apower_id']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_apower_id']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Brochure */
  $handler->display->display_options['fields']['field_brochure_options']['id'] = 'field_brochure_options';
  $handler->display->display_options['fields']['field_brochure_options']['table'] = 'field_data_field_brochure_options';
  $handler->display->display_options['fields']['field_brochure_options']['field'] = 'field_brochure_options';
  $handler->display->display_options['fields']['field_brochure_options']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['field_brochure_options']['label'] = '';
  $handler->display->display_options['fields']['field_brochure_options']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_brochure_options']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_brochure_options']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_brochure_options']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_brochure_options']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Brochure */
  $handler->display->display_options['fields']['field_brochure_pdf']['id'] = 'field_brochure_pdf';
  $handler->display->display_options['fields']['field_brochure_pdf']['table'] = 'field_data_field_brochure_pdf';
  $handler->display->display_options['fields']['field_brochure_pdf']['field'] = 'field_brochure_pdf';
  $handler->display->display_options['fields']['field_brochure_pdf']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['field_brochure_pdf']['label'] = '';
  $handler->display->display_options['fields']['field_brochure_pdf']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_brochure_pdf']['alter']['text'] = '[field_apower_id]
<div id="direct-pdf">[field_brochure_pdf]</div> ';
  $handler->display->display_options['fields']['field_brochure_pdf']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_brochure_pdf']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_brochure_pdf']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_brochure_pdf']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_brochure_pdf']['type'] = 'gsb_field_formatter_download_link';
  $handler->display->display_options['fields']['field_brochure_pdf']['settings'] = array(
    'text' => 'Download Brochure',
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
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
  $handler->display->display_options['path'] = 'exec-ed/programs/compare';

  /* Display: Responsive compared page */
  $handler = $view->new_display('attachment', 'Responsive compared page', 'attachment_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'compared-page-responsive';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = TRUE;
  $handler->display->display_options['footer']['area']['format'] = 'gsb_wysiwyg_text';
  $handler->display->display_options['displays'] = array(
    'compare' => 'compare',
    'default' => 0,
  );
  $export['ee_program_finder'] = $view;

  $view = new view();
  $view->name = 'gsb_program_compare';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'GSB Program Compare';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Program Compare';
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
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = TRUE;
  $handler->display->display_options['footer']['area']['content'] = '* Other expenses may apply. Some programs may offer fellowships. scholarships, or discounts';
  $handler->display->display_options['footer']['area']['format'] = 'gsb_wysiwyg_text';
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
  /* Field: Content: Instance Label */
  $handler->display->display_options['fields']['field_instance_label']['id'] = 'field_instance_label';
  $handler->display->display_options['fields']['field_instance_label']['table'] = 'field_data_field_instance_label';
  $handler->display->display_options['fields']['field_instance_label']['field'] = 'field_instance_label';
  $handler->display->display_options['fields']['field_instance_label']['label'] = '';
  $handler->display->display_options['fields']['field_instance_label']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_instance_label']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_instance_label']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_instance_label']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
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
  /* Field: Content: Text */
  $handler->display->display_options['fields']['field_instance_text']['id'] = 'field_instance_text';
  $handler->display->display_options['fields']['field_instance_text']['table'] = 'field_data_field_instance_text';
  $handler->display->display_options['fields']['field_instance_text']['field'] = 'field_instance_text';
  $handler->display->display_options['fields']['field_instance_text']['label'] = '';
  $handler->display->display_options['fields']['field_instance_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_instance_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_instance_text']['settings'] = array(
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
  /* Field: Field collection item: Format */
  $handler->display->display_options['fields']['field_program_format']['id'] = 'field_program_format';
  $handler->display->display_options['fields']['field_program_format']['table'] = 'field_data_field_program_format';
  $handler->display->display_options['fields']['field_program_format']['field'] = 'field_program_format';
  $handler->display->display_options['fields']['field_program_format']['relationship'] = 'field_program_location_value_1';
  $handler->display->display_options['fields']['field_program_format']['label'] = '';
  $handler->display->display_options['fields']['field_program_format']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program_format']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_format']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_program_format']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Field collection item: Program Location */
  $handler->display->display_options['fields']['field_program_location_link']['id'] = 'field_program_location_link';
  $handler->display->display_options['fields']['field_program_location_link']['table'] = 'field_data_field_program_location_link';
  $handler->display->display_options['fields']['field_program_location_link']['field'] = 'field_program_location_link';
  $handler->display->display_options['fields']['field_program_location_link']['relationship'] = 'field_program_location_value_1';
  $handler->display->display_options['fields']['field_program_location_link']['label'] = '';
  $handler->display->display_options['fields']['field_program_location_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program_location_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_program_location_link']['alter']['text'] = '| [field_program_location_link]';
  $handler->display->display_options['fields']['field_program_location_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_location_link']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_program_location_link']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_program_location_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_program_location_link']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_program_location_link']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Global: Custom text (Instance) */
  $handler->display->display_options['fields']['nothing_4']['id'] = 'nothing_4';
  $handler->display->display_options['fields']['nothing_4']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_4']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_4']['ui_name'] = 'Global: Custom text (Instance)';
  $handler->display->display_options['fields']['nothing_4']['label'] = '';
  $handler->display->display_options['fields']['nothing_4']['alter']['text'] = '<span class="views-field-field-instance-label">[field_instance_label]</span>
<span class="views-field-field-instance-date">[field_instance_date]</span>
<span class="views-field-field-instance-text">[field_instance_text]</span>
<div class="views-field-field-time-commitment">[field_time_commitment]</div>
<div class="views-field-field-program-location">[field_program_format] [field_program_location_link]</div>';
  $handler->display->display_options['fields']['nothing_4']['element_label_colon'] = FALSE;
  /* Field: Content: Tuition or Program Fee */
  $handler->display->display_options['fields']['field_tuition']['id'] = 'field_tuition';
  $handler->display->display_options['fields']['field_tuition']['table'] = 'field_data_field_tuition';
  $handler->display->display_options['fields']['field_tuition']['field'] = 'field_tuition';
  $handler->display->display_options['fields']['field_tuition']['label'] = '';
  $handler->display->display_options['fields']['field_tuition']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tuition']['alter']['text'] = '<div class="title">Tuition or Program Fee*</div>
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
  /* Field: Content: Intro */
  $handler->display->display_options['fields']['field_overview_intro']['id'] = 'field_overview_intro';
  $handler->display->display_options['fields']['field_overview_intro']['table'] = 'field_data_field_overview_intro';
  $handler->display->display_options['fields']['field_overview_intro']['field'] = 'field_overview_intro';
  $handler->display->display_options['fields']['field_overview_intro']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['field_overview_intro']['label'] = '';
  $handler->display->display_options['fields']['field_overview_intro']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_overview_intro']['alter']['text'] = '<div class="title">Overview</div>
[field_overview_intro]';
  $handler->display->display_options['fields']['field_overview_intro']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_overview_intro']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Intro */
  $handler->display->display_options['fields']['field_key_benefits_intro']['id'] = 'field_key_benefits_intro';
  $handler->display->display_options['fields']['field_key_benefits_intro']['table'] = 'field_data_field_key_benefits_intro';
  $handler->display->display_options['fields']['field_key_benefits_intro']['field'] = 'field_key_benefits_intro';
  $handler->display->display_options['fields']['field_key_benefits_intro']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['field_key_benefits_intro']['label'] = '';
  $handler->display->display_options['fields']['field_key_benefits_intro']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_key_benefits_intro']['alter']['text'] = '<div class="title">Key Benefits</div>
[field_key_benefits_intro]';
  $handler->display->display_options['fields']['field_key_benefits_intro']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_key_benefits_intro']['settings'] = array(
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
  $handler->display->display_options['fields']['field_event_who_attend']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_event_who_attend']['multi_type'] = 'ul';
  /* Field: Global: Custom text (Who should attend) */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Global: Custom text (Who should attend)';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<div class="title">Who Should Attend</div>
[field_event_who_attend] ';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  /* Field: Content: Awarded Upon Completion */
  $handler->display->display_options['fields']['field_awarded_upon_completion']['id'] = 'field_awarded_upon_completion';
  $handler->display->display_options['fields']['field_awarded_upon_completion']['table'] = 'field_data_field_awarded_upon_completion';
  $handler->display->display_options['fields']['field_awarded_upon_completion']['field'] = 'field_awarded_upon_completion';
  $handler->display->display_options['fields']['field_awarded_upon_completion']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['field_awarded_upon_completion']['label'] = '';
  $handler->display->display_options['fields']['field_awarded_upon_completion']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_awarded_upon_completion']['alter']['text'] = '<div class="title">Awarded Upon Completion</div>
[field_awarded_upon_completion]';
  $handler->display->display_options['fields']['field_awarded_upon_completion']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_awarded_upon_completion']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Deadlines */
  $handler->display->display_options['fields']['field_application_deadlines']['id'] = 'field_application_deadlines';
  $handler->display->display_options['fields']['field_application_deadlines']['table'] = 'field_data_field_application_deadlines';
  $handler->display->display_options['fields']['field_application_deadlines']['field'] = 'field_application_deadlines';
  $handler->display->display_options['fields']['field_application_deadlines']['label'] = '';
  $handler->display->display_options['fields']['field_application_deadlines']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_application_deadlines']['alter']['text'] = 'Application Deadline(s)
[field_application_deadlines] ';
  $handler->display->display_options['fields']['field_application_deadlines']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_deadlines']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_application_deadlines']['settings'] = array(
    'view_mode' => 'teaser',
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  $handler->display->display_options['fields']['field_application_deadlines']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_deadlines']['multi_type'] = 'ul';
  /* Field: Global: Custom text (Application Deadline) */
  $handler->display->display_options['fields']['nothing_3']['id'] = 'nothing_3';
  $handler->display->display_options['fields']['nothing_3']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_3']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_3']['ui_name'] = 'Global: Custom text (Application Deadline)';
  $handler->display->display_options['fields']['nothing_3']['label'] = '';
  $handler->display->display_options['fields']['nothing_3']['alter']['text'] = '<div class="title">Application Deadline</div>
[field_application_deadlines]';
  $handler->display->display_options['fields']['nothing_3']['element_label_colon'] = FALSE;
  /* Field: Content: All Topics */
  $handler->display->display_options['fields']['field_program_topics']['id'] = 'field_program_topics';
  $handler->display->display_options['fields']['field_program_topics']['table'] = 'field_data_field_program_topics';
  $handler->display->display_options['fields']['field_program_topics']['field'] = 'field_program_topics';
  $handler->display->display_options['fields']['field_program_topics']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['field_program_topics']['label'] = '';
  $handler->display->display_options['fields']['field_program_topics']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program_topics']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_program_topics']['alter']['text'] = '[field_program_topics]';
  $handler->display->display_options['fields']['field_program_topics']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_topics']['type'] = 'gsb_field_formatter_path_term_separator';
  $handler->display->display_options['fields']['field_program_topics']['settings'] = array(
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
  $handler->display->display_options['fields']['field_program_topics']['delta_offset'] = '0';
  /* Field: Field collection item: Program Location */
  $handler->display->display_options['fields']['field_program_location_link_1']['id'] = 'field_program_location_link_1';
  $handler->display->display_options['fields']['field_program_location_link_1']['table'] = 'field_data_field_program_location_link';
  $handler->display->display_options['fields']['field_program_location_link_1']['field'] = 'field_program_location_link';
  $handler->display->display_options['fields']['field_program_location_link_1']['relationship'] = 'field_program_location_value_1';
  $handler->display->display_options['fields']['field_program_location_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_program_location_link_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program_location_link_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_program_location_link_1']['alter']['text'] = '[field_program_location_link_1-url]';
  $handler->display->display_options['fields']['field_program_location_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_location_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_program_location_link_1']['type'] = 'link_url';
  $handler->display->display_options['fields']['field_program_location_link_1']['settings'] = array(
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
  $handler->display->display_options['fields']['field_program_location_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program_location_category']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_program_location_category']['alter']['text'] = '[field_program_location_category]';
  $handler->display->display_options['fields']['field_program_location_category']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_program_location_category']['alter']['path'] = '[field_program_location_link_1]';
  $handler->display->display_options['fields']['field_program_location_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_location_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_program_location_category']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Global: Custom text (Explore More) */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Custom text (Explore More)';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="title">Explore More</div>
[field_program_topics]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Program Contact Link */
  $handler->display->display_options['fields']['field_program_contact_link']['id'] = 'field_program_contact_link';
  $handler->display->display_options['fields']['field_program_contact_link']['table'] = 'field_data_field_program_contact_link';
  $handler->display->display_options['fields']['field_program_contact_link']['field'] = 'field_program_contact_link';
  $handler->display->display_options['fields']['field_program_contact_link']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['field_program_contact_link']['label'] = '';
  $handler->display->display_options['fields']['field_program_contact_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program_contact_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_contact_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_program_contact_link']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Program Lead Name */
  $handler->display->display_options['fields']['field_program_director_name']['id'] = 'field_program_director_name';
  $handler->display->display_options['fields']['field_program_director_name']['table'] = 'field_data_field_program_director_name';
  $handler->display->display_options['fields']['field_program_director_name']['field'] = 'field_program_director_name';
  $handler->display->display_options['fields']['field_program_director_name']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['field_program_director_name']['label'] = '';
  $handler->display->display_options['fields']['field_program_director_name']['exclude'] = TRUE;
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
  /* Field: Global: Custom text (Contact) */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Global: Custom text (Contact)';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="title">Contact</div>
[field_program_director_name]
<div class="mba-admission-link">[field_program_contact_link]</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Content: APower ID */
  $handler->display->display_options['fields']['field_apower_id']['id'] = 'field_apower_id';
  $handler->display->display_options['fields']['field_apower_id']['table'] = 'field_data_field_apower_id';
  $handler->display->display_options['fields']['field_apower_id']['field'] = 'field_apower_id';
  $handler->display->display_options['fields']['field_apower_id']['label'] = '';
  $handler->display->display_options['fields']['field_apower_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_apower_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_apower_id']['alter']['text'] = 'Download Brochure';
  $handler->display->display_options['fields']['field_apower_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_apower_id']['alter']['path'] = '/exec-ed/programs/download-brochure?pid=[nid]';
  $handler->display->display_options['fields']['field_apower_id']['alter']['prefix'] = '<div id="apower-pdf">';
  $handler->display->display_options['fields']['field_apower_id']['alter']['suffix'] = '</div>';
  $handler->display->display_options['fields']['field_apower_id']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_apower_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_apower_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_apower_id']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_apower_id']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Brochure */
  $handler->display->display_options['fields']['field_brochure_options']['id'] = 'field_brochure_options';
  $handler->display->display_options['fields']['field_brochure_options']['table'] = 'field_data_field_brochure_options';
  $handler->display->display_options['fields']['field_brochure_options']['field'] = 'field_brochure_options';
  $handler->display->display_options['fields']['field_brochure_options']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['field_brochure_options']['label'] = '';
  $handler->display->display_options['fields']['field_brochure_options']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_brochure_options']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_brochure_options']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_brochure_options']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_brochure_options']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Brochure */
  $handler->display->display_options['fields']['field_brochure_pdf']['id'] = 'field_brochure_pdf';
  $handler->display->display_options['fields']['field_brochure_pdf']['table'] = 'field_data_field_brochure_pdf';
  $handler->display->display_options['fields']['field_brochure_pdf']['field'] = 'field_brochure_pdf';
  $handler->display->display_options['fields']['field_brochure_pdf']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['field_brochure_pdf']['label'] = '';
  $handler->display->display_options['fields']['field_brochure_pdf']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_brochure_pdf']['alter']['text'] = '[field_apower_id]
<div id="direct-pdf">[field_brochure_pdf]</div> ';
  $handler->display->display_options['fields']['field_brochure_pdf']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_brochure_pdf']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_brochure_pdf']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_brochure_pdf']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_brochure_pdf']['type'] = 'gsb_field_formatter_download_link';
  $handler->display->display_options['fields']['field_brochure_pdf']['settings'] = array(
    'text' => 'Download Brochure',
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
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
  $handler->display->display_options['path'] = 'programs/compare';
  $export['gsb_program_compare'] = $view;

  return $export;
}
