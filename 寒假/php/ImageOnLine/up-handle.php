<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>up-handle-Image OnLine</title>
</head>
<body>
	<?php 
		$upfile = $_POST["upfile"];
		if($upfile == "none")
		{
			echo "No file!";
	?>
	<p>Click <a href="up.php">there</a> return</p>
	<?php
		}
		else
		{
			$filepath = "images/";
			$filename = $filepath.$_FILES[upfile][name];
			if(copy($upfile, $filename))
			{
				unlink($_FILES[upfile][tmp_name]);
				$datename = "data.dat";
				$myfile = file($datename);
				if($myfile[0] == "")
				{
					$fp = fopen($datename, "a+");
					fwrite($fp, "1||".$_FILES[upfile][name]."||".$_POST["content"]."||".date("Y-M-D")."\n");
					fclose($fp);
				}
				else
				{
					$temp = explode("||", $myfile[0]);
					$temp[0]++;
					$fp = fopen($datename, "r");
					$line_has = fread($fp, filesize("$datename"));
					fclose($fp);
					$fp = fopen($datename, "w");
					fwrite($fp, temp[0]."||".$_FILES[upfile][name]."||".$_POST["content"]."||".date("Y-M-D"."\n"));
					fwrite($fp, $line_has);
					fclose($fp);
				}
				echo "<p>"."Success!"."</p>";
				echo "<a href='index.php'>Return</a>";
			}
			else
			{
				echo "Failed!";
			}
		}
	 ?>
</body>
</html>