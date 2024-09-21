<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    session_start();
    if ($_POST['username'] == 'portaria' and $_POST['password'] == 'FatecAraras') {
        $_SESSION['loggedin'] = TRUE;
        $_SESSION["username"] = 'portaria';
        header("location: welcome.php");
    } else {
        $_SESSION['loggedin'] = FALSE;
    }
}
?>

<!DOCTYPE html>
<html lang="pt_BR">

<head>
    <meta charset="UTF-8">
    <title>Portaria online</title>
    <style type="text/css">
        body {
            font: 14px sans-serif;
            text-align: left
        }

        h2 {
            margin-left: 10px;
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
    </style>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.css">
</head>

<body>
    <div>
        <h2>Acessar</h2>
        <p class="para">Favor inserir login e senha.</p>
        <div id="center">
            <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post" class="wrapper">
                <div class="form-group">
                    <label>Username</label>
                    <input type="text" name="username" class="form-control" value="portaria">
                    <span class="help-block"></span>
                </div>
                <div class="form-group">
                    <label>Password</label>
                    <input type="password" name="password" class="form-control" value="FatecAraras">
                    <span class="help-block"></span>
                </div>
                <div class="form-group">
                    <input type="submit" class="btn btn-primary" value="Acessar">
                </div>
            </form>
        </div>
    </div>
</body>

</html>