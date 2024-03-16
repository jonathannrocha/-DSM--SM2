
/*
* Você é encarregado de criar um programa em C++ para gerenciar informações de estudantes de uma escola.
* Cada estudante deve ter seu nome completo, idade e média final armazenados de forma organizada. Para
* isso, você deve criar uma estrutura (struct) chamada Estudante que contenha os seguintes campos:
* Nome Completo: Uma variável do tipo string para armazenar o nome completo do estudante.
* Idade: Uma variável do tipo int para armazenar a idade do estudante.
* Média Final: Uma variável do tipo float para armazenar a média final do estudante.
* O programa pode armazenar somente um estudante.
*/


#include <iostream>
using namespace std;

int main() {
	
	struct Estudante {
		string nome;
		int idade;
		float mediaFinal;
	};
	
	Estudante novoEstudante;
	
	cout << "Informe o nome do estudante: " << endl;
	cin >> novoEstudante.nome;
	
	cout << "Informe a idade do estudante: " << endl;
	cin >> novoEstudante.idade;
	
		cout << "Informe a media do estudante: " << endl;
	cin >> novoEstudante.mediaFinal;
	
	
	cout << "|" << "Nome               | " << novoEstudante.nome << endl ;
	cout << "|" << "Idade do estudante | " << novoEstudante.idade << endl ;
	cout << "|" << "Media Final        | " << novoEstudante.mediaFinal << endl ;
		
	return 0;
}