<?php
/**************************************************************************************************/
/* Created on May 30, 2010                                                                        */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "DB.inc" );
require_once( FUNCTIONS_PATH . "bankaccounts/bankaccounts_db.inc" );
// ---------------------------------------------------------------------------------------------- //
Check_Admin();
$BankList = ListBankAccountForAdmin();

if($_SERVER['REQUEST_METHOD'] == 'POST'){
//pd($_POST);
  DB_Update('configuration', array('configuration_key' => 'STORE_ADDRESS'),
                             array('configuration_value' => P_SQL_Quote($_POST['txtAddress'])));
  DB_Update('configuration', array('configuration_key' => 'STORE_EMAIL'),
                             array('configuration_value' => P_SQL_Quote($_POST['txtEmail1'])));
  DB_Update('configuration', array('configuration_key' => 'PHONE_1'),
                             array('configuration_value' => P_SQL_Quote($_POST['txtPhone1'])));
  DB_Update('configuration', array('configuration_key' => 'PHONE_2'),
                             array('configuration_value' => P_SQL_Quote($_POST['txtPhone2'])));

  $service = $_POST['txtService'];
  if(get_magic_quotes_gpc() == 1) $service = stripslashes($service);
  DB_Update('configuration', array('configuration_key' => 'SERVICE'),
                             array('configuration_value' => $service));

  $topMarquee = $_POST['txtTopMarquee'];
  if(get_magic_quotes_gpc() == 1) $topMarquee = stripslashes($topMarquee);
// pd($topMarquee);
  DB_Update('configuration', array('configuration_key' => 'TOP_MARQUEE'),
                             array('configuration_value' => $topMarquee));

  $_SESSION['flash']['update_configuration_ok'] = '1';
  header("Location: /admin/shop/config/" . $category_id);
} else {
  if($_SESSION['flash']['update_configuration_ok'] == '1'){
    $smarty->assign('update_configuration_ok', '1');
    unset($_SESSION['flash']['update_configuration_ok']);
  }
}
$center_col = $smarty->fetch( "admin/shop/configuration.tpl" );
?>
