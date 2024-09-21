<?php


include 'validarSessao.php';

function lerAquivo()
{
   

  
};

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
        }

        .page-header {
            display: flex;
            justify-content: space-between;


        }

        a {
            display: inline-block;
        }

        .cont {
            margin-left: 20px;
        }
    </style>
</head>

<body>

    <div class="page-header">
        <h1>Consultar registros
        </h1>
    </div>


    <div class="cont">
        <form method="post">
            <p>Qaul registros vamos visualizar:</p>
            <input type="radio" id="moto" name="tipo_vei" value="Carro">
            <label for="tipo_moto">Carro</label>
            <input type="radio" id="carro" name="tipo_vei" value="Moto">
            <label style="margin-bottom: 20px;" for="tipo_carro">Moto</label>
            <br>
            <input  class="btn" type="submit" name="button1" class="button" value="Consultar" />
            <a href="welcome.php" class="btn btn-primary">Voltar</a>
        </form>  
    </div>

    <?php

    if (array_key_exists('button1', $_POST)) {    
        if (array_key_exists('tipo_vei', $_POST)) {
            $tipoVeic = $_POST['tipo_vei'];
      
            if($tipoVeic=='Carro') {
                $fileName = 'registros/carros.txt';
            } else {
                $fileName = 'registros/motos.txt';
            }
        
            
            if(file_exists($fileName)) {

                echo "<br>","<br>";
                $conteudo = file_get_contents($fileName);
                echo nl2br($conteudo);
               
            }
        }
      
         
    }


    ?>

    <?php
    // $arquivo = 'carros.txt';
    // $conteudo = file_get_contents($arquivo);
    // echo nl2br($conteudo);
    ?>

</body>

</html>