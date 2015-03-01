<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>index</title>
</head>
<body>
<?php
/*
*To install the datebase with two form-message and reply
*message(id,username,email,content)
*reply(id,username,email.content)
*
*author:rccoder
*author-email:rccoder.net@gmail.com
*author-url:http://www.rccoder.net
**/
$conn = @mysql_connect("localhost", "root", "") or die("The connection of database is error!");
if($conn)
{
    mysql_query("set names 'UTF8'");
    if(!mysql_query("CREATE DATABASE message", $conn))
    {
        echo mysql_error();
    }
    try
    {
        mysql_select_db("message", $conn);
        $sql1 = "CREATE TABLE message
            (
                id int NOT NULL AUTO_INCREMENT,
                PRIMARY KEY(id),
                username varchar(255),
                email varchar(255),
                content text
            )";
        if(mysql_query($sql1, $conn))
        {
            echo "The form called message is created!";
        }
        else
        {
            echo "The form called message is not created!";
        }
        $sql2 = "CREATE TABLE reply
            (
                id int NOT NULL AUTO_INCREMENT,
                PRIMARY KEY(id),
                mid int(11),
                username varchar(255),
                email varchar(255),
                content text
            )";
        if(mysql_query($sql2, $conn))
        {
            echo "The form called reply is created!";
        }
        else
        {
            echo "The form called reply is not created!";
        }
    }
    catch(Exception $e)
    {
        echo $e->getMessage();
    }
}
?>
    
</body>
</html>
