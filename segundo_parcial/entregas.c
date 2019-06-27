#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "entregas.h"


Entregas* entrega_new()
{
    return (Entregas*) malloc(sizeof(Entregas));
}

Entregas* entrega_newParametros(char* idStr,char* tipoStr,char* cantidadStr,char* pesoStr)
{

    Entregas* cli = entrega_new();
    if(cli!=NULL)
    {
        entrega_setIdStr(cli,idStr);
        entrega_setTipo(cli,tipoStr);
        entrega_setCantidad(cli,cantidadStr);
        entrega_setPeso(cli,pesoStr);
    }
    return cli;
}

/*Entregas* entrega_newParametrosConInt(int id,char* nombreStr,char* apellidoStr,char* dniStr)
{

    Entregas* cli = entrega_new();
    if(cli!=NULL)
    {
        entrega_setId(cli,id);
        entrega_setTipo(cli,nombreStr);
        entrega_setCantidad(cli,apellidoStr);
        entrega_setPeso(cli,dniStr);
    }
    return cli;
}*/

int entrega_delete(Entregas* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int entrega_setIdStr(Entregas* this, char* value)
{
    int auxId;
    int retorno = -1;

    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxId = atoi(value);
        if(auxId > 0)
        {
            this->id = auxId;
            retorno = 0;
        }
    }
    return retorno;
}

/*int entrega_setId(Entregas* this,int value)
{
    int retorno  =-1;
    if (this!=NULL && value > 0)
    {
        this->idEntregas = value;
        retorno = 0;
    }
    return retorno;
}*/

int entrega_setPeso(Entregas* this,char* value)
{
    int retorno = -1;
    float auxPeso;

    if(this != NULL && value != NULL && isNumberFloat(value))
    {
        auxPeso = atof(value);
        if(auxPeso > 0)
        {
            this->peso = auxPeso;
            retorno = 0;
        }
    }
    return retorno;
}

int entrega_setTipo(Entregas* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isLetter(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->tipo,value,sizeof(this->tipo));
            retorno = 0;
        }
    }
    return retorno;
}


int entrega_setCantidad(Entregas* this,char* value)
{
    int retorno = -1;
    int auxCantidad;
    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxCantidad = atoi(value);
        if(auxCantidad > 0)
        {
            this->cantidad = auxCantidad;
            retorno = 0;
        }
    }
    return retorno;
}


int entrega_getTipo(Entregas* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

int entrega_getPeso(Entregas* this, float* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->peso;
        retorno = 0;
    }
    return retorno;
}

int entrega_getCantidad(Entregas* this,int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->cantidad;
        retorno = 0;
    }
    return retorno;
}

int entrega_getId(Entregas* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->id;
        retorno = 0;
    }
    return retorno;
}


int entrega_initArray(Entregas* arrayEntregas[],int lenEntregas)
{
    int i;
    int retorno = -1;
    if(arrayEntregas != NULL && lenEntregas > 0)
    {
        for(i=0; i<lenEntregas; i++)
        {
            arrayEntregas[i] = NULL;
        }
        retorno = 0;

    }
    return retorno;
}

int entrega_findFree(Entregas* arrayEntregas[], int lenEntregas)
{
    int i;
    int ret = -1;
    if(arrayEntregas != NULL && lenEntregas > 0)
    {
        for(i=0; i<lenEntregas; i++)
        {
            if(arrayEntregas[i] == NULL)
            {
                ret = i;
                printf("\n----Se encontro lugar libre----\n");
                break;
            }
        }
    }
    return ret;
}

int entrega_sortByTipo(void* pFirstEntregas,void* pSecondEntregas)
{
    int retorno;
    Entregas* pEntregasA;
    Entregas* pEntregasB;

    pEntregasA = (Entregas*) pFirstEntregas;
    pEntregasB = (Entregas*) pSecondEntregas;

    if(strcmp(pEntregasA->tipo,pEntregasB->tipo) > 0)
    {
        retorno = 1;///mayor el primero
    }
    else if(strcmp(pEntregasA->tipo,pEntregasB->tipo) < 0)
    {
        retorno = -1;///menor el primero
    }
    else
    {
        retorno = 0;///ambos iguales
    }
    return retorno;
}

int entrega_contarByTipoSTD(void* pFirstEntrega)
{
    int retorno = 0;
    Entregas* pEntregas;

    pEntregas = (Entregas*) pFirstEntrega;

    if(strcmp(pEntregas->tipo,"STD") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int entrega_contarByTipoEXP(void* pFirstEntrega)
{
    int retorno = 0;
    Entregas* pEntregas;

    pEntregas = (Entregas*) pFirstEntrega;

    if(strcmp(pEntregas->tipo,"EXP") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int entrega_contarByTipoECO(void* pFirstEntrega)
{
    int retorno = 0;
    Entregas* pEntregas;

    pEntregas = (Entregas*) pFirstEntrega;

    if(strcmp(pEntregas->tipo,"ECO") == 0)
    {
        retorno = 1;///mayor el primero
    }

    return retorno;
}

int entrega_contarCantidad(void* pFirstEntrega)
{
    int retorno = -1;
    Entregas* pEntregas;
    pEntregas = (Entregas*) pFirstEntrega;

    if(pEntregas != NULL && pEntregas->cantidad >= 0)
    {
        retorno = pEntregas->cantidad;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int entrega_contarPeso(void* pFirstEntrega)
{
    int retorno = -1;
    Entregas* pEntregas;
    pEntregas = (Entregas*) pFirstEntrega;

    if(pEntregas != NULL && pEntregas->peso >= 0)
    {
        retorno = pEntregas->peso;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}
