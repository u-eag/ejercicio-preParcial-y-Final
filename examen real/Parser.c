#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Parser.h"
#include "LinkedList.h"
#include "informes.h"
#include "Venta.h"
#include "Fecha.h"

int parser_parseVenta(char* fileName, LinkedList* listaVentas)
{
    int retorno = -1;
    char bufferId[4096];
    char fechaStr[4096];
    char tipoStr[4096];
    char cantidad[4096];
    char precio[4096];
    char cuitStr[4096];
    Venta* pVenta;
    int cantidadDatos; // para saber si la cantidad de elementos que saqué del archivo está ok

    FILE* pFile = fopen(fileName, "r");

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",   bufferId,
                                                                fechaStr,
                                                                tipoStr,
                                                                cantidad,
                                                                precio,
                                                                cuitStr);
        while(!feof(pFile))
        {
            cantidadDatos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",   bufferId,
                                                                                    fechaStr,
                                                                                    tipoStr,
                                                                                    cantidad,
                                                                                    precio,
                                                                                    cuitStr);

            if(cantidadDatos == 6) // chequeo si recibí los 6 datos que pedí
            {
                pVenta = venta_newParametros(       bufferId,
                                                    fechaStr,
                                                    tipoStr,
                                                    cantidad,
                                                    precio,
                                                    cuitStr);
                if(pVenta != NULL)
                {
                    if(!ll_add(listaVentas, pVenta))
                    {

                        //printf("%d\n", pVenta->cantidad);

                        retorno = 1;
                    }
                }
            }
        }
    }

    fclose(pFile);

    return retorno;
}

