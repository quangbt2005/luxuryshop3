<div id="header_image"></div>
{if $smarty.session.admin.id != ''}
<div id="header_menu">
  <ul class="sf-menu">
    <li class="current">
      <a target="_blank" href="/home"><font color="lightgreen"><strong>Shop</strong></font></a>
    </li>
    <li class="current">
      <a href="/admin/dashboard">Dashboard</a>
    </li>
    <li>
      <a href="/admin/categories">Sản phẩm</a>
    </li>
    <li>
      <a href="/admin/shop/config">Cấu hình</a>
    </li>
  </ul>
</div>
{/if}