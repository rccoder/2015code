<?php
function deleteDir($dir)
{
    $handle = @opendir($dir);
    readdir($handle);
    readdir($handle);
    while(false !== ($file = readdir($handle)))
    {
        $file = $dir.DIRECTORY_SEPARATOR.$file;

        if(is_dir($file))
        {
            rmdir($file);
        }
        else
        {
            if(@unlink($file))
            {
                echo '文件'.$file.'删除成功';
            }
            else
            {
                echo '文件'.$file.'删除失败';
            }
        }
    }
    if(rmdir($dir))
    {
        echo '目录'.$dir.'删除成功';
    }
    else
    {
        echo '目录'.$dir.'删除失败';
    }
}

$dir = 'test';
deleteDir($dir);
unlink('test');
?>
