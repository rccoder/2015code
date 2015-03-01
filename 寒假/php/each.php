<?php
$arr = array('name'=>'jiajia', 'age'=>20, 'sex'=>'F');
for($i = 0; $i < count($arr); $i++)
{
    $k = each($arr);
    echo $k['key'].'=>'.$k['value'].'<br />';
}
?>
