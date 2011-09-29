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
$category_id = $Request['parameters'][':parentid'];
$errors = array();

if($_SERVER['REQUEST_METHOD'] == 'POST'){
  $category_id          = $_POST['drpProductCategory'];

  $category_parent      = $_POST['drpProductCategory'];
  $category_name        = $_POST['txtCategoryName'];
  $category_sortorder   = $_POST['txtSortOrder'];

  if(empty($category_name)) $errors[] = 'Vui lòng nhập tên danh mục';

  if(count($errors) <= 0){
    $id = DB_Insert('categories',array(
      'parent_id'  => $category_parent,
      'sort_order' => $category_sortorder,
      'date_added' => date('Y-m-d H:i:s'),
    ));
    if(!empty($id)){
      DB_Insert('categories_description',array(
        'categories_id'        => $id,
        'language_id'          => '1',
        'categories_name'      => $category_name
      ));
    }

    $_SESSION['flash']['insert_category_ok']     = '1';
    $_SESSION['flash']['new_category_id']        = $id;
    $_SESSION['flash']['new_category_name']      = $category_name;
    $_SESSION['flash']['new_category_parent_id'] = $category_parent;
    header("Location: /admin/categories/add/" . $Request['parameters'][':parentid']);
    exit;
  }
} else {
  if($_SESSION['flash']['insert_category_ok'] == '1'){
    $smarty->assign('insert_category_ok', '1');
    $smarty->assign('new_category_id', $_SESSION['flash']['new_category_id']);
    $smarty->assign('new_category_name', $_SESSION['flash']['new_category_name']);
    $smarty->assign('parent_id', $_SESSION['flash']['new_category_parent_id']);
    unset($_SESSION['flash']['insert_category_ok']);
    unset($_SESSION['flash']['new_category_id']);
    unset($_SESSION['flash']['new_category_name']);
    unset($_SESSION['flash']['new_category_parent_id']);
  }
}

$html_select_categories = create_html_select_categories($category_id);
$smarty->assign('showing_category', $Request['parameters'][':catid']);
$smarty->assign('errors_count', count($errors));
$smarty->assign('errors', $errors);
$smarty->assign('html_select_categories', $html_select_categories);

$center_col = $smarty->fetch( "admin/categories/addcategory.tpl" );
?>
