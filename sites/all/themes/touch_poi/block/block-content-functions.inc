<?php


/**
 * Content for the Forum footer navigation block. 
 * Block defined in the malmo_forum module
 */
function touch_poi_footer_nav() {
	global $user;
	
	// Initialize columns
	$column1 = array( 'todo' => l("TODO", "") );
	$column2 = array( 'todo' => l("TODO", "") );
	$column3 = array( 'todo' => l("TODO", ""));

	// Serialize columns
	$column1 = implode( "", $column1 );
	$column2 = implode( "", $column2 );
	$column3 = implode( "", $column3 );

	return "
		<nav>
	    <ul class='list-1'>
	      $column1
	    </ul>
	    <ul class='list-2'>
	      $column2
	    </ul>
	    <ul class='list-3'>
	      $column3
	    </ul>
	  </nav>";
}