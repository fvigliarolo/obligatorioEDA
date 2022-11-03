#include "columnaSingular.h"
#include <string.h>
#include <iostream>
#include <stdbool.h> // para bool



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


void imprimirColumnaSingular(columnaSingular cs){
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
				crearColumSingular(cs, NombreCol, tipoCol, calificadorCol, primerCol);
				return OK;
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
TipoRet estructuraTablas_Columnasingular(columnaSingular cs, char *nombreTabla){

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

TipoRet InsertInto_ColumnasSingular(columnaSingular & cs, char *columnasTupla, char *valoresTupla, int lenghtColumnasTupla, int lenghtValoresTupla){
	char * param1;
	param1 = strtok(columnasTupla, ":");
	char * arrayColumnasTupla[lenghtColumnasTupla];
	int i = 0;
	while (param1 != NULL){
		arrayColumnasTupla[i] = param1;
		cout << arrayColumnasTupla[i] << endl ;
		param1 = strtok(NULL, ":");
		i += 1;
	}

	char * param2;
	param2 = strtok(valoresTupla, ":");
	char * arrayValoresTupla[lenghtValoresTupla];
	int j = 0;

	while (param2 != NULL){
	arrayValoresTupla[j] = param2;
	cout << arrayValoresTupla[j] << endl ;
	param2 = strtok(NULL, ":");
	j += 1;
	}

}




























	//  	// verificamos que no exista otra cs con mismo nombre
	
	// 		bool aux = true;
	// 		do{
	// 			if(compararNombreColumnaSingular_Tablas(ts, NombreCol)){
	// 				cout << "Imposible Crear Columna. Ya existe una columna con el nombre\n";
	// 				aux = false;
	// 				return ERROR;
	// 			}else{
	// 				if(isColumnasSingularEmpty_Tablas(getColumnaSig_Tablas(ts))){
	// 					//si col siguiente no es null, seguimos comparando
	// 					ts = getColumnaSig_Tabl	as(ts);
	// 					// cout << getColumnaSig_Tablas(ts);
						
	// 				}else{
	// 					//si el siguiente es null, ya se compararon todas las colums y no hay repetido.
	// 					crearColumSingular_Tablas(ts, nombreTabla, tipoCol, calificadorCol);
	// 					aux = false;
	// 					return OK;
	// 				}
	// 			}
	// 		}while(aux);
	// 	}

		// return OK;