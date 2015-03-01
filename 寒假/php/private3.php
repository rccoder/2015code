<?php
class MyClass
{
    public function __construct()
    {
    }
    public function MyPublic()
    {
    }
    protected function MyProtected()
    {
    }
    private function MyPrivate()
    {
    }
    function Foo()
    {
        $this->MyPublic();
        $this->MyProtected();
        $this->MyPrivate();
    }
}

$myclass = new MyClass();
$myclass -> MyPublic();
$myclass -> MyProtected();
$myclass -> MyPrivate();
$myclass -> Foo();


class MyClass2 extends MyClass
{
    function Foo2()
    {
        $this->MyPublic();
        $this->MyProtected();
        $this->MyPrivated();
    }
}
$myclass2 = new MyClass2();
$myclass2->MyPublic();
$myclass2->Foo2();
?>
