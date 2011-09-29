<div class="content" style="width: 600px;margin:0 auto;">
  <div class="header1">Chọn Icon cho Danh mục</div>
  <div class="blu-container" style="padding: 10px;text-align: center">
  {$IconsBoard}
  <input type="button" class="w80" value="Chọn" onclick="returnSelectedToParent()">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <input type="button" value="Đóng" onclick="window.close();">
  </div>
</div>
{literal}
<script>
var lastSelected = null;
function fillSelectedItem(item)
{
  if(lastSelected){
    lastSelected.style.backgroundColor = 'transparent';
  }
  item.style.backgroundColor = '#ff0000';
  lastSelected = item;
}
function onMouseOut(item)
{
  if((lastSelected == null) || (item.id != lastSelected.id)){
    item.style.backgroundColor = 'transparent';
  }
}
function returnSelectedToParent(){
  window.opener.setIcon(lastSelected.id);
  window.close();
}
</script>
{/literal}