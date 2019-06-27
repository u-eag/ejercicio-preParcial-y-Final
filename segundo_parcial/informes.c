#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "informes.h"
#include "controller.h"
#include "entregas.h"
#include "parser.h"

int generarArchivoInformes(char* fileName,LinkedList* listaEntregas)
{
    int size;
    int retorno = -1;
    int entregasSTD;
    int entregasEXP;
    int entregasECO;
    int entregaMaxima;
    float cantidadBultos;
    float cantidadPesos;

    FILE* fp = fopen(fileName,"w+");
    if(fp != NULL && listaEntregas!= NULL)
    {
        size = informe_cantidadTotalEntregas(listaEntregas);
        entregasSTD = informe_cantidadEntregasPorTipo(listaEntregas,1);
        entregasEXP = informe_cantidadEntregasPorTipo(listaEntregas,2);
        entregasECO = informe_cantidadEntregasPorTipo(listaEntregas,3);
        entregaMaxima = informe_cantidadMaximaDeEntregas(listaEntregas);
        cantidadBultos = informe_cantidadBultosPorEntrega(listaEntregas);
        cantidadPesos = informe_pesoTotalPorEntrega(listaEntregas);

        fprintf(fp,"*******************\n");
        fprintf(fp,"Informe de ventas\n");
        fprintf(fp,"*******************\n");
        fprintf(fp,"- Cantidad total de entregas: %d\n",size);
        fprintf(fp,"- Cantidad de entregas por tipo: %d (STD) %d (EXP) %d (ECO)\n",entregasSTD,entregasEXP,entregasECO);
        fprintf(fp,"- Cantidad maxima de bultos entregados: %d\n",entregaMaxima);
        fprintf(fp,"- Promedio de bultos por entrega: %.2f\n",cantidadBultos/size);
        fprintf(fp,"- Promedio de peso por entrega: %.2f\n",cantidadPesos/size);
        fprintf(fp,"*******************");


        fclose(fp);
        retorno = 1;
    }
    return retorno;
}

int informe_cantidadTotalEntregas(LinkedList* pArrayListEntregas)
{
    int auxReturn = -1;
    int size;

    if(pArrayListEntregas != NULL)
    {
        size = ll_len(pArrayListEntregas);
        auxReturn = size;
    }
    return auxReturn;
}

int informe_cantidadEntregasPorTipo(LinkedList* pArrayListEntregas,int tipo)///STD = 1 - EXP = 2 - ECO = 3
{
    int auxReturn = -1;
    int i;
    int size;

    if(pArrayListEntregas != NULL && (tipo >= 1 || tipo <= 3))
    {
        size = ll_len(pArrayListEntregas);
        auxReturn = 0;
        for(i=0;i<size;i++)
        {
            if(tipo == 1)
            {
                auxReturn = ll_contar(pArrayListEntregas,entrega_contarByTipoSTD);
            }
            else if(tipo == 2)
            {
                auxReturn = ll_contar(pArrayListEntregas,entrega_contarByTipoEXP);
            }
            else
            {
                auxReturn = ll_contar(pArrayListEntregas,entrega_contarByTipoECO);
            }
        }
    }
    return auxReturn;
}

int informe_cantidadMaximaDeEntregas(LinkedList* pArrayListEntregas)
{
    int auxReturn = -1;
    int i;
    int size;
    Entregas* pEntrega;
    int maximo = 0;

    if(pArrayListEntregas != NULL)
    {
        size = ll_len(pArrayListEntregas);
        auxReturn = 0;
        for(i=0;i<size;i++)
        {
            pEntrega = ll_get(pArrayListEntregas,i);
            if(pEntrega != NULL && pEntrega->cantidad > maximo)
            {
                maximo = pEntrega->cantidad;
            }
        }
        auxReturn = maximo;
    }

    return auxReturn;
}

int informe_cantidadBultosPorEntrega(LinkedList* pArrayListEntregas)
{
    int auxReturn = -1;
    int i;
    int size;
    Entregas* pEntrega;
    int cantidadTotal = 0;
    float promedio;

    if(pArrayListEntregas != NULL)
    {
        size = ll_len(pArrayListEntregas);
        auxReturn = 0;
        for(i=0;i<size;i++)
        {
            pEntrega = ll_get(pArrayListEntregas,i);
            if(pEntrega != NULL && pEntrega->cantidad )
            {
                cantidadTotal += ll_contar(pArrayListEntregas,entrega_contarCantidad);
            }
        }
        promedio = (float)cantidadTotal/size;
        auxReturn = promedio;
    }
    return auxReturn;
}

int informe_pesoTotalPorEntrega(LinkedList* pArrayListEntregas)
{
    int auxReturn = -1;
    int i;
    int size;
    Entregas* pEntrega;
    float cantidadTotal = 0;
    float promedio;

    if(pArrayListEntregas != NULL)
    {
        size = ll_len(pArrayListEntregas);
        auxReturn = 0;
        for(i=0;i<size;i++)
        {
            pEntrega = ll_get(pArrayListEntregas,i);
            if(pEntrega != NULL && pEntrega->peso >= 0)
            {
                cantidadTotal += ll_contarFloat(pArrayListEntregas,entrega_contarPeso);
            }
        }
        promedio = cantidadTotal/size;
        auxReturn = promedio;
    }
    return auxReturn;
}
