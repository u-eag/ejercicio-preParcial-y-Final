#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Parser.h"
#include "Entrega.h"
#include "LinkedList.h"
#include "informes.h"

// Cantidad total de entregas
int ii_cantidadTotal(LinkedList* this)
{
    int retorno;

    if(this != NULL)
    {
        retorno = ll_len(this);
    }

    return retorno;
}

// Cantidad de entregas por tipo: [1]STD [2]EXP [3]ECO
int ii_cantidadEntregaTipo(LinkedList* this, int tipo)
{
    int retorno = -1;
    Entrega* pEntrega;
    int i;

    if(this != NULL && tipo >= 1 && tipo >= 3)
    {
        for(i=0;i<ll_len(this);i++)
        {
            pEntrega = ll_get(this, i);

            if(pEntrega != NULL)
            {
                if(tipo == 1)
                {
                    retorno = ll_contar(this, entrega_contarSTD);
                }
                else if(tipo == 2)
                {
                    retorno = ll_contar(this, entrega_contarEXP);
                }
                else // tipo 3
                {
                    retorno = ll_contar(this, entrega_contarECO);
                }
            }
        }
    }

    return retorno;
}

// Cantidad maxima de bultos entregados
int ii_cantidadMaximaBultos(LinkedList* this)
{
    int retorno = -1;
    int i;
    Entrega* pEntrega;
    int auxMaximo = 0;

    if(this != NULL)
    {
        retorno = 0;

        for(i=0;i<ll_len(this);i++)
        {
            pEntrega = ll_get(this,i);

            if(pEntrega != NULL && pEntrega->cantidad > auxMaximo)
            {
                auxMaximo = pEntrega->cantidad;
            }
        }

        retorno = auxMaximo;
    }

    return retorno;
}

// Promedio de bultos por entrega
int ii_promedioBultos(LinkedList* this)
{
    int retorno = -1;
    int i;
    Entrega* pEntrega;
    int cantidadTotal = 0;
    float promedio;

    if(this != NULL)
    {
        retorno = 0;

        for(i=0;i<ll_len(this);i++)
        {
            pEntrega = ll_get(this,i);

            if(pEntrega != NULL && pEntrega->cantidad )
            {
                cantidadTotal += ll_contar(this, entrega_contarCantidad);
            }
        }
        retorno = cantidadTotal;
    }
    return retorno;
}

// Peso promedio por entrega
int ii_pesoPromedio(LinkedList* this)
{
    int retorno = -1;
    int i;
    Entrega* pEntrega;
    float cantidadTotal = 0;
    //float promedio;

    if(this != NULL)
    {
        retorno = 0;

        for(i=0;i<ll_len(this);i++)
        {
            pEntrega = ll_get(this,i);

            if(pEntrega != NULL && pEntrega->peso >= 0)
            {
                cantidadTotal += ll_contarFloat(this,entrega_contarPeso);
            }
        }
        retorno = cantidadTotal;
    }
    return retorno;
}
