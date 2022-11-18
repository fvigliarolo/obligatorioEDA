#include "atributo_simple.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>

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
	int contador;
	contador = 1;
	atributo_simple auxiliar = as;
	bool aux = true;
	while (aux){
		if(contador == id){
			getValor(auxiliar);
			aux = false;
		}else{
			contador += 1;
			auxiliar = auxiliar->sig;
		}
	}

}

void getValor(atributo_simple as){
	if(strcasecmp(as->valor, "__EMPTY") == 0){
		cout << as->valor_secundario << "		" ;
	}else{
		cout << as->valor << "		" ;
	}
}


void imprimirAll(atributo_simple as){
	while(as != NULL){
		if(strcasecmp(as->valor, "__EMPTY") == 0){
			cout << "		" << as->valor_secundario ;
		}else{
			cout << "		" << as->valor ;
		}
		cout << "		" << "      " << "		" << as->identificador << endl;
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
		as->valor_secundario = valorInt;
		as->valor = "__EMPTY";
	}else{
		valorInt = -2147483648;
		as->valor_secundario = valorInt; //no pongo 0 para diferenciar del valor NULL.
		as->valor = valorAtributo;
	}
	as->identificador 				= id;
	as->sig 						= asSiguiente;
	
}

bool pkduplicada(atributo_simple as, char *valorAtributo){
	bool aux = true;
	while(aux){
		if(as != NULL){
			if((as->valor == valorAtributo) && (strcasecmp(as->valor, "__EMPTY") != 0)){
				return true;
			}else{
				if((atoi(valorAtributo) == as->valor_secundario) && as->valor_secundario != -2147483648){
					return true;
				}else{
					as = as->sig;
				}
			}
		}else{
			aux = false;
			return false;
		}
	}
}

TipoRet InsertInto_AtributoSimple(atributo_simple & as, char *valorAtributo, int id, bool primerAtributo, bool pk){
	if (primerAtributo){
		insertInto(as, valorAtributo, id, primerAtributo);
		return OK;
	}else{
		if(pk){
			if(pkduplicada(as, valorAtributo)){
				cout << "Ya existe una tupla con la PRIMARY_KEY: " << valorAtributo << endl ;
				return ERROR;
			}else{
				bool aux = true;
				atributo_simple auxiliar = atributoSimpleNull();
				auxiliar = as;
				while(aux){
					if (auxiliar->sig != NULL){
						auxiliar = auxiliar->sig;
					}else{
						aux = false;
					}
				}
				atributo_simple nuevo = atributoSimpleNull();
				insertInto(nuevo, valorAtributo, id, primerAtributo);
				auxiliar->sig = nuevo;
				return OK;
			}
		}else{
			bool auxi = true;
			atributo_simple auxiliar = atributoSimpleNull();
			auxiliar = as;
			while(auxi){
				if (auxiliar->sig != NULL){
					auxiliar = auxiliar->sig;
				}else{
					auxi = false;
				}
			}
			atributo_simple nuevo = atributoSimpleNull();
			insertInto(nuevo, valorAtributo, id, primerAtributo);
			auxiliar->sig = nuevo;
			return OK;
		}
	}
}

int getLenght(atributo_simple as){
	if(as == NULL){
		return 0;
	}else{
		atributo_simple auxiliar;
		auxiliar = as;
		int contador;
		contador = 0;
		bool aux = true;
		while(aux){
			if(auxiliar == NULL){
				aux = false;
				return contador;
			}else{
				contador += 1;
				auxiliar = auxiliar->sig;
			}
		}
	}
}




