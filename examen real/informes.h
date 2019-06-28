#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Parser.h"
#include "LinkedList.h"

// Cantidad total de entregas
int ii_cantidadTotal(LinkedList* this);

// Cantidad de ventas por un monto mayor a $150:
int ii_mayor150(LinkedList* this);

// Cantidad de ventas por un monto mayor a $300:
int ii_mayor300(LinkedList* this);

// Cantidad de fotos polaroids reveladas:
int ii_polaroid(LinkedList* this);

#endif // INFORMES_H_INCLUDED
