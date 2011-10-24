<?php /* Smarty version 2.6.20, created on 2011-10-24 07:07:42
         compiled from products/list.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'TitleBox', 'products/list.tpl', 3, false),array('function', 'number_format', 'products/list.tpl', 15, false),)), $this); ?>
  <?php if ($this->_tpl_vars['total_products'] > 0): ?>
  <div class="wrapper" style="width: 715px; margin-left: 1px;">
  <?php echo smarty_title_box(array('title' => $this->_tpl_vars['cat_name']), $this);?>

    <?php $_from = $this->_tpl_vars['Product_List']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['product']):
?>
    <div class="product">
      <?php if ($this->_tpl_vars['product']['empty'] != 'true'): ?>
      <div style="background-color: black;" class="image_and_name_and_intro">
        <div class="image" style="background-color: black;"><a title="<?php echo $this->_tpl_vars['product']['products_name']; ?>
" href="/sanpham/<?php echo $this->_tpl_vars['product']['products_id']; ?>
/chitiet"><img src="/product_thumb.php?f=<?php echo $this->_tpl_vars['product']['products_image']; ?>
&w=auto&h=180&ma=120&cx=120&cy=180&trsp=1" border="0" alt="<?php echo $this->_tpl_vars['product']['products_name']; ?>
"></a></div>
        <div class="name_and_intro" style="background-color: black;">
          <div class="product_name"><?php echo $this->_tpl_vars['product']['products_name']; ?>
</div>
          <div class="product_intro" style="background-color: black"><?php echo $this->_tpl_vars['product']['products_intro']; ?>
</div>
        </div>
      </div>
      <div class="price_and_button">
        <div class="product_price"><strong><?php echo smarty_number_format(array('number' => $this->_tpl_vars['product']['products_price']), $this);?>
</strong></div>
        <div class="product_detail_button"><a href="/sanpham/<?php echo $this->_tpl_vars['product']['products_id']; ?>
/chitiet"><img src="/images/btn_detail.gif" border="0" alt="Chi tiết sản phẩm"></a></div>
      </div>
      <?php endif; ?>
    </div>
    <?php endforeach; endif; unset($_from); ?>
  </div>
  <div class="clear"></div>
  <?php echo $this->_tpl_vars['pager']; ?>
<div class="clear"></div>
  <div class="t-right" style="width: 713px;"><span class="f10"><font color="black">Hiển thị <?php echo $this->_tpl_vars['product_count']; ?>
 sản phẩm từ <?php echo $this->_tpl_vars['product_from']; ?>
 đến <?php echo $this->_tpl_vars['product_to']; ?>
 trong tổng số <?php echo $this->_tpl_vars['total_products']; ?>
 sản phẩm</font></span></div>
  <?php else: ?>
  <div style="width: 715px; margin-left: 1px;">
  <?php echo smarty_title_box(array('title' => $this->_tpl_vars['cat_name']), $this);?>

  <div style="padding: 10px;"><h3>Không tìm thấy sản phẩm nào</h3></div>
  </div>
  <?php endif; ?>