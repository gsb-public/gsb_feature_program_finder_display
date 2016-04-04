(function ($) {
  Drupal.behaviors.gsb_feature_program_finder = {
    attach: function (context, settings) {
      $(".views-field-field-brochure-pdf #apower-pdf").each(function(){
          $(this).siblings().hide();
      });
    }
  };
})(jQuery);