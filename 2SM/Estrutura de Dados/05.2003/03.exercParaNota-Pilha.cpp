/*
 * Exercício para nota 01.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Aplicado em : 30/03/2024
 */

#include <iostream>

#define TAMANHO_PILHA 10

using namespace std;

struct Carro {
    string  placa;
    int     ano;
};

struct Pilha {
    Carro   data[TAMANHO_PILHA];
    int     contador;
};
/* Protótipos das funções. Desenvolver a partir da linha 59 */
void inicializar(Pilha *);
void estacionar(Pilha *, string, int);
void estacionar(Pilha *, Carro);
Carro sair(Pilha *);
void imprime_pilha(Pilha *);
void imprime_tudo(Pilha *);
int quantidade_vagas(Pilha);


int main() {
    Pilha estacionamento;
    inicializar(&estacionamento);
    Carro carro_comum;

    estacionar(&estacionamento,"ABC1234", 1999);
    carro_comum.placa = "DOW5782";
    carro_comum.ano = 2004;
    estacionar(&estacionamento, carro_comum);
    cout << "Quantidade de vagas " << quantidade_vagas(estacionamento) << endl;
    imprime_pilha(&estacionamento);

    estacionar(&estacionamento,"XYZ3215", 2022);
    estacionar(&estacionamento,"WQT2245", 2020);
    estacionar(&estacionamento,"GIN3285", 2017);
    estacionar(&estacionamento,"HIX5215", 2008);
    imprime_pilha(&estacionamento);

    carro_comum = sair(&estacionamento);
    cout << "Saiu o carro: " << carro_comum.placa << endl;
    imprime_pilha(&estacionamento);
    cout << "Quantidade de vagas " << quantidade_vagas(estacionamento) << endl;
    imprime_tudo(&estacionamento);

}

/* Desenvolver as funções propostas a partir daqui */
void inicializar(Pilha *estacionamento) {
    estacionamento->contador = 0;
    int x;
	for (x = TAMANHO_PILHA-1; x >= 0 ; x--){
		estacionamento->data[x].placa = "AAA0000" ;
        estacionamento->data[x].ano = 0 ;
    }
}

void estacionar(Pilha *estacionamento, string placa, int ano) {
    int contador = estacionamento->contador;
    int novaPosicao = contador++;
    if( contador == TAMANHO_PILHA) {
        cout << "Estacionamento cheio!!" << endl;
        return;
    }

    estacionamento->data[novaPosicao].placa = placa;
    estacionamento->data[novaPosicao].ano = ano;

    estacionamento->contador++;
};

void estacionar(Pilha *estacionamento, Carro novoCarro){
    int contador = estacionamento->contador;
    int novaPosicao = contador++;
    if( contador == TAMANHO_PILHA) {
        cout << "Estacionamento cheio!!" << endl;
        return;
    }
    estacionamento->data[novaPosicao] = novoCarro;
    estacionamento->contador++;
};


Carro sair(Pilha *estacionamento) {
    int ultimaPosicao = estacionamento->contador - 1;
    Carro carroRetirado = estacionamento->data[ultimaPosicao];

    estacionamento->data[ultimaPosicao].placa = "AAA0000" ;
    estacionamento->data[ultimaPosicao].ano = 0 ;
    estacionamento->contador--;

    return carroRetirado;
};

void imprime_pilha(Pilha *estacionamento) {
    if( estacionamento->contador == 0) {
        cout << "Sem carro estacionado!!" << endl;
        return;
    }    

    cout << "PILHA DE CARROS" << endl;
    cout << "================" << endl;

    for( int itemEstacionado = estacionamento->contador; itemEstacionado >= 0; itemEstacionado--) {
        string placa = estacionamento->data[itemEstacionado].placa;
        int ano =  estacionamento->data[itemEstacionado].ano;

        if( placa != "AAA0000" && ano != 0) {
            cout <<  placa << "  " << ano << endl;
        }
    }

    cout << endl;
};


void imprime_tudo(Pilha *estacionamento) {
    if( estacionamento->contador == 0) {
        cout << "Sem carro estacionado!!" << endl;
        return;
    }    

    cout << "PILHA DE CARROS" << endl;
    cout << "================" << endl;

    for( int itemEstacionado = TAMANHO_PILHA-1; itemEstacionado >= 0; itemEstacionado--) {
        string placa = estacionamento->data[itemEstacionado].placa;
        int ano =  estacionamento->data[itemEstacionado].ano;
        cout <<  placa << "  " << ano << endl;
    }

    cout << endl;
};

int quantidade_vagas(Pilha estacionamento) {
    int vagasLivres=0;
    for( int posicaoEstacionamento=0; posicaoEstacionamento < TAMANHO_PILHA; posicaoEstacionamento++) {
        string placa = estacionamento.data[posicaoEstacionamento].placa;
        int ano =  estacionamento.data[posicaoEstacionamento].ano;
        if( placa == "AAA0000" && ano == 0) {
            vagasLivres++;
        }
        
    }
    return vagasLivres;
};
