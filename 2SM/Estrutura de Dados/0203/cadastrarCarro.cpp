/*
 
Desenvolva uma aplicação para cadastrar carro.
Crie uma estrutura para cadastro ( placa, ano, marca)
Crie uma estrutura para revisoes (data, local).
É previsto 5 revisões.
*/

#include <chrono>
#include <iostream>

using namespace std;

struct data {
    int data;
    char mes;
    int ano;
};

struct carro {
    string placa ;
    int ano ;
   string marca;
};

struct revisao{
    string data;
    string local;
};
    
string registrarPlaca();
int registrarAno();
string registrarMarca();
string criarData();
string registrarLocal(int qtdRevisoes);
string registrarData();


int main()
{
    int totalDeRevisoes=2;
    carro novoCarro;
    revisao vRegistroDerevisoes[totalDeRevisoes];
    
    novoCarro.placa = registrarPlaca();
    novoCarro.ano = registrarAno();
    novoCarro.marca = registrarMarca();
    
    
    cout << endl << "Vamos Agendar as revisoes: " << endl;
    for( int x =0; x <= totalDeRevisoes -1; x++) {
        vRegistroDerevisoes[x].local = registrarLocal(x);
         vRegistroDerevisoes[x].data = registrarData();
    }
   
    cout << endl << "Sua placa e:: " << novoCarro.placa << endl ;
    cout << endl << "Seu ano e:: " << novoCarro.ano << endl;
    cout << endl << "A marca do seu carro e:: " << novoCarro.marca << endl;
    
    cout << endl << "Segue revisoes:" << endl;;
    for(int j = 0; j <= totalDeRevisoes-1; j++   ) { 
        cout << endl << "Local " << j+1 << ":" << vRegistroDerevisoes[j].local << " Em " << vRegistroDerevisoes[j].data << endl;
    }
    return 0;
}


string registrarPlaca() {
    string nome;
    cout << endl << "Qual a placa?" << endl;
    cin >> nome;
    return nome;
};

int registrarAno() {
    int ano;
    cout  << endl << "Qual é o ano do carro?" <<endl;
    cin >> ano;
    return ano;
};

string registrarMarca() {
    string marca;
    cout << endl << "Informe a marca do carro:" << endl;
    cin >> marca;
    return marca;
};

string registrarLocal(int qtdRevisoes) {
    string local;
    cout <<endl << "Local que gostaria de levar o carro para revisao " << qtdRevisoes+1 << ":"<< endl;
    cin >> local;
    return local;
};

string registrarData() {
    string data;


    cout <<endl << "informe a data :" << endl;
    cin >> data;
    return data;
};
