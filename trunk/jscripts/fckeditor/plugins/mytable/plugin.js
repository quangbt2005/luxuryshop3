(function(){
  //Section 1 : Code to execute when the toolbar button is pressed
  var a= {
    exec:function(editor){
      editor.insertHtml('<table width="220" class="product_intro" cellpadding="0" cellspacing="0" style="color:#A8DCDF;font: bold 11px/18px Tahoma;"><tr><th align="left" width="110">Hãng sản xuất</th><td></td></tr><tr><th align="left">Reference</th><td></td></tr><tr><th align="left">Đường kính</th><td></td></tr><tr><th align="left">Độ dày</th><td></td></tr><tr><th align="left">Chất liệu</th><td></td></tr><tr><th align="left">Hàng trong kho</th><td></td></tr></table>');
    }
  },

  //Section 2 : Create the button and add the functionality to it
  b='mytable';
  CKEDITOR.plugins.add(b,{
    init:function(editor){
      editor.addCommand(b,a);
      editor.ui.addButton("mytable",{
        label:'Thêm bảng thông tin tóm tắt của sản phẩm Đồng Hồ',
        icon:this.path+"mytable.gif",
        command:b
      });
    }
  });
})();