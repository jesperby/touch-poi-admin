<?php

function TPA_malmo_assets_menu_link(array $variables) {
  if( $variables['element']['#theme'] == 'menu_link__main_menu') {
    $title = $variables['element']['#title'];
    $href = base_path() . $variables['element']['#href'];
    $output = "<a href='$href' class='assets_main_menu_link'>$title</a>";

    return $output;
  }
}