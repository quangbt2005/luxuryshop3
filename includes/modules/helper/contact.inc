<?php
/**************************************************************************************************/
/* Created on May 30, 2010                                                                        */
/**************************************************************************************************/
require_once( LIB_PATH . "P_Mail/P_Mail_Check_Function.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
if($_SERVER['REQUEST_METHOD'] == 'POST'){
  $errs = array();

  $name       = trim($_POST['txtName']);
  $email      = trim($_POST['txtEmail']);
  $content    = trim($_POST['txtContent']);
  $code       = $_POST['txtCode'];

  if(strlen($name) <= 0) $errs[] = 'Vui lòng nhập họ và tên khách hàng.';
  if(strlen($email) <= 0) $errs[] = 'Vui lòng nhập địa chỉ email.';
  if(strlen($email)>0)
    if(!P_Mail_Check($email)) $errs[] = 'Địa chỉ email không hợp lệ.';
  if(strlen($content) <= 0) $errs[] = 'Vui lòng nhập nội dung liên hệ.';

  if(count($errs)<=0)
    if(strtolower($code) != strtolower($_SESSION['contact']['seccode']))
      $errs[] = 'Mã an toàn không đúng.';

  unset($_SESSION['contact']['seccode']);

  if(count($errs)<=0)
  {
    $subject = 'Thông tin liên hệ từ ' . $name . '[' . $email . ']';
    $content = htmlentities($content);
    mailSMTP(STORE_NAME . ' Webmaster', ADMIN_EMAIL, SUPPORT_EMAIL, NULL, NULL, $subject, $content);

    header('Location: /lienhe/thanhcong');
    exit;
  }

  $smarty->assign( "error_count", count($errs) );
  $smarty->assign( "errs", $errs );
}
$center_col = $smarty->fetch( "helper/contact.tpl" );
?>