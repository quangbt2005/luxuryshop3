<?php
/**************************************************************************************************/
/* Created on July 2, 2010                                                                        */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "categories/categories_db.inc" );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function BuildCategoryTree()
{
  $overflow = false;

  $Tree = array();
  $List = List_All_Category();
  $ID_List = array();

  for($i=0;$i<count($List);$i++){
    $Tree[$List[$i]['categories_id']] = &$List[$i];
    $ID_List[] = $List[$i]['categories_id'];
  }

  for($i=0;$i<count($ID_List);$i++){
    $id = $ID_List[$i];
    $parent_of_id = $Tree[$id]['parent_id'];
    if(!empty($parent_of_id)){
      $Tree[$parent_of_id]['childs'][] = &$Tree[$id];
    }
  }

  for($i=0;$i<count($ID_List);$i++){
    $id = $ID_List[$i];
    $parent_of_id = $Tree[$id]['parent_id'];
    if(!empty($parent_of_id)){
      unset($Tree[$id]);
    }
  }
// pd($Tree);
  // reset($Tree);
  // $pointer = $Tree;
  // $stack   = array();
  $html = "<div class=\"arrowsidemenu\">\n";
  $no = 0;
  $cat_count = count($Tree) - 1;

  $margin_div = "";
  $margin_ul  = "";

  foreach($Tree as $cat){
    if($no == 0){
      $margin_div = "style=\"margin-top: 10px;\"";
      $margin_ul = "style=\"margin-bottom: 40px;\"";
    } elseif($no == $cat_count){
      $margin_div = "";
      $margin_ul = "style=\"margin-bottom: 200px;\"";
      // $margin_ul = "";
    } else {
      $margin_div = "";
      $margin_ul = "style=\"margin-bottom: 40px;\"";
    }

    if(isset($cat['childs'])){
      $html .= sprintf("<div class=\"expandablelevel1\" %s><a href=\"/sanpham/danhsach/%s\">%s</a></div>\n<ul class=\"menucontentslevel1\" %s>\n", $margin_div, $cat['categories_id'], $cat['categories_name'], $margin_ul);
      $childs = $cat['childs'];
      foreach($childs as $child_cat){
        if(isset($child_cat['childs'])){
          $html .= sprintf("<li><a class=\"expandablelevel2\" href=\"/sanpham/danhsach/%s\">%s</a>\n<ul class=\"menucontentslevel2\">", $child_cat['categories_id'], $child_cat['categories_name']);
          $child_childs = $child_cat['childs'];
          foreach($child_childs as $child_child){
            $html .= sprintf("<li><a href=\"/sanpham/danhsach/%s\">%s</a></li>\n", $child_child['categories_id'], $child_child['categories_name']);
          }
          $html .= '</ul></li>';
        } else {
          $html .= sprintf("<li><a href=\"/sanpham/danhsach/%s\">%s</a></li>\n", $child_cat['categories_id'], $child_cat['categories_name']);
        }
      }
      $html .= "</ul>";
    } else {
      $html .= sprintf("<div><a href=\"/sanpham/danhsach/%s\">%s</a></div>\n", $cat['categories_id'], $cat['categories_name']);
    }
    $no++;
  }
  $html .= '</div>';
  return $html;
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
?>
