#include "define.h"


#ifndef ATRIBUTO_SIMPLE_H
#define ATRIBUTO_SIMPLE_H

typedef struct nodo_atributo_simple * atributo_simple;

atributo_simple atributoSimpleNull();

void imprimirAtributo(atributo_simple & as, int id);

void insertInto(atributo_simple & as, char *valorAtributo, int id, bool primerAtributo);

void imprimirAll(atributo_simple as);

TipoRet InsertInto_AtributoSimple(atributo_simple & as, char *valorAtributo, int id, bool primerAtributo, bool pk);

bool pkduplicada(atributo_simple as, char *valorAtributo);
#endif