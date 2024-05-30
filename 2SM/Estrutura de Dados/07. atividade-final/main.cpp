#include <iostream>
using namespace std;
#include <stdio.h>

struct participante {
    int ID;
    string primeiroNome;
    int semestre;
    int anoIngresso;
    string curso;
};

struct node {
    node  *anterior;
    node  *proximo;
    participante item;
};

struct lista {
    int qtd;
    node * primeiroItem;
    node * ultimoItem;
};

participante criarParticipante();
void inicializarLista(lista *);
void inserirParticipante(lista *, participante);
void listarTudo(lista *);
void editarAluno(lista *);
int alterarProprieade(string propriedade);

int main() {

    lista *listagem = new lista;
    inicializarLista(listagem);

    int loopMenu = 0;
    while(loopMenu == 0) {
        int opcaoMenu;
        cout << endl;
        cout << "|-----------------------------------------|" << endl;
        cout << "|                  Menu                   |" << endl;
        cout << "|-----------------------------------------|" << endl;
        cout << "| 1 - Inserir participante                |" << endl;
        cout << "| 2 - lista tudo                          |" << endl;
        cout << "| 3 - Editar participante                 |" << endl;
        cout << "| # - Sair do menu                        |" << endl;
        cout << "|-----------------------------------------|" << endl;
        cin >> opcaoMenu;

        switch(opcaoMenu) {
            case 1:
                inserirParticipante(listagem, criarParticipante());           
            break;
             case 2:
                listarTudo(listagem);               
            break;
            case 3: 
                editarAluno(listagem);
            break;
            default:

            break;
        }
    };
    return 0;
};

participante criarParticipante(){
    participante novoParticipante;

    cout << endl;
    cout << "Qual e seu primeiro nome?" << endl;
    cin >> novoParticipante.primeiroNome;
    cout << "Qual e seu curso?" << endl;
    cin >> novoParticipante.curso ;
    cout << "Qual e seu ano de ingresso na Fatec?" << endl;
    cin >> novoParticipante.anoIngresso;
    cout << "Qual e seu semestre?" << endl;
    cin >> novoParticipante.semestre;
    novoParticipante.ID = 0;

    return novoParticipante;
}

void inicializarLista(lista *listagem) {
    listagem->primeiroItem = NULL;
    listagem->ultimoItem = NULL;
    listagem->qtd = 0;
}

void inserirParticipante(lista *listagem, participante novoParticipante) {
    node *novoNode = new node;
    if( novoNode == NULL) {
        exit(1);
    }

    novoNode->anterior = NULL;
    novoNode->proximo = NULL;
    novoNode->item = novoParticipante;
    
    if(listagem->primeiroItem == NULL) {
        listagem->qtd++;
        novoNode->item.ID=1;
        listagem->primeiroItem = novoNode;    
        return;
    }
    
    if( listagem->qtd == 1) {
        listagem->qtd++;
        novoNode->item.ID=2;
        listagem->ultimoItem = novoNode;
        listagem->primeiroItem->proximo = listagem->ultimoItem;
        listagem->ultimoItem->anterior = listagem->primeiroItem;
        return;
    } else {
        novoNode->item.ID = listagem->ultimoItem->item.ID + 1 ;
        novoNode->anterior = listagem->ultimoItem;
        novoNode->anterior->proximo = novoNode;
        listagem->ultimoItem = novoNode;
        listagem->qtd++;
        return;
    }
}

void listarTudo(lista *listagem) {
    if( listagem->qtd== 0) {
        cout << endl << "Nenhum aluno registrado!!!";
        return;
    }
     node * itemTemp = listagem->primeiroItem;
    while( itemTemp != NULL) {
        cout << endl << "[ID] " << itemTemp->item.ID;
        cout << endl << "[NOME] " << itemTemp->item.primeiroNome;
        cout << endl << "[CURSO] " << itemTemp->item.curso;
        cout << endl << "[SEMESTRE] " << itemTemp->item.semestre;
        cout << endl << "[ANO INGRESSO] " << itemTemp->item.anoIngresso;
        itemTemp = itemTemp->proximo;
        cout << endl;
    }
}

void editarAluno(lista * listagem) {
    int idParticipante;
    cout << "Informe o ID do participante:" << endl;
    cin >> idParticipante;

    node * participantePesquisado;
    participantePesquisado = NULL;
    node * itemTemp = listagem->primeiroItem;

    while( itemTemp != NULL) {
        if( itemTemp->item.ID == idParticipante) {
            participantePesquisado = itemTemp;
            itemTemp = NULL;
        } else {
            itemTemp = itemTemp->proximo;
        }
    }

    if(participantePesquisado == NULL) {
        cout << endl << "Participante não encontrado!!" << endl;
        return;
    }

    if( alterarProprieade("Nome") == 1 ) {
        cout << endl << "Qual e o novo valor?" ;
        cin >> participantePesquisado->item.primeiroNome;
    }

    if( alterarProprieade("Curso") == 1 ) {
        cout << endl << "Qual e o novo valor?" ;
        cin >> participantePesquisado->item.curso;
    }

    if( alterarProprieade("Semestre") == 1 ) {
        cout << endl << "Qual e o novo valor?";
        cin >> participantePesquisado->item.semestre;
    }
    if( alterarProprieade("Ano de Ingreso") == 1 ) {
        cout << endl << "Qual e o novo valor?" << endl ;
        cin >> participantePesquisado->item.anoIngresso;
    }       
};

int alterarProprieade(string propriedade) {
    int escolha;
    cout << endl << "Deseja alterar a propriedade " << propriedade << "?" << endl;
    cout << "1 - Sim" << endl;
    cout << "2 - Nao" << endl;
    cin >> escolha;
    return escolha;
};

