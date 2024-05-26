/*
2) Desenvolva uma aplicação para cadastrar cliente que
fará um crédito em até 12 vezes. Insira na estrutura
informações pertinentes ao cliente.
*/

#include <iostream>
using namespace std;

string solicitarInformacoes(string question);
int soliciarValores( string question);
int calcularParcelas( int qntParcelas, float valorTotalDeCompra);

int main() {
    
    struct compra {
        float  valorCompra;
        int qtdParcelas;
        int valorDaParcela;
    };
    
    struct cliente {
        string primeiroNome;
        string segundoNome;
        string CPF;
        compra CompraRealizada;
    };

    cliente novoCliente;

    novoCliente.primeiroNome = solicitarInformacoes("Qual e o seu nome: ");
    novoCliente.segundoNome = solicitarInformacoes("Qual e o seu segundo: ");
    novoCliente.CPF = solicitarInformacoes("Qual e o seu CPF: ");

    novoCliente.CompraRealizada.valorCompra = soliciarValores("Qual e o valor total: ");
    novoCliente.CompraRealizada.qtdParcelas = soliciarValores("Qual e a quantidade de parcelar entre 0 e 12");
    novoCliente.CompraRealizada.valorDaParcela = calcularParcelas(novoCliente.CompraRealizada.qtdParcelas,  novoCliente.CompraRealizada.valorCompra);

    cout 
        << endl 
        << "Seu nome e: " << novoCliente.primeiroNome << " " << novoCliente.segundoNome << endl 
        << "Seu CPF e: " << novoCliente.CPF << endl
        << "o valor total de compra e : " << novoCliente.CompraRealizada.valorCompra << endl
        << "o valor total de parcela : " << novoCliente.CompraRealizada.qtdParcelas << endl
        << "o valor por parcela e : " << novoCliente.CompraRealizada.valorDaParcela 
        << endl ;

    return 0;
}

string solicitarInformacoes(string question){
    string reposta;
    cout << endl  << question << endl;
    cin >> reposta;
    return reposta;
};


int soliciarValores( string question ) {
    int reposta;
    cout << endl  << question << endl;
    cin >> reposta;
    return reposta;
}

int calcularParcelas( int qntParcelas, float valorTotalDeCompra) {
    return valorTotalDeCompra / qntParcelas;
};