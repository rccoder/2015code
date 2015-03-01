<?php
/*
 *define a class called 'MyClass'
 * */
class MyClass
{
    public $public = 'Public';
    protected $protected = 'Protected';
    private $private = 'Private';

    function printHello()
    {
        echo $this->public;
        echo $this->protected;
        echo $this->private;
    }
}

$obj = new MyClass();
echo $obj->public;
echo $obj->protected;
echo $obj->private;
$obj->printHello();

/*
 *define a class called MyClass2
 * */
class MyClass2 extends MyClass
{
    protected $protected = 'Protected2';
    function printHello()
    {
        echo $this->public;
        echo $this->protected;
        echo $this->private;
    }
}

$obj2 = new MyClass2();
echo $obj2->public;
echo $obj2->protected;
echo $obj2->private;
$obj2->printHello();
?>
