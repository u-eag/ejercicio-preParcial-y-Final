#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED
#include "Fecha.h"
#include "Socios.h"
#include "Libros.h"

typedef struct
{
    int isEmpty;
    int idPrestamos; // C�digo del Pr�stamo (autoincremental a partir de 0)
    int idLibro; // C�digo del Libro
    int idSocio; // C�digo del Socio
    Fecha fechaPrestamo;
}Prestamos;

#endif // PRESTAMOS_H_INCLUDED

int initPrestamos(Prestamos* list, int len);
int findEmptyIndexPrestamos(Prestamos* list, int len, int* index);
int altaPrestamos(Prestamos* listPrestamos, int lenPrestamos, Libros* listLibros, int lenLibros, Socios* listSocios, int lenSocios);
int printPrestamos(Prestamos* listPrestamos, int lenPrestamos, Libros* listLibros, int lenLibros, Socios* listSocios, int lenSocios);


