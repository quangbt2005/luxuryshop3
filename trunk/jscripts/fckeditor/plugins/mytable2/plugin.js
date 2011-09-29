(function(){
  //Section 1 : Code to execute when the toolbar button is pressed
  var a= {
    exec:function(editor){
      editor.insertHtml('<table width="600" class="product_description" cellpadding="0" cellspacing="0" style="color:#A8DCDF;font: bold 14px/28px Tahoma;text-align: left"><tr><th align="left" width="140">Hãng sản xuất</th><td></td></tr><tr><th align="left">Movement</th><td></td></tr><tr><th align="left">Chất liệu</th><td></td></tr><tr><th align="left">Chân kính (Jewel)</th><td></td></tr><tr><th align="left">Đường kính</th><td></td></tr><tr><th align="left">Độ dày</th><td></td></tr><tr><th align="left">Mặt số (Dial)</th><td></td></tr><tr><th align="left">Kim (Hand)</th><td></td></tr><tr><th align="left">Vành (Bezel)</th><td></td></tr><tr><th align="left">Núm (Crow)</th><td></td></tr><tr><th align="left">Mặt lưng (Back)</th><td></td></tr><tr><th align="left">Dây (Strap)</th><td></td></tr><tr><th align="left">Chống nước</th><td></td></tr><tr><th align="left">Bảo hành</th><td></td></tr></table>');
    }
  },

  //Section 2 : Create the button and add the functionality to it
  b='mytable2';
  CKEDITOR.plugins.add(b,{
    init:function(editor){
      editor.addCommand(b,a);
      editor.ui.addButton("mytable2",{
        label:'Thêm bảng chi tiết sản phẩm Đồng Hồ',
        icon:this.path+"mytable.gif",
        command:b
      });
    }
  });
})();