<?php
/**************************************************************************************************/
/* Created on July 2, 2010                                                                        */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "categories/categories_db.inc" );
require_once( FUNCTIONS_PATH . "categories/create_html_select_categories.inc" );
require_once( FUNCTIONS_PATH . "DB.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
Check_Admin();
$category_id = $Request['parameters'][':catid'];
$errors = array();

if($_SERVER['REQUEST_METHOD'] == 'POST'){
  $category_id         = $_POST['drpProductCategory'];

  $product_category    = $_POST['drpProductCategory'];
  $product_price       = $_POST['txtProductPrice'];
  $product_name        = $_POST['txtProductName'];
  $product_intro       = $_POST['txtProductIntro'];
  $product_description = $_POST['txtProductDescription'];
  // $product_quantity    = $_POST['txtProductQuantity'];
  $product_image       = $_POST['txtProductImage'];

  if(get_magic_quotes_gpc() == 1) $product_description = stripslashes($product_description);

  if(empty($product_name)) $errors[] = 'Vui lòng nhập tên sản phẩm';
  if(empty($product_price)) $errors[] = 'Vui lòng nhập giá sản phẩm';
  if(!empty($product_quantity) && !Positive_Int_Check($product_quantity))
    $errors[] = 'Số lượng sản phẩm không hợp lệ';

  if(count($errors) <= 0){
    $product_id = DB_Insert('products',array(
      // 'products_quantity'    => $product_quantity,
      'products_price'       => $product_price,
      'products_image'       => $product_image,
      'products_date_added'  => date('Y-m-d H:i:s'),
    ));
    if(!empty($product_id)){
      DB_Insert('products_description',array(
        'products_id'          => $product_id,
        'language_id'          => '1',
        'products_name'        => $product_name,
        'products_intro'       => $product_intro,
        'products_description' => $product_description,
      ));
      DB_Insert('products_to_categories',array(
        'products_id'          => $product_id,
        'categories_id'        => $product_category,
      ));
    }

    $_SESSION['flash']['insert_product_ok'] = '1';
    header("Location: /admin/products/add/" . $Request['parameters'][':catid']);
    exit;
  }
} else {
  if($_SESSION['flash']['insert_product_ok'] == '1'){
    $smarty->assign('insert_product_ok', '1');
    unset($_SESSION['flash']['insert_product_ok']);
  }
}

$html_select_categories = create_html_select_categories($category_id);
$smarty->assign('showing_category', $Request['parameters'][':catid']);
$smarty->assign('errors_count', count($errors));
$smarty->assign('errors', $errors);
$smarty->assign('html_select_categories', $html_select_categories);

$center_col = $smarty->fetch( "admin/products/addproduct.tpl" );
?>
