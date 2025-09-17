#ifndef Grafo_h
#define Grafo_h

#include "Main.h"

Grafo novo_Grafo (bool direcionado, string nome)
{
    Grafo grafo = NULL;
    static int staticId = 0;

    malocar (grafo, Grafo, sizeof (sptGrafo));

    grafo->id = staticId++;
    grafo->direcionado = direcionado;

    if (nome == NULL) grafo->nome [0] = '\0'; else strcpy (grafo->nome, nome);

    grafo->arestas = nova_lisAresta ();
    grafo->vertices = nova_lisVertice ();

    return grafo;
}

void imprimir_Grafo (Grafo G)
{
    if (G->nome [0] != '\0') printf ("# %s\n\n", G->nome);

    for (int x = 0; x < G->vertices.quantia; x++)
    {
        if (G->vertices.elementos [x]->nome [0] == '\0')
            printf ("(%d)\n", G->vertices.elementos [x]->id);
        else 
            printf ("(%s)\n", G->vertices.elementos [x]->nome);

        for (int y = 0; y < G->vertices.elementos [x]->arestas.quantia; y++)
        {
            Aresta tmp = G->vertices.elementos [x]->arestas.elementos [y];

            if (tmp->origem->id == G->vertices.elementos [x]->id)
            {
                if (tmp->destino->nome [0] == '\0')
                    printf ("|- (%d)\n", tmp->destino->id);
                else 
                    printf ("|- (%s)\n", tmp->destino->nome);  
            }
            else 
            {
                if (tmp->origem->nome [0] == '\0')
                    printf ("|- (%d)\n", tmp->origem->id);
                else 
                    printf ("|- (%s)\n", tmp->origem->nome);  
            }
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
