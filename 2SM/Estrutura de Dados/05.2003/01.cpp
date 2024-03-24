/*
*Um estacionamento possui uma única entrada/saída e a
*capacidade máxima para guardar dez carros. Faça um programa
*que simule a entrada ( empilhar ) e saída ( desempilhar) de
*carros deste estacionamento.
*Armazene a placa, modelo e ano de cada carro estacionado. A
*entrada de dados deve ocorrer dentro da função de
*empilhamento.
*Funções esperadas: 
*Estacionar carro
*Chek-out de carro
*Listar carros estacionados
*/

#include <iostream>

using namespace std;

const int MAX_ESTACIONAMENTO = 3;

struct Carro {
	string placa;
	string modelo;
	int anoFab;
};

struct Estacionamento {
	Carro listaCarros[MAX_ESTACIONAMENTO];
	int qtdCarros;
};

void estacionarCarro( Estacionamento &estacionamento);
void listarCarroEstacionados(Estacionamento estacionamento);
Carro solicitarDadosCarro();


int main() {
	Estacionamento pilhaCarros;
	pilhaCarros.qtdCarros = 0;
	
	for( int qtdSolicitar=0; qtdSolicitar < MAX_ESTACIONAMENTO; qtdSolicitar++) {
		estacionarCarro(pilhaCarros);
		system("cls");
	}
	listarCarroEstacionados(pilhaCarros);
	
	return 0;
}

Carro solicitarDadosCarro() {
	Carro novoCarro;
	cout << "Qual é a placa do carro? "	<< endl;
	cin >> novoCarro.placa;
	cout << "Qual é o modelo?" << endl;
	cin >> novoCarro.modelo;
	cout << "Ano de fabricação?" << endl;
	cin >> novoCarro.anoFab;

    return novoCarro;
};

void estacionarCarro( Estacionamento &estacionamento) {

	int qtdCarro = estacionamento.qtdCarros;
	if(qtdCarro == MAX_ESTACIONAMENTO ) {
		cout << "Estacionamento cheio!!" << endl;
		return;
	}

	Carro registrarCarro = solicitarDadosCarro();
	
	estacionamento.listaCarros[qtdCarro] = registrarCarro;
	estacionamento.qtdCarros++;
}


void listarCarroEstacionados(Estacionamento estacionamento) {
	system("cls");
	if( estacionamento.qtdCarros == 0 ) {
		cout << endl << "Nao ha nenhum carro estacionado!!" << endl;
		return;
	}

	for( int posicaoVaga=0; posicaoVaga  < estacionamento.qtdCarros ;posicaoVaga++) {
		cout << endl;
		// cout << "Carro na vaga º" << posicaoVaga + 1  << endl;
		cout << "Modelo: " << estacionamento.listaCarros[posicaoVaga].modelo << endl;
		cout << "Ano de Fabricação: " << estacionamento.listaCarros[posicaoVaga].anoFab << endl;
		cout << "Placa: " << estacionamento.listaCarros[posicaoVaga].placa << endl;
	}
}
