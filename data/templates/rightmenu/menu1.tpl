<table width="100%" cellpadding="0" cellspacing="0" border="0">
	<tr>
		<td>
			<table width="100%" cellpadding="0" cellspacing="0" border="0" class="k-t6-heading">
				<tr>
					<td class="k-tl6"><img src="/images/spacer.gif" width="16" height="49" alt=""></td>
					<td class="k-tr6 heading_text_3" width="100%"><a href="/sanpham/giamgia/danhsach/1" class="saleofflink">KHUYẾN MÃI&nbsp;&nbsp;<img src="/images/123_hot.gif" border="0"></a></td>
				</tr>
			</table>
		</td>
	</tr>
	<tr>
		<td>
			<table width="100%" cellpadding="0" cellspacing="0" border="0">
				<tr>
					<td class="tall-l6"><img src="/images/spacer.gif" width="20" height="1" alt=""></td>
					<td class="tall-m6" width="100%" align="center">
						<div class="fix_height_container">
							<div id="divSaleOff" class="t-center h150" style="padding: 10 0 10 0"></div>
						</div>
					</td>
					<td class="tall-r6"><img src="/images/spacer.gif" width="20" height="1" alt=""></td>
				</tr>
			</table>
		</td>
	</tr>
	<tr>
		<td><table width="100%" cellpadding="0" cellspacing="0" border="0">
			<tr>
				<td><img src="/images/k-bl6.gif" alt=""></td>
				<td class="tall-b6" width="100%"><br style="line-height:10px"></td>
				<td><img src="/images/k-br6.gif" alt=""></td>
			</tr>
		</table></td>
	</tr>
</table><br>
<table width="100%" cellpadding="0" cellspacing="0" border="0">
	<tr>
		<td>
			<table width="100%" cellpadding="0" cellspacing="0" border="0" class="k-t4-heading">
				<tr>
					<td class="k-tl4"><img src="/images/spacer.gif" width="16" height="51" alt=""></td>
					<td class="k-tr4 heading_text_4" width="100%">GIỎ HÀNG</td>
				</tr>
			</table>
		</td>
	</tr>
	<tr>
		<td>
			<table width="100%" cellpadding="0" cellspacing="0" border="0">
				<tr>
					<td class="tall-l4"><img src="/images/spacer.gif" width="20" height="1" alt=""></td>
					<td class="tall-m4" width="100%">
						<div style="padding: 1 0 10 0;width:98%;margin: 1px;">
							<table border="0" cellpadding="0" cellspacing="0" width="100%" style="font:bold 11px/22px Tahoma;">
								<tr><td style="border-bottom: 1px solid #000000"><span class="f8 fb fore-red">{if $smarty.session.cart.product_count != ''}{$smarty.session.cart.product_count}{else}0{/if}&nbsp;Sản phẩm</span></td><td class="t-right" style="border-bottom: 1px solid #000000"><span class="f8 fb fore-red">{number_format number=$smarty.session.cart.total_price}&nbsp;VND</span></td></tr>
							</table>
							<table border="0" cellpadding="0" cellspacing="0" width="100%" style="font:bold 11px/20px Tahoma;">
								{foreach from=$smarty.session.cart item=product}
								{if $product.id != ''}
								<tr><td valign="top"><span>{$product.quantity}&nbsp;x&nbsp;</td><td><a href="/sanpham/{$product.id}/chitiet" class="side-cart">{$product.name}</a></span></td></tr>
								{/if}
								{/foreach}
								{if $smarty.session.cart.product_count > 0}
								<tr><td class="t-right" colspan="2"><a href="/giohang/xem">Cập nhật</a>&nbsp;|&nbsp<a href="/thanhtoan">Thanh toán</a></td></tr>
								{/if}
							</table>
						</div>
					</td>
					<td class="tall-r4"><img src="/images/spacer.gif" width="20" height="1" alt=""></td>
				</tr>
			</table>
		</td>
	</tr>
	<tr>
		<td><table width="100%" cellpadding="0" cellspacing="0" border="0">
			<tr>
				<td><img src="/images/k-bl5.gif" alt=""></td>
				<td class="tall-b4" width="100%"><br style="line-height:10px"></td>
				<td><img src="/images/k-br5.gif" alt=""></td>
			</tr>
		</table></td>
	</tr>
