<?php
session_start();

include "header.php";

?>
 
<!DOCTYPE html>
<html lang="pt_BR">
<head>
    <meta charset="UTF-8">
    <title>Welcome</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.css">
    <style type="text/css">
        body{ font: 14px sans-serif; text-align: center; }
    </style>
</head>
<body>
    <div style="display: flex;flex-direction:column;text-align: left;">
    <div class="page-header">
        <h1>Olá, <b><?php echo htmlspecialchars($_SESSION["username"]); ?>
        <br>
        </b>.Benvindo ao site.</h1>
    </div>
    <p>
        <a href="cadastro.php" class="btn btn-primary">Cadastro Pessoas</a>
        <br><br>
        <a href="logout.php" class="btn btn-danger">Sair da conta</a>
    </p>
    </div>
    
</body>
</html>