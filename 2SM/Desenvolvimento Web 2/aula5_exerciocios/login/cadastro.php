<?php
session_start();

include "header.php";

if($_SERVER["REQUEST_METHOD"] == "POST"){
    $nome = $_POST['nome'];
    $cpf = $_POST['cpf'];

    $filename = "./data/registroUsuario.txt";

    if(!file_exists($filename)) {
        $handle = fopen($filename, "w");
    }

    $handle = fopen($filename, "a");

    fwrite($handle, $nome );
    fwrite($handle,  " | "   );
    fwrite($handle,  $cpf   );
    fwrite($handle, "\n" );
    fflush($handle);
    fclose($handle);
}


?>
 
<!DOCTYPE html>
<html lang="pt_BR">
<head>
    <meta charset="UTF-8">
    <title>Cadastro</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.css">
    <style type="text/css">
        body{ font: 14px sans-serif; text-align: center; }
    </style>
</head>
<body>
    <div class="page-header">
        <h1>Olá, <b> <?php echo htmlspecialchars($_SESSION["username"]); ?> </b>   </h1>      
        <h3>vamos novos Usuários?</h3>
    </div>
    <div style="width: 70%; margin:auto; text-align:center">
      <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
              <div class="form-group" style="    text-align: left;" >
                  <label>Nome</label>
                  <input type="text" id="nome" name="nome" placeholder="insira seu nome" class="form-control">
                  <span class="help-block"></span>
              </div>    
              <div class="form-group"  style="text-align: left;">
                  <label>CPF</label>
                  <input type="text" id="'cpf'" name="cpf" placeholder="Insira seu CPF" class="form-control">
                  <span class="help-block"></span>
              </div>
              <div class="form-group">
                  <input style="width: 100%;" type="submit" class="btn btn-primary" value="Acessar">
              </div>
      </form>
    </div>
</body>
</html>