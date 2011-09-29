{literal}
<script language="javascript" type="text/javascript">
CKEDITOR.on( 'instanceReady', function( ev )
{
  if(ev.editor.name == 'txtService'){
    ev.editor.config.uiColor = '#33DC6E';
  }
});
</script>
{/literal}
<div id="bigBox">
  <div class="box">
    <div class="left"></div>
    <div class="right"></div>
    <div class="heading">
      <h1 class="bkg_dashboard">Cấu Hình</h1>
    </div>
    <div class="content">
    <form method="POST">
      <table cellpadding="0" cellspacing="5" width="100%" border="0">
        <tr>
          <th align="right" style="padding-right: 5px" width="200">Địa chỉ</th>
          <td align="left" style="padding-left: 5px" colspan="3"><input type="text" name="txtAddress" class="w400" value="{if $smarty.post.txtAddress != ''}{$smarty.post.txtAddress}{else}{$STORE_ADDRESS}{/if}"></td>
        </tr>
        <tr>
          <th align="right" style="padding-right: 5px">Email</th>
          <td align="left" style="padding-left: 5px" colspan="3"><input type="text" name="txtEmail1" class="w200" value="{if $smarty.post.txtEmail1 != ''}{$smarty.post.txtEmail1}{else}{$STORE_EMAIL}{/if}"></td>
        </tr>
        <tr>
          <th align="right" style="padding-right: 5px">Điện thoại 1</th>
          <td align="left" style="padding-left: 5px" colspan="3"><input type="text" name="txtPhone1" value="{if $smarty.post.txtPhone1 != ''}{$smarty.post.txtPhone1}{else}{$PHONE_1}{/if}"></td>
        </tr>
        <tr>
          <th align="right" style="padding-right: 5px">Điện thoại 2</th>
          <td align="left" style="padding-left: 5px" colspan="3"><input type="text" name="txtPhone2" value="{if $smarty.post.txtPhone2 != ''}{$smarty.post.txtPhone2}{else}{$PHONE_2}{/if}"></td>
        </tr>
        <tr>
          <th valign="top" align="right" style="padding-right: 5px">Dịch vụ</th>
          <td colspan="3">
            <textarea name="txtService" rows="25" class="ckeditor" style="width: 560px;">{$SERVICE}</textarea>
          </td>
        </tr>
        <tr>
          <th valign="top" align="right" style="padding-right: 5px">Marquee</th>
          <td colspan="3">
            <textarea name="txtTopMarquee" rows="2" class="ckeditor" style="width: 560px;">{$TOP_MARQUEE}</textarea>
          </td>
        </tr>
        <tr>
          <td colspan="4" align="center"><br><input type="submit" value="Lưu thay đổi" class="w100"></td>
        </tr>
      </table>
    </form>
    </div>
  </div>
</div>
{if $update_configuration_ok > 0}
<script language="javascript" type="text/javascript">
alert('Đã cập nhật cấu hình thành công');
</script>
{/if}