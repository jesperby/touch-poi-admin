<?php

function TPA_malmo_assets_links__system_main_menu($variables) {
  $html = "<div class='hej'>\n";
  $html .= "  <ul>\n";  
  foreach ($variables['links'] as $link) {
    $html .= "<li>".l($link['title'], $link['path'], $link)."</li>";
  }
  $html .= "  </ul>\n";
  $html .= "</div>\n";

  return $html;
}