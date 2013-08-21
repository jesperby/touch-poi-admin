/**
 * Function to enable/disable fields in the poi add form, based on settings in selected subcategory
 */
(function ($) {
  Drupal.behaviors.disableFields = {
    attach: function(context, settings) {
      $( '#edit-field-subcategory-und' ).change(function() {
        var selected_subcategory_id = $( '#edit-field-subcategory-und' ).val();
        $.ajax({
          type: 'GET',
          url: 'http://www.local.malmo.se/feeds/?feed=poi-types',
          dataType: 'json',
          success: function(json) {
            // Get info from feed about selected subcategory
            var selected_subcategory_obj = $.grep(json, function(e){ return e.id == selected_subcategory_id; });
            var picturesEnabled = selected_subcategory_obj[0]['picturesEnabled'];
            var closableEnabled = selected_subcategory_obj[0]['closableEnabled'];
            
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
          },
          error: function (request, status, error) {
            console.log( 'request: ', request );
            console.log( 'status: ', status );
            console.log( 'error: ', error );
          }
        });
      });
    }
  }
})(jQuery);