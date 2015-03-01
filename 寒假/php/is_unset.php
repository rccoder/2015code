<?php
class animal
{
    private $animal;
    private $color;
    private $age;

    private function __get($property_name)
    {
        echo '在直接获取私有属性值的时候，自动调用了__get()方法';
        if(isset($this->property_name))
        {
            return ($this->property_name);
        }
        else
        {
            return(NULL);
        }
    }
    private function __set($property_name, $value)
    {
        echo '在直接设置私有属性的时候，自定调用了__set()的方法';
        $this->$property_name = $value;
    }
    private function __isset($nm)
    {
        echo 'isset函数测定私有成员的时候自动调用';
        return isset($this->$nm);
    }
    private function __unset($nm)
    {
        echo '在外部使用unset函数删除私有成员变量的时候自动调用';
        unset($this->$nm);
    }
}
$pig = new animal();
$pig->name = 'This is a animal name';
echo var_dump(isset($pig->name));
echo $pig->name;
unset($pig->name);
echo($pig->name);
?>
