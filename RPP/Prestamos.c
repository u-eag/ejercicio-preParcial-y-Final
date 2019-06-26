#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Autores.h"
#include "Fecha.h"
#include "Libros.h"
#include "Prestamos.h"
#include "Socios.h"
#include "validaciones.h"
#include "InformarListar.h"

static int idPrestamoAutomatico = 0;

int generarIdPrestamo (void)
{
    return idPrestamoAutomatico++;
}

int initPrestamos(Prestamos* list, int len)
{
    int result=-1; // devuelve -1 si hay error y 0 si está todo ok
    int i;

    if(list!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=1;
        }
        result=0;
    }

    return result;
}

int findEmptyIndexPrestamos(Prestamos* list, int len, int* index)
{
    int result=-1;
    int i;

    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            *index=i;
            result=0;
            break;
        }
    }

    return result;
}

int altaPrestamos(Prestamos* listPrestamos, int lenPrestamos, Libros* listLibros, int lenLibros, Socios* listSocios, int lenSocios)
{
    int result=-1; // devuelve -1 si hay error y 0 si está todo ok
    int emptyIndex;
    int flagIndex=0; // para saber si se encontró un índice libre
    Prestamos aux; // para guardar los datos ingresados
    int idLibroBuscado;
    //int idSocioBuscado;

    // primero busco un lugar libre:
    if((findEmptyIndexPrestamos(listPrestamos, lenPrestamos, &emptyIndex))==0)
    {
        flagIndex=1;
    }
    else
    {
        printf("\nNo existen lugares libres para ingresar un nuevo prestamo\n\n");
    }

    // si encuentro un lugar libre pido los datos
    if(flagIndex && listPrestamos!=NULL && lenPrestamos>0)
    {
        if( !buscarLibros(listLibros, 10, &idLibroBuscado)
            && !getIntInRange(&aux.fechaPrestamo.dia, "\nIngrese dia de prestamo[1-31]: ", "\nIngreso invalido", 1, 31, 2) // fechaPrestamo.dia
            && !getIntInRange(&aux.fechaPrestamo.mes, "\nIngrese mes de prestamo [1-12]: ", "\nIngreso invalido", 1, 12, 2) // fechaPrestamo.mes
            && !getIntInRange(&aux.fechaPrestamo.anio, "\nIngrese anio de prestamo: ", "\nIngreso invalido", 1810, 2019,  2)) // fechaPrestamo.anio
        {
            // campo isEmpty
            aux.isEmpty=0; // ya no está más vacío

            // idPrestamos
            aux.idPrestamos = generarIdPrestamo();

            // si está todo bien, asigno los datos:
            listPrestamos[emptyIndex]=aux;

            result=0;

            printf("\nPrestamo ingresado exitosamente\n\n");
        }
    }

    return result;
}

int printPrestamos(Prestamos* listPrestamos, int lenPrestamos, Libros* listLibros, int lenLibros, Socios* listSocios, int lenSocios)
{
    int result=-1; // devuelve -1 si hay error y 0 si está todo ok
    int i;

    printf("\n\t idLibro \t idSocio\t Fecha de prestamo \n\n");

    for(i=0;i<lenPrestamos;i++)
    {
        if(listPrestamos[i].isEmpty==0)
        {

            printf("\t%d       \t%d         \t%d/%d/%d \n\n", listLibros[i].idLibros, listSocios[i].idSocios,
                   listPrestamos[i].fechaPrestamo.dia, listPrestamos[i].fechaPrestamo.mes, listPrestamos[i].fechaPrestamo.anio);
        }
    }

    return result;
}
