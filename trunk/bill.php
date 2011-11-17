<?php
$file = fopen('bill.txt', 'a+');
if($file){
  $s = sprintf("--> %s\t%s\n", $_SERVER['REMOTE_ADDR'], date('d-m-Y H:i:s'));
  fwrite($file, $s);
  fclose($file);
}
?>
