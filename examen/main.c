#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Parser.h"
#include "Entrega.h"
#include "LinkedList.h"
#include "informes.h"

int generarArchivoInformes(char* fileName, LinkedList* listaEntregas,   int cantidadEntregasTotales,
                                                                        int cantidadEntregasSTD,
                                                                        int cantidadMaximaBultos,
                                                                        int promedioBultosPorEntrega,
                                                                        int pesoPromedioPorEntrega);

int main()
{
    LinkedList* listaEntregas = ll_newLinkedList(); // Crear lista entregas
    int cantidadEntregasTotales;
    int cantidadEntregasSTD; // STD:318 - EXP:295 - ECO:387
    int cantidadEntregasEXP;
    int cantidadEntregasECO;
    int cantidadMaximaBultos;
    int promedioBultosPorEntrega;
    int pesoPromedioPorEntrega;

    // Leer entregas de archivo data.csv
    if(parser_parseEntrega("data.csv",listaEntregas)==1)
    {
        // Cantidad total de entregas
        cantidadEntregasTotales = ii_cantidadTotal(listaEntregas);

        // Cantidad de entregas por tipo: [1]STD [2]EXP [3]ECO
        cantidadEntregasSTD = ii_cantidadEntregaTipo(listaEntregas, 1);
        cantidadEntregasEXP = ii_cantidadEntregaTipo(listaEntregas, 2);
        cantidadEntregasECO = ii_cantidadEntregaTipo(listaEntregas, 3);

        // Cantidad maxima de bultos entregados
        cantidadMaximaBultos = ii_cantidadMaximaBultos(listaEntregas);

        // Promedio de bultos por entrega
        promedioBultosPorEntrega = ii_promedioBultos(listaEntregas);

        // Peso promedio por entrega
        pesoPromedioPorEntrega = ii_pesoPromedio(listaEntregas);

        // Generar archivo de salida
        if(generarArchivoInformes("informes.txt", listaEntregas,    cantidadEntregasTotales,
                                                                    cantidadEntregasSTD,
                                                                    cantidadMaximaBultos,
                                                                    promedioBultosPorEntrega,
                                                                    pesoPromedioPorEntrega)==1)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyando entregas\n");

    return 0;
}

int generarArchivoInformes(char* fileName, LinkedList* listaEntregas,   int cantidadEntregasTotales,
                                                                        int cantidadEntregasSTD,
                                                                        int cantidadMaximaBultos,
                                                                        int promedioBultosPorEntrega,
                                                                        int pesoPromedioPorEntrega)
{
    int retorno = -1;
    Entrega* pEntrega;
    int i;

    FILE* pFile = fopen(fileName, "w+");

    if(listaEntregas != NULL && pFile != NULL)
    {
        fprintf(pFile, "Cantidad total de entregas: %d\n"
                       "Cantidad de entregas por tipo: %d (STD) - XX (EXP) - XX (ECO)\n" // cambiar XX por %
                       "Cantidad maxima de bultos entregados: %d\n"
                       "Promedio de bultos por entrega: %d\n"
                       "Peso promedio por entrega: %d\n",
                        cantidadEntregasTotales,
                        cantidadEntregasSTD,
                        cantidadMaximaBultos,
                        promedioBultosPorEntrega,
                        pesoPromedioPorEntrega);


        fclose(pFile);

        retorno = 1;
    }

    return retorno;
}
