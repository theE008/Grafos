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

int grau_Vertice (Grafo G, Vertice V, bool grauDeEntrada)
{
    int grau = 0;

    if (G->direcionado)
    {
        for (int x = 0; x < V->arestas.quantia; x++)
        {
            if (V->arestas.elementos [x]->origem == V)
                 grau += (grauDeEntrada)?0:1;
            else grau += (grauDeEntrada)?1:0;           

            if (V->arestas.elementos [x]->origem == V->arestas.elementos [x]->destino) grau += 1; 
        }
    }
    else 
    {
        for (int x = 0; x < V->arestas.quantia; x++)
            if (V->arestas.elementos [x]->origem == V->arestas.elementos [x]->destino) grau += 2;
            else grau += 1;
    }

    return grau;
}

// Retorna a Aresta em qual A incide em B
Aresta Vertice_AIncidenteEmB (Grafo G, Vertice A, Vertice B)
{
    if (G->direcionado)
    {
        for (int x = 0; x < A->arestas.quantia; x++)
            if (A->arestas.elementos [x]->destino == B)
                return A->arestas.elementos [x];
    }
    else 
    {
        for (int x = 0; x < A->arestas.quantia; x++)
            if (A->arestas.elementos [x]->destino == B || A->arestas.elementos [x]->origem == B)
                return A->arestas.elementos [x];
    }

    return NULL;
}

// "Um vértice com nenhuma aresta incidente é chamado de vértice isolado."
bool Vertice_isolado (Vertice V)
{
    return V->arestas.quantia == 0;
}

// "Um vértice com grau 1 é chamado de vértice pendente"
bool Vertice_pendente (Grafo G, Vertice V, bool grauDeEntrada)
{
    return grau_Vertice (G, V, grauDeEntrada) == 1;
}

// Só diz se o Vértice possui aquela aresta
bool Vertice_possuiAresta (Vertice V, Aresta A)
{
    for (int x = 0; x < V->arestas.quantia; x++)
        if (V->arestas.elementos [x] == A)
            return true;

    return false;
}

#endif