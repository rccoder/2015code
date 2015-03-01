i<?php
class animal{
    public $name="";
    public $color="";
    public $age="";
    function getInfo()
    {
        return $this->name;
    }
    function setInfo()
    {
        return $this->name;
    }
}
$pig = new animal();
$pig->setInfo("PIG");
$name=$pig->getInfo();
echo $name;
?>
