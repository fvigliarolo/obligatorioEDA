// #include "tablas.h"
// #include "tabla.h"
// #include <stdio.h>
// #include <iostream>

// using namespace std;

// struct nodo_tablas{
// 	tabla t;
// };

// tablas crearTablas(){
// 	return NULL;
// }

// TipoRet crearTabla_Tablas(tablas & ts, char * nombreTabla){
// 	if (ts == NULL){
// 		ts = new(nodo_tablas);
// 		ts->t = crearTabla(nombreTabla);
// 		return OK;
// 	}else{
// 		cout << "Imposible Crear Tabla, ya hay una creada y el sistema soporta solo una\n";
// 		return ERROR;
// 	}
// }

// void imprimirTablas(tablas ts){
// 	if (ts == NULL){
// 		cout << " - No hay tablas\n";
// 	}else{
// 		cout << nombreTabla(ts->t);
// 	}
// }

// tabla getT(tablas ts){
// 	return ts->t;
// }

#include "tablas.h"
#include <stdio.h>
#include <iostream>
// #include <stdbool.h> // para bool


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

// tabla crearColumSingular_Tablas(char *NombreCol, char *tipoCol, char *calificadorCol){
// 	return crearColumSingular_Tabla(NombreCol, tipoCol, calificadorCol);
// }

void crearColumSingular_Tablas(tablas & ts, char *NombreCol, char *tipoCol, char *calificadorCol){
	crearColumSingular_Tabla(ts->t, NombreCol, tipoCol, calificadorCol);
}


TipoRet crearColumSingular_Columnas(tablas & ts, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol){
	if (isTablasEmpty_Tablas(ts)){
		return ERROR;
	}else{
		if(isColumnasEmpty_Tablas(ts)){
			crearColumnas_Tablas(ts);
			crearColumSingular_Tablas(ts, nombreTabla, tipoCol, calificadorCol);
			cout << "NO IMPLEMENTADA";
			return ERROR;
		}else{
			crearColumSingular_Tablas(ts, nombreTabla, tipoCol, calificadorCol);
			return OK;
		}
	}
}




// TipoRet crearColumSingular_Columnas(tablas & ts, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol){
// 	if (ts == NULL){
// 	// verificamos que exista una tabla creada
// 		cout << "Imposible crear columna, no existe la tabla\n";
// 		return ERROR;
// 	}else{
// 	// verificamos si ya existe una columna con el mismo nombre
// 			// columnaSingular col = ts->t->colums->columna_singular;
// 			// columnaSingular col = getT(ts)->colums->columna_singular;

// 			cout << "el valor " << getColumnaSingularNombre_Tablas(ts);
// 			// cout << "el valor " << getColumnas(getT(ts));
// 			// cout << ts->t;
// 		// do{
// 		// 	if (nombreTabla == ts->t->colums->columna_singular->nombre){
// 		// 		cout << "Imposible crear columna. Ya existe columna con el nombre" << NombreCol << "\n";
// 		// 		return ERROR;
// 		// 	}else{
// 		// 		ts->t->colums->columna_singular = ts->t->colums->columna_singular->sig;
// 		// 	} 


// 		// }while(ts->t->colums->columna_singular->sig != NULL);
// 		return OK;
// 	}
// }



