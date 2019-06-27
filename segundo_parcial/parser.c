#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "entregas.h"
#include "arraynuevo.h"

int parser_parseEntregasText(char* fileName, LinkedList* listaEntregas)
{
    char bufferId[1500];
    char bufferTipo[1500];
    char bufferCantidad[1500];
    char bufferPeso[1500];
    int cantidadDatos;
    Entregas* pEntrega;
    int retorno = -1;

    FILE* pFile = fopen(fileName,"r");

            if(pFile != NULL)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                                bufferId,
                                bufferTipo,
                                bufferCantidad,
                                bufferPeso);
                do
                {
                    cantidadDatos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                                                                        bufferId,
                                                                        bufferTipo,
                                                                        bufferCantidad,
                                                                        bufferPeso);
                    if(cantidadDatos == 4)
                    {
                        pEntrega = entrega_newParametros(bufferId,
                                                        bufferTipo,
                                                        bufferCantidad,
                                                        bufferPeso);
                        if(pEntrega != NULL)
                        {
                            if(ll_add(listaEntregas,pEntrega) == 0)
                            {
                                retorno = 1;
                            }
                        }
                    }
                }
                while(!feof(pFile));
                fclose(pFile);
            }
    return retorno; // OK
}
