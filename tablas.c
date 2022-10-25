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

void imprimirTablas(tablas ts){
	if (ts == NULL){
		cout << " - No hay tablas\n";
	}else{
		cout << nombreTabla(ts->t);
	}
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

tablas & getColumnaSig_Tablas(tablas ts){
	ts->t = getColumnaSig_Tabla(ts->t);
	return ts;
}

bool compararNombreColumnaSingular_Tablas(tablas ts, char * nombreC){
	return compararNombreColumnaSingular_Tabla(ts->t, nombreC);
}




TipoRet crearColumSingular_Columnas(tablas & ts, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol){
	if (isTablasEmpty_Tablas(ts)){
		cout << "Imposible Crear Columna. No existe tabla\n";
		return ERROR;
	}else{



		if(isColumnasEmpty_Tablas(ts)){
			crearColumnas_Tablas(ts); // Creamos un new(nodo_tablas)
			crearColumSingular_Tablas(ts, NombreCol, tipoCol, calificadorCol);

			// cout << getColumnaSingularNombre_Tablas(ts);
			return OK;
		}else{
			bool aux = true;
			do{
				if(compararNombreColumnaSingular_Tablas(ts, NombreCol)){
					cout << "Imposible Crear Columna. Ya existe una columna con el nombre\n";
					aux = false;
					return ERROR;
				}else{
					if(!isColumnasEmpty_Tablas(getColumnaSig_Tablas(ts))){
					// if(true){

						//si col siguiente no es null, seguimos comparando
						cout << "hay mas de una columna";
						// ts = getColumnaSig_Tablas(ts);
						aux = false;
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







