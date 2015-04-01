<?php 
include_once('conf.php');
$addsql = "update love set count=count+1";
if($query = mysql_query($addsql)){
	
}
$searchsql = mysql_query("select * from love");
if($row = mysql_fetch_array($searchsql)){
	$count = $row['count'];
	echo $count;
}
 ?>