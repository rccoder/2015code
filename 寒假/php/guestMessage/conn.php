<?php
/*
*the connection of datebase and selected the form called message
*
*author:rccoder
*author-email:rccoder.net@gmail.com
*author-url:http://www.rccoder.net
**/
$conn = @mysql_connect("localhost", "root", "") or die("数据库连接失败");
@mysql_select_db("message") or die("没有找到数据库");
mysql_query("set names 'UTF8'");
?>
