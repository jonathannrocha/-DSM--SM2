#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    FILE *arq = fopen("../text.txt", "rt");
    char linha[100];
    char *result;

    if (arq == NULL) {
        cout << "Problemas na abertura do arquivo!" << endl;
    }

    while (!feof(arq))  {
        result = fgets(linha, 100, arq);
        if (result) {
            cout << "valor::" << result;
        }
       
    }
    fclose(arq);
    return 0;
}