<div id="bigBox">
  <div class="box">
    <div class="left"></div>
    <div class="right"></div>
    <div class="heading">
      <h1 class="bkg_dashboard">Danh Mục Đặc Biệt</h1>
    </div>
    <div class="content">
    <form method="POST">
      <table cellpadding="0" cellspacing="0" width="100%" border="0">
        <tr>
          <td align="left" colspan="2">Sản phẩm của danh mục đặc biệt sẽ hiển thị random trên trang chủ</td>
        </tr>
        <tr>
          <td width="40%">
            <table class="vlist" cellpadding="0" cellspacing="0" width="100%" border="0">
              {foreach from=$specialSelect item=select key=key}
              <tr>
                <th align="right" style="padding-right: 5px" width="200">Vị trí {$key}</th>
                <td align="left" style="padding-left: 5px">{$select}</td>
              </tr>
            {/foreach}
            </table>
          </td>
          <td rowspan="2" valign="top"><img hspace="10" src="/images/specposition.gif" border="0" width="400"></td>
        </tr>
        <tr>
          <td align="center"><br /><input type="submit" value="Lưu thay đổi" class="w100"></td>
        </tr>
      </table>
    </form>
    </div>
  </div>
</div>
{if $edit_special_cat_ok > 0}
<script language="javascript" type="text/javascript">
alert('Đã cập nhật Danh Mục Đặc Biệt thành công');
</script>
{/if}