<?php
/**************************************************************************************************/
/* Created on Dec 3, 2008                                                                         */
/**************************************************************************************************/
require_once( FUNCTIONS_PATH . "Paging.inc" );
require_once( FUNCTIONS_PATH . "products/products_db.inc" );
require_once( FUNCTIONS_PATH . "categories/categories_db.inc" );
// ---------------------------------------------------------------------------------------------- //
$current_page = $Request['parameters'][':page'];
// ---------------------------------------------------------------------------------------------- //
// Load products
// ---------------------------------------------------------------------------------------------- //
$limit         = 10;
$total_records = Count_ProductsTotal();
$total_pages   = Compute_Total_Page( $total_records, $limit );
$current_page  = Validatize_Current_Page( $current_page, $total_pages );

$offset        = ($current_page - 1) * $limit;
$NewProducts   = FindNewProducts( 0, $offset, $limit );
// ---------------------------------------------------------------------------------------------- //
// Paging
// ---------------------------------------------------------------------------------------------- //
$Paging_info["TOTAL_PAGE"]   = $total_pages;
$Paging_info["CURRENT_PAGE"] = $current_page;
$Paging_info["LIMIT"]        = $limit;
$Paging_info["URL"]          = "/home/:page";

$pager = Paginate( $Paging_info );

$list_pad = 0;
$product_count = count($NewProducts);

if($product_count <= 2) $list_pad = 2;
elseif($product_count <= 4) $list_pad = 4;
elseif($product_count <= 6) $list_pad = 6;
elseif($product_count <= 8) $list_pad = 8;
elseif($product_count <= 10) $list_pad = 10;
$List = array_pad($NewProducts, $list_pad, array('empty'=>'true'));

$smarty->assign( "product_from", $offset + 1 );
$smarty->assign( "product_to", $offset + $product_count );
$smarty->assign( "product_count", $product_count );
$smarty->assign( "total_products", $total_records );
$smarty->assign( "NewProducts", $NewProducts );
$smarty->assign( "pager", $pager );
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$center_col = $smarty->fetch( "home/index.tpl" );
?>
