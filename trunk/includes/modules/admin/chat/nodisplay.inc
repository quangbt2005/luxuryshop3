<?php
/**************************************************************************************************/
/* Created on Dec 4, 2008                                                                         */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "DB.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
if(! Check_Admin_Ajax()) exit;

$chatid = $Request['parameters'][':chatid'];

if(!empty($chatid)){
  $ChatID = explode('_', $chatid);

  $query = "UPDATE chat SET isdisplay='0' WHERE id IN(" . implode(',', $ChatID) . ')';
  P_MySQL_Real_Exec($query);
}
?>