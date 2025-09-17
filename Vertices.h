#ifndef Vertices_h
#define Vertices_h
 
#include "Main.h"

Vertice novo_Vertice (Grafo grafo, string nome)
{
    if (grafo == NULL) 
        printf ("\n\n\tnova_Aresta recebendo grafo nulo\n\n");

    static int staticId = 0;
    Vertice tmp = NULL;

    malocar (tmp, Vertice, sizeof (sptVertice));

    tmp->id = ++staticId;
    tmp->arestas = nova_lisAresta ();

    if (nome == NULL) tmp->nome [0] = '\0'; else strcpy (tmp->nome, nome);

    putVertice (&grafo->vertices, tmp);

    return tmp;
}

#endif