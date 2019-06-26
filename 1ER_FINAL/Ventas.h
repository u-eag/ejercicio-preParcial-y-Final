#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "Clientes.h"
#include "parser.h"

typedef struct
{
    int id_venta;
    int id_cliente;
    int codProducto;
    int cantidad;
    float precioUnitario;

}Ventas;

Ventas* venta_new(); // malloc: construimos espacio para el sizeof de ese cliente
Ventas* venta_newParametros(char* idVentaStr, char* idClienteStr, char* codProductoStr, char* cantidadStr, char* precioUnitarioStr);
int venta_delete(Ventas* this);

int venta_setIdVenta(Ventas* this, char* value);
int venta_getIdVenta(Ventas* this, int* value);

int venta_setIdCliente(Ventas* this, char* value);
int venta_getIdCliente(Ventas* this, int* value);

int venta_setCodProducto(Ventas* this, char* value);
int venta_getCodProducto(Ventas* this, int* value);

int venta_setCantidad(Ventas* this, char* value);
int venta_getCantidad(Ventas* this, int* value);

int venta_setPrecioUnitario(Ventas* this, char* value);
int venta_getPrecioUnitario(Ventas* this, int* value);

#endif // VENTAS_H_INCLUDED
