<?php
/**************************************************************************************************/
/* Created on Dec 4, 2008                                                                         */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "DB.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
if(! Check_Admin_Ajax()) exit;

$cat_id = $Request['parameters'][':catid'];

if(!empty($cat_id)){
  $query = "DELETE FROM categories WHERE categories_id=" . $cat_id;
  P_MySQL_Real_Exec($query);
echo $query;
  $query = "DELETE FROM categories_description WHERE categories_id=" . $cat_id;
  P_MySQL_Real_Exec($query);
}
echo 'WHAT';
?>