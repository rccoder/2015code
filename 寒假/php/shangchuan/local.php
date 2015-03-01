<form action='' method='post' enctype='multipart/form-data'>
    <input type='hidden' name='MAX_FILE_SIZE' value='2000000'>
    选择文件:
    <input type='file' name='upfiles'>
    <input type="submit" value="上传">
</form>

<?php
    $file = "file/";
    $url = $file.$FILES["files"]["name"];
    if(move_uploaded_file($_FILES["file"]["tmp_name"], $url))
    {
        echo '文件上传成功';
        print_r($FILES);
    }
    else
    {
        echo '文件上传失败';
        print_r($FILES);
    }

?>
