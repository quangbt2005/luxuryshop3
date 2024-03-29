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
  reset($Tree);
  $pointer = $Tree;
  $stack   = array();
  $html = "<ul>\n";

  while(!empty($pointer)){
  	if(is_array($pointer)){
      $break = false;
      do{
        $cat = current($pointer);

        if(!empty($cat)){
          $html .= sprintf("<li class=\"%s\"><a href=\"/sanpham/danhsach/%s\">%s</a>%s\n", (isset($cat['childs']) ? 'parent' : 'child'), $cat['categories_id'], $cat['categories_name'], (isset($cat['childs']) ? '' : '</li>'));
          if(isset($cat['childs'])){
            if(next($pointer)) $stack[] = $pointer; else $stack[] = '</ul>';
            $stack[] = $cat['childs'];
            $html .= "<ul>\n";
            $break = true;
            break;
          }
        }
      } while (next($pointer));
      if(!(current($pointer)) && !$break) {
      	if(count($stack) > 0){
      		$html .= "</ul></li>\n";
      	} else {
      		$html .= "</ul>\n";
      	}
      }
      $pointer = array_pop($stack);
    } else {
      $html .= "</ul>\n";
      $pointer = array_pop($stack);
    }
  }

  return $html;
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
?>
