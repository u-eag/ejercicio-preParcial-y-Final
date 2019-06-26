#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Clientes.h"
#include "Ventas.h"
#include "LinkedList.h"

/** \brief Carga los datos de los clientes desde el archivo clientes.txt (modo texto).
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
int controller_loadClientesFromText(char* path , LinkedList* pArrayListClientes)
{
    FILE* pFile;
    int retorno = 1;

    if (pArrayListClientes != NULL)
    {
        pFile = fopen(path,"r");

        if(pFile != NULL)
        {
            parser_ClientesFromText(pFile , pArrayListClientes);
            fclose(pFile);
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Carga los datos de las ventas desde el archivo ventas.txt (modo texto).
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int
 *
 */
int controller_loadVentasFromText(char* path , LinkedList* pArrayListVentas)
{
    FILE* pFile;
    int retorno = 1;

    if (pArrayListVentas != NULL)
    {
        pFile = fopen(path,"r");

        if(pFile != NULL)
        {
            parser_VentasFromText(pFile , pArrayListVentas);
            fclose(pFile);
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Alta de clientes
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
int controller_addClientes(LinkedList* pArrayListClientes)
{
    int retorno = 1;
    Clientes* pCliente;
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferApellido[4096];
    char bufferDni[4096];

    if (pArrayListClientes != NULL)
    {
        if(!getStringNumerosInt(bufferId, "\nIngrese el ID: ", "\nIngreso invalido\n", 2)
           && !getStringLetras(bufferNombre, "\nIngrese el nombre: ", "\nIngreso invalido\n", 2)
           && !getStringLetras(bufferApellido, "\nIngrese el apellido: ", "\nIngreso invalido\n", 2)
           && !getDni(bufferDni, "\nIngrese el DNI: ", "\nIngreso invalido\n", 2))
        {
            pCliente = cliente_newParametros(bufferId, bufferNombre, bufferApellido, bufferDni);

            if(pCliente != NULL)
            {
                if(!ll_add(pArrayListClientes, pCliente))
                {
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}

/** \brief Modificar datos del cliente
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
int controller_editClientes(LinkedList* pArrayListClientes)
{
    int retorno = 1;
    Clientes* pCliente;
    int id;
    char bufferNombre[4096];
    char bufferApellido[4096];
    char bufferDni[4096];
    int i;
    int option;

    if (pArrayListClientes != NULL)
    {
        // busco el cliente a modificar:
        if(!getIntInRange(&id, "\nIngrese el ID del cliente a modificar: ", "\nIngreso invalido\n", 0, ll_len(pArrayListClientes), 2))
        {
            for (i=0;i<ll_len(pArrayListClientes);i++) // recorro la lista de clientes
            {
                pCliente = ll_get(pArrayListClientes, i); // me guardo el cliente actual

                if(pCliente->id == id) // pregunto si el cliente actual es el que busco
                {
                    // si lo encontré, muestro el menú modificar:
                    do{
                        getIntInRange(&option,"\nSeleccione un campo a modificar: \n\n"
                                      "1)Modificar Nombre\n"
                                      "2)Modificar Apellido\n"
                                      "3)Modificar DNI\n"
                                      "4)Salir\n",
                                      "\nIngreso invalido\n",1,4,1);

                        switch(option)
                        {
                            case 1:
                                if(!getStringLetras(bufferNombre, "\nIngrese el nombre: ", "\nIngreso invalido\n", 2))
                                {
                                    cliente_setNombre(pCliente, bufferNombre);
                                    retorno = 0;
                                }

                                break;

                            case 2:
                                if(!getStringLetras(bufferApellido, "\nIngrese el apellido: ", "\nIngreso invalido\n", 2))
                                {
                                    cliente_setApellido(pCliente, bufferApellido);
                                    retorno = 0;
                                }

                                break;

                            case 3:
                                if(!getDni(bufferDni, "\nIngrese el DNI: ", "\nIngreso invalido\n", 2))
                                {
                                    cliente_setDni(pCliente, bufferDni);
                                    retorno = 0;
                                }

                                break;

                        }
                    }while(option != 4);
                }
            }
        }
    }

    return retorno;
}

/** \brief Baja de cliente
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
 int controller_removeClientes(LinkedList* pArrayListClientes)
{
    int retorno = 1;
    Clientes* pCliente;
    int id;
    int i;

    if (pArrayListClientes != NULL)
    {
        // busco el cliente a eliminar:
        if(!getIntInRange(&id, "\nIngrese el ID del cliente a eliminar: ", "\nIngreso invalido\n", 0, ll_len(pArrayListClientes), 2))
        {
            for (i=0;i<ll_len(pArrayListClientes);i++) // recorro la lista de clientes
            {
                pCliente = ll_get(pArrayListClientes, i); // me guardo el cliente actual

                if(pCliente->id == id) // pregunto si el cliente actual es el que busco
                {
                    ll_remove(pArrayListClientes, id);
                    cliente_delete(pCliente); // para hacer el free
                    retorno = 0;
                    break;
                }
            }
        }
    }

    return retorno;
}

/** \brief Listar clientes
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
int controller_ListClientes(LinkedList* pArrayListClientes)
{
    int retorno = 1;
    Clientes* pCliente;
    int i;

    if(pArrayListClientes != NULL && ll_len(pArrayListClientes) > 0) // que tenga aunque sea un elemento para listar
    {
        printf("id_cliente\t nombre_cliente\t apellido_cliente\t dni_cliente\n");

        for (i=0;i<ll_len(pArrayListClientes);i++)
        {
            pCliente = ll_get(pArrayListClientes, i);

            if(pCliente != NULL)
            {
                printf ("%d\t %s\t %s\t %s\n", pCliente->id, pCliente->nombre,
                                                pCliente->apellido, pCliente->dni);
            }
        }

        retorno = 0;
    }

    return retorno;
}

/** \brief Ordenar clientes
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
int controller_sortClientes(LinkedList* pArrayListClientes)
{
    int retorno = 1;

    if(pArrayListClientes != NULL)
    {
        ll_sort(pArrayListClientes, cliente_sort, 1);

        retorno = 0;
    }

return retorno;
}

/** \brief Guarda los datos de los clientes en el archivo clientes.txt (modo texto).
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
int controller_saveClientesAsText(char* path , LinkedList* pArrayListClientes)
{
    int retorno = 1;
    Clientes* pCliente;
    int i;

    FILE* pFile = fopen(path,"w");

    if(pArrayListClientes != NULL && pFile != NULL)
    {
        fprintf(pFile, "id,nombre,apellido,dni\n");

        for (i=0;i<ll_len(pArrayListClientes);i++)
        {
            pCliente = ll_get(pArrayListClientes, i);

            if(pCliente != NULL)
            {
                fprintf (pFile,"%d,%s,%s,%s\n", pCliente->id, pCliente->nombre,
                                                pCliente->apellido, pCliente->dni);
            }
        }

        fclose(pFile);

        retorno = 0;
    }

    return retorno;
}
