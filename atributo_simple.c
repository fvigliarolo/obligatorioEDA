#include "atributo_simple.h"
#include <string.h>
#include <iostream>

using namespace std;

struct nodo_atributo_simple{
	char	*valor;
	int		*valor_secundario;
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

TipoRet InsertInto_AtributoSimple(atributo_simple & as, char *valorAtributo, int id, bool primerAtributo){
	if (primerAtributo){
		insertInto(as, valorAtributo, id, primerAtributo);
	}
		while(as->sig != NULL){
		as = as->sig;
	}


return OK;
}

void insertInto(atributo_simple & as, char *valorAtributo, int id, bool primerAtributo){
	atributo_simple asSiguiente = NULL;
	int valorInt;


	if(isdigit(valorAtributo[0])){
		valorInt = atoi(valorAtributo);
		as->valor_secundario = &valorInt;
		as->valor = "__EMPTY";
	}else{
		valorInt = 99;

		as->valor_secundario = &valorInt; //no pongo 0 para diferenciar del valor NULL.
		as->valor = valorAtributo;
	}
		
	if (primerAtributo){
		as->sig 						= NULL;
		as->identificador 				= id;
		as->sig 						= asSiguiente;
	}
	// else{
	// 	bool aux = true;
	// 	while(aux){
	// 		if ()
	// 	}
	// }
}