  <script type="text/javascript" src="/jscripts/fckeditor/ckeditor_basic.js"></script>
  {literal}
  <script type="text/javascript" language="javascript">
  $(document).ready(function() {
  CKEDITOR.replace( 'ckChat',
    {
      uiColor : '#9AB8F3',
      width: 547,
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

    if ( plainValue.length > 4096 ){
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
  <div class="wrapper" style="width: 547px; margin-left: 1px;">
  {TitleBox title="Chia Sẻ Kinh Nghiệm"}
  <table cellpadding="0" cellspacing="0" width="100%" class="chat">
    {if $error != ''}
    <tr><td><br /><font color="red"><h2>&nbsp;&nbsp;&nbsp;&nbsp;Mã an toàn không đúng</h2></font></td></tr>
    {/if}
    <tr>
      <td style="padding: 10px">
        {if $total_chat > 0}
        <table cellpadding="0" cellspacing="0" width="100%" border="0">
          {foreach from=$Chat_List item=chat}
          <tr>
            <th>{$chat.chatter}</th>
            <th class="chatdate">{$chat.createddate}</th>
          </tr>
          <tr>
            <td colspan="2">{$chat.content}</td>
          </tr>
          {/foreach}
        </table>
        {else}
        <img src="/images/transparent.png" width="1" height="300" border="0">
        {/if}
      </td>
    </tr>
  </table>
  </div>
  <div class="clear"></div>
  {if $total_chat > 0}
  {$pager}<div class="clear"></div>
  <div class="t-right" style="width: 547px;"><span class="f10">Hiển thị {$chat_count} record từ {$chat_from} đến {$chat_to} trong tổng số {$total_chat} record</span></div>
  {else}
  <div class="t-right" style="width: 547px;"><span class="f10">Không có record nào</span></div>
  {/if}
  <form method="post" action="/chat/post/1">
  <table cellpadding="0" cellspacing="0" width="547" border="0">
    <tr>
      <td colspan="2" style="padding-top: 20px"><textarea id="ckChat" name="ckChat"></textarea></td>
    </tr>
    <tr>
      <td align="left" width="30%" valign="top">
        <table cellpadding="0" cellspacing="0" width="100%" border="0">
          <tr><td valign="top" align="left">Tên người viết</td></tr>
          <tr><td valign="top" align="left"><input type="text" name="txtChatter" class="flat w200" onblur="onNameBlur()" value="Guest"></td></tr>
        </table>
      </td>
      <td align="left" valign="top">
        <table cellpadding="0" cellspacing="0" width="100%" border="0">
          <tr><td valign="top" align="left" colspan="2">Mã an toàn</td></tr>
          <tr>
            <td width="130" valign="top" align="left"><img src="/captcha.php?name=chatting"></td>
            <td align="left" valign="top"><input name="code" type="text" class="flat w50"></td>
          </tr>
        </table>
    </tr>
    <tr>
      <td colspan="2" style="padding-top: 20px" align="center"><input onclick="return onChatSubmit();" type="submit" class="w120" value="Gửi bài viết"></td>
    </tr>
  </table>
  </form>