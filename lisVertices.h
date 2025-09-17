#ifndef lisVertices_h
#define lisVertices_h

#include "Main.h"

lisVertices nova_lisVertice ()
{
    lisVertices  tmp;

    tmp.tamMax = 10;
    tmp.quantia = 0;
    malocar (tmp.elementos, Vertice*, 10 * sizeof (sptVertice));

    return tmp;  
}

int putVertice (lisVertices *lis, Vertice v)
{
    if (v == NULL) 
        printf ("\n\n\tputVertice recebendo valores nulos\n\n");

    if (lis->quantia + 1 >= lis->tamMax)
    {
        lis->tamMax += 10;

        lis->elementos = (Vertice*) realloc (lis->elementos, lis->tamMax * sizeof (sptVertice));
    }
    else lis->elementos [lis->quantia ++] = v;

    return lis->quantia;
} 

#endif