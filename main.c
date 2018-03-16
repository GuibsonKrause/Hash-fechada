#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int main()
{
    TContato *contato;
    THashFechada *hash;
    TLista *lista;
    int resp;
    char nome[50];

    do
    {
        printf("Informe o nome \n");
        gets(nome);
        strcpy(contato->nome, nome);
        insereHashFechada(hash, contato);

        printf("Quer inserir outro?\n\n");
        scanf("%d",&resp);
        getchar();
    }while(resp);

    listarHashFechada(lista, contato);
    /*
    printf("\nQuem voce deseja remover\n");
    gets(nome);
    int aux = remover(lista, nome);
    if (aux == 0)
        printf("%s nao foi encontrado\n\n", nome);
    else if (aux==-1)
        printf("lista vazia");
    else
        printf("%s foi removido da lista\n\n", nome);
    listar(lista);
    */
    return 0;
}
