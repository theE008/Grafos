#ifndef lisAresta_h
#define lisAresta_h

#include "Main.h"

lisArestas nova_lisAresta ()
{
    lisArestas  tmp;

    tmp.tamMax = 10;
    tmp.quantia = 0;
    malocar (tmp.arestas, Aresta*, 10 * sizeof (sptAresta));

    return tmp;
}

int putAresta (lisArestas *lis, Aresta ar)
{
    if (ar == NULL) 
        printf ("\n\n\tputAresta recebendo valores nulos\n\n");

    if (lis->quantia + 1 >= lis->tamMax)
    {
        lis->tamMax += 10;

        lis->arestas = (Aresta *) realloc (lis->arestas, lis->tamMax * sizeof (Aresta)); // <- aqui
    }
    else lis->arestas [lis->quantia ++] = ar;

    return lis->quantia;
} 

void limpar_lisAresta (lisArestas *lis)
{
    for (int x = 0; x < lis->quantia; x++)
        limpar (lis->arestas [x]);

    limpar (lis->arestas);

    //limpar (lis); // erro: lis não é instanciado
}

#endif