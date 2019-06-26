#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Clientes.h"
#include "Ventas.h"
#include "parser.h"
#include "LinkedList.h"

/** \brief Parsea los datos los datos de los clientes desde el archivo clientes.txt (modo texto).
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
int parser_ClientesFromText(FILE* pFile , LinkedList* pArrayListClientes) // char* para recibir el path en lugar el puntero a file
// se para en ese puntero a file y lo empieza a recorrer
{
    int retorno = 1;
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferApellido[4096];
    char bufferDni[4096];
    Clientes* pCliente;
    int cantidadDatos; // para saber si la cantidad de elementos que saqué del archivo está ok

    if(pFile != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                     bufferNombre,
                                                     bufferApellido,
                                                     bufferDni);
        while(!feof(pFile))
        {
            cantidadDatos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                                         bufferNombre,
                                                                         bufferApellido,
                                                                         bufferDni);

            if(cantidadDatos == 4) // chequeo si recibí los 4 datos que pedí
            {
                pCliente = cliente_newParametros( bufferId,
                                                  bufferNombre,
                                                  bufferApellido,
                                                  bufferDni);

                if(pCliente != NULL)
                {
                    if(!ll_add(pArrayListClientes,pCliente))
                    {
                        retorno = 0;
                    }
                }
            }
        }
    }

    return retorno;
}

/** \brief Parsea los datos los datos de las ventas desde el archivo ventas.txt (modo texto).
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int
 *
 */
int parser_VentasFromText(FILE* pFile , LinkedList* pArrayListVentas)
{
    int retorno = 1;
    char bufferIdVenta[4096];
    char bufferIdCliente[4096];
    char bufferCodProducto[4096];
    char bufferCantidad[4096];
    char bufferPrecioUnitario[4096];
    Ventas* pVenta;
    int cantidadDatos; // para saber si la cantidad de elementos que saqué del archivo está ok

    if(pFile != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",   bufferIdVenta,
                                                            bufferIdCliente,
                                                            bufferCodProducto,
                                                            bufferCantidad,
                                                            bufferPrecioUnitario);
        while(!feof(pFile))
        {
            cantidadDatos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",   bufferIdVenta,
                                                                                bufferIdCliente,
                                                                                bufferCodProducto,
                                                                                bufferCantidad,
                                                                                bufferPrecioUnitario);

            if(cantidadDatos == 5) // chequeo si recibí los 5 datos que pedí
            {
                pVenta = venta_newParametros(   bufferIdVenta,
                                                bufferIdCliente,
                                                bufferCodProducto,
                                                bufferCantidad,
                                                bufferPrecioUnitario);

                if(pVenta != NULL)
                {
                    if(!ll_add(pArrayListVentas, pVenta))
                    {
                        retorno = 0;
                    }
                }
            }
        }
    }

    return retorno;
}
