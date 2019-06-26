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

#define TAM_SOC 5 // cantidad máxima de socios de la biblioteca
            // 1000
#define TAM_PREST 5 // cantidad máxima de prestamos de la biblioteca
            // 1000

int main()
{
    Autores arrayAutores[10] =
    {
        {1000, "Miguel", "de Cervantes", 0},
        {1001, "William ", "Shakespeare", 0},
        {1002, "Dante", "Alighieri", 0},
        {1003, "Leon", "Tolstoi", 0},
        {1004, "Gustave", "Flaubert", 0},
        {1005, "Jorge Luis", "Borges", 0},
        {1006, "Franz", "Kafka", 0},
        {1007, "Marcel", "Proust", 0},
        {1008, "Fiodor", "Dostoievsky", 0},
        {1009, "Albert", "Camus", 0},
    };

    Libros arrayLibros[10] =
    {
        {100, "Don Quijote de la Mancha", 1000, 0},
        {101, "Hamlet", 1001, 0},
        {102, "La divina comedia", 1002, 0},
        {103, "La guerra y la paz", 1003, 0},
        {104, "Madame Bovary", 1004, 0},
        {105, "El Aleph", 1005, 0},
        {106, "El proceso", 1006, 0},
        {107, "En busca del tiempo perdido", 1007, 0},
        {108, "Los hermanos Karamazov", 1008, 0},
        {109, "El extranjero", 1009, 0},
    };


    Prestamos arrayPrestamos[TAM_PREST];
    char botonMenu='Z'; // lo inicializo en Z para que no se de la casualidad de que arranque en H y salga del menu
    int flagBotonAlta=0; // para saber si se ingresó aunque sea 1 alta
    Socios arraySocios[TAM_SOC];

    /*Socios arraySocios[5] = // antes de usar socios hardcodeados hay que comentar 50 y 61
    {
        {0, 0, "Juan", "Perez", 'M', "011-4818-3423", "juanperez@utn.mail", 10, 1, 2013},
        {0, 1, "Ana", "Gonzalez", 'F', "011-15-64427384", "anagonzalez@utn.mail", 18, 11, 2012},
        {0, 2, "Pedro", "Lopez", 'M', "011-4327-3452", "pedrolopez@utn.mail", 25, 6, 2015},
        {0, 3, "Maria", "Gomez", 'F', "011-4368-4575", "mariagomez@utn.mail", 30, 7, 2017},
        {0, 4, "Jose", "Palacios", 'M', "011-15-45733423", "josepalacios@utn.mail", 5, 2, 2019},
    };*/

    initSocios(arraySocios, TAM_SOC);
    initPrestamos(arrayPrestamos, TAM_PREST);

    do{
        system("cls");

        printf( "*** MENU PRINCIPAL - BIBLIOTECA ***\n\n"
                "A. Alta\n"
                "B. Modificar\n"
                "C. Baja\n"
                "D. Listar socios\n"
                "E. Listar libros\n"
                "F. Listar autores\n"
                "G. Prestamos\n"
                "H. Informar y Listar\n"
                "I. Salir\n\n");

        getChar(&botonMenu, "Seleccione una opcion del menu: ", "\nOpcion no valida\n\n", 'A', 'I', 1, 1);

        switch(botonMenu)
        {
            case 'A': // Alta
                if(!altaSocios(arraySocios, TAM_SOC))
                {
                    flagBotonAlta = 1;
                }
                system("pause");
                break;

            case 'B': // Modificar: nombre, apellido, sexo, telefono y mail (solicitando id de socio)
                if(flagBotonAlta)
                {
                    modificarSocios(arraySocios, TAM_SOC);
                }
                else
                {
                    printf("\nAntes de modificar se debe dar aunque sea un alta de socio\n\n");
                }
                system("pause");
                break;

            case 'C': // Baja (solicitando id de socio)
                if(flagBotonAlta)
                {
                    bajaSocios(arraySocios, TAM_SOC);
                }
                else
                {
                    printf("\nAntes de intentar la baja se debe dar aunque sea un alta de socio\n\n");
                }
                system("pause");
                break;

            case 'D': // Listar socios (ordenados)
                if(flagBotonAlta)
                {
                    ordenarSocios(arraySocios, TAM_SOC);
                    printSocios(arraySocios, TAM_SOC);
                }
                else
                {
                    printf("\nAntes de listar los socios se debe dar aunque sea un alta\n\n");
                }
                system("pause");
                break;

            case 'E': // listar libros (ordenados)
                ordenarLibros(arrayLibros, 10);
                printLibros(arrayLibros, 10);
                system("pause");
                break;

            case 'F': // listar autores (ordenados)
                ordenarAutores(arrayAutores, 10);
                printAutores(arrayAutores, 10);
                system("pause");
                break;

            case 'G': // alta prestamo
                if(flagBotonAlta)
                {
                    altaPrestamos(arrayPrestamos, TAM_PREST, arrayLibros, 10, arraySocios, TAM_SOC);
                    printPrestamos(arrayPrestamos, TAM_PREST, arrayLibros, 10, arraySocios, TAM_SOC);
                }
                else
                {
                    printf("\nAntes de registrar un prestamo se debe dar aunque sea un alta de socio\n\n");
                }
                system("pause");
                break;

            case 'H': // Informar y Listar
                if(flagBotonAlta)
                {
                    informarListar(arrayPrestamos, TAM_PREST, arrayLibros, 10, arraySocios, TAM_SOC);
                }
                else
                {
                    printf("\nAntes de informar o listar se debe dar aunque sea un alta de socio\n\n");
                }
                system("pause");
                break;
        }

    }while(botonMenu != 'I');

    return 0;
}
