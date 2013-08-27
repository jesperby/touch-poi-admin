/**
 * Drupal behavior for handling iframed Malmö Stad map
 */
(function ($) {
  Drupal.behaviors.mapHandler = {

    /* 
     * Function mapData()
     * Function called from within iframed map, when user clicks submit
     */
    mapData: function(data) {
      // Set lat lon of chosen position
      var lat = data.north;
      var lon = data.east;

      $('#edit-field-latitude-und-0-value').val(lat);
      $('#edit-field-longitude-und-0-value').val(lon);

      // Find nearest adress on openstreetmap
      $.ajax({
        type: 'GET',
        url: 'http://nominatim.openstreetmap.org/reverse?format=json&lat='+lat+'&lon='+lon+'&zoom=18&email=kominteamet@malmo.se',
        dataType: 'json',
        success: function(json) {
          // Update address field
          var road = json['address']['road'];   // Ex: Drottninggatan
          var house_number = json['address']['house_number'];  // Ex: 17 
          var address = '';
          
          if( typeof road != 'undefined' ) {
            address += road;
            if( typeof house_number != 'undefined' ) {
              address += ' ' + house_number;
            }
          }

          $('#edit-field-adress-und-0-value').val(address);
        },
        error: function (request, status, error) {
          console.log( 'request: ', request );
          console.log( 'status: ', status );
          console.log( 'error: ', error );
        }
      });

      // Reload map with marker on chosen position
      var map_coords = data.east + "," + data.north;
      //console.log(this.getBaseUrl());
      $('#map_iframe').attr('src', 'http://' + this.getBaseUrl() + '/malmostad_map/index.html?config=eurov.js&xy=' + map_coords);
    },
    

    /* 
     * Function map_loaded()
     * Called after iframe containing map has been loaded
     */
    map_loaded: function () {
    },
    

    /* 
     * Function attach()
     */
    attach: function(context, settings) {
    },

    // Returns base + first directory, ex www.domain.com/directory
    getBaseUrl: function() {
      try {
        var url = location.href;

        var start = url.indexOf('//');
        if (start < 0)
            start = 0 
        else 
            start = start + 2;

        var firstSlash = url.indexOf('/', start);
        var end = url.indexOf('/', firstSlash+1);

        if (end < 0) end = url.length - start;

        var baseURL = url.substring(start, end);
        return baseURL;
      }
      catch (arg) {
          return null;
      }
    }
  }
})(jQuery);