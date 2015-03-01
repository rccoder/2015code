<?php
class animal
{
    private $name='';
    private $color='';
    private $age='';

    function __construct($name, $color, $age)
    {
        $this->name = $name;
        $this->color = $color;
        $this->age = $age;
    }

    function getInfo()
    {
        echo $this->name.'<br/>'.$this->color.'<br/>'.$this->age.'<br/>';
    }

    private function fly()
    {
        echo 'I can fly!'.'<br/>';
    }
}

$crow = new animal('wuya', 'black', '11');
echo $crow->name.'<br/>';
echo $crow->color.'<br/>';
echo $crow->age.'<br/>';
?>
