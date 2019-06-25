#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validaciones.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee) // char* para recibir el path en lugar el puntero a file
// se para en ese puntero a file y lo empieza a recorrer
{
    int retorno = 1;
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferHorasTrabajadas[4096];
    char bufferSueldo[4096];
    Employee *pEmpleado;
    int cantidadDatos; // para saber si la cantidad de elementos que saqué del archivo está ok

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferNombre,
                                                  bufferHorasTrabajadas,
                                                  bufferSueldo);
        while(!feof(pFile))
        {
            cantidadDatos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                                        bufferNombre,
                                                                        bufferHorasTrabajadas,
                                                                        bufferSueldo);

            if(cantidadDatos == 4) // chequeo si recibí los 4 datos que pedí
            {
                pEmpleado = employee_newParametros(     bufferId,
                                                        bufferNombre,
                                                        bufferHorasTrabajadas,
                                                        bufferSueldo);

                if(pEmpleado != NULL)
                {
                    if(!ll_add(pArrayListEmployee,pEmpleado))
                    {
                        retorno = 0;
                    }
                }
            }
        }
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    Employee* pEmpleado;
    int cantidadDatos;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            pEmpleado = employee_new();

            if(pEmpleado != NULL)
            {
                cantidadDatos = fread(pEmpleado, sizeof(Employee), 1, pFile);
            }

            if(cantidadDatos == 1)
            {
                if(!ll_add(pArrayListEmployee, pEmpleado))
                {
                    retorno = 0;
                }
            }
            else
            {
                employee_delete(pEmpleado); // si no obtengo la línea de datos que esperaba, borro el espacio que separé
            }
        }
    }

    return retorno;
}
