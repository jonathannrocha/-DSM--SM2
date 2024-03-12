<?php
/*
Descrubra se $numero é :
 - Divisível por 10
 - Divisível por 3
 - Se não é divisível por nenhum destes 

Imprimir mensagem na tela do número e as condições acima.
*/
$numero = 150;

$resto10 = $numero % 3;
$resto3 = $numero % 10;

if( $resto10 == 0) {
    echo 'É divisil por 10', '<br>';
} else {
    echo 'Não é divisivel por 10', '<br>';
}


if( $resto3 == 0) { 
    echo 'É divisil por 3', '<br>';
} else {
    echo 'Não é divisivel por 3', '<br>';
}



