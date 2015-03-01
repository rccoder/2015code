<?php
class animal
{
    public $name='';
    public $color='';
    public $age='';

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

    function __destruct()
    {
        echo 'Bye!'.$this->name;
    }
}

$pig = new animal('Pig', 'White', '10');
$pig->getInfo();
?>
