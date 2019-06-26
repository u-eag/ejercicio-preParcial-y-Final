#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Autores.h"
#include "Fecha.h"
#include "Libros.h"
#include "Prestamos.h"
#include "Socios.h"
#include "validaciones.h"
#include "InformarListar.h"

static int idSocioAutomatico = 0;

int generarIdSocio (void)
{
    return idSocioAutomatico++;
}

/** \brief Inicializa el array de Socios
 *         seteando el campo isEmpty en 1
 *
 * \param list es el array de socios
 * \param len es la cantidad de socios
 * \return int Devuelve [-1] si hay error
 *                      [0] si está todo ok
 *
 */
int initSocios(Socios* list, int len)
{
    int result = -1;
    int i;

    if(len > 0) // si por lo menos la cantidad de socios es 1
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty = 1;
        }
        result = 0;
    }

    return result;
}

/** \brief Imprime la lista de socios activos
 *         (con el campo isEmpty == 0)
 *
 * \param list es el array de socios
 * \param len es la cantidad de socios
 * \return int Devuelve [-1] si hay error
 *                      [0] si está todo ok
 *
 */
int printSocios(Socios* list, int len)
{
    int result = -1;
    int i;

    if(list != NULL && len > 0)
    {
        printf("\n\t id \t Nombre\t Apellido\t Sexo\t Telefono\t eMail\t Fecha de ingreso \n\n");

        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty == 0)
            {
                printf("\t%d \t%s \t%s \t%c \t%s \t%s \t%d/%d/%d \n\n", list[i].idSocios, list[i].nombre,
                                                                        list[i].apellido, list[i].sexo,
                                                                        list[i].telefono, list[i].mail,
                                                                        list[i].fechaAsociado.dia,
                                                                        list[i].fechaAsociado.mes,
                                                                        list[i].fechaAsociado.anio);
            }
        }
    }

    return result;
}

/** \brief Busca el primer lugar vacío de la lista
 *         (con el campo isEmpty == 1)
 *
 * \param list es el array de socios
 * \param len es la cantidad de socios
 * \param index es donde se carga el indice libre
 * \return int Devuelve [-1] si hay error
 *                      [0] si está todo ok
 *
 */
int findEmptyIndexSocios(Socios* list, int len, int* index)
{
    int result = -1;
    int i;

    if(list != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty == 1)
            {
                *index = i;
                result = 0;
                break;
            }
        }
    }

    return result;
}

/** \brief Imprime la lista de socios activos
 *         (con el campo isEmpty == 0)
 *
 * \param list es el array de socios
 * \param len es la cantidad de socios
 * \return int Devuelve [-1] si hay error
 *                      [0] si está todo ok
 *
 */
int altaSocios(Socios* list, int len)
{
    int result = -1;
    int emptyIndex;
    int flagIndex = 0; // para saber si se encontró un índice libre
    Socios aux; // para guardar los datos ingresados

    // primero busco un lugar libre:
    if(!findEmptyIndexSocios(list, len, &emptyIndex))
    {
        flagIndex=1;
    }
    else
    {
        printf("\nNo existen lugares libres para ingresar una nueva alta\n");
    }

    // si encuentro un lugar libre pido los datos
    if(flagIndex && list!=NULL && len>0)
    {
        if( !getStringLetras(aux.nombre, "\nIngrese el nombre: \n", "\nIngreso invalido\n", 2) // nombre[31]
            && !getStringLetras(aux.apellido, "\nIngrese el apellido: \n", "\nIngreso invalido\n", 2) // apellido[31]
            && !getSexo(&aux.sexo, "\nIngrese el sexo[F][M]: \n", "\nIngreso invalido\n", 2) // sexo[F][M]
            && !getTelephone(aux.telefono, "\nIngrese el telefono [011-4XXXXXX]: \n", "Ingreso invalido\n", 2) // telefono[16]
            && !getString(aux.mail, "\nIngrese el eMail: ", "\nIngreso invalido") // mail[31]
            && !getIntInRange(&aux.fechaAsociado.dia, "\nIngrese la fecha de registro\nDia: ", "\nIngreso invalido. Reingrese dia: ", 1, 31, 2) // dia
            && !getIntInRange(&aux.fechaAsociado.mes, "\nMes: ", "\nIngreso invalido. Reingrese mes: ", 1, 12, 2) // mes
            && !getIntInRange(&aux.fechaAsociado.anio, "\nAnio: ", "\nIngreso invalido. Reingrese anio: ", 1810, 2019, 2)); // anio
        {
            // idSocios
            aux.idSocios = generarIdSocio();

            // campo isEmpty
            aux.isEmpty = 0; // ya no está más vacío

            // si está todo bien, asigno los datos:
            list[emptyIndex]=aux;

            result=0;

            printf("\nAlta ingresada exitosamente\n\n");
        }
    }

    return result;
}

