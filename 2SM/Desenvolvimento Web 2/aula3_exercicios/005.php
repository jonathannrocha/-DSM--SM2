<?php
/*
Escreva um script que imprima qual o maior número.
Use IF .. ELSE
*/
$a = 10;
$b = 1;
$c = 40;

$valores = array( $a, $b, $c);
$auxMaior = "";
for( $i = 0; $i < count( $valores); ++$i) {
    if( $i == 0 ) {
        $auxMaior = $valores[0];
    } else {
        if ( $valores[$i] > $auxMaior) {
            $auxMaior = $valores[$i];
        }
    }
}
echo 'Maior valor ', $auxMaior;


