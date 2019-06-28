#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Parser.h"
#include "LinkedList.h"
#include "informes.h"
#include "Venta.h"
#include "Fecha.h"

// respuestas validando: fotos:48279 / mayor a 150: 465 / menor a 300: 443 / polaroids: 171
// respuestas NO validando NADA: fotos:48452 / mayor a 150: 467 / menor a 300: 445 / polaroids: 172
// nota: validando alguito puede dar un resultado intermedio

int generarArchivoInformes(char* fileName, LinkedList* listaVentas, int cantidadTotal,
                                                                    int cantidad150,
                                                                    int cantidad300,
                                                                    int cantidadPolaroid);

int main()
{
    LinkedList* listaVentas = ll_newLinkedList();
    int cantidadTotal;
    int cantidad150;
    int cantidad300;
    int cantidadPolaroid;

    // Leer entregas de archivo data.csv
    if(parser_parseVenta("data.csv",listaVentas)==1)
    {
        // Cantidad de fotos reveladas totales:
        cantidadTotal = ii_cantidadTotal(listaVentas);

        // Cantidad de ventas por un monto mayor a $150:
        cantidad150 = ii_mayor150(listaVentas);

        // Cantidad de ventas por un monto mayor a $300:
        cantidad300 = ii_mayor300(listaVentas);

        // Cantidad de fotos polaroids reveladas:
        cantidadPolaroid = ii_polaroid(listaVentas);

        // Generar archivo de salida
        if(generarArchivoInformes("informes.txt", listaVentas,  cantidadTotal,
                                                                cantidad150,
                                                                cantidad300,
                                                                cantidadPolaroid)==1)
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

int generarArchivoInformes(char* fileName, LinkedList* listaVentas, int cantidadTotal,
                                                                    int cantidad150,
                                                                    int cantidad300,
                                                                    int cantidadPolaroid)
{
    int retorno = -1;

    FILE* pFile = fopen(fileName, "w+");

    if(listaVentas != NULL && pFile != NULL)
    {
        fprintf(pFile,"*******************\n");
        fprintf(pFile,"Informe de ventas\n");
        fprintf(pFile,"*******************\n");
        fprintf(pFile,"- Cantidad de fotos reveladas totales: %d\n", cantidadTotal);
        fprintf(pFile,"- Cantidad de ventas por un monto mayor a $150: %d\n", cantidad150);
        fprintf(pFile,"- Cantidad de ventas por un monto mayor a $300: %d\n", cantidad300);
        fprintf(pFile,"- Cantidad de fotos polaroids reveladas: %d\n", cantidadPolaroid);
        fprintf(pFile,"*******************");

        fclose(pFile);

        retorno = 1;
    }

    return retorno;
}
