#ifndef Controller_H_INCLUDED
#define Controller_H_INCLUDED
#include "LinkedList.h"

int controller_loadClientFromText(char* path,LinkedList* pArrayListClient);
int controller_loadSaleFromText(char* path,LinkedList* pArrayListSale);

int controller_addClient(LinkedList* pArrayListClient);
int controller_addSale(LinkedList* pArrayListSale, LinkedList* pArrayListClient);

int controller_modifyClient(LinkedList* pArrayListClient);

int controller_removeClient(LinkedList* pArrayListClient);
int controller_removeSale(LinkedList* pArrayListSale);


int controller_listClient(LinkedList* pArrayListClient);
int controller_listSale(LinkedList* pArrayListSale);


int controller_sortClient(LinkedList* pArrayListClient);
int controller_sortSale(LinkedList* pArrayListSale);


int controller_saveAsText(char* path, LinkedList* pArrayListEntregas);
#endif
