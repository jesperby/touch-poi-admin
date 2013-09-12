/**
 * Function to enable/disable fields in the poi add form, based on settings in selected subcategory
 */
(function ($) {
  Drupal.behaviors.disableFields = {
    attach: function(context, settings) {
      $( '#edit-field-subcategory-und' ).change( function() {
        var selected_subcategory_id = $( '#edit-field-subcategory-und' ).val();
        $.ajax({
          type: 'GET',
          url: Drupal.behaviors.TPA_poi_content_config.config['feed_url_poi_types'],
          dataType: 'xml',
          success: function(data) {
            processData(data, selected_subcategory_id);
          },
          error: function (request, status, error) {
            console.log( 'request: ', request );
            console.log( 'status: ', status );
            console.log( 'error: ', error );
          }
        });
      });

      function processData(data, selected_subcategory_id) {
        var selector = "pointType[id=" + selected_subcategory_id + "]";
        $(data).find(selector).each(function () {
          var $pointType = $(this);
          var picturesEnabled = $pointType.attr('picturesEnabled');
          var closableEnabled = $pointType.attr('closableEnabled');

          // Enable/disable poi input fields
          if( picturesEnabled === 'false') {
            $('#edit-field-poi-image-und-0-upload').attr('disabled','disabled');
          } else {
            $('#edit-field-poi-image-und-0-upload').attr('disabled','');
          }

          if( closableEnabled === 'false') {
            $('#edit-field-closed-und').attr('disabled','disabled');
          } else {
            $('#edit-field-closed-und').attr('disabled','');
          }
       });
      }
    },

    
  }
})(jQuery);