<?php
/**************************************************************************************************/
/* Created on May 27, 2010                                                                        */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "bankaccounts/bankaccounts_db.inc" );
// ---------------------------------------------------------------------------------------------- //
$BankList = ListBankAccountForFrontSite();
//pd($BankList);
$smarty->assign('BankList', $BankList);
$right_col = $smarty->fetch( "rightmenu/menu1.tpl" );
?>
