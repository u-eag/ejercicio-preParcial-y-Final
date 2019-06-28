#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Parser.h"
#include "LinkedList.h"
#include "informes.h"
#include "Venta.h"
#include "Fecha.h"

// Cantidad total de entregas
int ii_cantidadTotal(LinkedList* this) // cuento lo que contiene el campo cantidad de cada venta
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = 0;

        retorno += ll_contar(this,venta_contarTotal);
    }

    return retorno;
}

// Cantidad de ventas por un monto mayor a $150:
int ii_mayor150(LinkedList* this)
{
    int retorno = -1;

    if(this!= NULL)
    {
        retorno = 0;

        retorno += ll_contar(this,venta_contarMayor150);
    }
    return retorno;
}

// Cantidad de ventas por un monto mayor a $300:
int ii_mayor300(LinkedList* this)
{
    int retorno = -1;

    if(this!= NULL)
    {
        retorno = 0;

        retorno += ll_contar(this,venta_contarMayor300);
    }
    return retorno;
}

// Cantidad de fotos polaroids reveladas:
int ii_polaroid(LinkedList* this)
{
    int retorno = -1;

    if(this!= NULL)
    {
        retorno = 0;

        retorno += ll_contar(this,venta_contarPolaroid);
    }
    return retorno;
}
