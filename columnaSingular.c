#include "columnaSingular.h"
#include <string.h>
#include <iostream>
#include <stdbool.h> // para bool
#include <ctype.h> // isdigit()



using namespace std;

struct nodo_columnaSingular{
	char * nombre;
	char * tipo_dato; 
	char * calificador;
	atributo_simple atr_simple;
	columnaSingular sig;	
	columnaSingular anterior;	
};

columnaSingular columnaSingularNull(){
	return new(nodo_columnaSingular); //aca no tendri que ser return null?

}

void imprimircs(columnaSingular cs){
	cout << "cs actual " << cs << endl ;
}

columnaSingular columnaSingularNULL(){
	return NULL;	
}

bool isColumnaSingularEmpty(columnaSingular cs){
	return (cs == NULL);
}


bool compararNombreColumnaSingular(columnaSingular cs, char * nombreC){
	if (strcasecmp(nombreC, cs->nombre) == 0){
		return true;
	}else{
		return false;
	}
}


void imprimirColumnaSingular(columnaSingular & cs){
			cout << "Columna:	" << cs->nombre 	<< endl ;
			cout << "Tipo:		" << cs->tipo_dato  	<< endl ;
			cout << "Calificador:	" << cs->calificador 	<< endl ;
}


// AddColumn()
void crearColumSingular(columnaSingular cs, char *NombreCol, char *tipoCol, char *calificadorCol, bool primerCol){
	
	columnaSingular auxSig 				= NULL;
	// columnaSingular auxSig 				= columnaSingularNULL();

	if (primerCol){
		columnaSingular auxAnterior 	= columnaSingularNULL();
	 	cs->anterior 					= auxAnterior;
		cs->sig 						= auxSig;
		cs->nombre 						= new char[MAX_NOMBRE];
		cs->tipo_dato 					= new char[MAX_NOMBRE];
		cs->calificador 				= new char[MAX_NOMBRE];
		// cs->calificador 				= calificadorCol;
		strcpy(cs->nombre, NombreCol);
		strcpy(cs->tipo_dato, tipoCol);
		strcpy(cs->calificador, calificadorCol);

	}else{
			columnaSingular auxUltimaCS  			= columnaSingularNull();
			auxUltimaCS->nombre 					= new char[MAX_NOMBRE];
			auxUltimaCS->tipo_dato 					= new char[MAX_NOMBRE];
			auxUltimaCS->calificador 				= new char[MAX_NOMBRE];
			// auxUltimaCS->calificador 				= calificadorCol;
			strcpy(auxUltimaCS->nombre, NombreCol);
			strcpy(auxUltimaCS->tipo_dato, tipoCol);
			strcpy(auxUltimaCS->calificador, calificadorCol);
			
		bool aux = true;
		while (aux){
			if (isColumnaSingularEmpty(cs->sig)){
				cs->sig = auxUltimaCS;
				auxUltimaCS->anterior = cs;
				auxUltimaCS->sig = auxSig;
				aux = false;
			}else{
				cs = cs->sig;
			}
		}
	}
}
TipoRet crearColumnaSingular_ColumnasSingular(columnaSingular cs, char *NombreCol, char *tipoCol, char *calificadorCol, bool primerCol){

		
		bool aux = true;
		while(aux){
			if (primerCol){
				aux = false;
				if (strcasecmp(calificadorCol, "PRIMARY_KEY") != 0){
						cout << "La primer columna debe ser clave primaria" << endl ;
						columnaSingular elim = cs;
						delete elim;
						return ERROR;
				}else{
					crearColumSingular(cs, NombreCol, tipoCol, calificadorCol, primerCol);
					return OK;
				}
			}else{
				if (isColumnaSingularEmpty(cs->sig)){
					if(strcasecmp(NombreCol, cs->nombre) == 0){
						aux = false;
						cout << "Ya existe columna con el mismo nombre";
						return ERROR;
					}else{
						aux = false;
						crearColumSingular(cs, NombreCol, tipoCol, calificadorCol, primerCol);
						return OK;
					}
				}else{
					if(strcasecmp(NombreCol, cs->nombre) == 0){
						aux = false;
						cout << "Ya existe columna con el mismo nombre";
						return ERROR;
					}else{
						cs = cs->sig;
					}
				}
		}
	}
}

// PrintMetaData()
TipoRet estructuraTablas_Columnasingular(columnaSingular & cs, char *nombreTabla){
	bool aux = true;
	while(aux){
		cout << "========================================" << endl ;
		if (isColumnaSingularEmpty(cs->sig)){
			aux = false;
			imprimirColumnaSingular(cs);
		}else{
			imprimirColumnaSingular(cs);
			cs = cs->sig;
		}
	}
	cout << "========================================" << endl ;
	return OK;
}

bool existeColumnaSingular(columnaSingular cs, char *NombreCol){
	bool aux = true;

	while (aux){
		if (cs->sig == NULL){
			aux = false;
			if(strcasecmp (cs->nombre, NombreCol) == 0){
				return true;
			}else{
				return false;
			}
		}else{
			if(strcasecmp (cs->nombre, NombreCol) == 0){
				aux = false;
				return true;
			}else{
				cs = cs->sig;
			}
		}
	}
}

columnaSingular primerPosicion(columnaSingular cs){
	bool aux = true;
	while (aux){
		if (cs->anterior != NULL){
			cs = cs->anterior;
		}else{
			aux = false;
			return cs;
		}
	}
}

