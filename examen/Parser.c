#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Parser.h"
#include "Entrega.h"
#include "LinkedList.h"
#include "informes.h"

int parser_parseEntrega(char* fileName, LinkedList* listaEntregas)
{
    int retorno = -1;
    char bufferId[4096];
    char bufferTipo[4096];
    char bufferCantidad[4096];
    char bufferPeso[4096];
    Entrega* pEntrega;
    int cantidadDatos; // para saber si la cantidad de elementos que saqué del archivo está ok

    FILE* pFile = fopen(fileName, "r");

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                    bufferTipo,
                                                    bufferCantidad,
                                                    bufferPeso);
        while(!feof(pFile))
        {
            cantidadDatos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                                        bufferTipo,
                                                                        bufferCantidad,
                                                                        bufferPeso);

            if(cantidadDatos == 4) // chequeo si recibí los 4 datos que pedí
            {
                pEntrega = entrega_newParametros(   bufferId,
                                                    bufferTipo,
                                                    bufferCantidad,
                                                    bufferPeso);

                if(pEntrega != NULL)
                {
                    if(!ll_add(listaEntregas, pEntrega))
                    {
                        retorno = 1;
                    }
                }
            }
        }
    }

    fclose(pFile);

    return retorno;
}

