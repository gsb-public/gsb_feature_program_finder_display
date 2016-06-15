(function ($) {
  Drupal.behaviors.gsb_feature_program_finder = {
    attach: function (context, settings) {
      $(".views-field-field-brochure-pdf #apower-pdf").each(function(){
          $(this).siblings().hide();
      });

      // remove the pipe if found at the end for application deadlines
      $(".field-collection-item-field-application-deadlines").each(function(){
        var text = $(this).text();
        if (text.substr(-1) === '|') {
          $(this).text($(this).text().replace('|',''));
        }
      });

      if(document.referrer.indexOf("/program") == -1){
        $(".back-to-programs a").attr("href", "/exec-ed/programs")
      }
    }
  };
})(jQuery);
