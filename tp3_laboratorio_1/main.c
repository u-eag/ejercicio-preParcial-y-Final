#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int flagBoton1 = 0; // para saber si cargó los datos desde el archivo de texto
    int flagBoton2 = 0; // para saber si cargó los datos desde el archivo binario
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        getIntInRange(&option,"\nSeleccione una opcion del menu: \n\n"
                      "1)Cargar los datos de los empleados desde el archivo (texto)\n"
                      "2)Cargar los datos de los empleados desde el archivo (binario)\n"
                      "3)Alta de empleado\n"
                      "4)Modificacion de empleado\n"
                      "5)Baja de empleado\n"
                      "6)Listar empleados\n"
                      "7)Ordenar empleados\n"
                      "8)Guardar los datos de los empleados en el archivo (texto)\n"
                      "9)Guardar los datos de los empleados en el archivo (binario)\n"
                      "10)Salir\n",
                      "\nIngreso invalido\n",1,10,1);

        switch(option)
        {
            case 1:
                if(!controller_loadFromText("data.csv",listaEmpleados))
                {
                    flagBoton1 = 1;
                }
                break;

            case 2:
                if(!controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    flagBoton2 = 1;
                }
                break;

            case 3:
                if(flagBoton1 || flagBoton2)
                {
                    controller_addEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nEs necesario cargar los datos de los empleados del archivo de texto o binario antes de realizar esta accion\n\n");
                }
                break;

            case 4:
                if(flagBoton1 || flagBoton2)
                {
                    controller_editEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nEs necesario cargar los datos de los empleados del archivo de texto o binario antes de realizar esta accion\n\n");
                }
                break;

            case 5:
                if(flagBoton1 || flagBoton2)
                {
                    controller_removeEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nEs necesario cargar los datos de los empleados del archivo de texto o binario antes de realizar esta accion\n\n");
                }
                break;

            case 6:
                if(flagBoton1 || flagBoton2)
                {
                    controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nEs necesario cargar los datos de los empleados del archivo de texto o binario antes de realizar esta accion\n\n");
                }
                break;

            case 7:
                if(flagBoton1 || flagBoton2)
                {
                    controller_sortEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nEs necesario cargar los datos de los empleados del archivo de texto o binario antes de realizar esta accion\n\n");
                }
                break;

            case 8:
                if(flagBoton1)
                {
                    controller_saveAsText("data.csv",listaEmpleados);
                }
                else
                {
                    printf("\nEs necesario cargar los datos de los empleados del archivo de texto antes de realizar esta accion\n\n");
                }
                break;

            case 9:
                if(flagBoton2)
                {
                    controller_saveAsBinary("data.bin",listaEmpleados);
                }
                else
                {
                    printf("\nEs necesario cargar los datos de los empleados del archivo binario antes de realizar esta accion\n\n");
                }
                break;
        }
    }while(option != 10);
    return 0;
}
