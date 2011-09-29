{literal}
<script type="text/javascript" languge="javascript">
function _bindDragDrop(){
  // Enable document and folder nodes as drag source
  $("#tree span.ui-dynatree-document, span.ui-dynatree-folder").draggable({
      delay: 0,
      distance: 4,
      helper: 'clone',
      opacity: 0.5,
      addClasses: false,
      appendTo: 'body',
      revert: 'invalid',
      revertDuration: 400,
      start: function(event, ui) {
        //logMsg("draggable.start, %o, %o", event, ui);
      },
      drag: function(event, ui) {
        //logMsg("draggable.drag, %o, %o", event, ui);
      },
      stop: function(event, ui) {
        //logMsg("draggable.stop, %o, %o", event, ui);
      },
      _last: null
  });
  // Enable document and folder nodes as drop target
  $("#tree span.ui-dynatree-document, span.ui-dynatree-folder").droppable({
      accept: '.ui-dynatree-document, .ui-dynatree-folder',
      addClasses: false,
      //activeClass: '.ui-state-highlight',
      hoverClass: 'drophover',
      tolerance: 'intersect',
      activate: function(event, ui) {
        //logMsg("droppable.activate, %o, %o", event, ui);
      },
      deactivate: function(event, ui) {
        //logMsg("droppable.deactivate, %o, %o", event, ui);
      },
      over: function(event, ui) {
        //logMsg("droppable.over, %o, %o", event, ui);
      },
      out: function(event, ui) {
        //logMsg("droppable.out, %o, %o", event, ui);
      },
      drop: function(event, ui) {
        var srcnode = ui.draggable[0].dtnode;
        var destnode = event.target.dtnode;
        var copynode = srcnode.toDict(true, function(dict){
          // dict.title = "Copy of " + dict.title;
          // delete dict.key; // Remove key, so a new one will be created
        });
        destnode.addChild(copynode);
        var url = "/admin/categories/" + srcnode.data.key + "/move/" + destnode.data.key;
        $.get(url, function(data){});
        srcnode.remove();
        // Must re-binnd, so new nodes become draggable too
        _bindDragDrop();
      },
      _last: null
  });
}

$(document).ready(function() {
  $("#tree").dynatree({
      title: "Categories",
      rootVisible: true,
      onActivate: function(dtnode) {
        update_sub_categories_tree(dtnode.data.key);
      }
  });
  _bindDragDrop();
  $("#tree").dynatree("getRoot").childList[0].focus();
  update_sub_categories_tree($("#tree").dynatree("getRoot").childList[0].data.key);
});
</script>
<style type="text/css">
  .drophover{ border: 1px solid blue; }
</style>
{/literal}
<div id="bigBox">
  <div class="box">
    <div class="left"></div>
    <div class="right"></div>
    <div class="heading">
      <h1 class="bkg_dashboard">Categories</h1>
    </div>
    <div class="content">
      <div style="float: left;width: 30%;border: 0px solid #cccccc">
        <!-- <h1>Categories</h1> -->
        <div align="left">
          <input type="button" value="Thêm danh mục" onclick="openAddCategoryPopup();">&nbsp;&nbsp;
          <input type="button" value="Sửa danh mục" onclick="openEditCategoryPopup();">&nbsp;&nbsp;
          <input type="button" value="Xóa danh mục" onclick="deleteCategory();">
        </div>
        <div id="tree" style="overflow: auto;float: left;">
          {$Tree}
        </div>
      </div>
      <!-- <div style="float: left;margin-left: 1%;width: 69%;margin-top:-50px;"> -->
      <div style="float: left;margin-left: 1%;width: 69%;">
        <div class="header1">
          <div style="float: left">Danh sách sản phẩm</div>
          <div align="right"><input type="Button" value="Thêm sản phẩm" onclick="openAddProductPopup();"></div>
        </div>
        <div class="blu-container" style="padding: 10px;height:450px;overflow:auto;">
          <div id="sub_cat_con"></div>
        </div>
      </div>
      <div style="clear: both">&nbsp;</div>
    </div>
  </div>
