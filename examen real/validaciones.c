#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Parser.h"
#include "LinkedList.h"
#include "informes.h"
#include "Venta.h"
#include "Fecha.h"

/** \brief Obtiene un string
* \param array de char sin especificar
* \param algun mensaje que se quiera expresar
* \param msgE mensajes de error de las funciones
* \return retorna 0 diciendo que no hay error
*/
int getString(char* pStr, char* msg, char*msgE)
{
    char bufferStr[20];
    printf("%s",msg);
    fgets(bufferStr,sizeof(bufferStr),stdin);
    bufferStr[strlen(bufferStr)-1] = '\0';
    if(pStr!=NULL)
    {
        strncpy(pStr,bufferStr,20);
    }
    else
    {
        printf("%s",msgE);
    }
    return 0;
}

/** \brief Obtiene una variable int
* \param array de int sin especificar
* \param algun mensaje que se quiera expresar
* \param msgE mensajes de error de las funciones
* \return retorna 0 diciendo que no hay error o -1 si lo hay
*/
int getInt (int *pNum, char* msg, char* msgE)

{
    int number;
    int ret=-1;
    printf("%s",msg);
    if(scanf("%d",&number)==1)
    {
        (*pNum)=number;
        ret=0;
    }
    else
    {
        printf("%s",msgE);
    }
    return ret;
}

/** \brief Obtiene una variable int dentro de cierto rango
* \param array de int sin especificar
* \param algun mensaje que se quiera expresar
* \param msgE mensajes de error de las funciones
* \param min delimita el minimo del rango
* \param max delimita el maximo del rango
* \param la cantidad de reintentos antes de fallar
* \return retorna 0 diciendo que no hay error o -1 si lo hay
*/
int getIntInRange(  int *pNum,
                    char *msg,
                    char *msgE,
                    int minimo,
                    int maximo,
                    int reintentos)
{
    int retorno = -1;
    char bufferStr[20];
    int bufferInt;
    if( pNum != NULL &&
            reintentos >= 0)
    {
        if(!getString(bufferStr,msg,msgE) &&
                isNumberInt(bufferStr))
        {
            bufferInt = atoi(bufferStr);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                retorno = 0;
                *pNum = bufferInt;
            }
        }
    }
    return retorno;
}

/** \brief Obtiene un array de letras
* \param array de string (validado con letras)
* \param algun mensaje que se quiera expresar
* \param msgE mensajes de error de las funciones
* \param cantidad de reintentos antes de fallar
* \return retorna 0 diciendo que no hay error o -1 si lo hay
*/
int getStringLetras (char* pStr, char* msg, char* msgE,int reintentos)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && reintentos>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pStr!=NULL)&&(isLetter(bufferStr)))
        {
            strncpy(pStr,bufferStr,20);
            ret=0;
        }
        else
        {
            printf("%s",msgE);
            reintentos--;
        }
    }
    return ret;
}
/** \brief Obtiene un array de numeros int
* \param array de string (validado con int)
* \param algun mensaje que se quiera expresar
* \param msgE mensajes de error de las funciones
* \param cantidad de reintentos antes de fallar
* \return retorna 0 diciendo que no hay error o -1 si lo hay
*/
int getStringNumerosInt (char* pStr, char* msg, char* msgE,int reintentos)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && reintentos>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pStr!=NULL)&&(isNumberInt(bufferStr)))
        {
            strncpy(pStr,bufferStr,20);
            ret=0;
        }
        else
        {
            printf("%s",msgE);
            reintentos--;
        }
    }
    return ret;
}


/** \brief Ordena array de mayor a menor
* \param array de char
* \param tamaño del array
* \param tamaño del array
* \return retorna 0 diciendo que no hay error
*/
int ordenarArrayMayorMenor(char* pArray, int len,int limit)
{
    int i;
    int j;
    char buffer[limit];
    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(pArray[i]>pArray[j])
            {
                buffer[i]=pArray[i];
                pArray[i]=pArray[j];
                pArray[j]=buffer[i];
            }
        }
    }
    return 0;
}
/** \brief Muestra un array de int
* \param array de int
* \param tamaño del array
* \return retorna 0 diciendo que no hay error
*/
int showArrayInt(int* pArray,int len)

{
    int i;
    for(i=0; i<len; i++)
    {
        printf("%d\n",pArray[i]);
    }
    return 0;
}
/** \brief Muestra array de char
* \param array de char
* \param tamaño del array
* \return retorna 0 diciendo que no hay error
*/
int showArrayChar(char* pArray,int len)

