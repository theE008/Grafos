#ifndef Aresta_h
#define Aresta_h

#include "Main.h"

Aresta nova_Aresta (Grafo grafo, Vertice origem, Vertice destino, string nome)
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
    
    if (nome == NULL) tmp->nome [0] = '\0'; else strcpy (tmp->nome, nome);

    putAresta (&grafo->arestas, tmp);
    putAresta (&origem->arestas, tmp);

    if (origem != destino)
        putAresta (&destino->arestas, tmp);

    return tmp;
}

bool Arestas_saoAdjacentes (Grafo G, Aresta A, Aresta B)
{
    if (G->direcionado)
        return A->destino == B->destino;
    
    else 
        return  (A->origem  == B->origem ) ||
                (A->origem  == B->destino) ||
                (A->destino == B->origem ) ||
                (A->destino == B->destino) ;;
}

#endif