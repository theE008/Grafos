#ifndef Aresta_h
#define Aresta_h

#include "Main.h"

Aresta nova_Aresta (Grafo grafo, string nome, Vertice origem, Vertice destino)
{
    if (grafo == NULL) 
        printf ("\n\n\tnova_Aresta recebendo grafo nulo\n\n");
    if (origem == NULL) 
        printf ("\n\n\tnova_Aresta recebendo origem nulo\n\n");
    if (destino == NULL) 
        printf ("\n\n\tnova_Aresta recebendo destino nulo\n\n");

    static int staticId = 0;
    Aresta tmp = NULL;

    malocar (tmp, Aresta, sizeof (sptAresta));

    tmp->id = ++staticId;
    tmp->origem = origem;
    tmp->destino = destino;
    
    if (nome == NULL) tmp->nome = NULL; else strcpy (tmp->nome, nome);

    putAresta (&grafo->arestas, tmp);
    putAresta (&origem->arestas, tmp);
    putAresta (&destino->arestas, tmp);

    return tmp;
}

#endif