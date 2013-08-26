/**
 * Drupal behavior for handling iframed Malmö Stad map
 */
(function ($) {
  Drupal.behaviors.mapInit = {
    mapData: function(data) {
      $('#edit-field-latitude-und-0-value').val(data.north);
      $('#edit-field-longitude-und-0-value').val(data.east);

      // Reload map with marker on chosen position
      var map_coords = data.east + "," + data.north;
      $('#map_iframe').attr('src', 'http://localhost/msmap/index.html?config=eurov.js&&xy=' + map_coords);
    },
    
    map_loaded: function () {
    },
    
    attach: function(context, settings) {
    }
  }
})(jQuery);