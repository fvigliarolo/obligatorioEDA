#include "tablas.h"
#include <stdio.h>
#include <iostream>
#include <stdbool.h> // para bool


using namespace std;

struct nodo_tablas{
	tabla t;
};

tablas crearTablas(){
	return NULL;
}

char * imprimirTablas(tablas ts){
	// if (ts == NULL){
		// cout << " - No hay tablas\n";
	// }else{
		return nombreTabla(ts->t);
	// }
}

bool isTablasEmpty_Tablas(tablas & ts){
	return (ts == NULL);
}
bool isColumnasEmpty_Tablas(tablas & ts){
	return isColumnasEmpty_Tabla(ts->t);

}

tablas crearColumnas_Tablas(tablas & ts){
	ts->t = crearColumnas_Tabla(ts->t);
	return ts;
}

TipoRet crearTabla_Tablas(tablas & ts, char * nombreTabla){
	if (isTablasEmpty_Tablas(ts)){
		ts = new(nodo_tablas);
		ts->t = crearTabla(nombreTabla);
		return OK;
	}else{
		cout << "Imposible Crear Tabla, ya hay una creada y el sistema soporta solo una\n";
		return ERROR;
	}
}

char * getColumnaSingularNombre_Tablas(tablas & ts){
	return getColumnaSingularNombre_Tabla(ts->t);
}

char * getColumnaSingularTipoDato_Tablas(tablas ts){
	return getColumnaSingularTipoDato_Tabla(ts->t);
}

char * getColumnaSingularCalificador_Tablas(tablas ts){
	return getColumnaSingularCalificador_Tabla(ts->t);
}


void crearColumSingular_Tablas(tablas & ts, char *NombreCol, char *tipoCol, char *calificadorCol){
	crearColumSingular_Tabla(ts->t, NombreCol, tipoCol, calificadorCol);
}

tablas getColumnaSig_Tablas(tablas ts){
	// cout << "ts: " << ts << "\n";
	ts->t = getColumnaSig_Tabla(ts->t);
	// cout << "ts: " << ts << "\n";
	return ts;
}

bool compararNombreColumnaSingular_Tablas(tablas ts, char * nombreC){
	return compararNombreColumnaSingular_Tabla(ts->t, nombreC);
}

bool isColumnasSingularEmpty_Tablas(tablas ts){
	return isColumnasSingularEmpty_Tabla(ts->t);
}


TipoRet crearColumSingular_Columnas(tablas & ts, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol){
	if (isTablasEmpty_Tablas(ts)){
		cout << "Imposible Crear Columna. No existe tabla\n";
		return ERROR;
	}else{

		if(isColumnasEmpty_Tablas(ts)){
			crearColumnas_Tablas(ts); // Creamos un new(nodo_tablas)
			crearColumSingular_Tablas(ts, NombreCol, tipoCol, calificadorCol);

			return OK;
		}else{
			bool aux = true;
			do{
				if(compararNombreColumnaSingular_Tablas(ts, NombreCol)){
					cout << "Imposible Crear Columna. Ya existe una columna con el nombre\n";
					aux = false;
					return ERROR;
				}else{
					if(isColumnasSingularEmpty_Tablas(getColumnaSig_Tablas(ts))){
						//si col siguiente no es null, seguimos comparando
						ts = getColumnaSig_Tablas(ts);
						// cout << getColumnaSig_Tablas(ts);
						
					}else{
						//si el siguiente es null, ya se compararon todas las colums y no hay repetido.
						crearColumSingular_Tablas(ts, nombreTabla, tipoCol, calificadorCol);
						aux = false;
						return OK;
					}
				}
			}while(aux);
		}
	}
}



// TipoRet InsertInto_Tablas(tablas & ts, char *nombreTabla, char *columnasTupla, char *valoresTupla){
// 	// falta verificar PRIMARY KEY, NOT_EMPTY 

// 	if (isTablasEmpty_Tablas(ts)){
// 		cout << "No se puede insertar. No se ha encontrado la tabla\n";
// 		return ERROR;
// 	}else if(imprimirTablas(ts) != nombreTabla){
// 		cout << "No se puede insertar. No se ha encontrado la tabla\n";
// 		return ERROR;
// 	}else{
// 		bool errores = false;
// 		bool aux = true;
		
// 		char * param1, * param2;
// 		param1 = strtok (columnasTupla, ":");

// 		while(param1 != NULL){

// 			do{
// 				if(getColumnaSingularNombre_Tabla(ts) == param1 ){
// 					// existe la columna singular == param1. 
// 					aux = false;
// 				}else{
// 					if(){
// 						//siguiente es null. No existe la columna sigular
// 						errores = true;
// 						aux = false;
// 					}else{
// 						// si el siguiente es distinto de null, movemos a la siguiente columna_singular

// 					}
// 				}
				
// 			}while(aux);
			
// 			param1 = strtok (NULL, ":");
// 			// obtenemos el siguiente parametro.
// 		}

// 		if (errores){
// 			cout << "verifique las columnas";
// 			return ERROR;
// 		}else{
// 			//insertar bajo la columna_singular correspondiente
// 			param1 = strtok (columnasTupla, ":");
// 			while (parm1 != NULL){
// 				insertar_tabla(parm1);
// 				param1 = strtok (NULL, ":");

// 			}
// 			return OK;
// 		}

// 	}
// }


TipoRet dropTable_Tablas(tablas & TS, char *nombreTabla){
 	return dropTable_Tabla(TS->t, nombreTabla);
}


 TipoRet eliminarTabla_Tablas(tablas & TS, char *nombreTabla){
	
 	// if(isTablasEmpty_Tablas(TS)){
 	// 	//si la tabla esta vacia
	// 	cout <<"no se puede eliminar. no existe esta tabla   \n";
 	// 	return ERROR;
 	// }else{
 	// 	cout << "se eliminara la tabla: " << imprimirTablas(TS);
 	// 	delete TS ;
 	// 	cout << "se elimino la tabla.";
	// 	cout << TS ;
		
 	// }
// si llega aca se elimino, voy a poner un comentario solo para futuro debug
	
 	return dropTable_Tablas(TS,nombreTabla);

 }