bool verificaTipoDato(columnaSingular cs, char *dato, char *columna){
	cs = primerPosicion(cs);

	bool aux = true;
	while(aux){
		if(strcasecmp(cs->nombre, columna) == 0){

			if(strcasecmp(cs->tipo_dato, "integer") == 0){
				return isdigit(dato[0]);
			}else{
				return true;
			}

		}else{
			cs = cs->sig;
		}
	}

}

columnaSingular igualarCSaColumna(columnaSingular cs, char *columnaNombre){
	cs = primerPosicion(cs);
	bool aux = true;
	while (aux){
		if(strcasecmp(cs->nombre, columnaNombre) == 0){
			aux = false;
			return cs;
		}else{
			cs = cs->sig;
		}
	}
}

TipoRet InsertInto_ColumnasSingular(columnaSingular & cs, char *columnasTupla, char *valoresTupla, int lenghtColumnasTupla, int lenghtValoresTupla){
	int errores = 0;
	
	char * param1;
	param1 = strtok(columnasTupla, ":");
	char * arrayColumnasTupla[lenghtColumnasTupla];
	int i = 0;
	while (param1 != NULL){
		arrayColumnasTupla[i] = param1;
		// cout << arrayColumnasTupla[i] << endl ;
		param1 = strtok(NULL, ":");
		i += 1;
	}

	char * param2;
	param2 = strtok(valoresTupla, ":");
	char * arrayValoresTupla[lenghtValoresTupla];
	int j = 0;

	while (param2 != NULL){
		arrayValoresTupla[j] = param2;
		// cout << arrayValoresTupla[j] << endl ;
		param2 = strtok(NULL, ":");
		j += 1;
	}

	// cs = primerPosicion(cs);
	bool aux2 = true;
	while (aux2){
		if (cs->anterior != NULL){
			cs = cs->anterior;
		}else{
			aux2 = false;
		}
	}


	if (strcasecmp(cs->nombre, arrayColumnasTupla[0]) == 0){
		// cout << "La primer columna es PRIMARY_KEY. Se puede hacer el insert." << endl ;
		for(int p = 0; p<lenghtColumnasTupla; p++){
			if(!verificaTipoDato(cs, arrayValoresTupla[p], arrayColumnasTupla[p])){
				errores += 1;
				cout << arrayValoresTupla[i] << " No respeta el tipo de dato" << endl ;
			}
		}
	}else{
		cout <<  "El primer atributo del insert debe ser la PRIMARY_KEY." << endl ;
		errores += 1;
	}

	if (errores == 0){
		for (int l = 0; l<lenghtColumnasTupla; l++){
			cs = igualarCSaColumna(cs, arrayColumnasTupla[l]);
			if(cs->atr_simple == NULL){
				cs->atr_simple = atributoSimpleNull();
				if (InsertInto_AtributoSimple(cs->atr_simple, arrayValoresTupla[l], l, true) == ERROR){ errores +=1; }
			}else{
				if (InsertInto_AtributoSimple(cs->atr_simple, arrayValoresTupla[l], l, false) == ERROR){ errores += 1; }
					// implementar una solucion para eliminar todas las tuplas que se ingresaron
				imprimirAtributo(cs->atr_simple,l);
			}
		}
		

		if(errores == 0){
			return OK;
		}else{
			return ERROR;
		}
	}else{
		return ERROR;
	}

	bool iterar = true;

	// while(iterar){
	// 	if (errores == 0){

	// 	}else{
	// 		iterar = false;
	// 		return ERROR;
	// 	}
	// }




}

void eliminarC(columnaSingular & cs, char *NombreColumnaSingular){
	
				columnaSingular elim = cs;//pa borrar
				columnaSingular ant = cs->anterior; // apunta al nodo anterior
								ant->sig = cs->sig;
								delete elim;//elimino
								cs = primerPosicion(cs);
}

TipoRet eliminarColumnaSing(columnaSingular & cs, char *NombreColumnaSingular){
	bool auxi = true;
	cs = primerPosicion(cs);
	while(auxi){ 
		if(cs->sig != NULL){
			if(strcasecmp(cs->nombre, NombreColumnaSingular) == 0){
				if(strcasecmp(cs->calificador, "PRIMARY_KEY")!= 0){
					columnaSingular elim;
					auxi = false;

					cs->anterior->sig	= cs->sig;
					cs->sig->anterior	= cs->anterior;
					elim 				= cs;
					delete elim;
					cs 					= cs->anterior;
			
					return OK;
				}else{
					auxi = false;
					cout << "No se puede eliminar PRIMARY_KEY mientras existan otras columnas" << endl ;
					return ERROR;
				}
			}else{
				cs = cs->sig;
			}		
			
		}else{
			if(strcasecmp(cs->nombre, NombreColumnaSingular) == 0){
				columnaSingular elim;
				auxi = false;
				if(cs->anterior != NULL){
					cs->anterior->sig	= NULL;
					elim				= cs;
					cs 					= cs->anterior;
					delete elim;
					return OK;
				}else{
					cout << "Hay que eliminar la PRIMARY_KEY" << endl ;
					cs->anterior 	= NULL;
					cs->sig 		= NULL;
					elim 			= cs;
					delete elim;
					cs 				= NULL;
					cout << cs << endl ;
					return OK;
				}
			}else{
				auxi = false;
				cout << "No existe la columna de nombre: " << NombreColumnaSingular << endl ;
				return ERROR;
			}
		}
	}
}