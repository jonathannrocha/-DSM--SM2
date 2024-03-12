<?php
/*
Escreva um script que imprima qual o maior número.
Use IF
*/
$a = 10;
$b = 1;
$c = 40;


$valores = array( $a, $b, $c);
$auxMaior = $valores[0];
for( $i = 0; $i < count( $valores); ++$i) {
    if( $valores[$i] > $auxMaior) {
        $auxMaior = $valores[$i];
    }
}
echo 'Maior valor ', $auxMaior;

