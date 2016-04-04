(function ($) {

  Drupal.behaviors.gsb_feature_program_finder = {
    attach: function (context, settings) {
      $("#submit2").attr("disabled", "disabled");
      $("#submit2").hide();
      $('#form-compare').before('<div id="sticker" class="compare-items" style="z-index:99 "></div>');
      $('.compare-items').append('<div class="header"><h3 class="compare-title">Compare Programs</h3><div class="compare-button"><input type="submit" id="js-submit" value="Compare" /></div></div>');
      $("#sticker").sticky({topSpacing:0});
      $("#sticker-sticky-wrapper").css({"z-index":99});

      if ($('.compare-item').length == 0) {
        $("#sticker-sticky-wrapper").hide();
        $("#sticker").hide();
      }
      else  {
        $("#sticker-sticky-wrapper").show();
        $("#sticker").show();
      }
      if ($('.programs input:checkbox').filter(':checked').length > 0 && $('.compare-item').length == 0){
        $('.programs input:checkbox').filter(':checked').each(function() {
          val = $(this).attr("id");
          if (val != undefined) {
            programParts = val.split('--');
            if ($('.' + programParts).length == 0 && $('.compare-item').length < 4) {
              if ($('#' + programParts[0]).length == 0) {
                program_title = "<div id='" + programParts[0] + "' class='compare-item' '>" + "<span class='remove-item'>x</span><div class='compare-program-title'>" + programParts[1] + "</div></div>";
                $('.compare-items').append(program_title);
              }
            }
          }
        });
        $("#sticker-sticky-wrapper").show();
        $("#sticker").show();
      }

      $('.compare').click(function( e ) {
        if ( $(e.target).is('input[type="checkbox"]') ) return;
        $(this).find('input').prop('checked', function( newValue, oldValue ) {return !oldValue});
        $(this).find('input').change();
      });

      i=0;
      var $compareItems = new Array();
      $('.programs input:checkbox').change( function() {
        if (this.checked == false) {
          item = $(this).val();
          $(".compare-items #" + item).remove();
          $("#" + item + "-label").text("Compare");
        }
        if (this.checked == true) {
          $("#sticker-sticky-wrapper").show();
          $("#sticker").show();
        }
        var $checked_checkboxes = $('.programs input:checkbox');
        $compareItems.length = 0;
        $checked_checkboxes.each(function () {
          if (this.checked) {
            $compareItems[i] = $(this).attr("id");
            parts = $compareItems[i].split('--');
            $("#" + parts[0] + "-label").text("Added");
            i++;
          }
        });
        jQuery.each($compareItems, function (i, val) {
          if (val != undefined) {
            programParts = val.split('--');
            if ($('.' + programParts).length == 0 && $('.compare-item').length < 4) {
              if ($('#' + programParts[0]).length == 0) {
                program_title = "<div id='" + programParts[0] + "' class='compare-item '>" + "<span class='remove-item'>x</span><div class='compare-program-title'>" + programParts[1] + "</div></div>";
                $('.compare-items').append(program_title);
              }
            }
          }
        });

        $checked = $('.programs input:checkbox').filter(':checked').length;
        var $checkboxes = $('.programs input:checkbox');
        if ($checked >= 3){
        $checkboxes.each(function () {
          if (!(this.checked)) {
            $(this).attr("disabled", "disabled");
            $(this).parent().addClass("inactive");
          }
        });
        }
          else
        {
          $checkboxes.each(function () {
            $(this).removeAttr("disabled");
            $(this).parent().removeClass("inactive");
          });
        }
        if ($('.compare-item').length == 0) {
          $('.compare-items').hide();
          $("#sticker-sticky-wrapper").hide();
          $("#sticker").hide();
        }
        ($('.compare-item').length > 1) ? $('.compare-button').show() : $('.compare-button').hide();
     });

    $(document).on('click','.remove-item',function() {
      item_id = $(this).parent().attr("id");
      term = ($(this).parent().text().trim()).slice(0,2);
      checkbox_id  = item_id + '--' + term;
      $(this).parent().remove();
      $("input[name=" +  item_id + '-item' + "]").attr('checked', false);
      $("#" + item_id + "-label").text("Compare");
      if ($('.compare-item').length == 0) {
        $('.compare-items').hide();
        $("#sticker-sticky-wrapper").hide();
        $("#sticker").hide();
      }
      ($('.compare-item').length > 1) ? $('.compare-button').show() : $('.compare-button').hide();
      $("input[name=" +  item_id + '-item' + "]").change();

    });

      $('#js-submit').click(function () {
      ids = '';
        $( ".compare-button").parent().siblings().each(function () {
        (ids == '') ? ids = $(this).attr('id') : ids += '+' + $(this).attr('id');
      });

        $(location).attr('href', document.location.origin + "/exec-ed/programs/compare/" + ids);
    });
    }
  };
})(jQuery);
