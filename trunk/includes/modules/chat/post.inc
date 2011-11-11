<?php
/**************************************************************************************************/
/* Created on May 30, 2010                                                                        */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "DB.inc" );
require_once( FUNCTIONS_PATH . "chat/chat_db.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$page = $Request['parameters'][':page'];
if($_SERVER['REQUEST_METHOD'] == 'POST'){
  $maxAvatarSize = 1024*30;
  $validAvatarType = array('png','bmp','gif','jpg');

  $errs = array();

  $chatter_name = $_POST['txtChatter'];
  $code         = $_POST['txtCode'];

  if(!empty($_FILES['txtAvatar']['name'])){
    $avatarSize = $_FILES['txtAvatar']['size'];
    $avatarName = date('YmdHis') . $_FILES['txtAvatar']['name'];
    $ext = substr($avatarName, strrpos($avatarName, '.') + 1);
    $ext = strtolower($ext);

    if($avatarSize > $maxAvatarSize) $errs[] = 'Kích thước avatar lớn hơn 30KB.';
    if(!in_array($ext, $validAvatarType)) $errs[] = 'Loại file avatar không được chấp nhận.';
  }

  if(!empty($code)){
    $code = md5(md5($code));
    $chatter_code = CountCustomerByCustomerCode($code);
  } else {
    $chatter_code = 0;
  }

  if($chatter_code <= 0) $errs[] = 'Mã khách hàng không đúng.';

  if(count($errs)<=0)
  {
    $content = $_POST['ckChat'];
    $chatter = htmlentities($_POST['txtChatter']);
    $chatter = $chatter == '' ? 'Guest' : $chatter;

    DB_Insert('chat', array(
      'chatter'      => $chatter_name,
      'chatter_code' => $chatter_code,
      'avatar'       => $avatarName,
      'content'      => $content,
      'createddate'  => date('Y-m-d H:i:s')
    ));

    if(!empty($avatarName)){
      $avatarSavePath = SYS_IMAGES_PATH . 'avatars/' . $avatarName;
      move_uploaded_file($_FILES['txtAvatar']['tmp_name'], $avatarSavePath);
    }
    header("Location: /feedback/1/list");
  } else {
    $_SESSION['flash']['post_chat_error'] = $errs;
    header("Location: /feedback/$page/list");
  }
}
?>