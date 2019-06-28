#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Parser.h"
#include "LinkedList.h"
#include "informes.h"
#include "Venta.h"
#include "Fecha.h"

Venta* venta_new()
{
    return (Venta*) malloc(sizeof(Venta));
}

int venta_delete(Venta* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }

    return retorno;
}

Venta* venta_newParametros(char* id, char* fechaStr, char* tipoStr,
                           char* cantidad, char* precio, char* cuitStr)
{
    Venta* pVenta = venta_new();

    if(pVenta != NULL)
    {
        /*if( !venta_setId(pVenta, id)
            && !venta_setFechaStr(pVenta, fechaStr)
            && !venta_setTipoStr(pVenta, tipoStr)
            && !venta_setCantidadStr(pVenta, cantidad)
            && !venta_setPrecio(pVenta, cantidad)
            && !venta_setCuitStr(pVenta, cuitStr))
        {
            printf("OK\n");
        }
        else
        {
            venta_delete(pVenta);
        }*/

        venta_setId(pVenta, id);
        venta_setFechaStr(pVenta, fechaStr);
        venta_setTipoStr(pVenta, tipoStr);
        venta_setCantidadStr(pVenta, cantidad);
        venta_setPrecio(pVenta, cantidad);
        venta_setCuitStr(pVenta, cuitStr);
    }

    return pVenta;
}

int venta_setId(Venta* this, char* value)
{
    int id;
    int retorno = -1;

    if(this != NULL && value != NULL && isNumberInt(value))
    {
        id = atoi(value);

        if(id >= 0)
        {
            this->id = id;
            retorno = 0;
        }
    }
    return retorno;
}

int venta_getId(Venta* this, int* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        *value = this->id;

        retorno = 0;
    }
    return retorno;
}

int venta_setFechaStr(Venta* this, char* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL) // && isFecha(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->fechaStr, value, sizeof(this->fechaStr));
            retorno = 0;
        }
    }
    return retorno;
}

int venta_getFechaStr(Venta* this, char* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        strncpy(value, this->fechaStr, sizeof(this->fechaStr));

        retorno = 0;
    }
    return retorno;
}

int venta_setTipoStr(Venta* this, char* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL) //&& isFoto(value)) 4R_10x15
    {
        if(strlen(value) > 0)
        {
            strncpy(this->tipoStr, value , sizeof(this->tipoStr));
            retorno = 0;
        }
    }
    return retorno;
}

int venta_getTipoStr(Venta* this, char* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        strncpy(value, this->tipoStr, sizeof(this->tipoStr));

        retorno = 0;
    }
    return retorno;
}

int venta_setCantidadStr(Venta* this, char* value)
{
    int retorno = -1;
    int auxCantidad;

    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxCantidad = atoi(value);

        if(auxCantidad >= 0)
        {
            this->cantidad = auxCantidad;
            retorno = 0;
        }
    }
    return retorno;
}

int venta_getCantidad(Venta* this, int* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        *value = this->cantidad;

        retorno = 0;
    }
    return retorno;
}

int venta_setPrecio(Venta* this, char* value)
{
    int retorno = -1;
    int precio;

    if(this != NULL && value != NULL && isNumberFloat(value))
    {
        precio = atof(value);

        if(precio >= 0)
        {
            this->precio = precio;
            retorno = 0;
        }
    }
    return retorno;
}

int venta_getPrecio(Venta* this, float* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        *value = this->precio;

        retorno = 0;
    }
    return retorno;
}

int venta_setCuitStr(Venta* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isCuit(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->cuitStr,value,sizeof(this->cuitStr));
            retorno = 0;
        }
    }
    return retorno;
}

int venta_getCuitStr(Venta* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->cuitStr,sizeof(this->cuitStr));
        retorno = 0;
    }
    return retorno;
}

int venta_contarMayor150(void* pElement)
{
    int retorno = 0;
    Venta* pVentas;
    int precioTotal;

    pVentas = (Venta*) pElement;

    precioTotal = pVentas->precio * pVentas->cantidad;

    if(precioTotal > 150)
    {
        retorno = 1;
    }

    return retorno;
}

int venta_contarMayor300(void* pElement)
{
    int retorno = 0;
    Venta* pVentas;
    int precioTotal;

    pVentas = (Venta*) pElement;

    precioTotal = pVentas->precio * pVentas->cantidad;

    if(precioTotal > 300)
    {
        retorno = 1;
    }

    return retorno;
}

int venta_contarPolaroid(void* pElement)
{
    int retorno = 0; // para que ll_contar NO lo cuente
    Venta* pVentas;
    pVentas = (Venta*) pElement;

    //char tipoTruncado[20];
    //venta_getTipoTruncado(pVentas, tipoTruncado);
    //if(strcmp(tipoTruncado,'POLAROID') == 0)

    /* si fuese cantidad de fotos reveladas:
    if(strcmp(pVentas->tipoStr,"POLAROID_")>0)
    {
        retorno = pVentas->cantidad;
    }*/

    // cantidad de personas que revelaron polaroids:
    if(strcmp(pVentas->tipoStr,"POLAROID_")>0)
    {
        retorno = 1; // para que ll_contar lo cuente
    }

    return retorno;
}

int venta_getTipoTruncado(Venta* this, char* value)
{
    int retorno = -1;
 /*   char tipoTruncado[20];
    Venta* pVenta;

    if(this != NULL && value != NULL)
    {
        pVenta = venta_getTipoStr(this, tipoTruncado);

        if(!pVenta)
        {
            while(!strcmp(pVenta->tipoStr,'_')==0)
            {
                strncpy(tipoTruncado, pVenta->tipoStr, sizeof(tipoTruncado));
            }

            *value = tipoTruncado;

            retorno = 0;
        }
    }*/
    return retorno;
}

int venta_contarTotal(void* pElement)
{
    int retorno = -1;
    Venta* pVentas;

    pVentas = (Venta*) pElement;

    retorno = pVentas->cantidad;

    //printf("Cantidad: %d\n", pVentas->cantidad);

    return retorno;
}
