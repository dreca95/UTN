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
    LinkedList* this= NULL;


    this= (LinkedList*) malloc(sizeof(LinkedList));

    if(this!=NULL)
    {

        this->size=0;
        this->pFirstNode=NULL;
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

    if(this!=NULL)
    {

        returnAux= this->size;

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
    int tam;
    Node* nodo=NULL;
    int i=0;

    if(this!=NULL)
    {

        tam= ll_len(this);

        if(nodeIndex>=0&&nodeIndex<tam)
        {


            if(this->pFirstNode!=NULL)
            {

                nodo=this-> pFirstNode;

                while (nodo->pNextNode!=NULL)
                {

                    if (i==nodeIndex)
                    {

                        break;
                    }

                    nodo = nodo->pNextNode;
                    i++;
                }

            }
        }


    }

    return nodo;
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
    int tam;
    int returnAux = -1;
    Node* nuevoNodo=NULL;
    Node* nodoAnt=NULL;

    if(this!=NULL)
    {

        tam= ll_len(this);

        if( nodeIndex>=0 && nodeIndex<=tam)
        {


            nuevoNodo=(Node*) malloc(sizeof(Node));
            if(nuevoNodo!=NULL)
            {

                nuevoNodo->pElement=pElement;
                if(nodeIndex==0)
                {
                    nuevoNodo->pNextNode=this->pFirstNode;
                    this->pFirstNode = nuevoNodo;
                    this->size++;
                    returnAux=0;
                }
                else if(nodeIndex>0)
                {

                    nodoAnt=getNode(this, nodeIndex-1);

                    if(nodoAnt!=NULL)
                    {

                        nuevoNodo->pNextNode= nodoAnt->pNextNode;
                        nodoAnt->pNextNode=nuevoNodo;
                        this->size++;
                        returnAux=0;

                    }
                }

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
    int tam;

    if( this !=NULL)
    {
        tam= ll_len(this);


        if (!addNode(this,tam, pElement))
        {
            returnAux=0;
        }
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
    int tam;
    Node* nodo=NULL;

    if(this!=NULL)
    {

        tam = ll_len(this);

        if(index>=0&& index<tam)
        {

            nodo= getNode(this, index);

            if(nodo!=NULL)
            {
                returnAux= nodo->pElement;
            }
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
    int tam;
    Node* nodo=NULL;

    if(this!=NULL)
    {
        tam=ll_len(this);


        if( index >= 0 && index < tam)
        {

            nodo= getNode(this,index);

            if(nodo!=NULL)
            {
                nodo->pElement=pElement;

                returnAux=0;
            }
        }

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
    int tam;
    Node* nodo=NULL;
    Node* siguiente=NULL;
    Node* anterior=NULL;

    if(this!=NULL)
    {

        tam= ll_len(this);

        if(index>=0&&index<tam)
        {
            nodo=getNode(this,index);
            siguiente=getNode(this,index+1);
            anterior=getNode(this, index-1);


            if(index==0&&siguiente!=NULL&&nodo!=NULL)
            {
                this->pFirstNode = nodo->pNextNode;

            }
            else if( index>0 && siguiente!=NULL&&nodo!=NULL)
            {
                anterior->pNextNode=nodo->pNextNode;

            }
            else if(nodo!=NULL)
            {

                this->pFirstNode =NULL;

            }

            free(nodo);
            this->size--;
            returnAux=0;
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
    int tam;

    if(this!=NULL)
    {

        tam= ll_len(this);

        for(int i=0; i<tam; i++)
        {

            if(!ll_remove(this,i))
            {
                returnAux=0;
            }
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

    if(this!=NULL)
    {

        if(!ll_clear(this))
        {
            returnAux=0;
        }

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
    int tam;


    if(this!=NULL)
    {
        tam= ll_len(this);

        for(int i=0; i<tam; i++)
        {
            if(ll_get(this,i) == pElement)
            {

                returnAux=i;
                break;
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
    int tam;

    if(this!=NULL)
    {

        tam= ll_len(this);

        if(tam>0)
        {

            returnAux=0;

        }
        else if (tam==0)
        {

            returnAux=1;

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
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int tam;

    if(this!=NULL)
    {

        tam=ll_len(this);

        if(index>=0&&index<=tam)
        {


            if(!addNode(this, index, pElement))
            {

                returnAux=0;
            }


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
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int tam;
    void* pElement;

    if(this!=NULL)
    {
        tam=ll_len(this);
        pElement= ll_get(this, index);

        if(index < tam&& index >= 0)
        {
            if(!ll_remove(this, index))
            {
                returnAux = pElement;
            }
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
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int tam;

    if(this!=NULL)
    {
        tam= ll_len(this);
        returnAux=0;

        for(int i=0; i<tam; i++)
        {

            if (ll_get(this,i) == pElement)
            {

                returnAux= 1;
                break;
            }


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
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;;
    int tamL2;
    Node* nodo=NULL;


    if(this!=NULL&&this2!=NULL)
    {
        tamL2=ll_len(this2);

        returnAux =1;

        for(int i=0; i <tamL2; i++)
        {

            nodo=ll_get(this2, i);

            if (nodo!=NULL)
            {
                if(!ll_contains(this,nodo))
                {

                    returnAux=0;
                    break;
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
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    cloneArray = ll_newLinkedList();
    int tam;
    int flag=0;
    void* pElement;

    if(this != NULL)
    {
        tam = ll_len(this);

        if(cloneArray!=NULL && to >=0 && from >=0 &&to <= tam && to >= from )
        {
            for(int i = from; i < to; i++)
            {
                pElement = ll_get(this, i);
                if(!ll_add(cloneArray, pElement))
                {
                    continue;
                }
                else
                {
                    flag=1;
                    break;
                }
            }
        }

        else
        {
            flag=1;
        }

    }
    else
    {
        flag=1;
    }


    if(flag)
    {

        cloneArray = NULL;
        free(cloneArray);
    }


    return cloneArray;
}


/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    cloneArray = ll_newLinkedList();
    int tam;
    int flag=0;
    void* pElement;

    if(this != NULL && cloneArray!=NULL)
    {
        tam = ll_len(this);

        for(int i = 0; i < tam; i++)
        {
            pElement = ll_get(this, i);
            if(!ll_add(cloneArray, pElement))
            {
                continue;
            }
            else
            {
                flag=1;
                break;
            }
        }
    }
    else
    {
        flag=1;
    }

    if(flag)
    {

        cloneArray = NULL;
        free(cloneArray);

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
    int returnAux =-1;
    int tam;
    void* aux=NULL;
    void* aux2=NULL;

    if(this!=NULL&&pFunc!=NULL&&(order==0||order==1))
    {


        tam= ll_len(this);


        for(int i= 0; i<tam-1; i++)
        {


            for(int j= i+1; j<tam; j++)

            {

                aux=ll_get(this,i);
                aux2=ll_get(this,j);

                if(aux!=NULL&&aux2!=NULL)
                {

                    if((pFunc(aux,aux2)==1&&order)|| (pFunc(aux,aux2)==-1&&!order))
                    {
                        ll_set(this,i,aux2);
                        ll_set(this,j,aux);

                        returnAux=0;


                    }

                }

            }
        }
    }

    return returnAux;

}

