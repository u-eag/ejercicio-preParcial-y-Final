#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "parser.h"

typedef struct
{
    int id;
    char nombre[128];
    char apellido[128];
    char dni[20];

}Clientes;

Clientes* cliente_new(); // malloc: construimos espacio para el sizeof de ese cliente
Clientes* cliente_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* dniStr);
int cliente_delete(Clientes* this);

int cliente_setId(Clientes* this, char* value); // tip: hacer un setId que soporte un char (para todos las funcines que reciben int y float)
int cliente_getId(Clientes* this, int* value);

int cliente_setNombre(Clientes* this, char* value);
int cliente_getNombre(Clientes* this, char* value);

int cliente_setApellido(Clientes* this, char* value);
int cliente_getApellido(Clientes* this, char* value);

int cliente_setDni(Clientes* this, char* value);
int cliente_getDni(Clientes* this, char* value);

int cliente_sort(void* pElement1, void* pElement2); // pFunc criterio para ll_sort

#endif // CLIENTES_H_INCLUDED
