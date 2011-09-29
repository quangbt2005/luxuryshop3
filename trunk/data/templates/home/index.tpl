  <div class="wrapper" style="width: 715px; margin-left: 1px;"><!-- New product -->
    {TitleBox title="&nbsp;Sản phẩm mới nhất"}
    {foreach from=$NewProducts item=product}
    <div class="product">
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
    </div>
    {/foreach}
  </div>