#include "tabla.h"
#include <string.h>
#include <iostream>
// #include <stdbool.h> // para bool


using namespace std;

struct nodo_tabla{
	char * nombre;
	columnas colums;
	tabla sig;
};

tabla crearTabla(char * nombreTabla){
	tabla t = new(nodo_tabla);
	t->nombre = new char[MAX_NOMBRE];
	strcpy(t->nombre, nombreTabla);
	t->colums = crearColumnasNULL();
	return t;
}


bool existeTabla(tabla t, char *nombreTabla){
	tabla auxiliar = t;
	bool aux = true;
	while(aux){
		if(auxiliar != NULL){
			if(strcasecmp(auxiliar->nombre, nombreTabla) == 0){
				aux = false;
				return true;
			}else{
				auxiliar = auxiliar->sig;
			}
		}else{
			aux = false;
			return false;
		}
	}
}


tabla igualarTabla(tabla & t, char *nombreTabla){
	bool aux = true;
	tabla auxiliar = t;
	if(existeTabla(t, nombreTabla)){
		while(aux){
			if(strcasecmp(auxiliar->nombre, nombreTabla) == 0){
				aux = false;
				return auxiliar;
			}else{
				auxiliar = auxiliar->sig;
			}
		}
	}else{
		return t;
	}
}



























TipoRet crearTabla2(tabla & t, char * nombreTabla){

		if(existeTabla(t, nombreTabla)){
				cout << "Ya existe la tabla con el nombre " << nombreTabla << endl;
				return ERROR;
		}else{
			// if(strcasecmp(auxiliar->nombre, nombreTabla) == 0){
			// 	cout << "Ya existe la tabla con el nombre " << nombreTabla << endl;
			// 	return ERROR;
			// }else{
			tabla auxiliar = t;
			bool aux = true;
			while(aux){
				if(auxiliar->sig != NULL){
					auxiliar = auxiliar->sig;
				}else{
					aux  = false;
					tabla nueva 		= new(nodo_tabla);
					auxiliar->sig 		= nueva;			
					nueva->nombre 		= new char[MAX_NOMBRE];
					strcpy(nueva->nombre, nombreTabla);
					nueva->colums		 = crearColumnasNULL();
				}
		}
		return OK;
	}
}


tabla crearColumnas_Tabla(tabla & t){
	t->colums = crearColumnas(); 
	return t;
}

void nombreTabla(tabla t){
	tabla auxiliar = t;
	while(auxiliar != NULL){
		cout << auxiliar->nombre << endl ;
		auxiliar = auxiliar->sig;
	}
}

columnas getColumnas(tabla t){
	return t->colums;
}

bool compararNombreTabla(tabla t, char * nombreTabla){
	if (strcasecmp(nombreTabla, t->nombre) == 0){
		return true;
	}else{
		return false;
	}
}

//addColumn
 TipoRet crearColumnaSingular_Tabla(tabla t, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol){
	if(!existeTabla(t, nombreTabla)){
		cout << "No existe la tabla " << nombreTabla << "\n";
		return ERROR;
	}else{
		// if (strcasecmp (nombreTabla, t->nombre) != 0){
		tabla auxiliar = t;
		auxiliar = igualarTabla(auxiliar, nombreTabla);
	// }
	// }else{
		bool primerCol;
		if(isColumnasEmpty_Columnas(auxiliar->colums)){
			primerCol = true;
			auxiliar->colums = crearColumnas(); // Creamos un new(nodo_columnas)
			return crearColumnaSingular_Columnas(auxiliar->colums, NombreCol, tipoCol, calificadorCol, primerCol);
		}else{
			primerCol = false;
			return crearColumnaSingular_Columnas(auxiliar->colums, NombreCol, tipoCol, calificadorCol, primerCol);
		}		
	}
 }
 TipoRet EliminarColumnaSing_tabla(tabla & t, char *nombreTabla, char *nombreColumS){
	if (strcasecmp (nombreTabla, t->nombre) !=0 ){
			return ERROR;
	}else{
		
		return EliminarColumnaSing_columnas(t->colums, nombreColumS);
	}
 }
 

// PrintMetaData()
TipoRet estructuraTablas_tabla(tabla & t, char *nombreTabla){
	if(existeTabla(t, nombreTabla)){
		tabla auxiliar = t;
		auxiliar = igualarTabla(auxiliar, nombreTabla);
		return estructuraTablas_Columnas(auxiliar->colums, nombreTabla);
	}else{
		cout << "La tabla no existe" << endl ;
		return ERROR;
	}
}


TipoRet InsertInto_Tabla(tabla & t, char *nombreTabla, char *columnasTupla, char *valoresTupla){
// buscar si existe la tabla
	return InsertInto_Columnas(t->colums, columnasTupla, valoresTupla);
//else

}
tabla eliminarTabla(tabla & t, char * nombreTabla){
	int aux = strcasecmp(t->nombre,nombreTabla);
		if(aux == 0){
			tabla elim = t;
			t = NULL;
			
			delete elim;
			
		}
		else{
			cout << "la tabla " << t << " no fue borrada" << endl;
			return t;
		}
	return t;
}

TipoRet printdatatable_tabla(tabla t, char *NombreTabla){
	return printdatatable_columna(t->colums, NombreTabla);
}


