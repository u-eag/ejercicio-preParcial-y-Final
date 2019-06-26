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

int informarListar (Prestamos* listPrestamos, int lenPrestamos, Libros* listLibros, int lenLibros, Socios* listSocios, int lenSocios)
{
    int result=-1; // devuelve [-1] si hay error y [0] si esta ok
    char botonInformarListar='Z';

        do{
            system("cls");

            printf( "*** MENU INFORMAR Y LISTAR - BIBLIOTECA ***\n\n"
                    "A. Informar el Total general y Promedio diario de las solicitudes a prestamo de los libros\n"
                    "B. Informar la cantidad de dias cuya solicitud a prestamo NO superan el promedio del item anterior\n"
                    "C. Listar todos los socios que solicitaron el prestamo de un libro determinado\n"
                    "D. Listar todos los libros que fueron solicitados a prestamo por un socio determinado\n"
                    "E. Listar el/los libro/s menos solicitado/s en prestamo\n"
                    "F. Listar el/los socio/s que realizo/realizaron mas solicitudes a prestamo\n"
                    "G. Listar todos los libros solicitados a prestamo en una fecha determinada\n"
                    "H. Listar todos los socios que realizaron al menos una solicitud de prestamo en una fecha determinada\n"
                    "I. Listar todos los libros ordenados por titulo (descendente)\n"
                    "J. Listar todos los socios ordenaods por Apellido (ascendente)\n"
                    "K. Volver al menu anterior\n\n");

            getChar(&botonInformarListar, "Seleccione una opcion del menu: ", "\nOpcion no valida\n\n", 'A', 'K', 1, 1);

            switch(botonInformarListar)
            {
                case 'A': // Informar el Total general y Promedio diario de las solicitudes a prestamo de los libros
                    calcularPrestamos(listPrestamos, lenPrestamos);
                    system("pause");
                    break;

                case 'B': // Informar la cantidad de dias cuya solicitud a prestamo NO superan el promedio del item anterior
                    calcularDiasMenoresAlPromedio(listPrestamos, lenPrestamos);
                    system("pause");
                    break;

                case 'C': // Listar todos los socios que solicitaron el prestamo de un libro determinado
                    unLibroMuchosSocios(listPrestamos, lenPrestamos, listLibros, lenLibros, listSocios, lenSocios);
                    system("pause");
                    break;

                case 'D': // Listar todos los libros que fueron solicitados a prestamo por un socio determinado
                    unSocioMuchosLibros(listPrestamos, lenPrestamos, listLibros, lenLibros, listSocios, lenSocios);
                    system("pause");
                    break;

                case 'E': // Listar el/los libro/s menos solicitado/s en prestamo
                    listarLibrosMenosSolicitados(listPrestamos, lenPrestamos);
                    system("pause");
                    break;

                case 'F': // Listar el/los socio/s que realizo/realizaron mas solicitudes a prestamo
                    listarSociosMasActivos(listPrestamos, lenPrestamos);
                    system("pause");
                    break;

                case 'G': // Listar todos los libros solicitados a prestamo en una fecha determinada
                    unaFechaMuchosLibros(listPrestamos, lenPrestamos, listLibros, lenLibros, listSocios, lenSocios);
                    system("pause");
                    break;

                case 'H': // Listar todos los socios que realizaron al menos una solicitud de prestamo en una fecha determinada
                    unaFechaMuchosSocios(listPrestamos, lenPrestamos, listSocios, lenSocios);
                    system("pause");
                    break;

                case 'I': // Listar todos los libros ordenados por titulo (descendente, burbujeo mas eficiente)
                    listarLibrosPorTitulo(listLibros, 10);
                    system("pause");
                    break;

                case 'J': // Listar todos los socios ordenaods por Apellido (ascendente, insercion)
                    listarSociosPorApellido(listSocios, lenSocios);
                    system("pause");
                    break;

            }

            result=0;

        }while(botonInformarListar!='K');

    return result;
}

// A. Informar el Total general y Promedio diario de las solicitudes a prestamo de los libros
int calcularPrestamos (Prestamos* listPrestamos, int lenPrestamos)
{
    int result = -1;

    if(listPrestamos != NULL && lenPrestamos > 0)
    {
        result = 0;
    }

    return result;
}

// B. Informar la cantidad de dias cuya solicitud a prestamo NO superan el promedio del item A
int calcularDiasMenoresAlPromedio (Prestamos* listPrestamos, int lenPrestamos)
{
    int result = -1;

    if(listPrestamos != NULL && lenPrestamos > 0)
    {
        result = 0;
    }

    return result;
}

