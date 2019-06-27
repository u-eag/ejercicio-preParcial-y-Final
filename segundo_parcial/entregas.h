#ifndef ENTREGAS_H_INCLUDED
#define ENTREGAS_H_INCLUDED

typedef struct
{
    int id; /// se va autoincrementando
    char tipo[50];
    int cantidad;
    float peso;

}Entregas;

Entregas* entrega_new();
Entregas* entrega_newParametros(char* idStr,char* tipoStr,char* cantidadStr,char* pesoStr);
Entregas* entrega_newParametrosConInt(int id,char* nombreStr,char* apellidoStr,char* dniStr);
int entrega_delete(Entregas* this);

int entrega_setIdStr(Entregas* this, char* value);
int entrega_setId(Entregas* this,int value);
int entrega_getId(Entregas* this,int* value);

int entrega_setTipo(Entregas* this,char* value);
int entrega_getTipo(Entregas* this,char* value);

int entrega_setCantidad(Entregas* this,char* value);
int entrega_getCantidad(Entregas* this,int* value);

int entrega_setPeso(Entregas* this,char* value);
int entrega_getPeso(Entregas* this,float* value);

int entrega_sortByTipo(void* pFirstEntregas,void* pSecondEntregas);
int entrega_contarByTipoSTD(void* pEntrega);
int entrega_contarByTipoEXP(void* pFirstEntrega);
int entrega_contarByTipoECO(void* pFirstEntrega);
int entrega_contarCantidad(void* pFirstEntrega);
int entrega_contarPeso(void* pFirstEntrega);

#endif // ENTREGAS_H_INCLUDED
