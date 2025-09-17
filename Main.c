#include "Main.h"

#include "Vertices.h"
#include "lisAresta.h"
#include "lisVertices.h"
#include "Vertices.h"
#include "Grafo.h"
#include "Aresta.h"

////////////////////////////////////

int main (void)
{
    Grafo G = novo_Grafo  (true);

    Vertice A = novo_Vertice (G);
    Vertice B = novo_Vertice (G);
    Vertice C = novo_Vertice (G);
    Vertice D = novo_Vertice (G);
    
    Aresta a1 = nova_Aresta (G, A, B);
    Aresta a2 = nova_Aresta (G, A, B);
    Aresta a3 = nova_Aresta (G, A, C);
    Aresta a4 = nova_Aresta (G, A, C);
    Aresta a5 = nova_Aresta (G, A, D);
    Aresta a6 = nova_Aresta (G, D, B);
    Aresta a7 = nova_Aresta (G, D, C);

    imprimir_Grafo (G);

    limpar_Grafo (G);

    printf 
    (
        "\n\n\tFim do programa\n\n\tMallocs: %d\n\tLimpezas: %d\n\tLixo: %d\n\n", 
        alocacoes_feitas, limpezas_feitas, alocacoes_feitas - limpezas_feitas
    );
}
