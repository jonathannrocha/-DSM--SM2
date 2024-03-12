<?php
/*
Crie um script que percorra toda a $array, apresentando os valores.
Utilize foreach.
Adapte o código para exibir somente os valores inteiros.
Realize a soma dos números inteiros

Dica: https://www.php.net/manual/en/control-structures.foreach.php
*/ 
$array = [
    "n1" => 10,
    "n2" => 20,
    "n3" => 30,
    "n4" => 'oi mundo',
];

echo 'todos os valores: ';
foreach( $array as $chaveArray => $valores ) {
    echo  $valores, '<br>'; 
}

echo '<br>';
echo 'apenas inteiros: <br>';
foreach( $array as $chaveArray => $valores ) {
    if( is_numeric($valores)) echo $valores, '<br>'; 
}

echo '<br>';
echo 'soma: <br>';
$auxSoma=0;
foreach( $array as $chaveArray => $valores ) {
    if( is_numeric($valores)) $auxSoma+=$valores; 
}
echo $auxSoma;