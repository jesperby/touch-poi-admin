<?php

/**
 * Config functions and settings
 */

/**
 * Function to check if we are in a local environment
 */
function TPA_malmo_assets_localenv( $assets_config ) {
  return ($_SERVER['HTTP_HOST'] == $assets_config['domainname_local'] ) ? true : false;
}

