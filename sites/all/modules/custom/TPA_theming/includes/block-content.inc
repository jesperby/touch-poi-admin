<?php


/**
 * Content for the TPA footer navigation block. 
 */
function TPA_theming_footer_nav() {
	global $user;
	
	// Initialize columns
	$column1 = array( 'login' => '');
	//$column2 = array( 'todo' => l("TODO", "") );
	//$column3 = array( 'todo' => l("TODO", ""));

	// Login
	if( user_is_logged_in() ) {
		$column1['login'] = "<li>" . l( t("Logout"), 'user/logout' ) . "</li>";
	} else {
		$column1['login'] = "<li>" . l( t("Login"), 'user/login' ) . "</li>";
	}

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