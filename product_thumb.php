<?php
include_once('data/configs/application.inc');
// ---------------------------------------------------------------------------------------------- //
$defaultBackground = '#ffffff';
// ---------------------------------------------------------------------------------------------- //
function hex2RGB($hexStr, $returnAsString = false, $seperator = ',') {
    $hexStr = preg_replace("/[^0-9A-Fa-f]/", '', $hexStr); // Gets a proper hex string
    $rgbArray = array();
    if (strlen($hexStr) == 6) { //If a proper hex code, convert using bitwise operation. No overhead... faster
        $colorVal = hexdec($hexStr);
        $rgbArray['red'] = 0xFF & ($colorVal >> 0x10);
        $rgbArray['green'] = 0xFF & ($colorVal >> 0x8);
        $rgbArray['blue'] = 0xFF & $colorVal;
    } elseif (strlen($hexStr) == 3) { //if shorthand notation, need some string manipulations
        $rgbArray['red'] = hexdec(str_repeat(substr($hexStr, 0, 1), 2));
        $rgbArray['green'] = hexdec(str_repeat(substr($hexStr, 1, 1), 2));
        $rgbArray['blue'] = hexdec(str_repeat(substr($hexStr, 2, 1), 2));
    } else {
        return false; //Invalid hex color code
    }
    return $returnAsString ? implode($seperator, $rgbArray) : $rgbArray; // returns the rgb string or the associative array
}
// ---------------------------------------------------------------------------------------------- //
function setTransparency($new_image,$image_source)
{
  $transparencyIndex = imagecolortransparent($image_source);
  $transparencyColor = array('red' => 255, 'green' => 255, 'blue' => 255);

  if ($transparencyIndex >= 0) {
    $transparencyColor    = imagecolorsforindex($image_source, $transparencyIndex);
  }

  $transparencyIndex    = imagecolorallocate($new_image, $transparencyColor['red'], $transparencyColor['green'], $transparencyColor['blue']);
  imagefill($new_image, 0, 0, $transparencyIndex);
  imagecolortransparent($new_image, $transparencyIndex);
}
// ---------------------------------------------------------------------------------------------- //
$f  = $_GET['f'];
$img_dir = SYS_PRODUCTS_IMAGES;
if(!is_file($img_dir.$f)){
  $f = '../noimage.jpg';
}
// ---------------------------------------------------------------------------------------------- //
$gis = getimagesize($img_dir.$f);
$type = $gis[2];
switch($type)
{
  case "1": $imorig = imagecreatefromgif($img_dir.$f); break;
  case "2": $imorig = imagecreatefromjpeg($img_dir.$f);break;
  case "3": {
    $imorig = imagecreatefrompng($img_dir.$f); break;
    imagealphablending($imorig, false);
    imagesavealpha($imorig, true);
  }
  default: $imorig = imagecreatefromjpeg($img_dir.$f);
}

$x = imagesx($imorig);
$y = imagesy($imorig);
// ---------------------------------------------------------------------------------------------- //
$w  = empty($_GET['w']) ? $x : $_GET['w'];
$h  = empty($_GET['h']) ? $y : $_GET['h'];
$ma = empty($_GET['ma']) ? 500 : $_GET['ma'];
$isTransparent = isset($_GET['trsp']) ? 1 : 0;
$colorHex = isset($_GET['cl']) ? $_GET['cl'] : $defaultBackground;
// ---------------------------------------------------------------------------------------------- //
if($h=='auto' && is_numeric($w))
{
  $h=($w/$x*100)*($y/100);
  if($h > $ma)
  {
    $h = $ma;
    $w = ($h/$y*100)*($x/100);
  }
}
if($w=='auto' && is_numeric($h))
{
  $w=($h/$y*100)*($x/100);
  if($w > $ma)
  {
    $w = $ma;
    $h = ($w/$x*100)*($y/100);
  }
}

$im = imagecreatetruecolor($w,$h);
imagealphablending($im, false);
imagesavealpha($im, true);
//setTransparency($im,$imorig);
imagecopyresampled($im,$imorig , 0,0,0,0,$w,$h,$x,$y);

$cx = empty($_GET['cx']) ? 0 : $_GET['cx'];
$cy = empty($_GET['cy']) ? 0 : $_GET['cy'];

if(!empty($cx) && !empty($cy))
{
  // $cc     = empty($_GET['cc']) ? 'white' : $_GET['cc'];
  @$valign = !isset($_GET['val']) ? 1 : $_GET['val'];
  @$halign = !isset($_GET['hal']) ? 1 : $_GET['hal'];

    $sx     = $halign==1 ? (($cx - $w)/2) : 0;
    $sy     = $valign==1 ? (($cy - $h)/2) : 0;

    $canvas = imagecreatetruecolor($cx,$cy);
    imagealphablending($canvas, false);
    imagesavealpha($canvas, true);

    $colorArray = hex2RGB($colorHex);
    $transparent = imagecolorallocatealpha($canvas, 0,0,0,127);

    //$white  = imagecolorallocate($canvas, 255, 255, 255);
    //$black  = imagecolorallocate($canvas, 255, 0, 0);
    if(!$isTransparent)
    {
      $color = imagecolorallocate($canvas, $colorArray['red'],
                                           $colorArray['green'],
                                           $colorArray['blue']);
      imagefill($canvas, 0, 0, $color);
    } else {
      imagefill($canvas, 0, 0, $transparent);
    }
    imagecopy($canvas, $im, $sx, $sy, 0, 0, $w, $h);
    $im = $canvas;
}

//if (imagecopyresampled($im,$imorig , 0,0,0,0,$w,$h,$x,$y))
{
  header('Content-Type: image/png');
  imagepng($im);

  // header('Content-Type: image/jpeg');
  // imagejpeg($im);
  imagedestroy($im);
  imagedestroy($canvas);
  imagedestroy($imorig);
}
//} else {
//    $imorig = imagecreatefrompng($img_dir.'app-search.png');
//    header('Content-Type: image/jpeg');
//    imagejpeg($imorig);
//    imagedestroy($imorig);
//}
?>
