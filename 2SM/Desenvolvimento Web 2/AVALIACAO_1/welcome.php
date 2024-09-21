<?php

include 'validarSessao.php';
?>

<!DOCTYPE html>
<html lang="pt_BR">

<head>
    <meta charset="UTF-8">
    <title>Bem vindo</title>
    <style type="text/css">
        body {
            font: 14px sans-serif;
            text-align: left;
        }

        h1 {
            margin-left: 20px;
        }

        .para {
            margin-left: 10px;
        }

        .wrapper {
            width: 350px;
            padding: 20px;
        }

        #center {
            display: flex;
            flex-direction: row;
            justify-content: left;
        }

        .page-header {
            display: flex;
            justify-content: space-between;


        }

        a {
            display: inline-block;
        }

        .btn-sair {
            margin-right: 10px;
            text-decoration: none;
        }

    </style>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.css">
</head>

<body>
    <div class="page-header">
        <h1>Olá, <b><?php echo htmlspecialchars($_SESSION["username"]); ?></b>
            <br><br>
            Bem vindo ao site
        </h1>
        <br>
        <a href="logout.php" class="btn-sair">Sair</a>
    </div>
    <p class="para">
        <a href="registrarItem.php" class="btn btn-primary">Registrar motos</a>
        <a href="consultarRegistros.php" class="btn btn-default">Consultar Registros</a>
        <br><br>

    </p>
</body>

</html>