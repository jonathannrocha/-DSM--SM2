<?php


include 'validarSessao.php';
?>
<!DOCTYPE html>
<html lang="pt_BR">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Cadastro</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.css">
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
            margin-left: 10px;
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
</head>

<body>
    <h1>Cadastro de carros</h1>
    <div id="center">
        <form action="salvarInfos.php" method="post">
            <div class="form-group">
                <label>Nome do aluno</label>
                <input type="text" name="nome" class="form-control">
                <span class="help-block"></span>
            </div>
            <div class="form-group">
                <label>RA</label>
                <input type="text" name="RA" class="form-control">
                <span class="help-block"></span>
            </div>
            <div class="form-group">
                <label>Placa</label>
                <input type="text" name="placa" class="form-control">
                <span class="help-block"></span>
            </div>

            <div class="form-group">
                <p>Qual o tipo de veículo:</p>
                <div></div>
                 <input type="radio" id="moto" name="tipo_vei" value="Carro">
                <label for="tipo_moto">Carro</label>
                <input type="radio" id="carro" name="tipo_vei" value="Moto">
                <label for="tipo_carro">Moto</label>
                
            </div>
            <div class="form-group">
                <input type="submit" class="btn btn-success" value="Cadastrar">
                <a href="welcome.php" class="btn btn-primary">Voltar</a>
            </div>
        </form>
    </div>
</body>

</html>