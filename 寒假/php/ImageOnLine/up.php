<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>up-Image OnLine</title>
</head>
<body>
	<script language="javascript">
		function judge(theForm)
		{
			if(theForm.upfile.value == "")
			{
				alert("Please select the file!");
				theForm.upfile.focus();
				return false;
			}
			if(theForm.content.value == "")
			{
				alert("Please input the description of the image!");
				theForm.content.focus();
				return false;
			}
			if(theForm.content.value.length > 60)
			{
				alert("The content is too large! Please delete something!");
				theForm.content.focus();
				return false;
			}
		}
		function view(img1, upfile)
		{
			if(upfile.value)
			{
				img1.src = upfile.value;
				img1.style.display = "";
				img1.border = 1;
			}
		}
	</script>
	<h1>Upfile</h1>
	<a href="index.php">Return To Index</a>
	<table>
		<form entype="multipart/form-data" method="post" action="up-handle.php" onsubmit="return judge(this)">
			<tr>
				<td>Choose the Image:</td>
				<td><input type="file" name="upfile" onchange=view(img1, this.form.upfile)></td>
			</tr>
			<tr>
				<td>Description:</td>
				<td><input type="text" name="content"></td>
			</tr>
			<tr>
				<td><input type="submit" value="Submit"></td>
				<td><input type="reset" value="Reset"></td>
			</tr>
			<tr>
				<td><img src="" id="img1" style="display:none"></td>
			</tr>
		</form>
	</table>
</body>
</html>