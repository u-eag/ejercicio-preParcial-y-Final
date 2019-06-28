#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Parser.h"
#include "LinkedList.h"
#include "informes.h"
#include "Venta.h"
#include "Fecha.h"

typedef struct
{
    int id;
    char fechaStr[20];
    char tipoStr[20];
    int cantidad;
    float precio;
    char cuitStr[20];

}Venta;

Venta* venta_new();

int venta_delete(Venta* this);

Venta* venta_newParametros(char* id, char* fechaStr, char* tipoStr,
                           char* cantidad, char* precio, char* cuitStr);

int venta_setId(Venta* this, char* value);
int venta_getId(Venta* this, int* value);

int venta_setFechaStr(Venta* this, char* value);
int venta_getFechaStr(Venta* this, char* value);

int venta_setTipoStr(Venta* this, char* value);
int venta_getTipoStr(Venta* this, char* value);

int venta_getTipoTruncado(Venta* this, char* value);

int venta_setCantidadStr(Venta* this, char* value);
int venta_getCantidad(Venta* this, int* value);

int venta_setPrecio(Venta* this, char* value);
int venta_getPrecio(Venta* this, float* value);

int venta_setCuitStr(Venta* this, char* value);
int venta_getCuitStr(Venta* this, char* value);

int venta_contarMayor150(void* pElement);
int venta_contarMayor300(void* pElement);
int venta_contarPolaroid(void* pElement);

int venta_contarTotal(void* pElement);

#endif // VENTA_H_INCLUDED
