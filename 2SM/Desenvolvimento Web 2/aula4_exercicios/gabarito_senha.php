<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Adivinhando a senha</title>
</head>
<body>
<?php

$senha = $_POST['senha'];

if($senha == "JUBILEU") {
    echo("Parabéns, senha correta!!");
    die();
   return;
}  

echo "Senha errada!!";
    
$filename = "gabarito.txt";

if(!file_exists($filename)) {
    $handle = fopen($filename, "w");
}

$handle = fopen($filename, "a");


fwrite($handle, $senha );
fwrite($handle, "\n" );
fflush($handle);
fclose($handle);


?>
</body>
</html>
