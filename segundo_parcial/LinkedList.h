#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

struct Node
{
    void* pElement;
    struct Node* pNextNode;
} typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
} typedef LinkedList;

#endif // LINKEDLIST_H_INCLUDED

//Publicas
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this);
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);
void* ll_get(LinkedList* this, int index);
int ll_set(LinkedList* this, int index,void* pElement);
int ll_remove(LinkedList* this,int index);
int ll_clear(LinkedList* this);
int ll_deleteLinkedList(LinkedList* this);
int ll_indexOf(LinkedList* this, void* pElement);
int ll_isEmpty(LinkedList* this);
int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this,int index);
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList* this);
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order);

int ll_map(LinkedList* this,int (*pFunc)(void*)); /// recorre ejecutando la funci�n que recibe como par�metro
int ll_reduce(LinkedList* this,int (*pFunc)(void*)); ///borra nodo cuando se cumple el filtro de la funcion parametro (hay que tener en cuenta el for con el borrado)
LinkedList* ll_filter(LinkedList* this,int (*pFunc)(void*)); /// crea una lista nueva con los elementos que cumplan el filtro de la funcion par�metro
int ll_contar(LinkedList* this,int (*pFunc)(void*)); ///necesito hacer funciones para contrar int y float
int ll_contarFloat(LinkedList* this,int (*pFunc)(void*)); ///necesito hacer funciones para contrar int y float

