#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "LinkedList.h"

int generarArchivoInformes(char* fileName,LinkedList* listaEntregas);

int informe_cantidadTotalEntregas(LinkedList* pArrayListEntregas);
int informe_cantidadEntregasPorTipo(LinkedList* pArrayListEntregas,int tipo);
int informe_cantidadMaximaDeEntregas(LinkedList* pArrayListEntregas);
int informe_cantidadBultosPorEntrega(LinkedList* pArrayListEntregas);
int informe_pesoTotalPorEntrega(LinkedList* pArrayListEntregas);

#endif // INFORMES_H_INCLUDED
