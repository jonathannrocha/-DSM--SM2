/*
*Ao navegar na internet, a cada site acessado, o endereço é 
*armazenado em uma pilha. Ao clicar em voltar, pode-se acessar 
*novamente o endereço anteriormente visitado. 
*Faça um programa que simule as funcionalidades de acessar um 
*site e voltar. Ao empilhar, armazenar o endereço http. Ao 
*desempilhar, retornar o endereço http. Não há limite de sites 
*que podem ser acessados.
*Armazene o endereço http. A entrada de dados deve ocorrer 
*dentro da função de empilhamento.
*/

#include <iostream>

using namespace std;

struct Domain {
    string path;
    Domain *before;
};

struct Historic {
    Domain *lastItem;
    int size;
};

string getDomain();
void addDomain(Historic *historic);
void deleteDomain(Historic *historic);

int main(){ 
    Historic *historicDomains;

    historicDomains = new Historic;
    historicDomains ->size = 0;

    int controller =0;
    while( controller==0) {
        int selection = 0;
        cout << "Escolha uma opcao:" << endl;
        cout << "1 - acessar site" << endl;
        cout << "2 - voltar site anterior" << endl;
        cout << "3 - finalizar"<< endl;
        cin >> selection;

        if(selection  == 1) {
            addDomain(historicDomains);
            system("cls");
        }

        if( selection == 2) {
            deleteDomain(historicDomains);
            // system("cls");
        }

        if( selection == 3) {
            system("cls");
            controller++;
        }
    }
};

string getDomain() {
    string searchDomain;
    cout << "Qual site vamos acessar?" << endl;
    cin >> searchDomain;
    system("cls");
    return searchDomain;
};

void addDomain(Historic *historic) {
    Domain *newDomain;
    newDomain = new Domain;

    newDomain ->path = getDomain();
    newDomain ->before = historic->lastItem;

    historic->lastItem = newDomain;    
    historic-> size++;
}

void deleteDomain(Historic *historic) {

    if( historic->size == 0 ) {
        cout << "Sem histórico!!" << endl;
        return;
    }
    Domain *lastItemHistoric = historic->lastItem;
    historic->lastItem = lastItemHistoric->before;
    historic->size--;
    cout << "Endereco anterior acessado: " << lastItemHistoric->path << endl;
    delete lastItemHistoric;
}

void printRegisterActives() {
    
}