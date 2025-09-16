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

void imprimir_Grafo (Grafo G)
{
    for (int x = 0; x < G->vertices.quantia; x++)
    {
        printf ("(%d)\n", G->vertices.vertices [x]->id);

        for (int y = 0; y < G->vertices.vertices [x]->arestas.quantia; y++)
        {
            printf ("|- (%d - %d)\n", G->vertices.vertices [x]->arestas.arestas [y]->origem->id, G->vertices.vertices [x]->arestas.arestas [y]->destino->id);
        }
    }
}

void limpar_Grafo (Grafo G)
{
    for (int x = 0; x < G->arestas.quantia; x++)
        limpar (G->arestas.arestas [x]);

    limpar (G->arestas.arestas);
    
    for (int x = 0; x < G->vertices.quantia; x++)
    {
        limpar (G->vertices.vertices [x]->arestas.arestas); 
        limpar (G->vertices.vertices [x]); 
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   

    limpar (G->vertices.vertices);

    limpar (G);
}

#endif
