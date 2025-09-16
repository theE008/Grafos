#ifndef Vertices_h
#define Vertices_h
 
#include "Main.h"

Vertice novo_Vertice (Grafo grafo)
{
    if (grafo == NULL) 
        printf ("\n\n\tnova_Aresta recebendo grafo nulo\n\n");

    static int staticId = 0;
    Vertice tmp = NULL;

    malocar (tmp, Vertice, sizeof (sptVertice));

    tmp->id = ++staticId;
    tmp->arestas = nova_lisAresta ();

    putVertice (&grafo->vertices, tmp);

    return tmp;
}

void limpar_Vertice (Vertice v)
{
    limpar_lisAresta (&v->arestas);

    limpar (v);
}

#endif