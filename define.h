#ifndef DEFINE_H
#define DEFINE_H

// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// define.h
// Modulo de Definiciones Generales.

#define MAX_COMANDO 128
#define MAX_NOMBRE 20


enum _retorno{OK, ERROR, NO_IMPLEMENTADA};
typedef enum _retorno TipoRet;


enum _calificador{ANY, PRIMARY_KEY, NOT_EMPTY};
typedef enum _calificador TipoCalificador;

enum _tipoDato{INTEGER, CHAR};
typedef enum _tipoDato TipoDato;




#endif
