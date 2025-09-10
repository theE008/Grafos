#include "Grafos.h"

#include "Vertices.h"
#include "lisAresta.h"
#include "lisVertices.h"

////////////////////////////////////

Aresta nova_Aresta (Grafo grafo, Vertice origem, Vertice destino)
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

    putAresta (&grafo->arestas, tmp);

    return tmp;
}

//

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
    // fazer sistema para apagar vertices
}

//

int main (void)
{
    Grafo G = novo_Grafo (true);
    Vertice v = novo_Vertice (G);
    Vertice w = novo_Vertice (G);
    Aresta v_w = nova_Aresta (G, v, w);

    limpar_Grafo (G);

    printf 
    (
        "\n\n\tFim do programa\n\n\tMallocs: %d\n\tLimpezas: %d\n\tLixo: %d\n\n", 
        alocacoes_feitas, limpezas_feitas, alocacoes_feitas - limpezas_feitas
    );
}
