<?php
$info = array('name'=>'jiajia', 'age'=> 18, 'sex'=>'F');
while(list($key, $value) = each($info))
{
    echo $key.'=>'.$value.'<br/>';
}
?>
