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

Aresta Vertice_temLoop (Vertice v)
{
    Aresta resposta = NULL;

    for (int x = 0; x < v->arestas.quantia && resposta == NULL; x++)
    {
        Aresta a = v->arestas.elementos [x];

        if (a->origem == a->destino) resposta = a;
    }

    return resposta;
}

Aresta Vertice_temArestaParalela (Grafo G, Vertice v)
{
    Aresta resposta = NULL;

    if (G->direcionado)
    for (int x = 0; x < v->arestas.quantia && resposta == NULL; x++)
    {
        Aresta a = v->arestas.elementos [x];

        for (int y = x + 1; y < v->arestas.quantia && resposta == NULL; y++)
        {
            Aresta b = v->arestas.elementos [y];

            if (a->origem == b->origem && a->destino == b->destino)
                resposta = a;
        }
    }
    else 
    for (int x = 0; x < v->arestas.quantia && resposta == NULL; x++)
    {
        Aresta a = v->arestas.elementos [x];

        for (int y = x + 1; y < v->arestas.quantia && resposta == NULL; y++)
        {
            Aresta b = v->arestas.elementos [y];

            if 
            (
                (a->origem == b->origem  && a->destino == b->destino) ||
                (a->origem == b->destino && a->destino == b->origem )
            ) resposta = a;
        }
    }

    return resposta;
}

#endif