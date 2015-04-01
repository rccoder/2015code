<script src="http://libs.baidu.com/jquery/1.11.1/jquery.min.js"></script>
<?php 

include_once('conf.php');
$sql = mysql_query("select * from love");
while($row = mysql_fetch_array($sql)){
	$count = $row['count'];
 ?>
 <li><p><a href=""><?php echo $count ?></a></p></li>
 <?php } ?>

 <script>
 $(function(){
 	$('p a').click(function(){
 		var love = $(this);
 		$.ajax({
 			url: 'love.php',
 			type: 'get',
 			success:function(data){   
                love.html(data);   
                love.fadeIn(300); //渐显效果   
            }   
 		});	
 	})
 })
 </script>
