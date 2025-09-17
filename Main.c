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
    Grafo G = novo_Grafo  (true, NULL);

    Vertice A = novo_Vertice (G, NULL);
    Vertice B = novo_Vertice (G, NULL);
    Vertice C = novo_Vertice (G, NULL);
    Vertice D = novo_Vertice (G, NULL);
    
    Aresta a1 = nova_Aresta (G, A, B, NULL);
    Aresta a2 = nova_Aresta (G, A, B, NULL);
    Aresta a3 = nova_Aresta (G, A, C, NULL);
    Aresta a4 = nova_Aresta (G, A, C, NULL);
    Aresta a5 = nova_Aresta (G, A, D, NULL);
    Aresta a6 = nova_Aresta (G, D, B, NULL);
    Aresta a7 = nova_Aresta (G, D, C, NULL);

    imprimir_Grafo (G);

    limpar_Grafo (G);

    printf 
    (
        "\n\n\tFim do programa\n\n\tMallocs: %d\n\tLimpezas: %d\n\tLixo: %d\n\n", 
        alocacoes_feitas, limpezas_feitas, alocacoes_feitas - limpezas_feitas
    );
}
