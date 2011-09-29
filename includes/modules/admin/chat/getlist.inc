<?php
/**************************************************************************************************/
/* Created on June 30, 2010                                                                       */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "chat/chat_db.inc" );
// ---------------------------------------------------------------------------------------------- //
if(! Check_Admin_Ajax()) return;

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
$html = $smarty->fetch('admin/chat/getlist.tpl');
echo $html;
?>