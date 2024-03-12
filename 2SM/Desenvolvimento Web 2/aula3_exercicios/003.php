<?php
/*
Escreva um script que imprima qual o maior número.
Converter variáveis strings em inteiros
Use IF
*/
$a = "10";
$b = "1";


print converter($a);
echo '<br>';
print converter($b);
echo '<br>';

function converter( $valor) {
    if( is_numeric($valor)) {
        return (int)$valor;
    }
    return "Não é um inteiro!";
}