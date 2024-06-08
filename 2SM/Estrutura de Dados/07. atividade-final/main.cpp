#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

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
vector< string> split(const string& , char );
void lerGravarArquivo(lista *);
void gravarParticipantes(lista * );

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
        cout << "| 4 - ler Arquivo                         |" << endl;
        cout << "| 5 - Gravar Arquivo                      |" << endl;
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
            case 4: 
                lerGravarArquivo(listagem);
            break;
            case 5: 
                gravarParticipantes(listagem);
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
      
        cout << endl << "--------------------------------------------- ";
        cout << endl << "ID aluno: " << itemTemp->item.ID;
        cout << endl << "--------------------------------------------- ";
        cout << endl << "Nome: " << itemTemp->item.primeiroNome;
        cout << endl << "Curso: " << itemTemp->item.curso;
        cout << endl << "Semestre: " << itemTemp->item.semestre;
        cout << endl << "Ano de Ingreso: " << itemTemp->item.anoIngresso;
          cout << endl;
        itemTemp = itemTemp->proximo;
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
        cout << endl << "Qual e o novo valor?" << endl ;
        cin >> participantePesquisado->item.primeiroNome;
    }

    if( alterarProprieade("Curso") == 1 ) {
        cout << endl << "Qual e o novo valor?" << endl ;
        cin >> participantePesquisado->item.curso;
    }

    if( alterarProprieade("Semestre") == 1 ) {
        cout << endl << "Qual e o novo valor?" << endl;
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

void lerGravarArquivo(lista * listagem) {
  
    FILE *arq = fopen("../text.txt", "rt");         
    if (arq == NULL) {
       cout << "Problemas na abertura do arquivo!" << endl;
    }
    int vezes = 0;
    char linha[100];
    char *rowResult;
    participante novoParticipante;

    while ((rowResult = fgets(linha, 100, arq)) != NULL)  {
        // rowResult = fgets(linha, 100, arq);
        string input = rowResult;

        char delimiter = ',';
        if(input != " ") {
            vector<string> result = split(input, delimiter);
            vezes++;
            for (const auto& s : result) {
                string str = s;
                string valor;
                string propriedade;
                size_t end = str.find(":");
                valor = str.substr(end+1);
                propriedade = str.substr(0, end);
                cout << valor;
                novoParticipante.ID = 0;
                if(propriedade == "nome" ) novoParticipante.primeiroNome = valor;
                if(propriedade == "semestre" ) novoParticipante.semestre = stol(valor);
                if(propriedade == "anoIngresso" ) novoParticipante.anoIngresso = stol(valor);
                if(propriedade == "curso" )  {
                    novoParticipante.curso = valor.substr(0,2);
                    // cout << valor;
                }
            }

            inserirParticipante(listagem, novoParticipante);
        }
    }

    if( vezes == 0 )  {
         cout << endl << "Nao foi encontrado nenhum valor!!!";
    } else {
        cout << endl << "Foi inserido  " << vezes << " Participantes!!";
    }
    fclose(arq);
};

vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    size_t start = 0;
    size_t end = str.find(delimiter);
    
    while (end != string::npos) {
        token = str.substr(start, end - start);
        tokens.push_back(token);
        start = end + 1;
        end = str.find(delimiter, start);
    }
    
    // Adiciona o último token
    token = str.substr(start, end - start);
    tokens.push_back(token);
    
    return tokens;
}


void gravarParticipantes(lista * listagem) {

    if( listagem->qtd== 0) {
        cout << endl << "Nenhum aluno registrado!!!";
        return;
    }

    FILE *arq = fopen("../text.txt", "w");         
    if (arq == NULL) {
       cout << "Problemas na abertura do arquivo!" << endl;
    }

    
    node * itemTemp = listagem->primeiroItem;
    while( itemTemp != NULL) {

        string valor = "nome:" + itemTemp->item.primeiroNome;
        valor = valor + ",semestre:" + to_string(itemTemp->item.semestre);
        valor = valor + ",anoIngresso:"+to_string(itemTemp->item.anoIngresso);
        valor = valor + ",curso:"+itemTemp->item.curso;
        valor = valor + "\n";

        string temp = valor;
        fputs(valor.c_str(), arq);
        itemTemp = itemTemp->proximo;
    }

    fclose(arq);
}