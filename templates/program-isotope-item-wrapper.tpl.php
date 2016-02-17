<div>
  <div class="programs">
    <?php print $programs; ?>
    <h3 class="full-time-header"><?php print t('Full-Time Degree Programs'); ?></h3>
    <div class="full-time-programs-wrapper">
      <?php if (!empty($full_time_programs)): ?>
        <?php foreach ($full_time_programs as $it => $itd): ?>
          <div class="full-time-program">
            <?php print $itd['data']; ?>
          </div>
        <?php endforeach; ?>
      <?php endif; ?>
    </div>
    <!--
    <div class="image-ctas">
      <?php //print drupal_render($ctas); ?>
    </div> -->
  </div>
</div>