// C. Listar todos los socios que solicitaron el prestamo de un libro determinado
int unLibroMuchosSocios (Prestamos* listPrestamos, int lenPrestamos, Libros* listLibros, int lenLibros, Socios* listSocios, int lenSocios)
{
    int result=1; // devuelve [-1] si hay error, sino [0]
    int idLibroBuscado;
    int i;
    int j;

    // pasos: 1. buscar el libro, 2. mostrar los socios que lo pidieron en prestamo

    if(buscarLibros(listLibros, lenLibros, &idLibroBuscado)==0)
    {
        printf("\nLos siguientes socios pidieron en prestamo el libro id: %d titulo: %s \n",
               listLibros[idLibroBuscado].idLibros, listLibros[idLibroBuscado].titulo);

        printf("\n\tidSocio \tNombre \tApellido\n");

        for(i=0;i<lenLibros;i++)
        {
            for(j=0;i<lenPrestamos;j++)
            {
                if(listLibros[i].idLibros==idLibroBuscado && listPrestamos[j].idLibro==idLibroBuscado)
                {
                    printf("\n\t%d \t%s \t%s\n", listSocios[i].idSocios, listSocios[i].nombre, listSocios[i].apellido);
                }
            }
        }

        result=0;
    }

    return result;
}

// D. Listar todos los libros que fueron solicitados a prestamo por un socio determinado
int unSocioMuchosLibros (Prestamos* listPrestamos, int lenPrestamos, Libros* listLibros, int lenLibros, Socios* listSocios, int lenSocios)
{
    int result=1; // devuelve [-1] si hay error, sino [0]
    int idSocioBuscado;
    int i;
    int j;

    // pasos: 1. buscar el socio, 2. mostrar los libros que pidio en prestamo

    if(buscarSocios(listSocios, lenSocios, &idSocioBuscado)==0)
    {
        printf("\nEl socio id: %d %s %s pidio en prestamo los siguientes libros: \n",
               listSocios[idSocioBuscado].idSocios, listSocios[idSocioBuscado].nombre, listSocios[idSocioBuscado].apellido);

        printf("\n\tidLibro \tTitulo \n");

        for(i=0;i<lenSocios;i++)
        {
            for(j=0;i<lenPrestamos;j++)
            {
                if(listSocios[i].idSocios==idSocioBuscado && listPrestamos[j].idLibro==idSocioBuscado)
                {
                    printf("\n\t%d \t%s \n", listLibros[i].idLibros, listLibros[i].titulo);
                }
            }
        }

        result=0;
    }

    return result;
}

// E. Listar el/los libro/s menos solicitado/s en prestamo
int listarLibrosMenosSolicitados (Prestamos* listPrestamos, int lenPrestamos)
{
    int result = -1;

    if(listPrestamos != NULL && lenPrestamos > 0)
    {
        result = 0;
    }

    return result;
}

// F. Listar el/los socio/s que realizo/realizaron mas solicitudes a prestamo
int listarSociosMasActivos (Prestamos* listPrestamos, int lenPrestamos)
{
    int result = -1;

    if(listPrestamos != NULL && lenPrestamos > 0)
    {
        result = 0;
    }

    return result;
}

// G. Listar todos los libros solicitados a prestamo en una fecha determinada
int unaFechaMuchosLibros (Prestamos* listPrestamos, int lenPrestamos, Libros* listLibros, int lenLibros, Socios* listSocios, int lenSocios)
{
    int result=-1; // devuelve [-1] si hay error, sino [0]
    int indiceDiaBuscado;
    int indiceMesBuscado;
    int indiceAnioBuscado;
    int rDia; // retorno de la funcion buscarDia
    int rMes;
    int rAnio;
    int i;

    // pasos: 1. busco la fecha, 2. muestro los libros que se prestaron en esa fecha

    rDia = buscarDia(listPrestamos, lenPrestamos, &indiceDiaBuscado);
    rMes = buscarMes(listPrestamos, lenPrestamos, &indiceMesBuscado);
    rAnio = buscarAnio(listPrestamos, lenPrestamos, &indiceAnioBuscado);

    if(rDia==0 && rMes==0 && rAnio==0)
    {
        printf("\nid libro prestado: \n\n");

        for (i=0;i<lenPrestamos;i++)
        {
            if(listPrestamos[i].fechaPrestamo.dia == listPrestamos[indiceDiaBuscado].fechaPrestamo.dia
              && listPrestamos[i].fechaPrestamo.mes == listPrestamos[indiceMesBuscado].fechaPrestamo.mes
              && listPrestamos[i].fechaPrestamo.anio == listPrestamos[indiceAnioBuscado].fechaPrestamo.anio)
            {
                printf("\n%d", listPrestamos[i].idLibro);
            }
        }

        result=0;
    }

    return result;
}

