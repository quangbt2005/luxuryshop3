<?php
// ---------------------------------------------------------------------------------------------- //
function ListBankAccountForAdmin()
{
  $SQL = 'SELECT * FROM bank_account';

  $List = P_MySQL_Real_SELECT_GetArrayIndex( $SQL );

  if( empty( $List[0] ) == FALSE )
  {
    return $List;
  }

  return array();
}
// ---------------------------------------------------------------------------------------------- //
function ListBankAccountForFrontSite()
{
  $SQL = "SELECT * FROM bank_account WHERE active='1'";

  $List = P_MySQL_Real_SELECT_GetArrayIndex( $SQL );

  if( empty( $List[0] ) == FALSE )
  {
    return $List;
  }

  return array();
}
// ---------------------------------------------------------------------------------------------- //
?>