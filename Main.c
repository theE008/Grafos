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
    Grafo G = novo_Grafo  (true, "Loop");

    Vertice A = novo_Vertice (G, "A");

    Aresta a1 = nova_Aresta (G, A, A, NULL);

    imprimir_Grafo (G);
    limpar_Grafo (G);

    printf 
    (
        "\n\n\tFim do programa\n\n\tMallocs: %d\n\tLimpezas: %d\n\tLixo: %d\n\n", 
        alocacoes_feitas, limpezas_feitas, alocacoes_feitas - limpezas_feitas
    );
}
