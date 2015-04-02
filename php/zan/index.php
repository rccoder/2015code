<!DOCTYPE html>
<html>
<head lang="en">
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no" />
    <script src="http://libs.baidu.com/jquery/1.11.1/jquery.min.js"></script>
    <link rel="stylesheet" type="text/css" href="css/bootstrap.min.css"/>
    <link rel="stylesheet" href="style.css">
    <meta charset="UTF-8">
    <title>纪马祖光院士</title>
</head>
<body>
    <div class="word">
        <p>以德激光——纪马祖光院士</p>
    </div>
<div class="row main">

    <div class="col-md-offset-1 col-md-4">
    <img id='person' src='images/person3.jpg'/>
    </div>
    
    <div class="col-md-offset-2 col-md-4 info">
    <div class="trans">
    <p><strong>马祖光</strong><br\>
        (1928.4.11-2003.7.15)<br/>
        光电子技术专家<br/>
        出生于北京<br/>
        1950毕业于青岛山东大学物理系,<br>
        1953哈尔滨工业大学物理系研究生毕业。<br/>
        哈尔滨工业大学教授<br/>
        长期从事激光介质光谱、新型可调谐激光和非线性光学及应用研究.<br/>
        对光电子应用进行了探索性研究.<br/>
        2001年当选中国科学院院士。<br>
    </p>
    </div>
    
    <button id="bt" type="button" class="btn btn-warning">点击献花</button>
    <?php 

include_once('conf.php');
$sql = mysql_query("select * from love");
while($row = mysql_fetch_array($sql)){
    $count = $row['count'];
 ?>
 <p class='new'style="position: relative;
            left: 30%;
            font-size: 0.75em;">已有<aa style="color: red;"><?php echo $count ?></aa>朵花</p>
 <?php } ?>
    

    </div>
</div>
<script>
 $(function(){
    $('#bt').click(function(){
        var love = $('p aa');
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

</body>
</html>