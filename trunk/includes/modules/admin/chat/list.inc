<?php
/**************************************************************************************************/
/* Created on June 30, 2010                                                                       */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "chat/chat_db.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
Check_Admin();
// pd();
$List = ListChatForAdmin();

$ListWithIntro = array();
foreach($List as $chat){
  $intro = strip_tags($chat['content']);
  $intro = substr($intro, 0, 150);
  $intro .= ' ...';
  $chat['intro'] = $intro;
  $ListWithIntro[] = $chat;
}

$smarty->assign('Chat_List', $ListWithIntro);

$center_col = $smarty->fetch( "admin/chat/list.tpl" );
?>