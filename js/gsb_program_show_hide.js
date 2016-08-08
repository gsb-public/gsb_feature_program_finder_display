(function ($) {

  Drupal.behaviors.gsb_program_show_hide = {
    attach: function (context, settings) {

      var $location = $('.form-item-filter-program-location input:checkbox').filter(':checked');
      var $no_results_text = $(".isotopify .no-results-text");
      var $header = $('.full-time-header');
      var $wrapper = $('.full-time-programs-wrapper');
      $header.show();
      $wrapper.show();
      if ($location.length == 0) {
        $no_results_text.hide();
        $header.show();
        $wrapper.show();
      } else {
        $location.each(function () {
          val = $(this).val();
          if (val == 'in-person-stanford') {
            $header.show();
            $wrapper.show();
            return false;
          } else {
            $header.hide();
            $wrapper.hide();
          }
        });
      }
      $("#edit-submit ").click(function() {
        if ( $("#isotopify ").hasClass("no-degree-programs") &&  $("#isotopify ").hasClass("no-results")) {
          $no_results_text.show();
        } else {
          $header.show();
          $wrapper.show();
        }
      });

      $('.filter-exit').click( function() {
        $(".checkbox-apply ").click();
      });
      $('.clear-filters ').click( function() {
        $(".checkbox-apply ").click();
      });

      $(".checkbox-apply ").click(function(){
        var showFlag = false;
        $location = $('.form-item-filter-program-location input:checkbox').filter(':checked');
        if ($location.length == 0) {
          showFlag = true;
        }
        $location.each(function() {
          val = $(this).val();
          if (val == 'in-person-stanford') {
            showFlag = true;
            return false;
          } else {
            showFlag = false;
          }
        });
        if (showFlag) {
          $header.show();
          $wrapper.show();
          $('#isotopify').removeClass("no-degree-programs");
          $no_results_text.hide();

        } else {
          $header.hide();
          $wrapper.hide();
          $('#isotopify').addClass("no-degree-programs");
          $no_results_text.hide();
          if ($("#isotopify").hasClass("no-results")) {
            $no_results_text.show();
          }
        }

      });
    }
  }

})(jQuery);
