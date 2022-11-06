#include "define.h"


#ifndef ATRIBUTO_SIMPLE_H
#define ATRIBUTO_SIMPLE_H

typedef struct nodo_atributo_simple * atributo_simple;

atributo_simple atributoSimpleNull();

void imprimirAtributo(atributo_simple & as, int id);

TipoRet InsertInto_AtributoSimple(atributo_simple & as, char *valorAtributo, int id);

void InsertInto(atributo_simple & as, char *valorAtributo, int id);

#endif