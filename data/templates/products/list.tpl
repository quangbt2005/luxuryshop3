  {if $total_products > 0}
  <div class="wrapper" style="width: 715px; margin-left: 1px;">
  {TitleBox title=$cat_name}
    {foreach from=$Product_List item=product}
    <div class="product">
      {if $product.empty != 'true'}
      <div style="background-color: black;" class="image_and_name_and_intro">
        <div class="image" style="background-color: black;"><a title="{$product.products_name}" href="/sanpham/{$product.products_id}/chitiet"><img src="/product_thumb.php?f={$product.products_image}&w=auto&h=180&ma=120&cx=120&cy=180&trsp=1" border="0" alt="{$product.products_name}"></a></div>
        <div class="name_and_intro" style="background-color: black;">
          <div class="product_name">{$product.products_name}</div>
          <div class="product_intro" style="background-color: black">{$product.products_intro}</div>
        </div>
      </div>
      <div class="price_and_button">
        <div class="product_price"><strong>{number_format number=$product.products_price}</strong></div>
        <div class="product_detail_button"><a href="/sanpham/{$product.products_id}/chitiet"><img src="/images/btn_detail.gif" border="0" alt="Chi tiết sản phẩm"></a></div>
      </div>
      {/if}
    </div>
    {/foreach}
  </div>
  <div class="clear"></div>
  {$pager}<div class="clear"></div>
  <div class="t-right" style="width: 713px;"><span class="f10"><font color="white">Hiển thị {$product_count} sản phẩm từ {$product_from} đến {$product_to} trong tổng số {$total_products} sản phẩm</font></span></div>
  {else}
  <div style="width: 715px; margin-left: 1px;">
  {TitleBox title=$cat_name}
  <div style="padding: 10px;"><h3>Không tìm thấy sản phẩm nào</h3></div>
  </div>
  {/if}