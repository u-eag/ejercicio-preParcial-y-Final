#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Autores.h"
#include "Fecha.h"
#include "Libros.h"
#include "Prestamos.h"
#include "Socios.h"
#include "validaciones.h"

int informarListar (Prestamos* listPrestamos, int lenPrestamos, Libros* listLibros, int lenLibros, Socios* listSocios, int lenSocios);

// punto A.
int calcularPrestamos (Prestamos* listPrestamos, int lenPrestamos, float* promedio);

// punto B.
int calcularDiasMenoresAlPromedio (Prestamos* listPrestamos, int lenPrestamos, float promedio);

// punto C.
int unLibroMuchosSocios (Prestamos* listPrestamos, int lenPrestamos, Libros* listLibros, int lenLibros, Socios* listSocios, int lenSocios);

// punto D.
int unSocioMuchosLibros (Prestamos* listPrestamos, int lenPrestamos, Libros* listLibros, int lenLibros, Socios* listSocios, int lenSocios);

// punto E.
int listarLibrosMenosSolicitados (Prestamos* listPrestamos, int lenPrestamos);

// punto F.
int listarSociosMasActivos (Prestamos* listPrestamos, int lenPrestamos);

// punto G.
int unaFechaMuchosLibros (Prestamos* listPrestamos, int lenPrestamos, Libros* listLibros, int lenLibros, Socios* listSocios, int lenSocios);

int buscarDia(Prestamos* listPrestamos, int lenPrestamos, int* input);
int buscarMes(Prestamos* listPrestamos, int lenPrestamos, int* input);
int buscarAnio(Prestamos* listPrestamos, int lenPrestamos, int* input);

// punto H.
int unaFechaMuchosSocios(Prestamos* listPrestamos, int lenPrestamos, Socios* listSocios, int lenSocios);

// punto I.
int listarLibrosPorTitulo (Libros* arrayLibros, int lenLibros);

// punto J.
int listarSociosPorApellido(Socios* arraySocios, int lenSocios);
