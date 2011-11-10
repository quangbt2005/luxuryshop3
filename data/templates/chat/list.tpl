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
  <div class="wrapper" style="width: 715px; margin-left: 1px;">
  {TitleBox title="Feedback"}
  <table cellpadding="0" cellspacing="0" width="100%" class="chat">
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
  <div class="t-right" style="width: 715px;"><span class="f10">Hiển thị {$chat_count} record từ {$chat_from} đến {$chat_to} trong tổng số {$total_chat} record</span></div>
  {else}
  <div class="t-right" style="width: 715px;"><span class="f10">Không có record nào</span></div>
  {/if}
  <form method="post" action="/chat/post/{$page}">
  {if $error_count > 0}
  {foreach from=$errs item=error}
  <div class="w100p error_field t-left">&nbsp;&nbsp;<img height="10" border="0" width="10" title=" Lỗi " alt="Lỗi" src="/images/icons/error.gif">&nbsp;{$error}</div>
  {/foreach}
  <br>
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
          <td align="left">Tên khách hàng</td>
          <td align="left"><input type="text" name="txtChatter" class="flat w200" onblur="onNameBlur()" value="Guest"></td></tr>
        </tr>
        <tr>
          <td align="left">Avatar</td>
          <td align="left"><input type="file" name="txtAvatar" class="flat w200">&nbsp;&nbsp;(Kích thước không lớn hơn 30KB)</td></tr>
        </tr>
        <tr>
          <td align="left">Mã khách hàng</td>
          <td align="left"><input name="code" type="text" class="flat w150 t-right"></td>
        </tr>
      </table></td>
    </tr>
    <tr>
      <td colspan="2" style="padding-top: 20px" align="center"><input onclick="return onChatSubmit();" type="submit" class="w120" value="Gửi bài viết"></td>
    </tr>
  </table>
  </form>