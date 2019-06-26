#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Clientes.h"
#include "Ventas.h"
#include "LinkedList.h"

static int idVenta = 0;

int generarIdVenta (void)
{
    return idVenta++;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
Ventas* venta_new()
{
    return (Ventas*) malloc(sizeof(Ventas));
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
Ventas* venta_newParametros(char* idVentaStr, char* idClienteStr, char* codProductoStr, char* cantidadStr, char* precioUnitarioStr)
{
    Ventas* pVenta = venta_new();

    if(pVenta != NULL)
    {
        venta_setIdVenta(pVenta, idVentaStr);
        venta_setIdCliente(pVenta, idClienteStr);
        venta_setCodProducto(pVenta, codProductoStr);
        venta_setCantidad(pVenta, cantidadStr);
        venta_setPrecioUnitario(pVenta, precioUnitarioStr);

    }
    return pVenta;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int venta_delete(Ventas* this)
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
int venta_setIdVenta(Ventas* this, char* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
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
int venta_getIdVenta(Ventas* this, int* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
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
int venta_setIdCliente(Ventas* this, char* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
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
int venta_getIdCliente(Ventas* this, int* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
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
int venta_setCodProducto(Ventas* this, char* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
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
int venta_getCodProducto(Ventas* this, int* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
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
int venta_setCantidad(Ventas* this, char* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
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
int venta_getCantidad(Ventas* this, int* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
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
int venta_setPrecioUnitario(Ventas* this, char* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
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
int venta_getPrecioUnitario(Ventas* this, int* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        retorno = 0;
    }

    return retorno;
}
