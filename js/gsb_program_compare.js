(function ($) {
  Drupal.behaviors.gsb_feature_program_finder = {
    attach: function (context, settings) {

      // gets the row parent for an expandMark
      var getRowParent = function(expandMark) {
        return $(expandMark).parent('.field-content').parent('.views-field-title').parent('.views-row');
      };

      // checks if a row is collapsed
      var isCollapsedRow = function(row) {
        var classNames = row.attr('class');
        if (classNames.indexOf('collapsed-row') != -1) {
          return true;
        }
        return false;
      };

      // collapses a row
      var collapseRow = function(row) {
        row.removeClass('expanded-row');
        row.addClass('collapsed-row');
        row.children().each(function(){
          var classValues = $(this).attr('class');
          if (classValues.indexOf('views-field-title') == -1) {
            $(this).hide();
          }
        });
      };

      // expands a row
      var expandRow = function(row) {
        row.removeClass('collapsed-row');
        row.addClass('expanded-row');
        row.children().each(function(){
          var classValues = $(this).attr('class');
          if (classValues.indexOf('views-field-title') == -1) {
            $(this).show();
          }
        });
      };

      var collapseAllRows = function() {
        $('.fieldset-expand-mark').each(function () {
          var row = getRowParent($(this));
          collapseRow(row);
        });
      };

      // if there are expand/collapse markers
      // then initially:
      //   - collapse all the rows
      //   - expand the first row
      //   - setup click handling to enable expand/collapse
      //     toggling of rows
      if ($('.fieldset-expand-mark').length > 1) {

        // first collapse all the rows
        collapseAllRows();

        // then... expand the first row
        $('.fieldset-expand-mark').first().each(function () {
          var row = getRowParent($(this));
          expandRow(row);
        });

        $('.fieldset-expand-mark').click(function (e) {
          e.preventDefault();
          var row = getRowParent($(this));
          if (isCollapsedRow(row)) {
            var yPos = row.offset().top - $(window).scrollTop();
            collapseAllRows();
            expandRow(row);
            $(window).scrollTop(row.offset().top - yPos);
          }
        });

        $(".views-field-field-brochure-pdf #apower-pdf").each(function() {
            $(this).siblings().hide();
        });

        // remove the pipe if found at the end for application deadlines
        $(".field-collection-item-field-application-deadlines").each(function(){
          var text = $(this).text();
          if (text.substr(-1) === '|') {
            $(this).text($(this).text().replace('|',''));
          }
        });
      }

      if (document.referrer.indexOf("/program") == -1) {
        $(".back-to-programs a").attr("href", "/exec-ed/programs")
      }
    }
  };
})(jQuery);
