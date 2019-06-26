#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "Clientes.h"
#include "Ventas.h"

int main()
{
    int option = 0; // para el menú principal

    do
    {
        getIntInRange(&option,"\nSeleccione una opcion del menu: \n\n"
                      "1)Alta de cliente\n"
                      "2)Modificacion de cliente\n"
                      "3)Baja de cliente\n"
                      "4)Listar clientes\n"
                      "5)Realizar una venta\n"
                      "6)Anular una venta\n"
                      "7)Informar ventas\n"
                      "8)Informar ventas por producto\n"
                      "9)Generar informe por ventas\n"
                      "10)Informar cantidad de ventas por cliente\n"
                      "11)Salir\n", "\nIngreso invalido\n",1,11,1);

        switch(option)
        {
            case 1: // Alta de cliente
                break;

            case 2: // Modificacion de cliente
                break;

            case 3: // Baja de cliente
                break;

            case 4: // Listar clientes
                break;

            case 5: // Realizar una venta
                break;

            case 6: // Anular una venta
                break;

            case 7: // Informar ventas
                break;

            case 8: // Informar ventas por producto
                break;

            case 9: // Generar informe por ventas
                break;

            case 10: // Informar cantidad de ventas por cliente
                break;

        }

    }while(option != 11);

    return 0;
}
