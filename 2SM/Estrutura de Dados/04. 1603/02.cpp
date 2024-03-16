/*
* Você foi designado para criar um programa em C++ para gerenciar informações sobre produtos em um
* estoque. O objetivo é criar uma estrutura de dados que permita armazenar detalhes sobre cada produto, como
* nome, preço e quantidade em estoque, utilizando alocação dinâmica de memória com ponteiros em heap e
* garantindo a utilização dos tipos string, integer e float.
* Para isso, você deve criar uma estrutura (struct) chamada Produto que inclua os seguintes campos:
* Nome: Uma variável do tipo string para armazenar o nome do produto.
* Preço: Uma variável do tipo float para armazenar o preço do produto.
* Quantidade em Estoque: Uma variável do tipo integer para armazenar a quantidade disponível do produto em
* estoque.
* O software deve armazenar 10 produtos diferentes, alocando-se na memória heap.
*/

#include <iostream>
using namespace std;

int main() {	

	struct Produto {
		string nome;
		string preco;
		int qtdEstoque;
	};
	
	int qtdProdutos = 10;
	
	Produto *produtosEmEstoque;
	
	produtosEmEstoque = new Produto[qtdProdutos];
	
	for( int qtdItens=0;qtdItens < qtdProdutos;qtdItens++)	 {
		cout << "Informe o  nome do produto " << qtdItens+1 << ":"; 
		cin >> produtosEmEstoque[qtdItens].nome;
		
		cout << "Informe o preco de produto "  << qtdItens+1 << ":"; 
		cin >> produtosEmEstoque[qtdItens].preco;
		
		cout << "Informe a quantidade em estoque " << qtdItens+1 << ":"; 
		cin >> produtosEmEstoque[qtdItens].qtdEstoque;
		cout << endl << endl;
		
		system("cls");
	}
	
	for( int qtdItens =0;qtdItens < qtdProdutos;qtdItens++)	 {
		cout << "*****************************************************" << endl;
		cout << "Produto  " << qtdItens+1 << endl;
		cout << "Seu nome:" << produtosEmEstoque[qtdItens].nome << endl;
		cout << "Seu preco" << produtosEmEstoque[qtdItens].nome << endl;
		cout << "A quantidade do item e " << produtosEmEstoque[qtdItens].nome << endl;
	
	}
	
	delete[] produtosEmEstoque;
	return 0;
		
}