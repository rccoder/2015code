<?php
$info = array('name'=>'jiajia', 'age'=>18, 'sex'=>'F');
foreach($info as $value)
{
    echo $value.'<br/>';
}
echo '<hr>';
foreach($info as $key=>$value)
{
    echo $key.'=>'.$value.'<br/>';
}
?>