/** \brief Busca un socio a partir del id
 *
 * \param list es el array de socios
 * \param len es la cantidad de socios
 * \param input Se carga el indice del socio buscado
 * \return int Devuelve [-1] si hay error
 *                      [0] si está todo ok
 *
 */
int buscarSocios(Socios* list, int len, int* input)
{
    int result=-1;
    int idSocioBuscado;
    int i;

    getIntInRange(&idSocioBuscado, "\nIngrese el id del socio: ", "\nIngreso invalido\n\n", 0, len, 2);

    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==0 && list[i].idSocios==idSocioBuscado)
        {
            *input=i;
            result=0;
            break;
        }
    }

    return result;
}

/** \brief Realiza la baja lógica de un socio
 *
 * \param list es el array de socios
 * \param len es la cantidad de socios
 * \return int Devuelve [-1] si hay error
 *                      [0] si está todo ok
 *
 */
int bajaSocios(Socios* list, int len)
{
    int result=-1;
    int idSocioBaja;

    if(!buscarSocios(list, len, &idSocioBaja))
    {
        list[idSocioBaja].isEmpty=1; // baja lógica
        result = 0;
        printf("\nSe dio de baja a %s %s\n\n", list[idSocioBaja].nombre, list[idSocioBaja].apellido);
    }
    else
    {
        printf("\nNo se encontro socio con ese id\n\n");
    }

    return result;
}

/** \brief Ordena los socios por apellido
 *
 * \param list es el array de socios
 * \param len es la cantidad de socios
 * \return int Devuelve [-1] si hay error
 *                      [0] si está todo ok
 *
 */
int ordenarSocios(Socios* list, int len)
{
    int result=-1;
    Socios aux;
    int i;
    int j;

    for(i=0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(strcmp(list[i].apellido, list[j].apellido)>0)
            {
                aux=list[i];
                list[i]=list[j];
                list[j]=aux;
                result=0;
            }
        }
    }

    return result;
}

/** \brief Muestra un menú para editar socio
 *
 * \param list es el array de socios
 * \param len es la cantidad de socios
 * \return int Devuelve [-1] si hay error
 *                      [0] si está todo ok
 *
 */
int modificarSocios(Socios* list, int len)
{
    int result=-1;
    int idSocioBuscado;
    int menuModificar;

    if(buscarSocios(list, len, &idSocioBuscado)==0)
    {
        result=0;

        do{
            system("cls");

            printf("*** MENU MODIFICAR - SOCIO: %s %s ***\n\n", list[idSocioBuscado].nombre, list[idSocioBuscado].apellido);
            printf("1. Nombre\n");
            printf("2. Apellido\n");
            printf("3. Sexo\n");
            printf("4. Telefono\n");
            printf("5. eMail\n");
            printf("6. Volver al menu principal\n");

            getIntInRange(&menuModificar, "\nSeleccione una opcion del menu: ", "\nOpcion no valida\n\n", 1, 6, 1);

            switch(menuModificar)
            {
                case 1: // modificar nombre
                    getStringLetras(list[idSocioBuscado].nombre, "\nIngrese el nuevo nombre: ", "\nIngreso invalido\n\n", 2);
                    system("pause");
                    break;

                case 2: // modificar apellido
                    getStringLetras(list[idSocioBuscado].apellido, "\nIngrese el nuevo apellido: ", "\nIngreso invalido\n\n", 2);
                    system("pause");
                    break;

                case 3: // modificar sexo
                    getSexo(&list[idSocioBuscado].sexo, "\nIngrese nuevo sexo: ", "\nIngreso invalido\n\n", 2);
                    system("pause");
                    break;

                case 4: // modificar telefono
                    getTelephone(list[idSocioBuscado].telefono, "\nIngrese nuevo telefono: ", "\n Ingreso invalido\n\n", 2);
                    system("pause");
                    break;

                case 5: // modificar mail
                    getMail(list[idSocioBuscado].mail, "\nIngrese nuevo eMail: ", "\nIngreso invalido\n\n", 2);
                    system("pause");
                    break;
            }
        }while(menuModificar!=6);
    }

    return result;
}
