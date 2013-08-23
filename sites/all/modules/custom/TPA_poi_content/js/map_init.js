/**
 * Drupal behavior to initiate Malmö stad map
 */
(function ($) {
  Drupal.behaviors.mapInit = {
    attach: function(context, settings) {
      var _maploaded = false;
      console.log($(document));
      //$(document).bind("pagechange", function() { 
        console.log( "in pagechange");
        if (!_maploaded) {  
          console.log( "in map not loaded");
          var mainInst = LS.Main;
          mainInst.init();
          _maploaded = true;
        }
        
        $("#ev-btn-submit").on("click", function(event){
          var lonLat = LS.map.getCenter();
          alert(lonLat);
        });
      //});
    }
  }
})(jQuery);