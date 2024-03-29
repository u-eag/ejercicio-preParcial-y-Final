#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "LinkedList.h" // ac� va mi linkedlist
#include "Parser.h"

/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en un LinkedList de entidades
    empleado.
    Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180.
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350

    Para hacer este calculo, se debera desarrollar la funcion "map" en la biblioteca LinkedList, La cual recibe la lista y una funcion.
    La funcion map ejecutara la funcion recibida como parametro por cada item de la lista, y le pasaran en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra realizar un calculo con el item recibido, en este caso, calcular el sueldo.

    Una vez cargados los campos sueldo en las entidades, se debera generar un archivo de salida "sueldos.csv" el cual sera igual que el
    original pero con una columna mas al final, en donde se indicara el sueldo calculado.
*/

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados);

int main()
{
    // Definir lista de empleados
    LinkedList* listaEmpleados = ll_newLinkedList(); // Crear lista empledos
    LinkedList* listaFiltrada = ll_newLinkedList(); // crea la lista para ll_filter

    // Leer empleados de archivo data.csv
    if(parser_parseEmpleados("data.csv",listaEmpleados)==1)
    {
        // Calcular sueldos
        printf("Calculando sueldos de empleados\n");
        ll_map(listaEmpleados,em_calcularSueldo);

        // Pruebo la funci�n ll_filter
        printf("Quitando empleados que ganan +20.000\n");
        listaFiltrada = ll_filter(listaEmpleados, employee_filterBySalary);
        generarArchivoSueldos("filter.csv", listaFiltrada);

        // Pruebo la funci�n ll_reduce
        printf("Quitando empleados con sueldos que no pagan ganancias\n");
        ll_reduce(listaEmpleados, employee_reduceBySalary);

        // Generar archivo de salida
        if(generarArchivoSueldos("sueldos.csv",listaEmpleados)==1)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyando empleados\n");

    return 0;
}

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados)
{
    int retorno = -1;
    Employee* pEmployee;
    int i;

    FILE* pFile = fopen(fileName,"w+");

    if(listaEmpleados != NULL && pFile != NULL)
    {
        fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");

        for (i=0;i<ll_len(listaEmpleados);i++)
        {
            pEmployee = ll_get(listaEmpleados, i);

            if(pEmployee != NULL)
            {
                fprintf (pFile,"%d,%s,%d,%d\n", pEmployee->id, pEmployee->nombre,
                                                pEmployee->horasTrabajadas, pEmployee->sueldo);
            }
        }

        fclose(pFile);

        retorno = 1;
    }

    return retorno;
}
