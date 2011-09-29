<?php
$images = glob(SYS_IMAGES_PATH . 'cat/*.png');
$Icons = array();
// ---------------------------------------------------------------------------------------------- //
foreach($images as $image)
{
  $Icons[] = basename($image);
}
$icon_onrow = 5;
$Icons = array_chunk($Icons, $icon_onrow);
$rowcount = count($Icons);
if(count($Icons[$rowcount-1])<$icon_onrow){
  $Icons[$rowcount-1] = array_pad($Icons[$rowcount-1], 5, "cat_deko.png");
}

$IconsBoard = '<div style="width: 100%;height: 200px;overflow-y: scroll">' .
              '<table width="100%" cellpadding="0" cellspacing="0">';
foreach($Icons as $RowIcon){
  $IconsBoard .= '<tr>';
  foreach($RowIcon as $icon){
    $IconsBoard .= ('<td align="center"><img id="' .$icon . '" onMouseOver="this.style.cursor='
                    . "'hand';" . 'this.style.backgroundColor=' . "'#71FFB8';"
                    . '" onMouseOut="onMouseOut(this);" onclick="fillSelectedItem(this)"'
                    . ' style="padding: 5px" src="/images/cat/' . $icon . '" border="0"></td>');
  }
  $IconsBoard .= '</tr>';
}
$IconsBoard .= '</table></div>';
// ---------------------------------------------------------------------------------------------- //
$smarty->assign('IconsBoard', $IconsBoard);
// ---------------------------------------------------------------------------------------------- //
$center_col = $smarty->fetch( "admin/categories/iconboard.tpl" );
?>