</table><br>
<table width="100%" cellpadding="0" cellspacing="0" border="0">
	<tr>
		<td>
			<table width="100%" cellpadding="0" cellspacing="0" border="0" class="k-t4-heading">
				<tr>
					<td class="k-tl4"><img src="/images/spacer.gif" width="16" height="51" alt=""></td>
					<td class="k-tr4 heading_text_4" width="100%">TÌM KIẾM</td>
				</tr>
			</table>
		</td>
	</tr>
	<tr>
		<td>
			<table width="100%" cellpadding="0" cellspacing="0" border="0">
				<tr>
					<td class="tall-l4"><img src="/images/spacer.gif" width="20" height="1" alt=""></td>
					<td class="tall-m4" width="100%">
						<form style="padding: 0" class="t-left" method="post" action="/timkiem">
							<input type="text" style="width: 135px; border: 1px solid #afb51a" name="txtKey" />
							<input type="image" border="0" title=" Tìm nhanh " alt="Tìm nhanh" src="/images/languages/vietnam/buttons/button_quick_find.gif">
							<br><span class="f8">Dùng từ khóa để tìm nhanh sản phẩm</span>
						</form>
					</td>
					<td class="tall-r4"><img src="/images/spacer.gif" width="20" height="1" alt=""></td>
				</tr>
			</table>
		</td>
	</tr>
	<tr>
		<td><table width="100%" cellpadding="0" cellspacing="0" border="0">
			<tr>
				<td><img src="/images/k-bl5.gif" alt=""></td>
				<td class="tall-b4" width="100%"><br style="line-height:10px"></td>
				<td><img src="/images/k-br5.gif" alt=""></td>
			</tr>
		</table></td>
	</tr>
</table><br>
<table width="100%" cellpadding="0" cellspacing="0" border="0">
	<tr>
		<td>
			<table width="100%" cellpadding="0" cellspacing="0" border="0" class="k-t4-heading">
				<tr>
					<td class="k-tl4"><img src="/images/spacer.gif" width="16" height="51" alt=""></td>
					<td class="k-tr4 heading_text_4" width="100%">HỖ TRỢ THANH TOÁN</td>
				</tr>
			</table>
		</td>
	</tr>
	<tr>
		<td>
			<table width="100%" cellpadding="0" cellspacing="0" border="0">
				<tr>
					<td class="tall-l4"><img src="/images/spacer.gif" width="20" height="1" alt=""></td>
					<td class="tall-m4" width="100%"><table width="100%" cellpadding="0" cellspacing="0" border="0">
						{foreach from=$BankList item=bank}
						<tr>
							<td style="padding: 10px 0"><img src="/images/banks/{$bank.image}" border="0" alt="{$bank.bank_name}" title="{$bank.bank_name}"></td>
						</tr>
						<tr>
							<td style="font-size: 14px;padding-left:5px;"><b><span title="Tên chủ tài khoản {$bank.bank_name}">{$bank.account_name}</span><br><font color="#ff0000" title="Số tài khoản {$bank.bank_name}">{$bank.account_no}</font></b></td>
						</tr>
						{/foreach}
						<tr>
							<th style="padding: 10px 0"><a href="http://baokim.vn" target="blank"><img src="/images/baokim_logo.jpg" width="160" border="0"></a></th>
						</tr>
						<tr>
							<th style="padding: 10px 0"><a href="http://nganluong.vn" target="blank"><img src="/images/ngan_luong_logo.png" width="160" border="0"></a></th>
						</tr></table>
					</td>
					<td class="tall-r4"><img src="/images/spacer.gif" width="20" height="1" alt=""></td>
				</tr>
			</table>
		</td>
	</tr>
	<tr>
		<td><table width="100%" cellpadding="0" cellspacing="0" border="0">
			<tr>
				<td><img src="/images/k-bl5.gif" alt=""></td>
				<td class="tall-b4" width="100%"><br style="line-height:10px"></td>
				<td><img src="/images/k-br5.gif" alt=""></td>
			</tr>
		</table></td>
	</tr>
</table>