<?php
function copyDir($dirFrom, $dirTo)
{
    if(is_file($dirTo))
    {
        die ('无法建立目录'.$dirTo);
    }
    if(!file_exists($dirTo))
    {
        mkdir($dirTo);
    }
    $handle = opendir($dirTo);
    readdir($handle);
    readdir($handle);

    while(false !== ($file = readdir($handle)))
    {
        $fileForm = $dirFrom.DIRECTORY_SEPARATOR.$file;

        $filrTo = $dirTo.DIRECTORY_SEPARATORY.$file;

        if(is_dir($filrFrom))
        {
            copyDir($fileFrom, $fileTo);
        }
        else
        {
            @copy($fileFrom, $fileTo);
        }
    }

}
copy('test', 'test_01');
?>
