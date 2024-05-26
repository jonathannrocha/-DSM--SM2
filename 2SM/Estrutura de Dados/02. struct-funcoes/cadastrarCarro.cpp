/*
1) Desenvolva uma aplicação para cadastrar carro. Insira
na estrutura informações pertinentes ao carro.
*/

#include <iostream>

using namespace std; 

int main() {

    struct carro {
        string marca;
        string modelo;
        int anoFabricacao;
        string cor;
    };

    carro novoCarro;

    cout  << endl << "Insira a marca do carro: " << endl;
    cin >> novoCarro.marca;

    cout  << endl << "Insira o modelo do carro: " << endl;
    cin >> novoCarro.modelo;

    cout  << endl << "Insira o ano de fabricacao do carro: " << endl;
    cin >> novoCarro.anoFabricacao;

    cout  << endl << "Insira a cor do carro: " << endl;
    cin >> novoCarro.cor;

    
    cout 
        << "A marca do carro e " << novoCarro.marca 
        << ", o modelo do carro e " << novoCarro.modelo 
        << ", o ano de fabricacao e " << novoCarro.anoFabricacao 
        << " e a cor " << novoCarro.cor;


    return 0;
}