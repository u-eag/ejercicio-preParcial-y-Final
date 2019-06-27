#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Parser.h"
#include "Entrega.h"
#include "LinkedList.h"
#include "informes.h"

Entrega* entrega_new()
{
    return (Entrega*) malloc(sizeof(Entrega));
}

int entrega_delete(Entrega* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

Entrega* entrega_newParametros(char* idStr, char* tipo, char* cantidad, char* peso)
{
    Entrega* pEntrega = entrega_new();

    if(pEntrega != NULL)
    {
        entrega_setId(pEntrega, idStr);
        entrega_setTipo(pEntrega, tipo);
        entrega_setCantidad(pEntrega, cantidad);
        entrega_setPeso(pEntrega, peso);
    }

    return pEntrega;
}

int entrega_setId(Entrega* this, char* value)
{
    int auxID;
    int retorno = -1;

    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxID = atoi(value);

        if(auxID >= 0)
        {
            this->id = auxID;
            retorno = 0;
        }
    }
    return retorno;
}

int entrega_setTipo(Entrega* this, char* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL && isLetter(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->tipo, value , sizeof(this->tipo));
            retorno = 0;
        }
    }
    return retorno;
}

int entrega_setCantidad(Entrega* this, char* value)
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

int entrega_setPeso(Entrega* this, char* value)
{
    int retorno = -1;
    int auxPeso;

    if(this != NULL && value != NULL && isNumberFloat(value))
    {
        auxPeso = atof(value);

        if(auxPeso >= 0)
        {
            this->peso = auxPeso;
            retorno = 0;
        }
    }
    return retorno;
}

int entrega_getId(Entrega* this, int* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        *value = this->id;

        retorno = 0;
    }
    return retorno;
}

int entrega_getTipo(Entrega* this, char* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        strncpy(value, this->tipo, sizeof(this->tipo));

        retorno = 0;
    }
    return retorno;
}

int entrega_getCantidad(Entrega* this, int* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        *value = this->cantidad;

        retorno = 0;
    }
    return retorno;
}

int entrega_getPeso(Entrega* this, float* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        *value = this->peso;

        retorno = 0;
    }
    return retorno;
}

int entrega_contarSTD(void* this)
{
    int retorno = 0; // [0]si F [1] si V
    Entrega* pEntrega;

    if(this != NULL)
    {
        pEntrega = (Entrega*) this;

        if(pEntrega != NULL)
        {
            if(strcmp(pEntrega->tipo, "STD") == 0)
            {
                retorno = 1; // para que ll_contar pueda contarla
            }
        }
    }

    return retorno;
}

int entrega_contarEXP(void* this)
{
    int retorno = 0; // [0]si F [1] si V
    Entrega* pEntrega;

    if(this != NULL)
    {
        pEntrega = (Entrega*) this;

        if(pEntrega != NULL)
        {
            if(strcmp(pEntrega->tipo, "EXP") == 0)
            {
                retorno = 1; // para que ll_contar pueda contarla
            }
        }
    }

    return retorno;
}

int entrega_contarECO(void* this)
{
    int retorno = 0; // [0]si F [1] si V
    Entrega* pEntrega;

    if(this != NULL)
    {
        pEntrega = (Entrega*) this;

        if(pEntrega != NULL)
        {
            if(strcmp(pEntrega->tipo, "ECO") == 0)
            {
                retorno = 1; // para que ll_contar pueda contarla
            }
        }
    }

    return retorno;
}

int entrega_contarCantidad(void* this)
{
    int retorno = 0;
    Entrega* pEntrega;

    pEntrega = (Entrega*) this;

    if(pEntrega != NULL && pEntrega->cantidad >= 0)
    {
        retorno = pEntrega->cantidad;
    }

    return retorno;
}

int entrega_contarPeso(void* this)
{
    int retorno = 0;
    Entrega* pEntrega;

    pEntrega = (Entrega*) this;

    if(pEntrega != NULL && pEntrega->peso >= 0)
    {
        retorno = pEntrega->peso;
    }

    return retorno;
}
