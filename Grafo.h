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
            else if (!G->direcionado)
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

Aresta Grafo_temLoop (Grafo G)
{
    Aresta resposta = NULL;

    for (int x = 0; x < G->vertices.quantia && resposta == NULL; x++)
        resposta = Vertice_temLoop (G->vertices.elementos [x]);

    return resposta;
}

Aresta Grafo_temArestaParalela (Grafo G)
{
    Aresta resposta = NULL;

    for (int x = 0; x < G->vertices.quantia && resposta == NULL; x++)
        resposta = Vertice_temArestaParalela (G, G->vertices.elementos [x]);

    return resposta;
}

// Um Grafo Simples não tem loop ou aresta paralela
Aresta Grafo_naoEhSimples (Grafo G)
{
    Aresta resposta = NULL;

    resposta = Grafo_temLoop (G);

    if (resposta == NULL) resposta = Grafo_temArestaParalela (G);

    return resposta;
}

// "Um grafo no qual todos os vértices possuem o mesmo grau é chamado de grafo regular"
// retorna contraexemplo se o grafo nao for regular, retorna null se grafo for regular
Vertice Grafo_ehIrregular (Grafo G)
{
    int grauDeEntrada = grau_Vertice (G, G->vertices.elementos [0], true);
    int grauDeSaida   = grau_Vertice (G, G->vertices.elementos [0], false);

    for (int x = 1; x < G->vertices.quantia; x++)
        if 
        (
            grau_Vertice (G, G->vertices.elementos [x], false) != grauDeSaida  ||
            grau_Vertice (G, G->vertices.elementos [x], true ) != grauDeEntrada
        )   return           G->vertices.elementos [x];
        
    return NULL;
}

// "Um grafo sem nenhuma aresta é chamado de grafo nulo. 
// Todos os vértices em um grafo nulo são vértices isolados"
bool Grafo_ehNulo (Grafo G)
{
    return G->arestas.quantia == 0;
}

// Um grafo G=(V,A) é dito ser rotulado em vértices (ou arestas) 
// quando a cada vértice (ou aresta) estiver associado um rótulo
string Grafo_ehRotulado (Grafo G)
{
    for (int x = 0; x < G->vertices.quantia; x++)
        if (G->vertices.elementos [x]->nome != NULL)
            return G->vertices.elementos [x]->nome;

    for (int x = 0; x < G->arestas.quantia; x++)
        if (G->arestas.elementos [x]->nome != NULL)
            return G->arestas.elementos [x]->nome;
}

//  Um grafo G=(V,E) é completo se para cada par de vértices vi e vj
// existe uma aresta entre vi e vj . Em um grafo completo quaisquer dois
// vértices distintos são adjacentes (Kn).
//
// Seja Kn um grafo completo com n vértices. O número de arestas de
// um grafo completo é |E| = ((n − 1) × n)/2
bool Grafo_ehCompleto (Grafo G)
{
    if (Grafo_naoEhSimples (G))
        return false;
    else 
    {
        if (G->arestas.quantia == ((G->vertices.quantia - 1) * G->vertices.quantia)/2)
            return true; 
        else 
            return false;
    }
}

// Valida a caminhada no grafo (TEM QUE ACABAR EM NULL)
bool CaminhadaValidaNo_Grafo (Grafo G, Vertice V, Aresta A, ...)
{
    va_list args;
    Vertice v;
    Aresta a;

    va_start(args, A);

    v = V;
    a = A;

    while (a != NULL) 
    {
        if (!Vertice_possuiAresta (v, a)) 
        {
            va_end (args);
            return false;
        }

        v = va_arg (args, Vertice);
        a = va_arg (args, Aresta);
    }

    va_end (args);
    return true;
}

#endif