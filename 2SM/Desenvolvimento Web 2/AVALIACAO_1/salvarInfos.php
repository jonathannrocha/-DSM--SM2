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
        body{ font: 14px sans-serif; text-align: center;}
        .wrapper{ width: 350px; padding: 20px; }
    </style>
</head>
<body>
         <?php
            $nome = $_POST['nome'];
            $ra = $_POST['RA'];
            $placa = $_POST['placa'];
            $tipo_carro = $_POST['tipo_vei'];

            if( $tipo_carro == 'Carro') {
                $filename = "./registros/carros.txt";
            } else {
                $filename = "./registros/motos.txt";
            }
             
            
            if(!file_exists($filename)) {
                $handle = fopen($filename, "w");
            }
        
            $handle = fopen($filename, "a");
        
            fwrite($handle, $nome );
            fwrite($handle,  " | "   );
            fwrite($handle,  $ra   );
            fwrite($handle,  " | "   );
            fwrite($handle,  $placa  );
            fwrite($handle, "\n" );
            fflush($handle);
            fclose($handle);

            header('location:welcome.php')
          

          
        ?> 
</body>
</html>