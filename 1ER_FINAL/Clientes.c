#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Clientes.h"
#include "Ventas.h"
#include "LinkedList.h"

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
Clientes* cliente_new()
{
    return (Clientes*) malloc(sizeof(Clientes));
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
Clientes* cliente_newParametros(char* idStr, char* nombreStr,char* apellidoStr,char* dniStr)
{
    Clientes* pCliente = cliente_new();

    if(pCliente != NULL)
    {
        cliente_setId(pCliente, idStr);
        cliente_setNombre(pCliente, nombreStr);
        cliente_setApellido(pCliente, apellidoStr);
        cliente_setDni(pCliente, dniStr);
    }
    return pCliente;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int cliente_delete(Clientes* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }

    return retorno;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int cliente_setId(Clientes* this, char* value)
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

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int cliente_getId(Clientes* this, int* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        *value = this->id;

        retorno = 0;
    }
    return retorno;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int cliente_setNombre(Clientes* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isLetter(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->nombre,value, sizeof(this->nombre));
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int cliente_getNombre(Clientes* this, char* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        strncpy(value, this->nombre, sizeof(this->nombre));

        retorno = 0;
    }
    return retorno;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int cliente_setApellido(Clientes* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isLetter(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->apellido, value, sizeof(this->apellido));
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int cliente_getApellido(Clientes* this, char* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        strncpy(value, this->apellido, sizeof(this->apellido));

        retorno = 0;
    }
    return retorno;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int cliente_setDni(Clientes* this, char* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        strncpy(value, this->apellido, sizeof(this->apellido));

        retorno = 0;
    }
    return retorno;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int cliente_getDni(Clientes* this, char* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        strncpy(value, this->apellido, sizeof(this->apellido));

        retorno = 0;
    }
    return retorno;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int cliente_sort(void* pElement1, void* pElement2)
{
    int retorno = -1;

    if(pElement1 != NULL && pElement2 != NULL)
    {
        retorno = 0;
    }
    return retorno;
}
