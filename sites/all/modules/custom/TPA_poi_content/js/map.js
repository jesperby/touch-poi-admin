/**
 * Drupal behavior for handling Malmö Stad map data
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
      $('#map_iframe').attr('src', Drupal.behaviors.TPA_poi_content_config.config['malmostad_map_url'] + '&xy=' + map_coords);
    },


    /**
     * Function to attach address drop down to add poi form
     */
     poi_address_dropdown: function() {
      var that = this;
      var $address;
      $address = $("#edit-field-adress-und-0-value");
      if ($address.length) {
        $address.autocomplete({
          source: function(request, response) {
            return $.ajax({
              url: "//xyz.malmo.se/rest/1.0/addresses/",
              dataType: "jsonp",
              data: {
                q: request.term,
                items: 25
              },
              success: function(data) {
                return response($.map(data.addresses, function(item) {
                  return {
                    label: item.name + ", " + item.district,
                    value: item.name,
                    address: item.name,
                    post_code: item.postcode,
                    neighborhood: item.district,
                    postal_town: item.postal_town,
                    east: item.east,
                    north: item.north
                  };
                }));
              }
            });
          },
          minLength: 2,
          select: function(event, ui) {
            // Set address field with chosen address
            $('#user_address').val(ui.item.address);

            // Convert address coordinates to google maps coordinates
            var coords_espg_4326 = that.transform_epsg_3008_4326(ui.item.north, ui.item.east);
            
            // Reload map with marker on chosen address
            var map_coords = coords_espg_4326.lon + "," + coords_espg_4326.lat;
            $('#map_iframe').attr('src', Drupal.behaviors.TPA_poi_content_config.config['malmostad_map_url'] + '&xy=' + map_coords);
            
            // Set lat/lon fields of chosen address
            $('#edit-field-latitude-und-0-value').val(coords_espg_4326.lat);
            $('#edit-field-longitude-und-0-value').val(coords_espg_4326.lon);
          },
          open: function() {
            //return $(this).removeClass("ui-corner-all").addClass("ui-corner-top");
          },
          close: function() {
            //return $(this).removeClass("ui-corner-top").addClass("ui-corner-all");
          }
        });
        return $('#user_address').keydown(function(event) {
          if (event.which === 13) {
            return event.preventDefault();
          }
        });
      }
    },
    

    /**
     * Function to transform coordinates from EPSG:3008 to EPSG:4326
     */
    transform_epsg_3008_4326: function(lat, lon) {
      // Add espg definitions
      Proj4js.defs["EPSG:3008"] = "+proj=tmerc +lat_0=0 +lon_0=13.5 +k=1 +x_0=150000 +y_0=0 +ellps=GRS80 +towgs84=0,0,0,0,0,0,0 +units=m +no_defs";
      Proj4js.defs["EPSG:4326"] = "+proj=longlat +ellps=WGS84 +datum=WGS84 +no_defs";
      
      // creating source and destination Proj4js objects
      var source = new Proj4js.Proj('EPSG:3008');    //source coordinates will be in Longitude/Latitude
      var dest = new Proj4js.Proj('EPSG:4326');     

      // transforming point coordinates
      var p = new Proj4js.Point(lon, lat);   //any object will do as long as it has 'x' and 'y' properties
      Proj4js.transform(source, dest, p);      //do the transformation.  x and y are modified in place

      return {lon: p.x, lat: p.y};
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
      // Attach autocomplete to add poi address field
      this.poi_address_dropdown();
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