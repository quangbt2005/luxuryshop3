<?php
/**************************************************************************************************/
/* Created on Nov 29, 2008                                                                        */
/**************************************************************************************************/
// ---------------------------------------------------------------------------------------------- //
// Should reduce SUBDOMAIN when deploy
// ---------------------------------------------------------------------------------------------- //
define( 'SUBDOMAIN', '' );
// ---------------------------------------------------------------------------------------------- //
// Just change SYS_ROOT when deploy
// ---------------------------------------------------------------------------------------------- //
//define( 'SYS_ROOT', '/home/thamtuth/public_html/kittyshop/' . SUBDOMAIN );
define( 'SYS_ROOT', 'd:/www/luxuryshop1/' . SUBDOMAIN );
define( 'WEB_ROOT', '/' . SUBDOMAIN );

define( 'DATA_PATH',                  SYS_ROOT . 'data/' );
define( 'TEMPLATES_PATH',             SYS_ROOT . 'data/templates/' );
define( 'TEMPLATES_C_PATH',           SYS_ROOT . 'data/templates_c/' );
define( 'SMARTY_CACHE',               SYS_ROOT . 'data/cache/' );
define( 'SMARTY_CONFIG',              SYS_ROOT . 'data/configs/' );
define( 'XML_PATH',                   SYS_ROOT . 'data/xml/' );
define( 'INCLUDES_PATH',              SYS_ROOT . 'includes/' );
define( 'LIB_PATH',                   SYS_ROOT . 'libs/' );
define( 'FUNCTIONS_PATH',             INCLUDES_PATH . 'functions/' );
define( 'MODULES_PATH',               INCLUDES_PATH . 'modules/' );

define( 'LAYOUT_PATH',                INCLUDES_PATH . 'layout/' );
define( 'IMAGES_PATH',                WEB_ROOT . 'images/' );
define( 'PRODUCTS_IMAGES',            IMAGES_PATH . 'products/' );
define( 'IMAGES_LANG_PATH',           WEB_ROOT . 'images/languages/' );
define( 'JSCRIPTS_PATH',              WEB_ROOT . 'javascripts/' );
define( 'STYLES_PATH',                WEB_ROOT . 'styles/' );

define( 'SYS_IMAGES_PATH',            SYS_ROOT . 'images/' );
define( 'SYS_UPLOAD_PATH',            SYS_ROOT . 'uploads/' );
define( 'SYS_PRODUCTS_IMAGES',        SYS_IMAGES_PATH . 'products/' );

define( 'DEFAULT_MODULE',             'home' );
define( 'DEFAULT_PAGE',               'default' );

define( 'NO_MODULE',                  'home' );
define( 'NO_PAGE',                    'default' );

define( 'DEFAULT_LAYOUT',             'layouts/layout03.tpl' );
define( 'YM_PATH',                    SYS_ROOT . 'ym/yms.txt' );
// ---------------------------------------------------------------------------------------------- //
// For paging
// ---------------------------------------------------------------------------------------------- //
define( 'DEFAULT_PAGER_LIMIT',      12 );
define( 'DEFAULT_PAGER_PREV_SCALE', 2 );
define( 'DEFAULT_PAGER_NEXT_SCALE', 2 );
define( 'DEFAULT_PAGER_CSS_CLASS',  'pager' );
define( 'DEFAULT_PAGER_ALIGN',      'right' );
define( 'DEFAULT_PAGER_PARAM_NAME', 'page' );
define( 'DEFAULT_PAGER_CURRENT_CSS_CLASS', 'current_page' );
define( 'DEFAULT_PAGER_NEWS_LIMIT', 5 );
define( 'MAX_BEST_SELLER', 10 );
// ---------------------------------------------------------------------------------------------- //
// For new product on Home page
// ---------------------------------------------------------------------------------------------- //
define( 'PART_ROW', '3' );
define( 'PART_ROW_ITEM', '3' );
define( 'PART_ITEM_LIMIT', (int)PART_ROW*(int)PART_ROW_ITEM );
// ---------------------------------------------------------------------------------------------- //
// URL
// ---------------------------------------------------------------------------------------------- //
define( 'URL_NO_MODULE',   WEB_ROOT . 'errors/nopage' );
define( 'URL_NO_PRODUCT',  WEB_ROOT . 'errors/noproduct' );
define( 'URL_SUBMIT_CART', WEB_ROOT . 'cart/submit' );
define( 'URL_ORDER_COMPLETE', WEB_ROOT . 'cart/complete' );

define( 'LANGUAGE_ID', 1 );
define( 'LANGUAGE', 'vietnam' );
define( 'SMALL_IMAGE_HEIGHT', 180 );
define( 'HEADING_NEWS_IMAGE_WIDTH', '100' );
define( 'HEADING_NEWS_IMAGE_HEIGHT', '100' );
// ---------------------------------------------------------------------------------------------- //
// YM NOTIFIER CONFIG
// ---------------------------------------------------------------------------------------------- //
define( 'YM_USER',            'meokittyshop' );
define( 'YM_USER_PASS',       'b7DVMElU' );
define( 'YM_CONSUMER_KEY',    'dj0yJmk9NmE3OVIwYmQyU2dZJmQ9WVdrOWRHdFVZV2hITnpBbWNHbzlNVEUyTXpFMU9USTJNZy0tJnM9Y29uc3VtZXJzZWNyZXQmeD0yNg--' );
define( 'YM_CONSUMER_SECRET', '3a0f3ac40cfea6ca52841d707565a48e6318aa51' );
// ---------------------------------------------------------------------------------------------- //
// SMTP ACCOUNT
// ---------------------------------------------------------------------------------------------- //
define( 'SMTP_HOST',          'server-112-78-8-153.domainhostingvn.com' );
define( 'SMTP_USER',          'admin@meokitty.com' );
define( 'SMTP_PASS',          'b7DVMElU' );
// ---------------------------------------------------------------------------------------------- //
?>