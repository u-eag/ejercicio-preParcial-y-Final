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

int initLibros(Libros* list, int len)
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
int printLibros(Libros* list, int len)
{
    int result=-1; // devuelve -1 si hay error y 0 si está todo ok
    int i;

    printf("\n\tid \tTitulo \tAutor \n\n");
    for(i=0;i<len;i++)
    {
        printf("\t%d \t%s \t\t%d \n", list[i].idLibros, list[i].titulo, list[i].idAutor);
        result=0;
    }
    printf("\n");

    return result;
}

int buscarLibros(Libros* list, int len, int* input)
{
    int result=-1;
    int idLibroBuscado;
    int i;

    printf("\nIngrese el id del libro: ");
    scanf("%d", &idLibroBuscado);

    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==0 && list[i].idLibros==idLibroBuscado)
        {
            *input=i;
            result=0;
            break;
        }
    }

    return result;
}

int ordenarLibros(Libros* list, int len)
{
    int result=-1;
    Libros aux;
    int i;
    int j;

    for(i=0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(strcmp(list[i].titulo, list[j].titulo)>0)
            {
                aux=list[i];
                list[i]=list[j];
                list[j]=aux;
                result=0;
            }
        }
    }

    return result;
}
