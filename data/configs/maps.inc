<?php
/**************************************************************************************************/
/* Created on Nov 30, 2008                                                                        */
/**************************************************************************************************/
// ---------------------------------------------------------------------------------------------- //
// ROUTE
// ---------------------------------------------------------------------------------------------- //
$Routes = array(
      "/home/:page"                        => array('module'=>'home',      'page'=>'default'),
      "/sanpham/danhsach/:catid/:page"     => array('module'=>'products',  'page'=>'list'),
      "/sanpham/danhsach/:catid"           => array('module'=>'products',  'page'=>'list'),
      "/sanpham/:productid/chitiet"        => array('module'=>'products',  'page'=>'detail'),
      "/lienhe"                            => array('module'=>'helper',    'page'=>'contact'),
      "/lienhe/thanhcong"                  => array('module'=>'helper',    'page'=>'contact_success'),
      "/dichvu"                            => array('module'=>'helper',    'page'=>'service'),
      "/timkiem"                           => array('module'=>'search',    'page'=>'search'),
      "/timkiem/:key"                      => array('module'=>'search',    'page'=>'search'),
      "/timkiem/:key/:page"                => array('module'=>'search',    'page'=>'search'),
      "/feedback"                          => array('module'=>'chat',      'page'=>'list'),
      "/feedback/:page/list"               => array('module'=>'chat',      'page'=>'list'),
      "/feedback/post/:page"               => array('module'=>'chat',      'page'=>'post'),
      // ADMIN ---------------------------------------------------------------------------------- //
      "/admin/login"                         => array('module'=>'admin',     'page'=>'login'),
      "/admin/home"                          => array('module'=>'admin',     'page'=>'home'),
      "/admin/categories"                    => array('module'=>'admin',     'page'=>'categories'),
      "/admin/categories/sub/:parentid"      => array('module'=>'admin',     'page'=>'getsubcategories'),
      "/admin/categories/add/:parentid"      => array('module'=>'adminpopup','page'=>'addcategory'),
      "/admin/categories/edit/:catid"        => array('module'=>'adminpopup','page'=>'editcategory'),
      "/admin/categories/:catid/products"    => array('module'=>'admin',     'page'=>'listproductsincategory'),
      "/admin/categories/:catid/move/:desid" => array('module'=>'admin',     'page'=>'movecategory'),
      "/admin/categories/:catid/delete"      => array('module'=>'admin',     'page'=>'deletecategory'),
      "/admin/categories/iconboard"          => array('module'=>'adminpopup','page'=>'iconboard'),
      "/admin/products/add/:catid"           => array('module'=>'adminpopup','page'=>'addproduct'),
      "/admin/products/delete/:productid/:catid" => array('module'=>'admin', 'page'=>'deleteproduct'),
      "/admin/products/edit/:productid"      => array('module'=>'adminpopup','page'=>'editproduct'),
      "/admin/products/saleoff/:productid"   => array('module'=>'adminpopup','page'=>'saleoffsetting'),
      "/admin/shop/config"                   => array('module'=>'admin',     'page'=>'shopconfig'),
      "/admin/:filename/uploadproductimage"  => array('module'=>'admin',     'page'=>'uploadproductimage'),
      "/admin/specialcat"                    => array('module'=>'admin',     'page'=>'specialcat'),
);
// ---------------------------------------------------------------------------------------------- //
// MODULES MAP
// ---------------------------------------------------------------------------------------------- //
$Module_Map = array(
      "home"        => array(
          "default"     => MODULES_PATH . "home/default.inc"
      ),
      "categories"  => array(
      ),
      "products"    => array(
          "list"           => MODULES_PATH . "products/list.inc",
          "detail"         => MODULES_PATH . "products/detail.inc",
          "random1saleoff" => MODULES_PATH . "products/random1saleoff.inc",
          "saleoff_list"   => MODULES_PATH . "products/saleoff_list.inc",
      ),
      "cart"        => array(
          "order"       => MODULES_PATH . "cart/order.inc",
          "view"        => MODULES_PATH . "cart/view.inc",
          "update"      => MODULES_PATH . "cart/update.inc",
          "checkout1"   => MODULES_PATH . "cart/checkout.inc",
          "checkout2"   => MODULES_PATH . "cart/checkout_confirmation.inc",
          "checkout3"   => MODULES_PATH . "cart/checkout_success.inc",
          "checkout4"   => MODULES_PATH . "cart/payment_gateways_return.inc",
      ),
      "account"    => array(
          "manage"           => MODULES_PATH . "account/manage.inc",
          "edit_info"        => MODULES_PATH . "account/edit_info.inc",
          "edit_pass"        => MODULES_PATH . "account/edit_pass.inc",
          "last_ordered"     => MODULES_PATH . "account/last_ordered.inc",
          "register"         => MODULES_PATH . "account/register.inc",
          "register_success" => MODULES_PATH . "account/register_success.inc",
      ),
      "logon"     => array(
          "login"       => MODULES_PATH . "logon/login.inc",
          "logout"      => MODULES_PATH . "logon/logout.inc",
          "resetpass"   => MODULES_PATH . "logon/resetpass.inc",
      ),
      "helper"    => array(
          "contact"         => MODULES_PATH . "helper/contact.inc",
          "buyinghelper"    => MODULES_PATH . "helper/buyinghelper.inc",
          "checkouthelper"  => MODULES_PATH . "helper/checkouthelper.inc",
          "contact_success" => MODULES_PATH . "helper/contact_success.inc",
          "service"         => MODULES_PATH . "helper/service.inc",
      ),
      "errors"      => array(
          "noproduct"   => MODULES_PATH . "errors/noproduct.inc",
          "nopage"      => MODULES_PATH . "errors/nopage.inc",
      ),
      "search"      => array(
          "search"      => MODULES_PATH . "search/search.inc",
      ),
      "news"        => array(
          "index"         => MODULES_PATH . "news/index.inc",
          "news_in_cat"   => MODULES_PATH . "news/news_in_cat.inc",
          "news_detail"   => MODULES_PATH . "news/news_detail.inc",
      ),
      "orders"      => array(
          "view"          => MODULES_PATH . "orders/view.inc",
      ),
      "admin"       => array(
          "dashboard"        => MODULES_PATH . "admin/home/home.inc",
          "login"            => MODULES_PATH . "admin/login/login.inc",
          "home"             => MODULES_PATH . "admin/home/home.inc",
          "categories"       => MODULES_PATH . "admin/categories/categories.inc",
          "getsubcategories" => MODULES_PATH . "admin/categories/getsubcategories.inc",
          "listproductsincategory" => MODULES_PATH . "admin/categories/listproductsincategory.inc",
          "deleteproduct"    => MODULES_PATH . "admin/products/deleteproduct.inc",
          "deletecategory"   => MODULES_PATH . "admin/categories/deletecategory.inc",
          "movecategory"     => MODULES_PATH . "admin/categories/movecategory.inc",
          "orderslist"       => MODULES_PATH . "admin/orders/list.inc",
          "ordersdelete"     => MODULES_PATH . "admin/orders/delete.inc",
          "getorderslist"    => MODULES_PATH . "admin/orders/getlist.inc",
          "shopconfig"       => MODULES_PATH . "admin/shop/configuration.inc",
          "uploadproductimage" => MODULES_PATH . "admin/products/upload_product_image.inc",
          "specialcat"       => MODULES_PATH . "admin/categories/specialcat.inc",
          "chatlist"         => MODULES_PATH . "admin/chat/list.inc",
          "chatdelete"       => MODULES_PATH . "admin/chat/delete.inc",
          "chatnodisplay"    => MODULES_PATH . "admin/chat/nodisplay.inc",
          "chatgetlist"      => MODULES_PATH . "admin/chat/getlist.inc",
          "chatdisplay"      => MODULES_PATH . "admin/chat/display.inc",
      ),
      "adminpopup"      => array(
          "addcategory"      => MODULES_PATH . "admin/categories/addcategory.inc",
          "editcategory"     => MODULES_PATH . "admin/categories/editcategory.inc",
          "addproduct"       => MODULES_PATH . "admin/products/addproduct.inc",
          "editproduct"      => MODULES_PATH . "admin/products/editproduct.inc",
          "orderdetail"      => MODULES_PATH . "admin/orders/detail.inc",
          "saleoffsetting"   => MODULES_PATH . "admin/products/saleoff_setting.inc",
          "iconboard"        => MODULES_PATH . "admin/categories/iconboard.inc",
      ),
      "chat"            => array(
          "list"             => MODULES_PATH . "chat/list.inc",
          "post"             => MODULES_PATH . "chat/post.inc",
      ),
      "test"            => array(
          "testupload"       => MODULES_PATH . "test/testupload.inc",
      ),
);
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
$Ajax_Map = array(
      "products"    => array(
          "random1saleoff",
      ),
      "admin"       => array(
          "getsubcategories",
          "listproductsincategory",
          "movecategory",
          "deleteproduct",
          "ordersdelete",
          "getorderslist",
          "deletecategory",
          "uploadproductimage",
          "chatdelete",
          "chatnodisplay",
          "chatgetlist",
          "chatdisplay"
      )
);
// ---------------------------------------------------------------------------------------------- //
// SESSION DATA USE IN MODULE
// ---------------------------------------------------------------------------------------------- //
$Session_Map = array(
      "require"                       => array( "cart" ),
      "cart"                          => array(
          "submit"      => array( "cart_token" ),
          "complete"    => array( "cart_token" ),
      )
);
// ---------------------------------------------------------------------------------------------- //
// LAYOUT FOR MODULE
// ---------------------------------------------------------------------------------------------- //
$Layout_Map = array(
      "home"        => "layouts/layout03.tpl",
      "cart"        => "layouts/layout03.tpl",
      "products"    => "layouts/layout03.tpl",
      "account"     => "layouts/layout03.tpl",
      "logon"       => "layouts/layout03.tpl",
      "helper"      => "layouts/layout03.tpl",
      "search"      => "layouts/layout03.tpl",
      "news"        => "layouts/layout03.tpl",
      "orders"      => "layouts/layout03.tpl",
      "admin"       => "admin/layouts/layout01.tpl",
      "adminpopup"  => "admin/layouts/popup.tpl",
      "test"        => "test/layouts/layout01.tpl"
);
// ---------------------------------------------------------------------------------------------- //
// LEFT MENU
// ---------------------------------------------------------------------------------------------- //
$Left_Menu_Map = array(
      "default"     => MODULES_PATH . "leftmenu/menu1.inc",
      "home"        => MODULES_PATH . "leftmenu/menu1.inc",
      "cart"        => MODULES_PATH . "leftmenu/menu1.inc",
      "products"    => MODULES_PATH . "leftmenu/menu1.inc",
      "account"     => MODULES_PATH . "leftmenu/menu1.inc",
      "logon"       => MODULES_PATH . "leftmenu/menu1.inc",
      "helper"      => MODULES_PATH . "leftmenu/menu1.inc",
      "search"      => MODULES_PATH . "leftmenu/menu1.inc",
      "orders"      => MODULES_PATH . "leftmenu/menu1.inc",
      "news"        => MODULES_PATH . "leftmenu/menu1.inc",
      "admin"       => MODULES_PATH . "admin/leftmenu/menu1.inc",
      "adminpopup"  => MODULES_PATH . "admin/leftmenu/menu1.inc",
      "test"        => MODULES_PATH . "test/menu/leftmenu1.inc",
);
// ---------------------------------------------------------------------------------------------- //
// RIGHT MENU
// ---------------------------------------------------------------------------------------------- //
$Right_Menu_Map = array(
      "default"     => MODULES_PATH . "rightmenu/menu1.inc",
      "home"        => MODULES_PATH . "rightmenu/menu1.inc",
      "cart"        => MODULES_PATH . "rightmenu/menu1.inc",
      "products"    => MODULES_PATH . "rightmenu/menu1.inc",
      "account"     => MODULES_PATH . "rightmenu/menu1.inc",
      "logon"       => MODULES_PATH . "rightmenu/menu1.inc",
      "helper"      => MODULES_PATH . "rightmenu/menu1.inc",
      "search"      => MODULES_PATH . "rightmenu/menu1.inc",
      "orders"      => MODULES_PATH . "rightmenu/menu1.inc",
      "news"        => MODULES_PATH . "rightmenu/menu1.inc",
      "admin"       => MODULES_PATH . "admin/rightmenu/menu1.inc",
      "adminpopup"  => MODULES_PATH . "admin/rightmenu/menu1.inc",
      "test"        => MODULES_PATH . "test/menu/rightmenu1.inc",
);
// ---------------------------------------------------------------------------------------------- //
// HEADER
// ---------------------------------------------------------------------------------------------- //
$Header_Map = array(
      "default"     => MODULES_PATH . "header/header1.inc",
      "home"        => MODULES_PATH . "header/header1.inc",
      "cart"        => MODULES_PATH . "header/header1.inc",
      "products"    => MODULES_PATH . "header/header1.inc",
      "account"     => MODULES_PATH . "header/header1.inc",
      "logon"       => MODULES_PATH . "header/header1.inc",
      "helper"      => MODULES_PATH . "header/header1.inc",
      "search"      => MODULES_PATH . "header/header1.inc",
      "news"        => MODULES_PATH . "header/header1.inc",
      "orders"      => MODULES_PATH . "header/header1.inc",
      "admin"       => MODULES_PATH . "admin/header/header1.inc",
      "adminpopup"  => MODULES_PATH . "admin/header/header1.inc",
      "test"        => MODULES_PATH . "test/menu/header1.inc",
);
// ---------------------------------------------------------------------------------------------- //
// FOOTER
// ---------------------------------------------------------------------------------------------- //
$Footer_Map = array(
      "default"     => MODULES_PATH . "footer/footer1.inc",
      "home"        => MODULES_PATH . "footer/footer1.inc",
      "cart"        => MODULES_PATH . "footer/footer1.inc",
      "products"    => MODULES_PATH . "footer/footer1.inc",
      "account"     => MODULES_PATH . "footer/footer1.inc",
      "logon"       => MODULES_PATH . "footer/footer1.inc",
      "helper"      => MODULES_PATH . "footer/footer1.inc",
      "search"      => MODULES_PATH . "footer/footer1.inc",
      "news"        => MODULES_PATH . "footer/footer1.inc",
      "orders"      => MODULES_PATH . "footer/footer1.inc",
      "admin"       => MODULES_PATH . "admin/footer/footer1.inc",
      "adminpopup"  => MODULES_PATH . "admin/footer/footer1.inc",
      "test"        => MODULES_PATH . "test/menu/footer1.inc",
);
// ---------------------------------------------------------------------------------------------- //
// TITLE
// ---------------------------------------------------------------------------------------------- //
$Title_Map = array(
      "default"     => "DONG HO DANG CAP - ĐỒNG HỒ ĐẲNG CẤP",
      "admin"       => "DONG HO DANG CAP - ĐỒNG HỒ ĐẲNG CẤP - Quan Tri",
      "adminpopup"  => "DONG HO DANG CAP - ĐỒNG HỒ ĐẲNG CẤP - Quan Tri",
      "test"        => "DONG HO DANG CAP - ĐỒNG HỒ ĐẲNG CẤP - Test",
);
?>
