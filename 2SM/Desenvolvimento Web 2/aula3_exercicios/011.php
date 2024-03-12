<?php
/*
Faça o cálculo da média simples de 
$nota_1 e $nota_2.
Imprima a média simples.
Imprima a condição:
    Se a média menor ou igual a 4.9, reprovado.
    Se a média entre 5 e 7, recuperação.
    Se a média acima de 7, aprovado.

Crie uma função com o nome calculo_media.
Use tipagem estrita e limite os parâmetros a receber float.
*/
declare(strict_types=1);

$nota_1 = 9;
$nota_2 = 4;


$media = media(9,4);

if( $media > 7 ) {
    echo 'Aprovado';
} elseif( $media >= 5 and $media <= 7) {
    echo 'recuperacao';
} else {
    'echo reprovado';
}
 
function media( float $n1,$n2) {
    return ($n1+$n2)/2;
}





