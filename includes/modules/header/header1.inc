<?php
/**************************************************************************************************/
/* Created on May 30, 2010                                                                        */
/**************************************************************************************************/
$_topMarquee = str_ireplace('p>', 'span>', TOP_MARQUEE);
$smarty->assign('_MARQUEE', $_topMarquee);
$header = $smarty->fetch( "header/header1.tpl" );
?>
