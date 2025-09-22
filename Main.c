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
    Grafo G = novo_Grafo  (false, "Grafo Regular");

    Vertice v = novo_Vertice (G, NULL);
    Vertice w = novo_Vertice (G, NULL);
    Vertice x = novo_Vertice (G, NULL);
    
    Aresta v_w = nova_Aresta (G, v, w, NULL);
    Aresta w_x = nova_Aresta (G, w, x, NULL);
    Aresta x_v = nova_Aresta (G, x, v, NULL);
    
    printf ("Grafo eh irregular? %d\n", (Grafo_ehIrregular (G))?1:0);
    printf ("A caminhada 1 1_2 2 2_3 3 3_1 eh valida? %d\n", (
        CaminhadaValidaNo_Grafo (G,
            v, v_w, w, w_x, x, x_v, v,
        NULL)
    )?1:0);

    printf ("A caminhada 1 1_2 2 2_3 1 3_1 eh valida? %d\n", ( // dando 1 erroneamente
        CaminhadaValidaNo_Grafo (G,
            v, v_w, w, w_x, v, x_v, v,
        NULL)
    )?1:0);

    imprimir_Grafo (G);
    limpar_Grafo (G);

    printf 
    (
        "\n\n\tFim do programa\n\n\tMallocs: %d\n\tLimpezas: %d\n\tLixo: %d\n\n", 
        alocacoes_feitas, limpezas_feitas, alocacoes_feitas - limpezas_feitas
    );
}
