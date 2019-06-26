#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Autores.h"
#include "Fecha.h"
#include "Libros.h"
#include "Prestamos.h"
#include "Socios.h"
#include "validaciones.h"

int initPrestamos(Prestamos* list, int len)
{
    int result=-1; // devuelve -1 si hay error y 0 si est� todo ok
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
    int result=-1; // devuelve -1 si hay error y 0 si est� todo ok
    int emptyIndex;
    int flagIndex=0; // para saber si se encontr� un �ndice libre
    Prestamos aux; // para guardar los datos ingresados
    int idLibroBuscado;
    int idSocioBuscado;

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
        if(buscarLibros(listLibros, 10, &idLibroBuscado)==0)
        {
            if(buscarSocios(listSocios, lenSocios, &idSocioBuscado)==0)
            {
                if(getStringNumerosInt(&aux.fechaPrestamo.dia, "\nIngrese dia de prestamo[1-31]: ", "\nIngreso invalido", 2) == 0) // fechaPrestamo.dia
                {
                    if(getStringNumerosInt(&aux.fechaPrestamo.mes, "\nIngrese mes de prestamo [1-12]: ", "\nIngreso invalido", 2) == 0) // fechaPrestamo.mes
                    {
                        if(getStringNumerosInt(&aux.fechaPrestamo.anio, "\nIngrese anio de prestamo: ", "\nIngreso invalido",  2) == 0) // fechaPrestamo.anio
                        {
                            // campo isEmpty
                            aux.isEmpty=0; // ya no est� m�s vac�o

                            // idPrestamos
                            aux.idPrestamos=emptyIndex;

                            // si est� todo bien, asigno los datos:
                            listPrestamos[emptyIndex]=aux;

                            result=0;

                            printf("\nPrestamo ingresado exitosamente\n\n");
                        }
                    }
                }
            }
        }
    }

    return result;
}

int printPrestamos(Prestamos* listPrestamos, int lenPrestamos, Libros* listLibros, int lenLibros, Socios* listSocios, int lenSocios)
{
    int result=-1; // devuelve -1 si hay error y 0 si est� todo ok
    int i;

    printf("\n\t idLibro \t idSocio\t Fecha de prestamo \n\n");

    for(i=0;i<lenPrestamos;i++)
    {
        if(listPrestamos[i].isEmpty==0)
        {

            printf("\t%d \t%d \t%d/%d/%d \n\n", listLibros[i].idLibros, listSocios[i].idSocios,
                   listPrestamos[i].fechaPrestamo.dia, listPrestamos[i].fechaPrestamo.mes, listPrestamos[i].fechaPrestamo.anio);
        }
    }

    return result;
}
