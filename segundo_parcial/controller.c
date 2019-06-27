#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "entregas.h"
#include "Controller.h"
#include "parser.h"
#include "arraynuevo.h"
#define TRIES 3


/** \brief Alta de entrega
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int

 */
int controller_addEntrega(LinkedList* pArrayListEntrega)
{
    Entregas* newEntrega;
    char bufferId[1500];
    char bufferTipo[1500];
    char bufferCantidad[1500];
    char bufferPeso[1500];
    int retorno = -1;

    if(pArrayListEntrega != NULL)
    {
        if((getStringNumerosInt(bufferId,"Ingrese id: ","Error",TRIES)== 0)
           &&(getStringLetras(bufferTipo,"Ingrese tipo: ","Error",TRIES) == 0)
                &&(getStringNumerosInt(bufferCantidad,"Ingrese cantidad: ","Error",TRIES) == 0)
                &&(getStringNumerosFloat(bufferPeso,"Ingrese peso: ","Error",TRIES == 0)))
        {
            newEntrega = entrega_newParametros(bufferId,bufferTipo,bufferCantidad,bufferPeso);
            if(newEntrega != NULL)
            {
                if(ll_add(pArrayListEntrega,newEntrega) == 0)
                    {
                       retorno = 0;
                    }
            }
        }
    }
    return retorno;
}

/** \brief Modificar datos de entrega
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int controller_modifyEntregas(LinkedList* pArrayListEntregas)
{
    Entregas* pEntregas;
    int retorno = -1;
    int size;
    char bufferId[1500];
    int auxId;
    int idBuscado;
    char bufferTipo[1500];
    char bufferCantidad[1500];
    char bufferPeso[1500];
    int i;
    int option;

    if (pArrayListEntregas != NULL)
    {
        size = ll_len(pArrayListEntregas);
        if(getStringNumerosInt(bufferId,"Ingrese el ID de la entrega que desea modificar: ","Error\n",TRIES) == 0)
        {
            auxId = atoi(bufferId);
            for (i=0; i<size; i++)
            {
                pEntregas = ll_get(pArrayListEntregas,i);
                if(auxId == entrega_getId(pEntregas,&idBuscado))
                {
                    do
                    {
                        printf("Elija que desea modificar: \n");
                        printf("1- Tipo de la entrega\n2- Cantidad de la entrega\n"
                               "3- Peso de la entrega\n4- Salir\n");

                        getIntInRange(&option,"Ingrese Opcion: ","Error\n",1,4,TRIES);
                        switch (option)
                        {
                        case 1:
                            if(getStringLetras(bufferTipo,"Ingrese nuevo tipo: ","Error\n",TRIES) == 0)
                            {
                                entrega_setTipo(pEntregas,bufferTipo);
                                retorno = 0;
                            }
                            break;
                        case 2:
                            if(getStringNumerosInt(bufferCantidad,"Ingrese nueva cantidad: ","Error\n",TRIES) == 0)
                            {
                                entrega_setCantidad(pEntregas,bufferCantidad);
                                retorno = 0;
                            }
                            break;
                        case 3:
                            if(getStringNumerosFloat(bufferPeso,"Ingrese nuevo peso: ","Error\n",TRIES) == 0)
                            {
                                entrega_setPeso(pEntregas,bufferPeso);
                                retorno = 0;
                            }
                            break;
                        }
                    }
                    while (option != 4);
                }
            }
        }
    }
    return retorno;
}

/** \brief Baja de entrega
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int controller_removeEntregas(LinkedList* pArrayListEntregas)
{
    Entregas* pEntregas;
    int retorno = -1;
    int size;
    char bufferId[1500];
    int auxId;
    int idBuscado;
    int i;

    if (pArrayListEntregas != NULL)
    {
        size = ll_len(pArrayListEntregas);
        if(getStringNumerosInt(bufferId,"Ingrese el ID de la entrega que desea bajar: ","Error\n",TRIES) == 0)
        {
            auxId = atoi(bufferId);
            for (i=0; i<size; i++)
            {
                pEntregas = ll_get(pArrayListEntregas,i);
                if(auxId == entrega_getId(pEntregas,&idBuscado))
                {
                    ll_remove(pArrayListEntregas,i);
                    entrega_delete(pEntregas);
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}

/** \brief Listar entregas
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int controller_listEntregas(LinkedList* pArrayListEntregas)
{
    Entregas* pE;
    int auxId;
    float auxPeso;
    int auxCantidad;
    char auxTipo[1500];
    int size;
    int i;

    if(pArrayListEntregas != NULL)
    {
        size = ll_len(pArrayListEntregas);
        for(i=0; i<size; i++)
        {
            pE = ll_get(pArrayListEntregas,i);
            entrega_getId(pE,&auxId);
            entrega_getTipo(pE,auxTipo);
            entrega_getCantidad(pE,&auxCantidad);
            entrega_getPeso(pE,&auxPeso);
            if(pE != NULL)
            {
                printf("%d\t %s\t %d\t %f\n",auxId,
                                            auxTipo,
                                            auxCantidad,
                                            auxPeso);
            }
        }
    }
    return 0;
}

/** \brief Ordenar entregas
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int controller_sortEntregas(LinkedList* pArrayListEntregas)
{
    int retorno = -1;

    if(pArrayListEntregas != NULL)
    {
        ll_sort(pArrayListEntregas,entrega_sortByTipo,1);
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda los datos de los entregas en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEntregas)
{
    Entregas* pE;
    int auxId;
    float auxPeso;
    int auxCantidad;
    char auxTipo[1500];
    int size;
    int i;
    int retorno = 1;

    FILE* fp = fopen(path,"w+");
    if(fp != NULL && pArrayListEntregas != NULL)
    {
        fprintf(fp,"id,tipo,cantidad,peso\n");

        size = ll_len(pArrayListEntregas);

        for(i=0;i<size;i++)
        {
            pE = ll_get(pArrayListEntregas,i);
            entrega_getId(pE,&auxId);
            entrega_getTipo(pE,auxTipo);
            entrega_getCantidad(pE,&auxCantidad);
            entrega_getPeso(pE,&auxPeso);
            if(pE != NULL)
            {
                fprintf(fp,"%d,%s,%d,%f\n",auxId,
                                            auxTipo,
                                            auxCantidad,
                                            auxPeso);
            }
        }
        fclose(fp);
        retorno = 0;
    }
    return retorno;
}
