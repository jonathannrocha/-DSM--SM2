<?php
/*
Crie uma função que demonstre 
 - Passagem por valor.
 - Passagem por referência.

 
*/


// por valor => duplicata da variavel
// por referência => o endereço da variavel

$valor_referencia=2;
$valor_valor=2;

function parametroPorReferencia(&$valor) {
    $valor = $valor+1;
}

parametroPorReferencia($valor_referencia);


echo 'Referência: ' , $valor_referencia, '<br>';

function parametroPorValor( $valor) {
    $valor =  $valor+1;
}

echo parametroPorValor($valor_valor);
echo 'Valor: ' , $valor_valor, '<br>';

