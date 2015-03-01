<?php
$time = strtotime('2015-1-1 11:11:11');
$last = $time + 30*24*60*60;
echo date('Y-m-d:i:s', $last);
?>
<hr>
<?php
$tm = time();
echo date('Y-M-D H:I:S A',$tm);
echo date('y-m-d h:i:s a', $tm);
?>
