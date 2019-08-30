(function ($) {

  Drupal.behaviors.gsb_feature_program_finder = {
    attach: function (context, settings) {

      $("#submit2").attr("disabled", "disabled");
      $("#submit2").hide();
      if ($("#sticker").length == 0 ) {
        $('#form-compare').before('<div id="sticker" class="compare-items" style="z-index:99 "></div>');
      }
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
            if ($('#' + programParts[0]).length == 0 && $('.compare-item').length < 4) {
              program_title = "<div id='" + programParts[0] + "' class='compare-item' '>" + "<span class='remove-item'>x</span><div class='compare-program-title'>" + programParts[1] + "</div></div>";
              $('.compare-items').append(program_title);
            }
          }
        });
        $("#sticker-sticky-wrapper").show();
        $("#sticker").show();
      }

      $('.compare').click(function( e ) {
        if ( $(e.target).is('input[type="checkbox"]') ) return;
        if (!$(this).find('input').prop('disabled')) {
          $(this).find('input').prop('checked', function( newValue, oldValue ) {return !oldValue});
          $(this).find('input').change();
        }
      });

      i=0;
      var $compareItems = new Array();
      $('.programs input:checkbox').change( function() {

        // get initial position
        var yPos = $(this).offset().top - $(window).scrollTop();

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
          if (this.checked && !(this.disabled)) {
            $compareItems[i] = $(this).attr("id");
            parts = $compareItems[i].split('--');
            $("#" + parts[0] + "-label").text("Added");
            i++;
          }
        });
        jQuery.each($compareItems, function (i, val) {
          if (val != undefined) {
            programParts = val.split('--');
            title = programParts[1];
            programParts[1] = programParts[1].replace('(', ' ' ).replace(')', ' ' );
            if ($('#' + programParts[0]).length == 0 && $('.compare-item').length < 4) {
              if ($('#' + programParts[0]).length == 0) {
                program_title = "<div id='" + programParts[0] + "' class='compare-item '>" + "<span class='remove-item'>x</span><div class='compare-program-title'>" + title + "</div></div>";
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
              $(this).prop("disabled", true);
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

        $(".remove-item").on('click', function() {
          Drupal.removeItemHandler.removeItem(this);
        });

        //reset to initial position
        $(window).scrollTop($(this).offset().top - yPos);
      });

      $checked = $('.programs input:checkbox').filter(':checked').length;
      var $checkboxes = $('.programs input:checkbox');
      if ($checked >= 3){
        $checkboxes.each(function () {
          if (!(this.checked)) {
            $(this).attr("disabled", "disabled");
            $(this).prop("disabled", true);
            $(this).parent().addClass("inactive");
          }
        });
      }

      $(".remove-item").on('click', function() {
        Drupal.removeItemHandler.removeItem(this);
      });

      $('#js-submit').click(function () {
        ids = '';
        $( ".compare-button").parent().siblings().each(function () {
          (ids == '') ? ids = $(this).attr('id') : ids += '+' + $(this).attr('id');
        });

        if(($(location).attr('pathname')).indexOf('exec-ed') !== -1 ) {
          path = "/exec-ed/programs/compare/";
        }
        else {
          path = "/programs/compare/";
        }
        function pad(n){return n<10 ? '0'+n : n.toString()}
        var filters = {};
        if ($('a.filter-exit').length >0) {
          $('a.filter-exit').each(function () {
            var $filter = $(this);
            if ($filter.data('item-type') == "checkbox") {
              var key = $filter.data('item-key');
              var filterID = $filter.data('filter-id');
              filters[filterID] = filters[filterID] || [];
              filters[filterID].push(key);
            } else if ($filter.data('item-type') == "daterange") {

              var daterange = ($filter.closest(".filter-button").find(".term").text()).split("-");

              start_date = new Date(daterange[0]);
              filters['date-range-from'] = [];
              filters['date-range-from'].push(start_date.getFullYear() + pad(start_date.getMonth() + 1) + pad(start_date.getDate()));

              filters['date-range-to'] = [];
              end_date = new Date(daterange[1]);
              filters['date-range-to'].push(end_date.getFullYear() + pad(end_date.getMonth() + 1) + pad(end_date.getDate()));
            }
          });

          //// Add search term
          term = $("#edit-filters").find('[name=search]').val();
          //if (term) {
          if (term) {
            filters['search'] = [];
            filters['search'].push(term);
          }
          link = "";
          for (var filterID in filters) {
            link += filterID + '=';

            for (var key in filters[filterID]) {
              link += filters[filterID][key];
              if (key != filters[filterID].length - 1) {
                link += ',';
              }
            }

            link += '&';
          }
          link = "?" + link.substring(0, link.length - 1);
          window.history.pushState(null, null, link);
        }
        $(location).attr('href', document.location.origin + path + ids);
      });

      Drupal.removeItemHandler = Drupal.removeItemHandler || {};

      Drupal.removeItemHandler.removeItem = function (item) {
        item_id = $(item).parent().attr("id");
        term = ($(item).parent().text().trim()).slice(0,2);
        checkbox_id  = item_id + '--' + term;
        $(item).parent().remove();
        $("input[name=" +  item_id + '-item' + "]").attr('checked', false);
        $("#" + item_id + "-label").text("Compare");
        if ($('.compare-item').length == 0) {
          $('.compare-items').hide();
          $("#sticker-sticky-wrapper").hide();
          $("#sticker").hide();
        }
        ($('.compare-item').length > 1) ? $('.compare-button').show() : $('.compare-button').hide();
        $("input[name=" +  item_id + '-item' + "]").change();
      }

    }
  };
})(jQuery);
