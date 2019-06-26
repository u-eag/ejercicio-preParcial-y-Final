#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Clientes.h"
#include "Ventas.h"
#include "LinkedList.h"

int parser_ClientesFromText(FILE* pFile, LinkedList* pArrayListClientes);
int parser_VentasFromText(FILE* pFile, LinkedList* pArrayListVentas);

