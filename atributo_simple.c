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


void imprimirAll(atributo_simple as){
	while(as != NULL){
		if(strcasecmp(as->valor, "__EMPTY") == 0){
			cout << "valor: " << as->valor_secundario << endl ;
		}else{
			cout << "valor: " << as->valor << endl ;
		}
		cout << "identificador: " << as->identificador << endl;
		// cout << "valor secundario: " << as->valor_secundario << endl;
		cout << "===========================================" << endl ;
		as = as->sig;
	}

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
	as->identificador 				= id;
	as->sig 						= asSiguiente;
	
}
TipoRet InsertInto_AtributoSimple(atributo_simple & as, char *valorAtributo, int id, bool primerAtributo){
	if (primerAtributo){
		insertInto(as, valorAtributo, id, primerAtributo);
	}else{
		bool aux = true;
		while(aux){
			if (as->sig != NULL){
				as = as->sig;
			}else{
				aux = false;
			}
		}
		atributo_simple nuevo = atributoSimpleNull();
		as->sig = nuevo;
		insertInto(nuevo, valorAtributo, id, primerAtributo);
	}
	imprimirAll(as);


return OK;
}