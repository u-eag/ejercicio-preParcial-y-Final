#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "client.h"


Client* client_new()
{
    return (Client*) malloc(sizeof(Client));
}

Client* client_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* dniStr)
{

    Client* cli = client_new();
    if(cli!=NULL)
    {
        client_setIdStr(cli,idStr);
        client_setNombre(cli,nombreStr);
        client_setApellido(cli,apellidoStr);
        client_setDni(cli,dniStr);
    }
    return cli;
}

Client* client_newParametrosConInt(int id,char* nombreStr,char* apellidoStr,char* dniStr)
{

    Client* cli = client_new();
    if(cli!=NULL)
    {
        client_setId(cli,id);
        client_setNombre(cli,nombreStr);
        client_setApellido(cli,apellidoStr);
        client_setDni(cli,dniStr);
    }
    return cli;
}

int client_delete(Client* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int client_setIdStr(Client* this, char* value)
{
    int auxID;
    int retorno = -1;

    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxID = atoi(value);
        if(auxID > 0)
        {
            client_setId(this,auxID);
            retorno = 0;
        }
    }
    return retorno;
}

int client_setId(Client* this,int value)
{
    int retorno  =-1;
    if (this!=NULL && value > 0)
    {
        this->idClient = value;
        retorno = 0;
    }
    return retorno;
}

int client_setDni(Client* this,char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isDni(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->dni,value,sizeof(this->dni));
            retorno = 0;
        }
    }
    return retorno;
}

int client_setNombre(Client* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isLetter(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->name,value,sizeof(this->name));
            retorno = 0;
        }
    }
    return retorno;
}


int client_setApellido(Client* this,char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isLetter(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->surname,value,sizeof(this->surname));
            retorno = 0;
        }
    }
    return retorno;
}


int client_getNombre(Client* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->name,sizeof(this->name));
        retorno = 0;
    }
    return retorno;
}

int client_getDni(Client* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->dni,sizeof(this->dni));
        retorno = 0;
    }
    return retorno;
}

int client_getApellido(Client* this,char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->surname,sizeof(this->surname));
        retorno = 0;
    }
    return retorno;
}

int client_getId(Client* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->idClient;
        retorno = 0;
    }
    return retorno;
}


int client_initArray(Client* arrayCliente[],int lenCliente)
{
    int i;
    int retorno = -1;
    if(arrayCliente != NULL && lenCliente > 0)
    {
        for(i=0; i<lenCliente; i++)
        {
            arrayCliente[i] = NULL;
        }
        retorno = 0;

    }
    return retorno;
}

int client_findFree(Client* arrayClient[], int lenClient)
{
    int i;
    int ret = -1;
    if(arrayClient != NULL && lenClient > 0)
    {
        for(i=0; i<lenClient; i++)
        {
            if(arrayClient[i] == NULL)
            {
                ret = i;
                printf("\n----Se encontro lugar libre----\n");
                break;
            }
        }
    }
    return ret;
}

int client_sortBySurname(void* pFirstClient,void* pSecondClient)
{
    int retorno;
    Client* pClientA;
    Client* pClientB;

    pClientA = (Client*) pFirstClient;
    pClientB = (Client*) pSecondClient;

    if(strcmp(pClientA->surname,pClientB->surname) > 0)
    {
        retorno = 1;///mayor el primero
    }
    else if(strcmp(pClientA->surname,pClientB->surname) < 0)
    {
        retorno = -1;///menor el primero
    }
    else
    {
        retorno = 0;///ambos iguales
    }
    return retorno;
}

static int idCli = 0;

int client_generarId(void)
{
    return idCli++;
}
