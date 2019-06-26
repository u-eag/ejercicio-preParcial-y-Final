#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Clientes.h"
#include "Ventas.h"
#include "LinkedList.h"

int controller_loadClientesFromText(char* path , LinkedList* pArrayListClientes);
int controller_loadVentasFromText(char* path , LinkedList* pArrayListVentas);

int controller_addClientes(LinkedList* pArrayListClientes);


int controller_editClientes(LinkedList* pArrayListClientes);
// ventas no necesita una función edit

int controller_removeClientes(LinkedList* pArrayListClientes);


int controller_ListClientes(LinkedList* pArrayListClientes);


int controller_sortClientes(LinkedList* pArrayListClientes);


int controller_saveClientesAsText(char* path , LinkedList* pArrayListClientes);



