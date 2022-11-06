#include "atributo_simple.h"
#include <string.h>
#include <iostream>

using namespace std;

struct nodo_atributo_simple{
	char	*valor;
	int		valor_secundario;
	int		identificador;
	atributo_simple sig;
};

atributo_simple atributoSimpleNull(){
	return new(nodo_atributo_simple);
}

void imprimirAtributo(atributo_simple & as, int id){
	cout << as->valor << endl ;
	cout << as->identificador << endl;
}

TipoRet InsertInto_AtributoSimple(atributo_simple & as, char *valorAtributo, int id){
	as->valor = valorAtributo;
	as->identificador = id;
	as->sig = NULL;
return OK;
}

void InsertInto(atributo_simple & as, char *valorAtributo, int id){

}