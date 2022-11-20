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

bool isTablasEmpty_Tablas(tablas & ts){
	return (ts == NULL);
}

void imprimirTablas(tablas ts){
	if (ts == NULL){
		cout << " - No hay tablas\n";
	}else{
		nombreTabla(ts->t);
	}
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
		// cout << "Imposible Crear Tabla, ya hay una creada y el sistema soporta solo una\n";
		return crearTabla2(ts->t, nombreTabla);
	}
}

TipoRet EliminarTabla_tablas(tablas & ts, char * nombreTabla){
	if (isTablasEmpty_Tablas(ts)){
		cout <<"no hay tabla que eliminar \n";
		return 	ERROR;		
	}
	 else{
		ts->t = eliminarTabla(ts->t, nombreTabla);
		if (ts->t==NULL)
		{
			ts = crearTablas();
		}
		
		return OK;
	 }
}

// AddColumn()
TipoRet crearColumSingular_Columnas(tablas & ts, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol){
	if (isTablasEmpty_Tablas(ts)){
		cout << "Imposible Crear Columna. No existe tabla\n";
		return ERROR;
	}else{
		return crearColumnaSingular_Tabla(ts->t, nombreTabla, NombreCol, tipoCol, calificadorCol);
	}
}	

// PrintMetaData()
TipoRet estructuraTablas_tablas(tablas & ts, char *nombreTabla){
	// cout << "tablas 71" ;
	return estructuraTablas_tabla(ts->t, nombreTabla);
}

// InsertInto
TipoRet InsertInto_Tablas(tablas & ts, char *nombreTabla, char *columnasTupla, char *valoresTupla){
	// falta verificar PRIMARY KEY, NOT_EMPTY 

	if (isTablasEmpty_Tablas(ts)){
		cout << "No se puede insertar. No se ha encontrado la tabla\n";
		return ERROR;
	}else{
		return InsertInto_Tabla(ts->t, nombreTabla, columnasTupla, valoresTupla);
	}
}
TipoRet EliminarColumnaSing_tablas(tablas & ts, char *nombreTabla, char *nombreColS){
	if (isTablasEmpty_Tablas(ts)){
		//chequeamos que no este vacia
		cout << "No se puede insertar. No se ha encontrado la tabla\n";
		return ERROR;
	}else{
		  return EliminarColumnaSing_tabla(ts->t, nombreTabla, nombreColS);
		 
	}
}


TipoRet printdatatable_tablas(tablas ts, char *NombreTabla){
	return printdatatable_tabla(ts->t, NombreTabla);
}

