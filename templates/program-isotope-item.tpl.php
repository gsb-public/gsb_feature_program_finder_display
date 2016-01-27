<div class="program-title">
  <?php print $program_title; ?>
</div>
<?php if($start_date != '' && $end_date != '' ) { ?>
  <div class="program-date">
    <?php print date_format(date_create($start_date),'d M Y').' – '.date_format(date_create($end_date),'d M Y'); ?>
  </div>
<?php } ?>
<?php if ($program_location != '') { ?>
  <div class="program-location">
    <?php print $program_location; ?>
  </div>
<?php } ?>
<div class="program-teaser">
  <?php print $program_teaser; ?>
</div>
<?php if ($program_topic != '') { ?>
  <div class="program-topic">
    <?php print $program_topic; ?>
  </div>
<?php } ?>
