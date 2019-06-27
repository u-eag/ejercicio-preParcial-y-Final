#ifndef ENTREGA_H_INCLUDED
#define ENTREGA_H_INCLUDED

typedef struct
{
    int id;
    char tipo[10];
    int cantidad;
    float peso;

}Entrega;

Entrega* entrega_new();
int entrega_delete(Entrega* this);
Entrega* entrega_newParametros(char* idStr, char* tipo, char* cantidad, char* peso);

int entrega_setId(Entrega* this, char* value);
int entrega_getId(Entrega* this, int* value);

int entrega_setTipo(Entrega* this, char* value);
int entrega_getTipo(Entrega* this, char* value);

int entrega_setCantidad(Entrega* this, char* value);
int entrega_getCantidad(Entrega* this, int* value);

int entrega_setPeso(Entrega* this, char* value);
int entrega_getPeso(Entrega* this, float* value);

#endif // ENTREGA_H_INCLUDED
