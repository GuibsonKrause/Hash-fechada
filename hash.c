#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.c"

// hash fechada

THashFechada criaHashFechada(int tam)
{
	int i;
	THashFechada *hash = (THashFechada *) malloc (sizeof (THashFechada));
	hash->tam = tam;
	hash->tabela = (TLista *) malloc (tam * sizeof (TLista));
	
	for (i = 0; i < tam; i++)
	{
        hash->tabela[i] = *inicLista(); // Usar o metodo de iniciar lista da biblioteca de lista
	}
	
    return *hash;
}

int hashCode(TContato *c, THashFechada *h)
{
	return c->nome[0] % h->tam;
}

void insereHashFechada(THashFechada *hash, TContato *contato)
{
	int code = hashCode(contato, hash);
    insereOrdenado(contato, &hash->tabela[code]); // Metodo da biblioteca lista
}

/*
void removerHashFechada(THashFechada *hash, TContato *contato)
{
	int code = hashCode(contato, hash);
    removerLista(contato, hash->tabela[code]); // Metodo da biblioteca lista
}
*/

void listarHashFechada(THashFechada *hash, TContato *contato)
{
    int code = hashCode(contato, hash);
    listar(&hash->tabela[code]);
}

