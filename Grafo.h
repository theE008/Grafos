#ifndef Grafo_h
#define Grafo_h

#include "Main.h"

Grafo novo_Grafo (bool direcionado)
{
    Grafo grafo = NULL;
    static int staticId = 0;

    malocar (grafo, Grafo, sizeof (sptGrafo));

    grafo->id = staticId++;
    grafo->direcionado = direcionado;

    grafo->arestas = nova_lisAresta ();
    grafo->vertices = nova_lisVertice ();

    return grafo;
}

void limpar_Grafo (Grafo G)
{
    limpar_lisAresta (&G->arestas);
    
    for (int x = 0; x < G->vertices.quantia; x++)
    {
        limpar (G->vertices.vertices [x]->arestas.arestas); 
        limpar (G->vertices.vertices [x]); 
    }

    limpar (G->vertices.vertices);

    limpar (G);
}

#endif
