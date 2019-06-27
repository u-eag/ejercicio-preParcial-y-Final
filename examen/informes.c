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

// Cantidad de entregas por tipo
/*int ii_cantidadEntregaTipo(LinkedList* this)
{
    int retorno;
    Entrega pEntrega;
    int acumuladorSTD = 0;
    int acumuladorEXP = 0;
    int acumuladorECO = 0;
    int i;

    if(this != NULL)
    {
        for(i=0;i<ll_len(this);i++)
        {
            pEntrega = ll_get(this, i);

            if(pEntrega != NULL)
            {
                if(strcmp(pEntrega->tipo, STD) == 0)
                {
                    acumuladorSTD++;
                }
                else if(strcmp(pEntrega->tipo, EXP) == 0)
                {
                    acumuladorEXP++;
                }
                else
                {
                    acumuladorECO++;
                }
            }
        }
    }

    return retorno;
}*/

// Cantidad maxima de bultos entregados
int ii_cantidadMaximaBultos(LinkedList* this)
{
    int retorno;

    if(this != NULL)
    {
        retorno = 0;
    }

    return retorno;
}

// Promedio de bultos por entrega
int ii_promedioBultos(LinkedList* this)
{
    int retorno;

    if(this != NULL)
    {
        retorno = 0;
    }

    return retorno;
}

// Peso promedio por entrega
int ii_pesoPromedio(LinkedList* this)
{
    int retorno;

    if(this != NULL)
    {
        retorno = 0;
    }

    return retorno;
}