</div>{literal}
<script type="text/javascript" language="javascript">
var popupWidth  = 840;
var popupHeight = 700;
function openAddProductPopup(){
  var url = '/admin/products/add/';
  var dtnode_id = 0;
  if($("#tree").dynatree("getActiveNode") != null){
    dtnode_id = $("#tree").dynatree("getActiveNode").data.key;
  } else {
    dtnode_id = $("#tree").dynatree("getRoot").childList[0].data.key;
  }
  if(dtnode_id > 0){
    url = url + dtnode_id;
    var topPos = (getHeight()-popupHeight)/2;
  var leftPos = (getWidth()-popupWidth)/2;

    var popup = window.open(url, 'Them_san_pham_moi',"resizable=no,menubar=no,toolbar=no,location=no,scrollbars=yes,width=" + popupWidth + ",height=" + popupHeight + ",left="+leftPos+",top="+topPos);
  } else {
    alert('Chưa chọn Danh mục hoặc Danh mục này không thể chứa sản phẩm');
  }
}
function reloadProductList(category_id)
{
  if($("#tree").dynatree("getActiveNode") != null){
    var dtnode_id = $("#tree").dynatree("getActiveNode").data.key;
    if(category_id == dtnode_id){
      update_sub_categories_tree(dtnode_id);
    }
  }
}
function addTreeNewCategory(category_id, category_name, parent_id)
{
  if(parent_id == 0){
    activenode = $("#tree").dynatree("getRoot").addChild({
        title: category_name,
        key: category_id,
        isFolder: true
      });
  } else {
    $("#tree").dynatree("getTree").selectKey(parent_id).addChild({
        title: category_name,
        key: category_id,
        isFolder: true
    });
  }
}
function editTreeCategory(category_name, old_parent_id, new_parent_id)
{
  var node = $("#tree").dynatree("getActiveNode");
  node.data.title = category_name;
  if(old_parent_id != new_parent_id){
    node_id = node.data.key;
    new_parent = $("#tree").dynatree("getTree").selectKey(new_parent_id).addChild({
        title: category_name,
        key: node_id,
        isFolder: true
    });
    node.remove();
  } else {
    node.render();
  }
}
function openAddCategoryPopup(){
  var url = '/admin/categories/add/';
  if($("#tree").dynatree("getActiveNode") != null){
    var dtnode_id = $("#tree").dynatree("getActiveNode").data.key;
    url = url + dtnode_id;
  } else url = '/admin/categories/add/' + $("#tree").dynatree("getRoot").childList[0].data.key;

  var topPos = (getHeight()-popupHeight)/2;
  var leftPos = (getWidth()-popupWidth)/2;

  var popup = window.open(url, 'Them_danh_muc_moi',"resizable=no,menubar=no,toolbar=no,location=no,width=" + popupWidth + ",height=" + popupHeight + ",left="+leftPos+",top="+topPos);
}
function openEditCategoryPopup(){
  var url = '/admin/categories/edit/';
  var dtnode_id = 0;
  if($("#tree").dynatree("getActiveNode") != null){
    dtnode_id = $("#tree").dynatree("getActiveNode").data.key;
  } else {
    dtnode_id = $("#tree").dynatree("getRoot").childList[0].data.key;
  }
  if(dtnode_id > 0){
    url = url + dtnode_id;

    var topPos = (getHeight()-popupHeight)/2;
  var leftPos = (getWidth()-popupWidth)/2;

    var popup = window.open(url, 'Sua_danh_muc',"resizable=no,menubar=no,toolbar=no,location=no,width=" + popupWidth + ",height=" + popupHeight + ",left="+leftPos+",top="+topPos);
  } else {
    alert('Chưa chọn Danh mục hoặc Danh mục này không thể hiệu chỉnh');
  }
}
function openEditProductPopup(product_id){
  var url = '/admin/products/edit/' + product_id;

  var topPos = (getHeight()-popupHeight)/2;
  var leftPos = (getWidth()-popupWidth)/2;

  var popup = window.open(url, 'Hieu_chinh_thong_tin_san_pham',"resizable=no,menubar=no,toolbar=no,location=no,scrollbars=yes,width=" + popupWidth + ",height=" + popupHeight + ",left="+leftPos+",top="+topPos);
}
function openSaleoffSettingPopup(product_id){
  var url = '/admin/products/saleoff/' + product_id;

  var topPos = (getHeight()-popupHeight)/2;
  var leftPos = (getWidth()-popupWidth)/2;

  var popup = window.open(url, 'Khuyen_mai_san_pham',"resizable=no,menubar=no,toolbar=no,location=no,width=" + popupWidth + ",height=" + popupHeight + ",left="+leftPos+",top="+topPos);
}
function deleteCategory(){
  var dtnode_id = 0;
  var dtnode = null;
  var _confirm = false;

  if($("#tree").dynatree("getActiveNode") != null){
    dtnode = $("#tree").dynatree("getActiveNode");
    dtnode_id = $("#tree").dynatree("getActiveNode").data.key;
  } else {
    dtnode = $("#tree").dynatree("getRoot").childList[0];
    dtnode_id = $("#tree").dynatree("getRoot").childList[0].data.key;
  }

  if(dtnode_id > 0){
    if(dtnode.hasChildren())
    {
      _confirm = confirm("Xóa danh mục " + dtnode.data.title + " và toàn bộ danh mục con ?");
      //var nodes = dtnode.childList;
      //alert(nodes.length);
    } else {
      _confirm = confirm("Xóa danh mục " + dtnode.data.title + " ?");
    }
    if(_confirm){
      recursiveDeleteNode(dtnode);
      $("#tree").dynatree("getRoot").render();
    }
  } else {
    alert('Chưa chọn Danh mục hoặc Danh mục này không thể xóa');
  }
}
function recursiveDeleteNode(node){
  if(node.hasChildren()){
    var children = node.childList;
    for(i=0;i < children.length;i++){
      recursiveDeleteNode(children[i]);
    }
  }
  var url = "/admin/categories/" + node.data.key + "/delete";
  $.get(url, function(data){
    node.remove();
  });
}
</script>{/literal}