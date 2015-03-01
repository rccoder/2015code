<?php
class animal{
    public $name='';
    public $age='';
    public $color='';

    function __construct($name, $color, $age)
    {
        $this->name = $name;
        $this->color = $color;
        $this->age = $age;
    }

    function getInfo()
    {
        echo 'Name:'.$this->name.',Color:'.$this->color.',Age:'.$this->age.'<br/>';

    }
}

$pig = new animal('Pig', 'White', '10');
$pig->getInfo();
?>
