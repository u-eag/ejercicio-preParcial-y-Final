#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED
#include "Fecha.h"

typedef struct
{
    int isEmpty;
    int idSocios; // Código de Socio (autoincremental arrancando en 0)
    char nombre[31];
    char apellido[31];
    char sexo; // [F][M]
    char telefono[16]; // 16 caracteres
    char mail[31]; // 31 caracteres
    Fecha fechaAsociado;
}Socios;

#endif // SOCIOS_H_INCLUDED

int initSocios(Socios* list, int len);
int findEmptyIndexSocios(Socios* list, int len, int* index);
int altaSocios(Socios* list, int len);
int printSocios(Socios* list, int len);
int buscarSocios(Socios* list, int len, int* input);
int bajaSocios(Socios* list, int len);
int ordenarSocios(Socios* list, int len);
int modificarSocios(Socios* list, int len);

