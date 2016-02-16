<!--<div class="program-title" style="padding-right:300px">
  <?php// print $title; ?>
</div>-->
<div class="program-title">
  <?php if ($program_detail_page == 0){
    print l(t($program_title), drupal_lookup_path('alias', "node/".$program_nid));
  } else {
    $parsed = parse_url($link_url);
    if ($parsed['scheme'] == 'http' || $parsed['scheme'] == 'https' ){
      print l(t($program_title), $link_url , array('external' => TRUE ));
    } else {
      print l(t($program_title), $link_url);
    }
  } ?>
</div>
<?php
      if ($program_category != 'Full-Time Degree program'):
         if ($start_date != '' && $end_date != '' && $date_select == 'Date'): ?>
           <div class="program-date">
             <?php print date_format(date_create($start_date), 'd M Y') . ' – ' . date_format(date_create($end_date), 'd M Y'); ?>
           </div>
         <?php endif; ?>
         <?php if ($date_select == 'Text' && $text_date != ''): ?>
           <div class="program-text-date">
             <?php print $text_date; ?>
           </div>
         <?php endif;
      endif;
?>
<?php $location = $program_format;
      if ($location != '' &&  $location_name != '') {
       $location .= ' | ' . $location_name;
      } else {
       $location .= $location_name;
      }
      if ($location != ''):
       ?>
  <div class="program-format">
    <?php print $location ?>
  </div>
<?php endif; ?>
<div class="program-teaser">
  <?php print $program_teaser; ?>
</div>
<?php if ($program_topic != ''): ?>
  <div class="program-topic">
    <?php
    foreach ($program_topic as $id => $topic):
      $topic_key = drupal_html_class($topic);
      $link = url(drupal_get_path_alias(), array('absolute' => TRUE, 'query' => array('program-topic' => $topic_key)));
      $program_topic[$id] = l($topic, $link);
    endforeach;
    $program_topic = implode($program_topic, ', ');
    print $program_topic; ?>
  </div>
<?php endif; ?>