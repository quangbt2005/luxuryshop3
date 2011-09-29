<?php
/**************************************************************************************************/
/* Created on Nov 30, 2008                                                                        */
/**************************************************************************************************/
function DB_Insert($table, $params){
  global $P_MySQL_Connect;

  if( empty( $params ) || empty( $table ) ){
    return;
  }

  $query = 'INSERT INTO ' . $table . ' ';
  foreach($params as $key => $value){
    $fields[] = $key;
    $values[] = "'" . P_SQL_Quote($value) . "'";
  }

  $query .= '(' . implode(',', $fields) . ') ';
  $query .= 'VALUES(' . implode(',', $values) . ')';

  P_MySQL_Real_Exec($query);

  return @mysql_insert_id( $P_MySQL_Connect );
}
// ---------------------------------------------------------------------------------------------- //
function DB_Update($table, $conditions, $values, $valueIsExpression=false){
  if( empty( $values ) || empty( $table ) ){
    return;
  }

  $query_values = array();
  $query_conditions = array();
  $quoteMark = $valueIsExpression ? "" : "'";

  foreach($values as $key=>$value){
    $tmp = sprintf("%s=%s%s%s", $key, $quoteMark, P_SQL_Quote($value), $quoteMark);
    $query_values[] = $tmp;
  }
  if(!empty($conditions)){
    foreach($conditions as $key=>$value){
      $query_conditions[] = $key . "='" . P_SQL_Quote($value) . "'";
    }
  }

  $query  = 'UPDATE ' . $table . ' SET ' . implode(',', $query_values);
  if(!empty($conditions)){
    $query .= ' WHERE ' . implode(' AND ', $query_conditions);
  }

  P_MySQL_Real_Exec($query);
}
// ---------------------------------------------------------------------------------------------- //
function DB_Delete($table, $conditions){
  if( empty( $table ) ){
    return;
  }

  $query_values = array();
  $query_conditions = array();

  foreach($conditions as $key=>$value){
    $query_conditions[] = $key . "='" . P_SQL_Quote($value) . "'";
  }

  $query  = 'DELETE FROM ' . $table;
  $query .= ' WHERE ' . implode(' AND ', $query_conditions);

  P_MySQL_Real_Exec($query);
}
// ---------------------------------------------------------------------------------------------- //
?>
