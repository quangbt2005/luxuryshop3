<?php
/**************************************************************************************************/
/* Created on July 2, 2010                                                                        */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "categories/create_html_select_categories.inc" );
require_once( FUNCTIONS_PATH . "DB.inc" );
// ---------------------------------------------------------------------------------------------- //
if($_SERVER['REQUEST_METHOD'] == 'POST'){
  foreach($_POST as $clientName=>$postData){
    if(strpos($clientName, 'drpCell') !== FALSE){
      $cell = str_replace('drpCell', '', $clientName);
      DB_Update('special_cat', array('cell' => $cell), array('cat_id' => $postData));
    }
  }

  $_SESSION['flash']['edit_special_cat_ok'] = '1';
  header("Location: /admin/specialcat");
  exit;
} else {
  if($_SESSION['flash']['edit_special_cat_ok'] == '1'){
      $smarty->assign('edit_special_cat_ok', '1');
      unset($_SESSION['flash']['edit_special_cat_ok']);
  }
  $specialCategories = List_Special_Category();
  $select = array();
  foreach($specialCategories as $cat){
    $select[$cat['cell']] = create_html_select_categories($cat['cat_id'],
                                                          'drpCell' . $cat['cell'],
                                                          0);
  }
  // -------------------------------------------------------------------------------------------- //
  $smarty->assign('specialSelect', $select);
  // -------------------------------------------------------------------------------------------- //
  $center_col = $smarty->fetch( "admin/categories/specialcat.tpl" );
}
?>