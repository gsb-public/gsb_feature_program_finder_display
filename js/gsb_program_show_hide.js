(function ($) {

  Drupal.behaviors.gsb_program_show_hide = {
    attach: function (context, settings) {

      if ($('.form-item-filter-program-location input:checkbox').filter(':checked').length == 0) {
        $(".isotopify .no-results-text").hide();
      }

      $(".checkbox-apply ").click(function(){

        var showFlag = false;
        var loc_count = $('.form-item-filter-program-location input:checkbox').filter(':checked').length;
          $('.form-item-filter-program-location input:checkbox').filter(':checked').each(function() {
            val = $(this).val();
            if (val == 'in-person-stanford') {
              showFlag = true;
              return false;
            }
          });

          if (showFlag || loc_count == 0 ) {
            $('.full-time-header').show();
            $('.full-time-programs-wrapper').show();
            $(".isotopify .no-results-text").hide();

          } else {
            $('.full-time-header').hide();
            $('.full-time-programs-wrapper').hide();
            $(".isotopify .no-results-text").show();
          }

      });
    }
  }

  })(jQuery);