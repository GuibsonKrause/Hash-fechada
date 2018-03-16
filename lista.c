#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

TLista *inicLista()
{
    TLista *l = (TLista*) malloc (sizeof (TLista));
    l->prim = l->ult = NULL;
    return l;
}

int listaVazia (TLista *l)
{
    if (l->prim == NULL)
        return 1;
    else
        return 0;
}

void insereOrdenado (TContato *contato, TLista *l)
{
    TElemento *novo = (TElemento*) malloc (sizeof (TElemento));
    TElemento *p = l->prim, *aux = l->prim;

    novo->contato = contato;
    novo->prox = NULL;
    novo->ant = NULL;

    if (listaVazia(l))
    {
        l->prim = novo; // lista vazia
    }
    else
    {
        while ((p != NULL)&& strcmp(p->contato->nome, novo->contato->nome) <= 0) // percorre lista
        {
            aux = p;
            p = p->prox;
        }

        if (p == aux) // Novo eh menor do que todos da lista
        {
            novo->ant = NULL;
            l->prim->ant = novo;
            novo->prox = l->prim;
            l->prim = novo;
        }
        else if (p == NULL) // Novo eh maior do que todos da lista
        {
            aux->prox = novo;
            novo->ant = aux;
            novo->prox = NULL;
        }
        else  // se "j" eh menor do que "i" significa que o novo estah no meio
        {
            aux->prox->ant = novo;
            novo->prox = aux->prox;
            novo->ant = aux;
            aux->prox = novo;
        }
    }
}

/*
void insereNoFim (TLista *l)
{
    char nome[50];
    char endereco[300];
    float tel;

    printf("Informe o nome \n");
    gets(nome);
    printf("Informe o endereco \n");
    gets(endereco);
    printf("Informe o telefone \n");
    scanf("%f", &tel);

    TNO *novo = (TNO*) malloc (sizeof (TNO));
    novo->valor.tel= tel;
    strcpy(novo->valor.nome, nome);
    strcpy(novo->valor.endereco, endereco);
    novo->prox = NULL;
    if (listaVazia(l))
        l->prim = novo;
    else
        l->ult->prox = novo;
    l->ult = novo;
}

*/

void listar(TLista *l)
{
    int i = 1;
    //printf("\E[2J\E[2H");
    TElemento *atual = (TElemento*)malloc(sizeof(TElemento));
    atual = l->prim;

    if (atual == NULL)
    {
        printf("A lista esta vazia!\n");
        return;
    }

    while(atual != NULL)
    {
        printf("\nComponete %d da lista\n", i);
        printf("\nNome: %s\n",atual->contato->nome);
        atual = atual->prox;
        i++;
    }//while
}
/*
int remover(TLista *l, char *nome)
{
    TElemento *ante, *aux;

    if (listaVazia(l))
        return -1;
    else
    {
        aux = l->prim;
        ante=NULL;
        while ((aux != NULL) && (strcmp(aux->contato->nome, nome) != 0))
        {
            ante = aux;
            aux = aux->prox;
        }
        if (aux == NULL)
            return 0;
        if (aux != l->prim && aux != l->ult)
            ante->prox = aux->prox;
        else{
            if (aux == l->prim)
                l->prim = l->prim->prox;
            if (aux == l->ult)
            {
                l->ult = ante;
                if (ante != NULL)
                    ante->prox = NULL;
            }
        }
        free(aux);
        return 1;
    }
}
*/
