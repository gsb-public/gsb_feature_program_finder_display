<h3 class="full-time-header"><?php print t('Full-Time Degree Programs'); ?></h3>
<div class="full-time-programs-wrapper">
  <?php if (!empty($full_time_programs)): ?>
    <?php foreach ($full_time_programs as $it => $itd): ?>
      <div class="full-time-program " data-daterange="99999999" data-sort-start_date="99999999">
        <?php print $itd['data']; ?>
      </div>
    <?php endforeach; ?>
  <?php endif; ?>
</div>