<select class="w180" name="{$clientName}" id="{$clientName}">
{if $isIncludeRoot==1}<option value="0">Root Category</option>{/if}
{foreach from=$Categories_List item=category}
<option value="{$category.categories_id}"{if $category.categories_id==$selected_id} selected="selected"{/if}>{$category.categories_name}</option>
{/foreach}
</select>