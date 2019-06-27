#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;
    Node* auxNode;
    int size = ll_len(this);

    if(this != NULL && nodeIndex >= 0 && nodeIndex < size)
    {
        auxNode = this->pFirstNode;
        for(i=0; i<nodeIndex; i++)
        {
            auxNode = auxNode -> pNextNode;
        }
        pNode = auxNode;
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNode;
    Node* auxNode;
    int size = ll_len(this);

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= size)
    {
        newNode = (Node*)malloc(sizeof(Node));

        if(newNode != NULL)
        {
            newNode->pElement = pElement;
            newNode->pNextNode = NULL;
        }
        if(nodeIndex == 0)
        {
            auxNode = this->pFirstNode;
            this->pFirstNode = newNode;
            newNode->pNextNode = auxNode;
            returnAux = 0;
            this->size++;
        }
        else
        {
            auxNode = getNode(this,nodeIndex-1);
            if(auxNode != NULL)
            {
                newNode->pNextNode = auxNode->pNextNode;
                auxNode->pNextNode = newNode;
                returnAux = 0;
                this->size++;
            }
        }
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int size;

    if(this != NULL)
    {
        size = ll_len(this);
        addNode(this,size,pElement);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodeAux;
    int size;

    size = ll_len(this);
    if(this != NULL && index >= 0 && index < size)
    {
        nodeAux = getNode(this,index);
        if(nodeAux != NULL)
        {
            returnAux = nodeAux->pElement;
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int size;
    Node* auxNode;

    size = ll_len(this);
    if(this != NULL && index >= 0 && index < size)
    {
        auxNode = getNode(this,index);

        auxNode->pElement = pElement;

        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int size;
    Node* auxNodeAnterior;
    Node* auxNodeEliminado;

    size = ll_len(this);
    if(this != NULL && index >= 0 && index < size)
    {
        if(index == 0)
        {
            auxNodeEliminado = this->pFirstNode; ///guardo en el auxiliar la direccion del nodo 0 actual
            this->pFirstNode = auxNodeEliminado->pNextNode; ///el pNext del nodo eliminado pasa a ser el pFirst del THIS
            free(auxNodeEliminado);
            returnAux = 0;
            this->size--;
        }
        else
        {
            auxNodeAnterior = getNode(this,index-1);
            auxNodeEliminado = getNode(this,index);
            if(auxNodeAnterior != NULL && auxNodeEliminado != NULL)
            {
                auxNodeAnterior->pNextNode = auxNodeEliminado->pNextNode;
                free(auxNodeEliminado);
                this->size--;
                returnAux = 0;
            }
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        while(this->size != 0) /// entra mientras la lista tenga al menos 1 nodo
        {
            ll_remove(this,0); /// borra la posicion 0 y decrementa el size
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        ll_clear(this);
        free(this);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    void* auxElement; ///siempre que usemos el pElement se pone el void*

    if(this != NULL)
    {
        for(i=0; i<this->size; i++)
        {
            auxElement = ll_get(this,i); ///guardo el elemento que tiene el indice i en el auxiliar
            if(auxElement == pElement) ///comparo el elemento que obtuve con el que me pasan por parametro
            {
                returnAux = i;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int size;

    if(this != NULL)
    {
        size = ll_len(this);
        if(size == 0)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement) /// una forma de add
{
    int returnAux = -1;
    int size;

    size = ll_len(this);
    if(this != NULL && index >= 0 && index <= size)
    {
        if(addNode(this,index,pElement) == 0)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index) ///get + remove
{
    void* returnAux = NULL;
    int size;

    size = ll_len(this);
    if(this != NULL && index >= 0 && index < size)
    {
        returnAux = ll_get(this,index);
        if(returnAux != NULL)
        {
            ll_remove(this,index);
        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement) ///indexOf + if
{
    int returnAux = -1;
    int index;

    if(this != NULL)
    {
        index = ll_indexOf(this,pElement);

        if(index >= 0)
        {
            returnAux = 1; ///devuelvo 1 cuando la lista contiene el elemento
        }
        else
        {
            returnAux = 0; /// devuelvo 0 si la lista NO contiene al elemento
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2) /// for + get + if (si no esta es false)
{
    int returnAux = -1;
    int i;
    int size;
    void* auxElement;

    if(this != NULL && this2 != NULL)
    {
        size = ll_len(this2);
        returnAux = 1;
        for(i=0; i<size; i++)
        {
            auxElement = ll_get(this2,i);
            if(ll_contains(this,auxElement) == 0)
            {
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to) ///newLinkedList + for la lista original (from a to) y get + add en la lista nueva
{
    LinkedList* cloneArray = NULL;
    int size;
    int i;
    Node* auxNode;

    size = ll_len(this);
    if(this != NULL && from >= 0 && to <= size)
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            for(i=from; i<to; i++)
            {
                auxNode = getNode(this,i);
                if(auxNode != NULL)
                {
                    addNode(cloneArray,i,auxNode->pElement);
                }
            }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this) /// llamo al subList e itero desde el 0 hasta el size
{
    LinkedList* cloneArray = NULL;
    int size;

    size = ll_len(this);

    if(this != NULL)
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            cloneArray = ll_subList(this,0,size);
        }
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    int size;
    int i;
    void* pFirstElement;
    void* pSecondElement;
    int flagSwap;

    size = ll_len(this);
    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
        do
        {
            flagSwap = 0;
            for(i=0; i<size-1; i++)
            {
                pFirstElement = ll_get(this,i);
                pSecondElement = ll_get(this,i+1);

                if(pFirstElement != NULL && pSecondElement != NULL)
                {
                    if((order == 1) && pFunc(pFirstElement,pSecondElement) == 1)
                    {
                        ll_set(this,i+1,pFirstElement);
                        ll_set(this,i,pSecondElement);
                        flagSwap = 1;
                    }
                    else if((order == 0) && pFunc(pFirstElement,pSecondElement) == -1)
                    {
                        ll_set(this,i+1,pFirstElement);
                        ll_set(this,i,pSecondElement);
                        flagSwap = 1;
                    }
                }
            }
            returnAux = 0;
        }
        while(flagSwap == 1);
    }
    return returnAux;
}


/** \brief
 * \param
 * \param
 * \param
 * \return
 */
int ll_map(LinkedList* this,int (*pFunc)(void*))
{
    int returnAux;
    int size;
    int i;
    void* pElement;

    size = ll_len(this);
    if(this != NULL && pFunc != NULL)
    {
        returnAux = 0;
        for(i=0; i<size; i++)
        {
            pElement = ll_get(this,i);
            if(pElement != NULL && pFunc(pElement) == -1)
            {
                returnAux = -1*i; /// la multiplicacion indica hasta donde llego con el proceso en caso de que la funcion sea grande
                break;
            }
        }
    }
    return returnAux;
}
/** \brief
 * \param
 * \param
 * \param
 * \return
 */
int ll_reduce(LinkedList* this,int (*pFunc)(void*))
{
    int returnAux = -1;
    int size;
    int i;
    void* pElement;

    size = ll_len(this);
    if(this != NULL && pFunc != NULL)
    {
        for(i=0; i<size; i++)
        {
            pElement = ll_get(this,i);
            if(pElement != NULL)
            {
                if(pFunc(pElement) == 0)
                {
                    if(ll_remove(this,i) == 0)
                    {
                        i--;
                    }
                }
            }
        }
        returnAux = 0;
    }
    return returnAux;
}
/** \brief
 * \param
 * \param
 * \param
 * \return
 */
LinkedList* ll_filter(LinkedList* this,int (*pFunc)(void*))
{
    LinkedList* returnAux = NULL;
    int i;
    int size;
    LinkedList* filterList = NULL;
    void* pElement;

    size = ll_len(this);
    if(this != NULL && pFunc != NULL)
    {
        filterList = ll_newLinkedList();
        if(filterList != NULL)
        {
            for(i=0; i<size; i++)
            {
                pElement = ll_get(this,i);
                if(pElement != NULL && pFunc(pElement) == 0)
                {
                    ll_add(filterList,pElement);
                }
            }
            returnAux = filterList;
        }
    }

    return returnAux;
}

int ll_contar(LinkedList* this,int (*pFunc)(void*)) ///necesito hacer funciones para contrar int y float
{
    int returnAux = -1;
    int size;
    int i;

    size = ll_len(this);
    if(this != NULL && pFunc != NULL)
    {
        returnAux = 0;
        for(i=0; i<size; i++)
        {
            returnAux += pFunc(ll_get(this,i));
        }
    }
    return returnAux;
}

int ll_contarFloat(LinkedList* this,int (*pFunc)(void*)) ///necesito hacer funciones para contrar int y float
{
    float returnAux = -1;
    int size;
    int i;

    size = ll_len(this);
    if(this != NULL && pFunc != NULL)
    {
        returnAux = 0;
        for(i=0; i<size; i++)
        {
            returnAux += pFunc(ll_get(this,i));
        }
    }
    return returnAux;
}
