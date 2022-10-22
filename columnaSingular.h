#ifndef ATRIBUTOSINGULAR_H
#define ATRIBUTOSINGULAR_H

typedef struct nodo_columnaSingular * columnaSingular;

// columnaSingular crearColumSingular(char *NombreCol, char *tipoCol, char *calificadorCol);
void crearColumSingular(columnaSingular cs, char *NombreCol, char *tipoCol, char *calificadorCol);

char * getColumnaSingularNombre(columnaSingular columna_singular);

columnaSingular columnaSingularNull();




#endif