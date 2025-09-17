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
        printf ("(%d)\n", G->vertices.elementos [x]->id);

        for (int y = 0; y < G->vertices.elementos [x]->arestas.quantia; y++)
        {
            // printf ("|- (%d - %d)\n", G->vertices.elementos [x]->arestas.elementos [y]->origem->id, G->vertices.elementos [x]->arestas.elementos [y]->destino->id);

            if (G->vertices.elementos [x]->arestas.elementos [y]->origem->id == G->vertices.elementos [x]->id)
                printf ("|- (%d)\n", G->vertices.elementos [x]->arestas.elementos [y]->destino->id);
            else 
                printf ("|- (%d)\n", G->vertices.elementos [x]->arestas.elementos [y]->origem->id);
        }

        printf ("\n");
    }
}

void limpar_Grafo (Grafo G)
{
    for (int x = 0; x < G->arestas.quantia; x++)
        limpar (G->arestas.elementos [x]);

    limpar (G->arestas.elementos);
    
    for (int x = 0; x < G->vertices.quantia; x++)
    {
        limpar (G->vertices.elementos [x]->arestas.elementos); 
        limpar (G->vertices.elementos [x]); 
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   

    limpar (G->vertices.elementos);

    limpar (G);
}

#endif
