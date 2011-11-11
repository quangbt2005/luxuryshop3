<?php
/**************************************************************************************************/
/* Created on Nov 30, 2008                                                                        */
/**************************************************************************************************/
// ---------------------------------------------------------------------------------------------- //
function CountChatForFrontEnd(){
  $query  = "SELECT COUNT(1) FROM chat WHERE deleted='0'";
  $Result = P_MySQL_Real_SELECT( $query ) ;

  if(!empty($Result[0]))
  {
    return $Result[0] ;
  }
  return 0 ;
}
// ---------------------------------------------------------------------------------------------- //
function ListChatForFrontEnd($offset=0,$limit=DEFAULT_PAGER_LIMIT){
  $query  = "SELECT *,if((avatar is null) or (avatar=''),'noavatar.png',avatar) as showingavatar";
  $query .= " FROM chat WHERE deleted='0' ORDER BY createddate DESC LIMIT ";
  $query .= ($offset . ',' . $limit);
  return P_MySQL_Real_SELECT_GetArrayIndex($query);
}
// ---------------------------------------------------------------------------------------------- //
function ListChatForAdmin($limit=100){
  $query  = "SELECT * FROM chat ORDER BY createddate DESC LIMIT " . $limit;
  return P_MySQL_Real_SELECT_GetArrayIndex($query);
}
// ---------------------------------------------------------------------------------------------- //
function CountCustomerByCustomerCode($code=''){
  if($code != ''){
    $code = P_SQL_Quote($code);
    $query = "SELECT id FROM chatter_code WHERE code='" . $code ."' AND deleted='0'";
    $Result = P_MySQL_Real_SELECT( $query ) ;

    if(!empty($Result[0]))
    {
      return $Result[0] ;
    }
  }
  return 0 ;
}
// ---------------------------------------------------------------------------------------------- //
?>