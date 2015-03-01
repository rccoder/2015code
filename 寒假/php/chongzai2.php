<?php
class birds extends animal
{
    var $swing;
    function fly()
    {
        echo 'I can fly';
    }

    function getInfo()
    {
        animal:getInfo();
        echo $this->swing;
    }
}
?>
