  <script type="text/javascript" src="/jscripts/fckeditor/ckeditor_basic.js"></script>
  {literal}
  <script type="text/javascript" language="javascript">
  $(document).ready(function() {
  CKEDITOR.replace( 'ckChat',
    {
      uiColor : '#9AB8F3',
      width: 715,
      toolbar: 'Enough4Chat',
    } );
  });
  function onChatSubmit(){
    var rawValue = CKEDITOR.instances.ckChat.getData();
    var plainValue = getClearText(rawValue);

    if ( plainValue.length < 10 ){
      alert( 'Hãy nhập Nội dung có ít nhất 10 ký tự' );
      return false;
    }

    if ( plainValue.length > 10000 ){
      alert( 'Nội dung quá dài' );
      return false;
    }

    return true;
  }
  function getClearText( strSrc ) {
    return strSrc.replace( /<[^<|>]+?>/gi,'' );
  }
  </script>
  {/literal}
  <table border="0" cellpadding="0" cellspacing="0" width="100%">
  <tr>
    <td style="padding: 10px" align="left"><span class="bigtitle">FEEDBACK</span></td>
  </tr>
  </table>
  <div class="wrapper" style="width: 715px; margin-left: 1px;padding-bottom: 50px;color: #00f;border: 1px solid #ccc">
  <table cellpadding="0" cellspacing="0" width="100%">
    <tr>
      <td style="padding: 10px">
        {if $total_chat > 0}
        <table cellpadding="0" cellspacing="0" width="100%" border="0">
          {foreach from=$Chat_List item=chat}
          <tr>
            <tr><td colspan="2" align="left"><img src="/images/transparent.png" width="1" height="10" border="0"></td></tr>
            <th valign="top" align="left"><img src="/product_thumb.php?f=..@avatars/{$chat.showingavatar}&w=60&h=60" width="60" height="60" border="0">&nbsp;&nbsp;&nbsp;{$chat.chatter|escape:"html"}</th>
            <th valign="top" align="right" class="chatdate">{$chat.createddate}</th>
          </tr>
          <tr><td colspan="2" align="left"><img src="/images/transparent.png" width="1" height="5" border="0"></td></tr>
          <tr><td colspan="2" align="left" style="color: #000">{$chat.content}</td></tr>
          <tr><td colspan="2" align="left" style="border-bottom: 3px solid #00ff80"><img src="/images/transparent.png" width="1" height="50" border="0"></td></tr>
          {/foreach}
        </table>
        {/if}
      </td>
    </tr>
  </table>
  {if $total_chat > 0}
  {$pager}&nbsp;&nbsp;&nbsp;<div class="clear"></div>
  <div class="t-right" style="width: 715px;"><span class="f10">Hiển thị {$chat_count} record từ {$chat_from} đến {$chat_to} trong tổng số {$total_chat} record&nbsp;&nbsp;&nbsp;</span></div>
  {else}
  <div class="t-center" style="width: 715px;"><span class="f10 fb">Chưa có nhận xét nào&nbsp;&nbsp;&nbsp;</span></div>
  {/if}
  <img src="/images/transparent.png" width="1" height="50" border="0">
  <form method="post" action="/feedback/post/{$page}" enctype="multipart/form-data">
  {if $error_count > 0}
  {foreach from=$errs item=error}
  <div class="w100p error_field t-left">&nbsp;&nbsp;<img height="10" border="0" width="10" title=" Lỗi " alt="Lỗi" src="/images/icons/error.gif">&nbsp;{$error}</div>
  {/foreach}
  {/if}
  <table cellpadding="0" cellspacing="0" width="715" border="0">
    <tr>
      <td colspan="2" style="padding-top: 20px"><textarea id="ckChat" name="ckChat"></textarea></td>
    </tr>
    <tr>
      <td colspan="2">&nbsp;</td>
    </tr>
    <tr>
      <td colspan="2"><table cellpadding="0" cellspacing="10" border="0">
        <tr>
          <th align="left">Tên khách hàng</th>
          <td align="left"><input type="text" name="txtChatter" class="flat w200" onblur="onNameBlur()" value="Guest"></td></tr>
        </tr>
        <tr>
          <th align="left">Avatar</th>
          <td align="left"><input type="file" name="txtAvatar" class="flat w200">&nbsp;&nbsp;(File ảnh kích thước không lớn hơn 30KB)</td></tr>
        </tr>
        <tr>
          <th align="left">Mã khách hàng</th>
          <td align="left"><input name="txtCode" type="text" class="flat w150 t-right"></td>
        </tr>
      </table></td>
    </tr>
    <tr>
      <td colspan="2" style="padding-top: 20px" align="center"><input onclick="return onChatSubmit();" type="image" src="/images/btnfeedback.png" value="Gửi feedback" alt="Gửi feedback" name="Gửi feedback"></td>
    </tr>
  </table>
  </form>
  </div>
  <div class="clear"></div>