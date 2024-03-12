<?php
/*
Variáveis 
*/

$variavel_1 = 'texto';
// Imprimir o valor a variável e o seu tipo
imprimirValor( $variavel_1, false);

$variavel_2 = 123;
// Imprimir o valor a variável e o seu tipo
imprimirValor( $variavel_2, true);

$variavel_3 = 1;
// Imprimir o valor a variável e o seu tipo
imprimirValor( $variavel_3, true);

$array = [
    "foo" => "bar",
    "bar" => "foo",
];
// Imprimir o valor a variável e o seu tipo

foreach( $array as  $arrayRecebido=> $valoresDoArray  ) {
    imprimirValor($valoresDoArray, true );
}

function imprimirValor($valor, $tipo) {
    print("[VALOR]::");
    print($valor);
  
    if( $tipo) {
        echo '<br>';
        print("[TIPO]::");
        var_dump($valor) ;
    }

    echo '<br>';
    echo '<br>';
}
 