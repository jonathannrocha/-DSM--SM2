/*
2) Escreva um programa com uma função chamado
soma. Este programa deve somar todos os valores entre
0 e n, onde n é o parâmetro passado para a função.
*/

#include <iostream>

using namespace std;

int somar( int valor);

int main(){

    int valorReposta;
    
    cout << "Informe um numero maior que zero:" << endl;
    cin >> valorReposta;

     int valorSoma = somar(valorReposta);

     cout << "[SOMA]" << valorSoma;
    return 0;
}

int somar( int valor) {

    if( valor <= 1 ) {
        return valor;
    } 

    return valor + somar( valor -1);
}
