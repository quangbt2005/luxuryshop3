<?php
/**************************************************************************************************/
/* Created on May 30, 2010                                                                        */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "DB.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$page = $Request['parameters'][':page'];
if($_SERVER['REQUEST_METHOD'] == 'POST'){
  $errs = array();

  if(strtolower($_POST['code']) != strtolower($_SESSION['chatting']['seccode']))
    $errs[] = 'Mã an toàn không đúng.';

  if(count($errs)<=0)
  {
    $content = $_POST['ckChat'];
    $chatter = htmlentities($_POST['txtChatter']);
    $chatter = $chatter == '' ? 'Guest' : $chatter;

    DB_Insert('chat', array(
      'chatter'     => $chatter,
      'content'     => $content,
      'createddate' => date('Y-m-d H:i:s')
    ));
  } else {
    $_SESSION['flash']['post_chat_error'] = 'Mã an toàn không đúng.';
  }
}
//p($_POST);
//pd($_SESSION);
unset($_SESSION['chatting']['seccode']);
header("Location: /chat/$page/list");
?>