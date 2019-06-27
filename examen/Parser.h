#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Entrega.h"
#include "LinkedList.h"

int parser_parseEntrega(char* fileName, LinkedList* listaEntregas);


#endif // PARSER_H_INCLUDED
