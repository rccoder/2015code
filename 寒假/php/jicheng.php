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
}

class birds extends animal
{
    var $swing;
    function fly()
    {
        echo 'I can fly';
    }
}

$a = new birds('ying', 'white', '10');
$a->getInfo();
$a->fly();
?>
