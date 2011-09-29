{if $product.products_id != ''}
<table width="100%" cellpadding="0" cellspacing="0" border="0" style="border: 2px solid #e6f3f3">
    <tr>
      <td style="padding: 10px 0 10px 10px;width:120px">
        <table cellpadding="0" cellspacing="0" border="0">
          <tr><td align="left"><img src="/product_thumb.php?f={$product.products_image}&w=auto&h=500&ma=280&cx=290&cy=510&trsp=1" width="290" border="0" vspace="0" hspace="0" style="padding:0;margin:0;float:left;" alt="{$product.products_name}"></td></tr>
        </table>
      </td>
      <td valign="top" style="padding: 0;width: 450px;" align="left">
        <table width="100%" cellpadding="0" cellspacing="0" border="0" align="left">
          <tr><td style="padding-top: 5px;height:38px;color:red" valign="top" align="left"><strong>{$product.products_name}</strong></td></tr>
          <tr><td style="padding: 5px 3px 5px 5px;height:130px;" valign="top" align="left">{$product.products_intro}</td></tr>
          <tr><td style="padding: 5px 3px 5px 5px;color: #00ff00;" valign="top" align="left"><strong>GIÁ: {number_format number=$product.products_price}</strong></td></tr>
        </table>
      </td>
    </tr>
    <tr>
      <td colspan="2" style="padding: 15px;" align="left"><div style="padding: 20px;border: 1px solid #cccccc;background-color: #456581;text-align: left">{$product.products_description}</div></td>
    </tr>
</table>
{else}
<p class="f20 fb">Không tìm thấy sản phẩm !</p>
<p><img src="/images/cry.gif"></p><br><br><br><br><br><br>
<div class="container t-right"><p><a href="/"><img border="0" width="110" title=" Quay lại " alt="Quay lại" src="/images/languages/vietnam/buttons/button_back.gif"></a></p></div>
{/if}
<br /><br />
<span class="bigtitle">Sản phẩm cùng danh mục</span>
<div id="makeMeScrollable">
  <div class="scrollingHotSpotLeft"></div>
  <div class="scrollingHotSpotRight"></div>
  <div class="scrollWrapper">
    <div class="scrollableArea">
      {foreach from=$OtherProductsList item=other}
      <a href="/sanpham/{$other.products_id}/chitiet" title="{$other.products_name} {number_format number=$other.products_price}VND"><img src="/product_thumb.php?f={$other.products_image}&w=auto&h=120&ma=150&cx=150&cy=150&trsp=1" width="150" height="150" border="0"></a>
      {/foreach}
    </div>
  </div>
</div>
