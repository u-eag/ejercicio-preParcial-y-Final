#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "validaciones.h"

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    Employee* pEmployee = employee_new();
    if(pEmployee != NULL)
    {
        employee_setId(pEmployee, idStr);
        employee_setNombre(pEmployee, nombreStr);
        employee_setHorasTrabajadas(pEmployee, horasTrabajadasStr);
        employee_setSueldo(pEmployee, sueldo);
    }
    return pEmployee;
}

int employee_delete(Employee* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int employee_setId(Employee* this, char* value)
{
    int auxID;
    int retorno = -1;

    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxID = atoi(value);

        if(auxID >= 0)
        {
            this->id = auxID;
            retorno = 0;
        }
    }
    return retorno;
}

int employee_setSueldo(Employee* this,char* value)
{
    int auxSueldo;
    int retorno = -1;
    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxSueldo = atoi(value);

        if(auxSueldo >= 0)
        {
            this->sueldo = auxSueldo;
            retorno = 0;
        }
    }
    return retorno;
}

int employee_setNombre(Employee* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isLetter(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->nombre,value, sizeof(this->nombre));
            retorno = 0;
        }
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,char* value)
{
    int auxHoras;
    int retorno = -1;

    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxHoras = atoi(value);

        if(auxHoras >= 0)
        {
            this->horasTrabajadas = auxHoras;

            retorno = 0;
        }
    }
    return retorno;
}

int employee_getNombre(Employee* this, char* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        strncpy(value,this->nombre, sizeof(this->nombre));

        retorno = 0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this, int* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        *value = this->sueldo;

        retorno = 0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this, int* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        *value = this->horasTrabajadas;

        retorno = 0;
    }
    return retorno;
}

int employee_getId(Employee* this, int* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        *value = this->id;

        retorno = 0;
    }
    return retorno;
}

int employee_initArray(Employee* arrayEmpleado[],int lenEmpleado)
{
    int i;
    int retorno = -1;

    if(arrayEmpleado != NULL && lenEmpleado > 0)
    {
        for(i=0; i<lenEmpleado; i++)
        {
            arrayEmpleado[i] = NULL;
        }
        retorno = 0;

    }
    return retorno;
}

int employee_findFree(Employee* arrayEmployee[], int lenEmployee)
{
    int i;
    int retorno = -1;

    if(arrayEmployee != NULL && lenEmployee > 0)
    {
        for(i=0; i<lenEmployee; i++)
        {
            if(arrayEmployee[i] == NULL)
            {
                retorno = i;
                printf("\nLugar libre disponible\n");
                break;
            }
        }
    }
    return retorno;
}

/** \brief Determina si debe hacerse el swap en una función de ordenamiento
 *
 * \param pEmployee1 Nombre del primer empleado a comparar
 * \param pEmployee2 Nombre del segundo empleado a comparar
 * \return Devuelve [0] si los nombres son iguales
 *                  [1] si pEmployee1 es mayor que pEmployee2
 *                  [-1] si pEmployee1 es menor que pEmployee2
 *
 */
int employee_sort(void* pEmployee1, void* pEmployee2) // para usar en ll_sort
{
    int retorno;
    int strcmp_r; // para guardar el retorno de strcmp
    Employee* pEmpleado1 = (Employee*) pEmployee1;
    Employee* pEmpleado2 = (Employee*) pEmployee2;

    strcmp_r = strcmp(pEmpleado1->nombre, pEmpleado2->nombre);

    if(strcmp_r > 0) // pEmployee1 > pEmployee2
    {
        retorno = 1;
    }
    else if(strcmp_r < 0) // pEmployee1 < pEmployee2
    {
        retorno = -1;
    }
    else // pEmployee1 == pEmployee2
    {
        retorno = 0;
    }

    return retorno;
}
