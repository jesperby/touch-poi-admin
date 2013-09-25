<?php

/**
 * Implementation of hook_form_element_label
 */

function TPA_malmo_assets_form_element_label($vars) {
	
	$id = $vars['element']['#id'];

	// The season/date time labels
	switch ($id) {
    case 'edit-field-spring-start-month-und':
      $vars['element']['#title'] = 'Från:'; 
      break;
    case 'edit-field-spring-end-month-und':
      $vars['element']['#title'] = 'Till:'; 
      break;
    case 'edit-field-spring-start-day-und':
      $vars['element']['#title'] = ''; 
      break;
    case 'edit-field-spring-end-day-und':
      $vars['element']['#title'] = ''; 
      break;
    case 'edit-field-spring-start-hour-und':
      $vars['element']['#title'] = 'Från:'; 
      break;
    case 'edit-field-spring-end-hour-und':
      $vars['element']['#title'] = 'Till:'; 
      break;
    case 'edit-field-spring-start-minute-und':
      $vars['element']['#title'] = ''; 
      break;
    case 'edit-field-spring-end-minute-und':
      $vars['element']['#title'] = ''; 
      break;
    case 'edit-field-autumn-start-month-und':
      $vars['element']['#title'] = 'Från:'; 
      break;
    case 'edit-field-autumn-end-month-und':
      $vars['element']['#title'] = 'Till:'; 
      break;
    case 'edit-field-autumn-start-day-und':
      $vars['element']['#title'] = ''; 
      break;
    case 'edit-field-autumn-end-day-und':
      $vars['element']['#title'] = ''; 
      break;
    case 'edit-field-autumn-start-hour-und':
      $vars['element']['#title'] = 'Från:'; 
      break;
    case 'edit-field-autumn-end-hour-und':
      $vars['element']['#title'] = 'Till:'; 
      break;
    case 'edit-field-autumn-start-minute-und':
      $vars['element']['#title'] = ''; 
      break;
    case 'edit-field-autumn-end-minute-und':
      $vars['element']['#title'] = ''; 
      break;
	}

	return theme_form_element_label( $vars );
}