{
    int i;
    for(i=0; i<len; i++)
    {
        printf("%d\n",pArray[i]);
    }
    return 0;
}
/** \brief Valida numeros enteros
* \param array de char
* \return retorna 1 diciendo que no hay error
*/
int isNumberInt (char* pStr)
{
    int i=0;
    while(pStr[i]!='\0')
    {
        if(pStr[i]<'0' || pStr[i]>'9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/** \brief Valida letras minusculas y mayusculas
* \param array de char
* \return retorna 1 diciendo que no hay error
*/
int isLetter (char* pStr)
{
    int i=0;
    while(pStr[i]!='\0')
    {
        if((pStr[i]!=' ')&&(pStr[i]<'a'||pStr[i]>'z')&&(pStr[i]<'A'||pStr[i]>'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/** \brief Obtiene una variable float
* \param array de float sin especificar
* \param algun mensaje que se quiera expresar
* \param msgE mensajes de error de las funciones
* \return retorna 0 diciendo que no hay error o -1 si lo hay
*/
int getFloat (float *pNum, char* msg, char* msgE)

{
    float number;
    int ret=-1;
    printf("%s",msg);
    if(scanf("%f",&number)==1)
    {
        (*pNum)=number;
        ret=0;
    }
    else
    {
        printf("%s",msgE);
    }
    return ret;
}

/** \brief Obtiene un array de numeros float
* \param array de string (validado con float)
* \param algun mensaje que se quiera expresar
* \param msgE mensajes de error de las funciones
* \param cantidad de reintentos antes de fallar
* \return retorna 0 diciendo que no hay error o -1 si lo hay
*/
int getStringNumerosFloat (char* pStr, char* msg, char* msgE,int reintentos)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && reintentos>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pStr!=NULL)&&(isNumberFloat(bufferStr)))
        {
            strncpy(pStr,bufferStr,20);
            ret=0;
        }
        else
        {
            printf("%s",msgE);
            reintentos--;
        }
    }
    return ret;
}

/** \brief Valida numeros flotantes
* \param array de char
* \return retorna 1 diciendo que no hay error
*/
int isNumberFloat (char* pStr)
{
    int i=0;
    int contadorPuntos=0;
    while(pStr[i]!='\0')
    {
        if((pStr[i]!='.') && (pStr[i]<'0' || pStr[i]>'9'))
        {
            return 0;
        }
        if(pStr[i] == '.')
        {
            contadorPuntos++;
            if(contadorPuntos > 1)
            {
                return 0;
            }
        }

        i++;
    }
    return 1;
}

/** \brief Valida fecha
* \param variable entera
* \param variable entera
* \param variable entera
* \return retorna 1 diciendo que no hay error
*/
int isFecha(int dia,int mes,int anio)
{
    int ret = 0;

    if((anio < 1900 || anio > 2030) &&
            (mes < 1 || mes > 12) &&
            (dia < 1 || dia > 31))
    {
        ret = 0;
    }
    switch(mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    {
        if(dia < 1 || dia > 31)
        {
            ret = 1;
        }
        break;
    }
    case 4:
    case 6:
    case 9:
    case 11:
    {
        if(dia < 1 || dia > 30)
        {
            ret = 1;
        }
        break;
    }
    case 2:
    {
        if(dia < 1 || dia > 29)
        {
            ret = 1;
        }
        break;
    }
    }
    return ret;
}

/** \brief Obtiene un array de string
* \param puntero entero
* \param puntero entero
* \param puntero entero
* \param msgE mensajes de error de las funciones
* \param cantidad de reintentos antes de fallar
* \return retorna 0 diciendo que no hay error o -1 si lo hay
*/
int getFecha (int* dia,int* mes,int* anio,char* msgE,int reintentos)
{
    int auxiliarDia;
    int auxiliarMes;
    int auxiliarAnio;
    int ret = -1;

    if(dia != NULL && mes != NULL && anio != NULL && reintentos > 0)
    {
        while(ret == -1)
        {
            if((getInt(&auxiliarDia,"Ingrese dia: ",msgE)==0)&&
                    (getInt(&auxiliarMes,"Ingrese mes: ",msgE)==0)&&
                    (getInt(&auxiliarAnio,"Ingrese anio: ",msgE)==0)&&
                    (isFecha(auxiliarDia,auxiliarMes,auxiliarAnio)))
            {
                *dia = auxiliarDia;
                *mes = auxiliarMes;
                *anio = auxiliarAnio;
                ret = 0;
            }
            else
            {
                printf(msgE);
                ret = -1;
                reintentos--;
            }
        }
    }
    return ret;
}

/** \brief Valida cuit/cuil
* \param array de char
* \return retorna 1 diciendo que no hay error
*/
int isCuit (char* pStr)
{
    int ret=0;
    int i=0;
    while(pStr[i]!='\0')
    {
        if((pStr[i]!='-')&&(pStr[i]<'0' || pStr[i]>'9'))
        {
            return 0;
        }
        else if((pStr[2]=='-')&&(pStr[10]=='-' || pStr[11]=='-'))
        {
            ret=1;
        }
        i++;
    }
    return ret;
}

/** \brief Obtiene un array de string
* \param array de string (validado con cuit/cuil)
* \param algun mensaje que se quiera expresar
* \param msgE mensajes de error de las funciones
* \param cantidad de reintentos antes de fallar
* \return retorna 0 diciendo que no hay error o -1 si lo hay
*/
int getCuit (char* pStr, char* msg, char* msgE,int reintentos)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && reintentos>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pStr!=NULL)&&(isCuit(bufferStr)))
        {
            strncpy(pStr,bufferStr,20);
            ret=0;
        }
        else
        {
            printf("%s",msgE);
            reintentos--;
        }
    }
    return ret;
}
