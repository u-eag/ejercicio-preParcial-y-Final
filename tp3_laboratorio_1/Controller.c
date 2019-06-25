#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validaciones.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno = 1;

    if (pArrayListEmployee != NULL)
    {
        pFile = fopen(path,"r");

        if(pFile != NULL)
        {
            parser_EmployeeFromText(pFile , pArrayListEmployee);
            fclose(pFile);
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno = 1;

    if (pArrayListEmployee != NULL)
    {
        pFile = fopen(path,"rb");

        if(pFile != NULL)
        {
            parser_EmployeeFromBinary(pFile , pArrayListEmployee);
            fclose(pFile);
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    Employee* pEmployee;
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferHorasTrabajadas[4096];
    char bufferSueldo[4096];

    if (pArrayListEmployee != NULL)
    {
        if(!getStringNumerosInt(bufferId, "\nIngrese el ID: ", "\nIngreso invalido\n", 2)
           && !getStringLetras(bufferNombre, "\nIngrese el nombre: ", "\nIngreso invalido\n", 2)
           && !getStringNumerosInt(bufferHorasTrabajadas, "\nIngrese las horas trabajadas: ", "\nIngreso invalido\n", 2)
           && !getStringNumerosInt(bufferSueldo, "\nIngrese el sueldo: ", "\nIngreso invalido\n", 2))
        {
            pEmployee = employee_newParametros(bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);

            if(pEmployee != NULL)
            {
                if(!ll_add(pArrayListEmployee, pEmployee))
                {
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    Employee* pEmployee;
    int id;
    char bufferNombre[4096];
    char bufferHorasTrabajadas[4096];
    char bufferSueldo[4096];
    int i;
    int option;

    if (pArrayListEmployee != NULL)
    {
        // busco el empleado a modificar:
        if(!getIntInRange(&id, "\nIngrese el ID del empleado a modificar: ", "\nIngreso invalido\n", 0, ll_len(pArrayListEmployee), 2))
        {
            for (i=0;i<ll_len(pArrayListEmployee);i++) // recorro la lista de empleados
            {
                pEmployee = ll_get(pArrayListEmployee, i); // me guardo el empleado actual

                if(pEmployee->id == id) // pregunto si el empleado actual es el que busco
                {
                    // si lo encontré, muestro el menú modificar:
                    do{
                        getIntInRange(&option,"\nSeleccione un campo a modificar: \n\n"
                                      "1)Modificar Nombre\n"
                                      "2)Modificar Horas Trabajadas\n"
                                      "3)Modificar Sueldo\n"
                                      "4)Salir\n",
                                      "\nIngreso invalido\n",1,4,1);

                        switch(option)
                        {
                            case 1:
                                if(!getStringLetras(bufferNombre, "\nIngrese el nombre: ", "\nIngreso invalido\n", 2))
                                {
                                    employee_setNombre(pEmployee, bufferNombre);
                                    retorno = 0;
                                }

                                break;

                            case 2:
                                if(!getStringNumerosInt(bufferHorasTrabajadas, "\nIngrese las horas trabajadas: ", "\nIngreso invalido\n", 2))
                                {
                                    employee_setHorasTrabajadas(pEmployee, bufferHorasTrabajadas);
                                    retorno = 0;
                                }

                                break;

                            case 3:
                                if(!getStringNumerosInt(bufferSueldo, "\nIngrese el sueldo: ", "\nIngreso invalido\n", 2))
                                {
                                    employee_setSueldo(pEmployee, bufferSueldo);
                                    retorno = 0;
                                }

                                break;

                        }
                    }while(option != 4);
                }
            }
        }
    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    Employee* pEmployee;
    int id;
    int i;

    if (pArrayListEmployee != NULL)
    {
        // busco el empleado a eliminar:
        if(!getIntInRange(&id, "\nIngrese el ID del empleado a eliminar: ", "\nIngreso invalido\n", 0, ll_len(pArrayListEmployee), 2))
        {
            for (i=0;i<ll_len(pArrayListEmployee);i++) // recorro la lista de empleados
            {
                pEmployee = ll_get(pArrayListEmployee, i); // me guardo el empleado actual

                if(pEmployee->id == id) // pregunto si el empleado actual es el que busco
                {
                    ll_remove(pArrayListEmployee, id);
                    employee_delete(pEmployee); // para hacer el free
                    retorno = 0;
                    break;
                }
            }
        }
    }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    Employee* pEmployee;
    int i;

    if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0) // que tenga aunque sea un elemento para listar
    {
        printf("\nID: \t Nombre: \t Horas Trabajadas: \t Sueldo: \n\n");

        for (i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);

            if(pEmployee != NULL)
            {
                printf ("%d \t %s \t %d \t %d\n", pEmployee->id, pEmployee->nombre,
                                                pEmployee->horasTrabajadas, pEmployee->sueldo);
            }
        }

        retorno = 0;
    }

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;

    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee, employee_sort, 1);

        retorno = 0;
    }

return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    Employee* pEmployee;
    int i;

    FILE* pFile = fopen(path,"w");

    if(pArrayListEmployee != NULL && pFile != NULL)
    {
        fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");

        for (i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);

            if(pEmployee != NULL)
            {
                fprintf (pFile,"%d,%s,%d,%d\n", pEmployee->id, pEmployee->nombre,
                                                pEmployee->horasTrabajadas, pEmployee->sueldo);
            }
        }

        fclose(pFile);

        retorno = 0;
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    Employee* pEmployee;
    int i;

    FILE* pFile = fopen(path,"wb");

    if(pArrayListEmployee != NULL && pFile != NULL)
    {

        for (i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);
            fwrite(pEmployee,sizeof(Employee),1,pFile);
        }

        fclose(pFile);

        retorno = 0;
    }

    return retorno;
}

