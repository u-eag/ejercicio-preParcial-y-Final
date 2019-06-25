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
    return retorno;//employee_getHorasTrabajadas
}

int employee_initArray(Employee* arrayEmpleado[],int lenEmpleado)
{
    int i;
    int retorno = -1;

    if(arrayEmpleado != NULL && lenEmpleado > 0)
    {
        for(i=0; i<lenEmpleado; i++)
        {
    /*    {Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180.
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350 */
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
            if(arrayEmployee[i] == NULL) //Los valores de horas varian entre 80 y 240.
    /*- Las primeras 120 horas la hora vale $180.
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350*/
            {
                retorno = i;
                printf("\nLugar libre disponible\n");
                break;
            }
        }
    }
    return retorno;
}

int em_calcularSueldo(void* pEmpleado)
{
    int retorno = -1; // es el sueldo
    Employee* pEmpleadoAux = pEmpleado;
    int horasTrabajadas;
    int horasAcumuladas;

    /*Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180.
    - De 120 a 160 horas, la hora vale $240 ----> las primeras 120 valen 180
    - De 160 a 240 horas, la hora vale $350 */

    employee_getHorasTrabajadas(pEmpleadoAux, &horasTrabajadas); // obtengo las hs que trabajó el empleado

    if(horasTrabajadas <= 120)
    {
        retorno = horasTrabajadas * 180;
    }
    else if(horasTrabajadas <=160)
    {
        horasAcumuladas = 120 * 180;

        horasTrabajadas = horasTrabajadas - 120;

        retorno = horasAcumuladas + horasTrabajadas * 240;
    }
    else if(horasTrabajadas <= 240)
    {
        horasAcumuladas = 120 * 180 + 40 * 240;

        horasTrabajadas = horasTrabajadas - 160;

        retorno = horasAcumuladas + horasTrabajadas * 350;
    }

    return retorno;
}
