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
$errors = array();
$category_id = $Request['parameters'][':catid'];
$parent_id = 0;
$category = Find_Category_By_ID($category_id);

if(!$category)
{
  $errors[] = 'Không tìm thấy danh mục';
} else {
  if($_SERVER['REQUEST_METHOD'] == 'POST'){
    $category_parent = $_POST['drpProductCategory'];
    $category_name   = $_POST['txtCategoryName'];
    $parent_id       = $_POST['drpProductCategory'];
    $category_sortorder   = $_POST['txtSortOrder'];

    if(empty($category_name)) $errors[] = 'Vui lòng nhập tên danh mục';

    if(count($errors) <= 0){
      DB_Update('categories',array('categories_id' => $category_id),array(
        'parent_id'  => $category_parent,
        'sort_order' => $category_sortorder,
        'date_added' => date('Y-m-d H:i:s'),
      ));
      DB_Update('categories_description',array('categories_id' => $category_id),array(
          'categories_name' => $category_name
        ));

      $_SESSION['flash']['edit_category_ok']   = '1';
      $_SESSION['flash']['new_category_name']  = $category_name;
      $_SESSION['flash']['new_parent_id']      = $parent_id;
      $_SESSION['flash']['old_parent_id']      = $category['parent_id'];
      header("Location: /admin/categories/edit/" . $category_id);
      exit;
    }
  } else {
    $parent_id = $category['parent_id'];
    if($_SESSION['flash']['edit_category_ok'] == '1'){
      $smarty->assign('edit_category_ok', '1');
      $smarty->assign('new_category_name', $_SESSION['flash']['new_category_name']);
      $smarty->assign('new_parent_id', $_SESSION['flash']['new_parent_id']);
      $smarty->assign('old_parent_id', $_SESSION['flash']['old_parent_id']);
      unset($_SESSION['flash']['edit_category_ok']);
      unset($_SESSION['flash']['new_category_name']);
      unset($_SESSION['flash']['new_parent_id']);
      unset($_SESSION['flash']['old_parent_id']);
    }
    $smarty->assign('category_name', $category['categories_name']);
    $smarty->assign('category_sortorder', $category['sort_order']);
  }
}
$html_select_categories = create_html_select_categories($parent_id);
$smarty->assign('errors_count', count($errors));
$smarty->assign('errors', $errors);
$smarty->assign('html_select_categories', $html_select_categories);

$center_col = $smarty->fetch( "admin/categories/editcategory.tpl" );
?>
