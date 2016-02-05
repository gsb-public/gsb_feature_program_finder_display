<div>
  <div class="programs">
    <?php print $programs; ?>
    <h3 class="full-time-header"><?php print t('Full-Time Degree Programs'); ?></h3>
    <div class="full-time-programs">
      <?php foreach ($full_time_programs as $it => $itd): ?>
        <?php print $itd['data']; ?>
      <?php endforeach; ?>
    </div>
    <div class="image-ctas">
      <?php print drupal_render($ctas); ?>
    </div>
  </div>
</div>