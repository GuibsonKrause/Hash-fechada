#ifndef hash_h
#define hash_h
/*------------------------------------------STRUCTS--------------------------------------------------*/
typedef struct Contato
{
    int telefone;
    char nome[50];
}TContato;

typedef struct Elemento
{
    TContato *contato;
    struct Elemento *prox, *ant;
}TElemento;

typedef struct lista
{
    struct Elemento *prim, *ult;
}TLista;

typedef struct HashFechada
{
    TLista *tabela;
    int tam;
}THashFechada;

/*-----------------------------------------CHAMADA DAS FUNCOES--------------------------------------------*/

TLista *inicLista();

int listaVazia (TLista *l);

void insereOrdenado (TContato *contato, TLista *l);

void insereNoFim (TLista *l);

void listar(TLista *l);

//int remover(TLista *l, char *nome);

THashFechada criaHashFechada(int tam);

int hashCode(TContato *c, THashFechada *h);

void insereHashFechada(THashFechada *hash, TContato *contato);

void removerHashFechada(THashFechada *hash, TContato *contato);

void listarHashFechada(THashFechada *hash, TContato *contato);

#endif
