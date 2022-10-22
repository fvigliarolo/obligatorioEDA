// #include "tabla.h"
// #include "columnas.h"
// #include <string.h>
// #include <iostream>

// using namespace std;

// struct nodo_tabla{
// 	char * nombre;
// 	columnas colums;
// };

// tabla crearTabla(char * nombreTabla){
// 	tabla t = new(nodo_tabla);
// 	t->nombre = new char[MAX_NOMBRE];
// 	strcpy(t->nombre, nombreTabla);
// 	t->colums = crearColumnas();
// 	return t;
// }

// char * nombreTabla(tabla t){
// 	return t->nombre;
// }

// // columnas getColumnas(tabla t){
// // 	return t->colums;
// // }

#include "tabla.h"
#include <string.h>
#include <iostream>
// #include <stdbool.h> // para bool


using namespace std;

struct nodo_tabla{
	char * nombre;
	columnas colums;
};

tabla crearTabla(char * nombreTabla){
	tabla t = new(nodo_tabla);
	t->nombre = new char[MAX_NOMBRE];
	strcpy(t->nombre, nombreTabla);
	t->colums = crearColumnasNULL();
	return t;
}

tabla crearColumnas_Tabla(tabla & t){
	t->colums = crearColumnas(); 
	return t;
}


char * nombreTabla(tabla t){
	return t->nombre;
}

columnas getColumnas(tabla t){
	return t->colums;
}

bool isColumnasEmpty_Tabla(tabla t){
	return isColumnasEmpty_Columnas(t->colums);
}

char * getColumnaSingularNombre_Tabla(tabla t){
	return getColumnaSingularNombre_Columnas(t->colums);
}

// columnas crearColumSingular_Tabla(char *NombreCol, char *tipoCol, char *calificadorCol){
// 	return crearColumSingular_Columnas(NombreCol, tipoCol, calificadorCol);
// }

void crearColumSingular_Tabla(tabla t, char *NombreCol, char *tipoCol, char *calificadorCol){
	crearColumSingular_Columnas(t->colums, NombreCol, tipoCol, calificadorCol);
}
