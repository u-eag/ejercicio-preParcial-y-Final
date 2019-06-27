#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

typedef struct
{
    int id; /// se va autoincrementando
    char tipo[50];
    int cantidad;
    float peso;

}Entregas;

Client* client_new();
Client* client_newParametros(char* idStr,char* nombreStr,char* surnameStr,char* dniStr);
Client* client_newParametrosConInt(int id,char* nombreStr,char* apellidoStr,char* dniStr);
int client_delete(Client* this);

int client_setIdStr(Client* this, char* value);
int client_setId(Client* this,int value);
int client_getId(Client* this,int* value);

int client_setTipo(Client* this,char* value);
int client_getTipo(Client* this,char* value);

int client_setCantidad(Client* this,char* value);
int client_getCantidad(Client* this,int* value);

int client_setPeso(Client* this,char* value);
int client_getPesoClient* this,float* value);

int client_sortBySurname(void* pFirstClient,void* pSecondClient);

#endif // CLIENT_H_INCLUDED

int client_generarId(void);

