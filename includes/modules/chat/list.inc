<?php
/**************************************************************************************************/
/* Created on Nov 30, 2008                                                                        */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "Paging.inc" );
require_once( FUNCTIONS_PATH . "chat/chat_db.inc" );

$current_page = $Request['parameters'][':page'];
// ---------------------------------------------------------------------------------------------- //
// Load products
// ---------------------------------------------------------------------------------------------- //
$limit         = 10;
$total_records = CountChatForFrontEnd();
$total_pages   = Compute_Total_Page( $total_records, $limit );
$current_page  = Validatize_Current_Page( $current_page, $total_pages );

$offset        = ($current_page - 1) * $limit;
$List          = ListChatForFrontEnd( $offset, $limit );
// ---------------------------------------------------------------------------------------------- //
// Paging
// ---------------------------------------------------------------------------------------------- //
$Paging_info["TOTAL_PAGE"]   = $total_pages;
$Paging_info["CURRENT_PAGE"] = $current_page;
$Paging_info["LIMIT"]        = $limit;
$Paging_info["URL"]          = "/chat/:page/list";

$pager = Paginate( $Paging_info );
$chat_count = count($List);

$smarty->assign( "chat_from", $offset + 1 );
$smarty->assign( "chat_to", $offset + $chat_count );
$smarty->assign( "chat_count", $chat_count );
$smarty->assign( "total_chat", $total_records );
$smarty->assign( "Chat_List", $List );
$smarty->assign( "pager", $pager );
if(($total_records % 10) == 0)
  $smarty->assign( "page", $current_page+1 );
else $smarty->assign( "page", $current_page );

if(isset($_SESSION['flash']['post_chat_error'])){
  $smarty->assign( 'error', $_SESSION['flash']['post_chat_error']);
  unset($_SESSION['flash']['post_chat_error']);
}

$center_col = $smarty->fetch( "chat/list.tpl" );
?>