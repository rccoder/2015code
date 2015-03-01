<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>index</title>
</head>
<body>
<a href="#message">I want to say!</a><hr>
<?php
/*
*get the post and insert it into the message form
*
*author:rccoder
*author-email:rccoder.net@gmail.com
*author-url:http://www.rccoder.net
**/
include_once "conn.php";
if(!empty($_POST['username']))
{
	$username = $_POST["username"];
	$email = $_POST["email"];
	$content = $_POST["content"];
	$sql = "INSERT INTO message (username, email, content) values ('$username', '$email', '$content')";
	//echo $sql;
	$result = mysql_query($sql);
	if($result)
	{
		echo "<script>alert('Success!');location.href='index.php';</script>";
	}
	else
	{
		echo "<script>alert('Failed!');location.href='.index.php';</script>";
	}
}
else
{
}
?>
<?php
/*
*show the message with username and email
*
*author:rccoder
*author-email:rccoder.net@gmail.com
*author-url:http://www.rccoder.net
**/
$sql1 = "SELECT * FROM message";
//echo $sql1;
$query = mysql_query($sql1);
$nums = mysql_num_rows($query);
if(0 != $nums)
{
	while($rs = mysql_fetch_array($query))
	{
		?>
		<table>
			<tr>
				<td><a href="view.php?id=<?php echo $rs['id'];?>"><?php echo $rs['username'];?></a>&nbsp;&nbsp;<a href="mailto:<?php echo $rs['email'];?>">Email</a></td>	
			</tr>
			<tr>
				<td><?php echo $rs['content'];?></td>
			</tr>
		</table>
		<br>
		<?php
	}
}
	else
	{
		echo "There is no message!";
	}
		?>
<hr>
<a name="message"></a>
<form action="" method="post">
	<table border="0" width="500">
		<tr>
			<td width="100" align="right">Name：</td>
			<td><input type="text" name="username" value="" /></td>
		</tr>
		<tr>
			<td width="100" align="right">E-mail:</td>
			<td><input type="text" name="email" value="" /></td>
		</tr>
		<tr>
			<td width="100" align="right">Content:</td>
			<td><textarea name="content" id="" cols="30" rows="10" width="303"></textarea></td>
		</tr>
		<tr>
			<td colspan="2" align="center"><input type="submit"  valut="Submit" /></td>
		</tr>
	</table>
</form>
	
</body>
</html>

