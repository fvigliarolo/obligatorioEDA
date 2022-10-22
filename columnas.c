// // #include "tablas.h"
// #include "columnas.h"
// #include <string.h>
// #include <iostream>


// using namespace std;

// struct nodo_columnas{
//   	columnaSingular columna_singular;
// 	columnas sig;
// };




// columnas crearColumnas(){
// 	return new(nodo_columnas);
// }



// TipoRet crearColumSingular_Columnas(tablas & ts, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol){
// 	if (ts == NULL){
// 	// verificamos que exista una tabla creada
// 		cout << "Imposible crear columna, no existe la tabla\n";
// 		return ERROR;
// 	}else{
// 	// verificamos si ya existe una columna con el mismo nombre
// 			// columnaSingular col = ts->t->colums->columna_singular;
// 			// columnaSingular col = getT(ts)->colums->columna_singular;

// 			cout << "el valor " << getT(ts);
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


#include "columnas.h"
#include <string.h>
#include <iostream>
// #include <stdbool.h> // para bool



using namespace std;

struct nodo_columnas{
  	columnaSingular columna_singular;
	columnas sig;
};


columnas crearColumnas(){
	return new(nodo_columnas);
}

columnas crearColumnasNULL(){
	return NULL;
}

char * getColumnaSingularNombre_Columnas(columnas col){
	return getColumnaSingularNombre(col->columna_singular);
}

bool isColumnasEmpty_Columnas(columnas col){
	return (col == NULL);
}

// columnaSingular crearColumSingular_Columnas(char *NombreCol, char *tipoCol, char *calificadorCol){
// 	return crearColumSingular(NombreCol, tipoCol, calificadorCol);
// }

void crearColumSingular_Columnas(columnas col, char *NombreCol, char *tipoCol, char *calificadorCol){
	col->columna_singular = columnaSingularNull();
	// cout << col;
	crearColumSingular(col->columna_singular, NombreCol, tipoCol, calificadorCol);
}
