#ifndef Main_h
#define Main_h

#include   <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <stdarg.h>
#include <stdbool.h>

typedef struct sptVertice   sptVertice;
typedef        sptVertice   *  Vertice;

typedef struct sptAresta     sptAresta; 
typedef        sptAresta    *   Aresta;

typedef struct sptGrafo       sptGrafo;
typedef        sptGrafo     *    Grafo;

typedef struct lisArestas   lisArestas;
typedef struct lisVertices lisVertices;

typedef char*        string;
typedef unsigned int    nat;

//

struct sptAresta
{
    char nome [64];
    int id;

    Vertice  origem;
    Vertice destino;
};


struct lisVertices
{
    int quantia;
    int tamMax;
    Vertice * elementos;
};

//

struct lisArestas
{
    int quantia;
    int tamMax;
    Aresta * elementos;
};

//

struct sptVertice 
{
    char nome [64];
    int id;

    lisArestas arestas;
};

//

struct sptGrafo
{
    char nome [64];
    int id;

    bool direcionado;

    lisVertices vertices;
    lisArestas   arestas;
};

//

int alocacoes_feitas = 0;
int memoria_usada    = 0;
int limpezas_feitas  = 0;

#define malocar(ptr,tipo,tam) \
do { ptr = (tipo) malloc(tam); \
    alocacoes_feitas ++; \
    if (ptr == NULL) printf ("\n\n\tMalloc fracassado\n\n"); \
    memoria_usada += tam; }\
    while (0);

#define limpar(ptr) \
do \
{\
    if (ptr == NULL) printf ("\n\n\tLimpando ponteiro nulo\n\n"); \
    limpezas_feitas ++; \
    free (ptr); \
    ptr = NULL;\
}\
while (0)

//

Aresta nova_Aresta (Grafo grafo, Vertice origem, Vertice destino, string nome);
lisArestas nova_lisAresta ();
int putAresta (lisArestas *lis, Aresta ar);
lisVertices nova_lisVertice ();
int putVertice (lisVertices *lis, Vertice v);



void limpar_lisAresta (lisArestas *lis);
void limpar_Vertice (Vertice v);

#endif