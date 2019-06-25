#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

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

    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    // la lista no puede ser nula, el índice no puede ser negativo ni mayor al tamaño de la lista
    {
         pNode = this->pFirstNode; // asigno la dirección de memoria del nodo cero

         for(i=0;i<nodeIndex;i++) // recorro hasta el índice pasado por parámetro -1
         {
             pNode = pNode->pNextNode; // devuelve la dirección de memoria del índice pasado por parámetro
                                        // que está guardado en la variable pNextNode del nodo anterior
         }
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

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)) // "=" para poder agregarlo al último
    {
        Node* pNodeAux = NULL; // para guardar pNextNode antes de hacer el swap
        Node* pNewNode;
        Node* getNodeR; // para guardar el retorno de la función getNode

        // crear un nodo, asignarle pElement (pasado por parámetro) y NULL/puntero en pNextNode
        // al último nodo asignarle el puntero al nodo nuevo

        pNewNode = (Node*)malloc(sizeof(Node)); // creo el nodo nuevo

        if(pNewNode != NULL) // valido que el nodo nuevo no sea null
        {
            pNewNode->pElement = pElement; // le cargo el elemento al nodo nuevo
            pNewNode->pNextNode = NULL; // capaz no hace falta, pero le asigno NULL de entrada
        }

        if(nodeIndex == 0)
        // el usuario quiere agregar el nodo nuevo en la posición cero
        {
            pNodeAux = this->pFirstNode; // me guardo la dirección de memoria del actual nodo cero

            this->pFirstNode = pNewNode; // asigno la dirección de memoria del nodo nuevo como nodo cero

            pNewNode->pNextNode = pNodeAux; // hago que el nodo nuevo (que ahora es el cero) apunte al ex-nodo-cero

            // incrementar el size
            this->size++;

            returnAux = 0;
        }
        else
        {
            // llamo a getNode y guardo en una variable auxiliar lo que tiene en pNextNode
            // después de guardar eso, asigno en pNextNode la dirección de memoria de la variable nueva

            getNodeR = getNode(this, nodeIndex-1); // voy a buscar el pNextNode del nodo ANTERIOR al que quiero posicionar el nuevo

            if (getNodeR != NULL)
                // getNode me devuelve la dirección de memoria del índice que le pasé -1
            {
                pNodeAux = getNodeR;

                getNodeR->pNextNode = pNewNode; // hago que el nodo ANTERIOR al que quiero apunte al nodo nuevo

                pNewNode->pNextNode = pNodeAux; // hago que el nodo nuevo apunte

                this->size++;

                returnAux = 0;
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
                        ( 0) Si funciono correctamente
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

    if(this != NULL)
    {
        addNode(this, ll_len(this), pElement);
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
    Node* nodeAux; // para guardar el nodo solicitado

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        nodeAux = getNode(this, index);

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
int ll_set(LinkedList* this, int index,void* pElement) // get + cambiar elemento
{
    int returnAux = -1;
    Node* auxNode;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        auxNode = getNode(this, index);

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
int ll_remove(LinkedList* this,int index) // get
{
    int returnAux = -1;
    Node* nodeRemoved;
    Node* nodePrev;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        if(index==0)
        {
            nodeRemoved = this->pFirstNode; // guardo el puntero al nodo cero actual

            this->pFirstNode = nodeRemoved->pNextNode; // el pNextNode del nodo cero paasa a ser el firstNode

            free(nodeRemoved);

            // incrementar el size
            this->size--;

            returnAux = 0;
        }
        else
        {
           // hacerle get el nodo a eliminar y al anterior
            nodeRemoved = getNode(this, index);

            nodePrev = getNode(this, index - 1);

            if(nodeRemoved != NULL && nodePrev != NULL)
            {
                // al nodo anterior le seteo en pNextNode el pNextNode que tiene el nodo a ser borrado
                nodePrev->pNextNode = nodeRemoved->pNextNode;

                // hacerle free al nodo a eliminar
                free(nodeRemoved);

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
int ll_clear(LinkedList* this) // borra todos los nodos
{
    int returnAux = -1;

    if(this != NULL)
    {
        // otra opción: while(ll_len(this) != 0)
        while(this->size != 0) // mientras la lista tenga aunque sea un nodo...
        {
            ll_remove(this, 0); // ...llamo a la función para remover el nodo 0
            // remove decrementa el size cada vez que borra un nodo
        }

        returnAux = 0;
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
int ll_deleteLinkedList(LinkedList* this) // clear + free
{
    int returnAux = -1;

    if(this != NULL)
    {
        ll_clear(this); // borra los nodos
        free(this); // libera la linkedlist
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
int ll_indexOf(LinkedList* this, void* pElement) // for + get + if
{
    int returnAux = -1;
    int i;

    if(this != NULL)
    {
        for(i=0;i<ll_len(this);i++)
        {
            // ll_get devuelve el elemento del índice que quiero
            if(ll_get(this, i) == pElement) // pregunto si el elemento que está en el índice i es igual al pElement pasado por parámetro
            {
                returnAux = i; // retorno el índice del elemento
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
int ll_isEmpty(LinkedList* this) // if size (si es 0 està empty)
{
    int returnAux = -1; // retorna 0 cuando la lista es NULL

    if(this != NULL)
    {
        if(ll_len(this) == 0)
        {
            returnAux = 1; // retorna 1 cuando la lista está vacía
        }
        else
        {
            returnAux = 0; // retorna 0 cuando la lista tiene aunque sea un nodo
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
int ll_push(LinkedList* this, int index, void* pElement) // llamar al add
{
    int returnAux = -1;

    if(this != NULL && index >= 0 &&  index <= ll_len(this))
    {
        if(!addNode(this, index, pElement)) // solo entra cuando la addNode devuelve 0
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
void* ll_pop(LinkedList* this,int index) // lamar a get, quedarse con el pElement y dps llamar a remove y retornar el elemento
{
    void* returnAux = NULL; // para retornar el pElement
    Node* nodeAux; // para guardar el nodo que contiene el pElement que quiero retornar

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        // llamo a get
        nodeAux = getNode(this, index);

        if(nodeAux != NULL)
        {
            // me quedo con el elemento y retorno el pElement
            returnAux = nodeAux->pElement;

            // remuevo el nodo
            ll_remove(this, index);
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
int ll_contains(LinkedList* this, void* pElement) // le pregunto al indexOf si el elemento existe
                                                  // indexOf retorna el índice del elemento o -1
{
    int returnAux = -1;
    int indexOf_r; // para guardar el retorno de indexOf

    if(this != NULL)
    {
        indexOf_r = ll_indexOf(this, pElement);

        if(indexOf_r >= 0) // si indexOf retorna un índice es porque el elemento existe
        {
            returnAux = 1; // devuelvo [1] porque la lista this contiene al pElement
        }
        else // indexOf retorna -1 cuando no logra encontrar al elemento
        {
            returnAux = 0; // devuelvo [0] porque la lista this NO contiene al pElement
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
int ll_containsAll(LinkedList* this,LinkedList* this2) // buscar el negativo: el elemento que no esté contenido
// for + get + if (si el elemento no está retorno 0 y chau)
// la 2da lista debe estar contenida en la 1ra
{
    int returnAux = -1;
    int i;
    void* pElementThis2; // para guardar el elemento de la lista this2
    int contains_r; // para guardar el retorno de la función ll_contains

    if(this != NULL && this2 != NULL) // && ll_len(this) >= ll_len(this2))
    {
        returnAux = 1; // asumo que los elementos están en la lista, todo de fiesta

        for(i=0;i<ll_len(this2);i++) // recorro los elementos de this2 para ver si están en this
        {
            // ll_get devuelve el elemento del índice que pido
            pElementThis2 = ll_get(this2, i);

            if(pElementThis2 != NULL)
            {
                // ll_contains devuelve [1] si contiene el elemento, [0] si no lo contiene y [-1] si la lista es NULL
                contains_r = ll_contains(this, pElementThis2);

                if(contains_r == 0) // le pregunto a ll_contains si el pElementThis2 está en la lista de this
                {
                    returnAux = 0; // el elemento no está en la lista
                    break; // no necesito seguir chequeando porque ya encontré un elemento que no está
                }
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
LinkedList* ll_subList(LinkedList* this,int from,int to) // crea una lista nueva desde hasta
// newLinkedList + for (desde hasta) + get + add
{
    LinkedList* cloneArray = NULL;
    int i;
    Node* auxNode;

    if(this != NULL && from >= 0 && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();

        if (cloneArray != NULL)
        {
            for(i=from;i<to;i++)
            {
                auxNode = getNode(this, i);

                if (auxNode != NULL)
                {
                    addNode(cloneArray, i, auxNode->pElement);
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
LinkedList* ll_clone(LinkedList* this) // llamo al sublist y le paso desde 0 hasta el size
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
        cloneArray = ll_subList(this, 0, ll_len(this));
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
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    int i;
    void* pElement1;
    void* pElement2;
    int swap;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
        do
        {
            swap = 0;

            for(i=0;i<ll_len(this)-1;i++)
            {

                pElement1 = ll_get(this, i);
                pElement2 = ll_get(this, i+1);

                if(pElement1 != NULL && pElement2 != NULL)
                {
                    // le pregunto a la función pasada por parámetro si hago el swap
                    if(order == 1 && pFunc(pElement1, pElement2) == 1) // order 1 es ascendente, cuando devuelve 1 hago el swap
                    {
                        ll_set(this, i+1, pElement1);
                        ll_set(this, i, pElement2);
                        swap = 1;
                    }
                    else if (order == 0 && pFunc(pElement1, pElement2) == -1) // order 0 es descentente, en -1 hago el swap
                    {
                            ll_set(this, i+1, pElement1);
                            ll_set(this, i, pElement2);
                            swap = 1;
                    }
                }
            }

        } while(swap);

        returnAux = 0;
    }

    return returnAux;
}

/** \brief Recorre la lista y ejecuta pFunc a cada elemento
 *
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return Devuelve [-1] si la lista es NULL o pFunc es NULL
 *                  o alguna de las llamadas a pFunc retorna error
 *                  [0] si está todo ok
 *
 */
int ll_map(LinkedList* this, int (*pFunc)(void*)) // for + get
{
    int returnAux = -1;
    int i;
    void* pElement;

    if(this != NULL && pFunc != NULL)
    {
        returnAux = 0;

        for(i=0;i<ll_len(this);i++)
        {
            pElement = ll_get(this, i);

            if(pElement != NULL && pFunc(pElement) == -1) // busco que pFunc retorne error
            {
                returnAux = -1*i; // para retornar que estaba todo ok hasta (-1 * i) el ìndice que dio error
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Recorre la lista y con pFunc determina si borra o no el elemento
 *
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return Devuelve [-1] si la lista es NULL o pFunc es NULL
 *                  [0] si está todo ok
 *
 */
int ll_reduce(LinkedList* this, int (*pFunc)(void*))
{
    int returnAux = -1;
    int i;
    void* pElement;

    if(this != NULL && pFunc != NULL)
    {
        for(i=0;i<ll_len(this);i++)
        {
            pElement = ll_get(this, i);

            if(pElement != NULL && pFunc(pElement) == 0)
            {
                if(!ll_remove(this, i))
                {
                    i--;
                }
            }
        }

        returnAux = 0;
    }

    return returnAux;
}

/** \brief Crea una lista nueva con los elementos que determina pFunc
 *
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return Devuelve [NULL] si la lista this es NULL o pFunc es NULL
 *                   o la nueva lista es NULL
 *                  [la nueva lista] si está todo ok
 *
 */
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* returnAux = NULL;
    int i;
    void* pElement;
    LinkedList* filterArray = NULL;

    if(this != NULL && pFunc != NULL)
    {
        filterArray = ll_newLinkedList();

        if(filterArray != NULL)
        {
            for(i=0;i<ll_len(this);i++)
            {
                pElement = ll_get(this, i);

                if(pElement != NULL && pFunc(pElement) == 0)
                {
                    ll_add(filterArray, pElement);
                }
            }

            returnAux = filterArray;
        }
    }

    return returnAux;
}
