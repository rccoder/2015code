<?php
class animal
{
    private $name;
    private $color;
    private $age;
    private function __get($property_name)
    {
        echo 'The __get is running!'.'<br>';
        if(isset($this->property_name))
        {
            return $this->property_name;
        }
        else
        {
            return (NULL);
        }
    }
    private function __set($property_name)
    {
        echo 'The __set is running!'；
            $this->property_name = $value;
    }
}

$pig = new animal();
$pig->name = 'Pig';
$pig->color = "White";
$pig->age = '11';
echo $pig->name.'<br>';
echo $pig->color.'<br>';
echo $pig->age.'<br>';
?>
