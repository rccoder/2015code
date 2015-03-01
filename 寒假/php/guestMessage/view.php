<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>view</title>
</head>
<body>
	<?php 
	include_once "conn.php";
	include_once "conn.php";
	
	$id = $_GET['id']
	$sql = "SELECT * FROM message where id = '$id'";
	$query = mysql_query($sql);
	$rs = mysql_fetch_array($query);
	 ?>
	 <table>
	 	<tr>
	 		<td><a href="view.php?id=<?php echo $rs['id']?>"><?php echo $rs['username']?></a>&nbsp;&nbsp;<a href="mailto:<?php echo $rs['email']?>">E-mail</a>&nbsp;&nbsp;<a href="#reply"I want to Reply></a></td>
	 	</tr>
	 	<tr>
	 		<td><?php echo $rs['content']?></td>
	 	</tr>
	 </table>
	 <hr>
	 <?php
	 	$sql = "SELECT * FROM reply where mid='$id'";
	 	$query = mysql_query($sql);
	 	$nums = mysql_num_rows($query);
	 	if(0 != $nums)
	 	{
	 		while($replyRS = mysql_fetch_array($query))
	 		{
	 			?>
	 <table>
	 	<tr>
	 		<td><?php echo $replyRS['username']?>&nbsp;&nbsp;<a href="mailto:<?php echo $replyRS['email']?>">E-mail</a></td>
	 	</tr>
	 	<tr>
	 		<td><?php echo $replyRS['content']?></td>
	 	</tr>
	 </table>
	 <br>
	 <?php 
	 		}
	 	}
	 	else
	 	{
	 		echo "There is no reply!";
	 	}
	 ?>
	 <hr>
	 <a name="#reply">I want to Reply</a>
	<form action="" method="post">
		<input type="hidden" value="<?php echo $rs['id'];?>" name="mid">
		<table>
			<tr>
				<td>Username:</td>
				<td><input type="text" name="username" /></td>
			</tr>
			<tr>
				<td>E-mail:</td>
				<td><input type="text" name="email" /></td>
			</tr>
			<tr>
				<td>Content:</td>
				<td><textarea name="content"></textarea></td>
			</tr>
			<tr>
				<td><input type="submit" value="Submit" /></td>
			</tr>
		</table>
	</form>
	<?php
$username = $_POST['username'];
	$email = $_POST['email'];
	$content = $_POST['content'];
	$mid = $_POST['mid']
	$sql = "INSERT INTO reply (username, email, content) VALUES ('$username', '$email', '$content')";
	echo $sql;
	$result = mysql_query($sql);
	if($result)
	{
		echo "<script type='text/javascript'>alert('Replyed Successed!');location.href='view.php?id=".$_POST['mid']."';</script>";
	}
	else
	{
		echo "<script type='text/javascript'>alert('Replyed Failed!');location.href='view.php?id=".$_POST['mid']."';</script>"
	}
	if(empty($_GET['id']))
	{
		die("Error");
	}
?>
</body>
</html>