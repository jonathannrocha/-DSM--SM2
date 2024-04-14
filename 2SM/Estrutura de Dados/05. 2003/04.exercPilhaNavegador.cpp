/*
 * Segunda lista
 *
 * Prof. Me. Orlando Saraiva Jr
 * Aplicado em : 13/04/2023
 */

#include <iostream>
#include <ctime>

using namespace std;

struct URL {
    string url;
    int dia;
    int mes;
    int ano;
};

struct Node {
    URL url;
    Node *next;
};

struct Pilha {
    Node *topo;
    int tamanho;
};

void inicializar(Pilha *);
void navegar(Pilha *, string);
void navegar(Pilha *historico, string, int, int, int);
URL voltar(Pilha *);
void imprime_historico(Pilha *);
void imprime_url(URL);
void destruir_historico(Pilha *);


int main() {

    URL site;
    Pilha historico_navegacao; 
    inicializar(&historico_navegacao);
    navegar(&historico_navegacao, "http://www.google.com");
    navegar(&historico_navegacao, "http://www.facebook.com");
    navegar(&historico_navegacao, "http://www.globo.com", 15, 1, 2023);
    navegar(&historico_navegacao, "http://www.fatecararas.sp.gov.br");
    navegar(&historico_navegacao, "http://www.google.com");
    navegar(&historico_navegacao, "http://www.facebook.com");
    navegar(&historico_navegacao, "http://www.fatecararas.sp.gov.br");
    navegar(&historico_navegacao, "http://www.gmail.com");

    imprime_historico(&historico_navegacao);
    
    site = voltar(&historico_navegacao);
    imprime_url(site);
    site = voltar(&historico_navegacao);
    imprime_url(site);
    imprime_url(voltar(&historico_navegacao));
    
    imprime_historico(&historico_navegacao);
    destruir_historico(&historico_navegacao);

    return 0;
}

void inicializar(Pilha *historico) {
    historico->tamanho = 0;
    historico->topo = NULL;
}

void navegar(Pilha *historico, string url_acessada) {
    Node *np = new Node;
    if (np == NULL) {
        cerr << "Acabou a memória. " << endl; 
        exit(1);
    }
    /*
    Com as bibliotecas chrono e ctime 
    seria mais fácil, mas como ambas são para 
    C++ 11, adotei a struct std::time_t.
    */ 
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    int dia = now->tm_mday;
    int mes = now->tm_mon + 1 ;
    int ano= now->tm_year + 1900;

    np->url.url = url_acessada;
    np->url.dia = dia;
    np->url.mes = mes;
    np->url.ano = ano;
    np->next = historico->topo;
    historico->topo = np; 
    historico->tamanho++; 
}

void navegar(Pilha *historico, string url_acessada, int dia, int mes, int ano) {
    Node *np = new Node;
    if (np == NULL) {
        cerr << "Acabou a memória. " << endl; 
        exit(1);
    }

    np->url.url = url_acessada;
    np->url.dia = dia;
    np->url.mes = mes;
    np->url.ano = ano;
    np->next = historico->topo;
    historico->topo = np; 
    historico->tamanho++; 
}

URL voltar(Pilha *historico) { 

    Node *ultimoItem = historico->topo;
    URL url = ultimoItem->url;
    historico->topo = ultimoItem->next;
    historico->tamanho--;
    return url;
    
    delete ultimoItem;
    
};

void imprime_historico(Pilha *historico) {
    if( historico->tamanho == 0) { 
        cout << "Nenhu site foi visitado!" << endl;
        exit(1);
    }
    Node *next = historico->topo;

    cout << "Quantidade de URLs: " << historico->tamanho  << " no histórico." << endl;
    cout << "====================================" << endl;

    for( int qntdItens = 0; qntdItens < historico->tamanho; qntdItens++ ) {
       cout << next->url.url << endl;
       next = next->next;
    }
    cout << "------------------------------------" << endl;
};

void imprime_url(URL url){ 
    cout <<url.dia<< "/" << url.mes << "/" << url.ano << "     " << url.url << endl ;
};

void destruir_historico(Pilha *historico){ 
    while(historico->tamanho > 0) {
        Node *ultimoItem = historico->topo;
        cout << "Desempilhado a URL: " << ultimoItem->url.url << endl;
        historico->topo = ultimoItem->next;
        historico->tamanho--;
        delete ultimoItem;
    }

};

