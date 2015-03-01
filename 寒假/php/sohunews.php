<?php
$url = 'http://it.sohu.com/itguonei.shtml';
$furl = fopen($url, 'r');
if($furl)
{
    $content='';
    while(!feof($furl))
    {
        $content .= fgets($furl, 1024);
    }
}

$code = "/<h1>.<a href='(.*)' target='_blank'>(.*)<\/a>/sU";
preg_match_all($code, $content, $urlrr);
foreach($urlrr[1] as $k=>$v)
{
    echo "<a herf=$v>".$urlrr[2][$k]."<br/>"."</a>";
    echo "&nbsp;&nbsp".$urlrr[1][$k]."<br/>";
    echo "<hr>";
}
?>