int buscarDia(Prestamos* listPrestamos, int lenPrestamos, int* indiceDiaBuscado)
{
    int result=-1;
    int diaBuscado;
    int i;

    printf("\nIngrese el dia del prestamo[1-31]: ");
    scanf("%d", &diaBuscado);

    for(i=0;i<lenPrestamos;i++)
    {
        if(listPrestamos[i].isEmpty==0 && listPrestamos[i].fechaPrestamo.dia==diaBuscado)
        {
            *indiceDiaBuscado=i;
            result=0;
            break;
        }
    }

    return result;
}

int buscarMes(Prestamos* listPrestamos, int lenPrestamos, int* indiceMesBuscado)
{
    int result=-1;
    int mesBuscado;
    int i;

    printf("\nIngrese el mes del prestamo[1-12]: ");
    scanf("%d", &mesBuscado);

    for(i=0;i<lenPrestamos;i++)
    {
        if(listPrestamos[i].isEmpty==0 && listPrestamos[i].fechaPrestamo.mes==mesBuscado)
        {
            *indiceMesBuscado=i;
            result=0;
            break;
        }
    }

    return result;
}

int buscarAnio(Prestamos* listPrestamos, int lenPrestamos, int* indiceAnioBuscado)
{
    int result=-1;
    int anioBuscado;
    int i;

    printf("\nIngrese el anio del prestamo: ");
    scanf("%d", &anioBuscado);

    for(i=0;i<lenPrestamos;i++)
    {
        if(listPrestamos[i].isEmpty==0 && listPrestamos[i].fechaPrestamo.anio==anioBuscado)
        {
            *indiceAnioBuscado=i;
            result=0;
            break;
        }
    }

    return result;
}

// H. Listar todos los socios que realizaron al menos una solicitud de prestamo en una fecha determinada
int unaFechaMuchosSocios(Prestamos* listPrestamos, int lenPrestamos, Socios* listLibros, int lenSocios)
{
    int result=-1; // devuelve [-1] si hay error, sino [0]
    int indiceDiaBuscado;
    int indiceMesBuscado;
    int indiceAnioBuscado;
    int rDia; // retorno de la funcion buscarDia
    int rMes;
    int rAnio;
    int i;

    // pasos: 1. busco la fecha, 2. muestro los socios que se prestaron en esa fecha

    rDia = buscarDia(listPrestamos, lenPrestamos, &indiceDiaBuscado);
    rMes = buscarMes(listPrestamos, lenPrestamos, &indiceMesBuscado);
    rAnio = buscarAnio(listPrestamos, lenPrestamos, &indiceAnioBuscado);

    if(rDia==0 && rMes==0 && rAnio==0)
    {
        printf("\nid socio que tomo por lo menos un libro prestado: \n\n");

        for (i=0;i<lenPrestamos;i++)
        {
            if(listPrestamos[i].fechaPrestamo.dia == listPrestamos[indiceDiaBuscado].fechaPrestamo.dia
              && listPrestamos[i].fechaPrestamo.mes == listPrestamos[indiceMesBuscado].fechaPrestamo.mes
              && listPrestamos[i].fechaPrestamo.anio == listPrestamos[indiceAnioBuscado].fechaPrestamo.anio)
            {
                printf("\n%d", listPrestamos[i].idSocio);
            }
        }

        result=0;
    }

    return result;
}

// I. Listar todos los libros ordenados por titulo (descendente)
int listarLibrosPorTitulo (Libros* arrayLibros, int lenLibros)
{
    int result = -1;

    if(arrayLibros != NULL && lenLibros > 0)
    {
        result = 0;
    }

    return result;
}

// J. Listar todos los socios ordenaods por Apellido (ascendente)
int listarSociosPorApellido(Socios* arraySocios, int lenSocios)
{
    int result = -1;

    if(arraySocios != NULL && lenSocios > 0)
    {
        result = 0;
    }

    return result;
}
