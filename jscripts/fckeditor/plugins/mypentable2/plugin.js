(function(){
  //Section 1 : Code to execute when the toolbar button is pressed
  var a= {
    exec:function(editor){
      editor.insertHtml('<table width="600" class="product_description" cellpadding="0" cellspacing="0" style="color:#A8DCDF;font: bold 14px/28px Tahoma;text-align: left"><tr><th align="left" width="140">Hãng sản xuất</th><td></td></tr><tr><th align="left">Ngòi bút (Nib)</th><td></td></tr><tr><th align="left">Kích cỡ Ngòi</th><td></td></tr><tr><th align="left">Thân Bút (Barrel)</th><td></td></tr><tr><th align="left">Chuôi Bút (Cap)</th><td></td></tr><tr><th align="left">Trim</th><td></td></tr><tr><th align="left">Clip</th><td></td></tr><tr><th align="left">Nạp mực</th><td></td></tr><tr><th align="left">Bảo hành</th><td></td></tr></table>');
    }
  },

  //Section 2 : Create the button and add the functionality to it
  b='mypentable2';
  CKEDITOR.plugins.add(b,{
    init:function(editor){
      editor.addCommand(b,a);
      editor.ui.addButton("mypentable2",{
        label:'Thêm bảng chi tiết sản phẩm Bút',
        icon:this.path+"mypentable.gif",
        command:b
      });
    }
  });
})();