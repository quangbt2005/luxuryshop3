        <table width="100%" class="vlist" cellpadding="0" cellspacing="0">
          <tr>
            <th width="240">Người gửi</th>
            <th>Nội dung</th>
            <th width="140">Ngày gửi</th>
            <th width="120">Trạng thái</th>
            <th width="50">Chọn</th>
          </tr>
          {foreach from=$Chat_List item=chat}
          <tr onMouseOver="this.style.backgroundColor='#71FFB8';" onMouseOut="this.style.backgroundColor='transparent';" style="cursor: hand;cursor: pointer;" ondblclick="openOrderDetailPopup({$order.orders_id})">
            <td><a href="javascript:openChatDetailPopup({$chat.id});">{$chat.chatter|escape:"html"}</a></td>
            <td align="left">{$chat.intro}&nbsp;</td>
            <td align="left">{$chat.createddate}</td>
            <td align="center">{if $chat.isdisplay==1}Hiển thị{else}Không hiển thị{/if}</td>
            <td align="center"><input type="checkbox" value="{$chat.id}" onclick="addCheckedList(this.value, this.checked)"></td>
          </tr>
          {/foreach}
        </table><br/>
        <table width="100%" cellpadding="0" cellspacing="0">
          <tr><td align="right"><input type="button" value="Hiển thị những dòng đã chọn" onclick="displayChat()">&nbsp;&nbsp;&nbsp;<input type="button" value="Không hiển thị những dòng đã chọn" onclick="noDisplayChat()">&nbsp;&nbsp;&nbsp;<input type="button" value="Xoá những dòng đã chọn" onclick="deleteChat()"></td></tr>
        </table>