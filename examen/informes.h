#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Parser.h"
#include "Entrega.h"
#include "LinkedList.h"


// Cantidad total de entregas
int ii_cantidadTotal(LinkedList* this);

// Cantidad de entregas por tipo
int ii_cantidadEntregaTipo(LinkedList* this);

// Cantidad maxima de bultos entregados
int ii_cantidadMaximaBultos(LinkedList* this);

// Promedio de bultos por entrega
int ii_promedioBultos(LinkedList* this);

// Peso promedio por entrega
int ii_pesoPromedio(LinkedList* this);

#endif // INFORMES_H_INCLUDED
