/* 
1) Escreva um programa com uma função chamado
soma. Este programa deve somar todos os valores entre
0 e n, onde n é o parâmetro passado para a função.
*/

#include <iostream>
using namespace std;


void somar(int &valor);

int main() {

    int valor;

    cout << "Informe um numero maior que zero:" << endl;
    cin >> valor;
    
    somar(valor);

    cout << "[SOMA] O valor da soma é:" << valor << endl;

    return 0;
}

void somar(int &valor) {
    int auxValor=0;
    for( int x=valor; x >= 0; x--) { 
        auxValor += x;  
    }
    valor = auxValor;
}
