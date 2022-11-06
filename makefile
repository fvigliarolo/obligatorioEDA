todo: main.o bd.o tablas.o tabla.o columnas.o columnaSingular.o atributo_simple.o
	g++ -Wall -o main bd.o main.o tablas.o tabla.o columnas.o columnaSingular.o atributo_simple.o
main.o: bd.o main.c
	g++ -Wall -c main.c
bd.o: bd.c bd.h
	g++ -Wall -c bd.c
tablas.o: tablas.c tablas.h
	g++ -Wall -c tablas.c
tabla.o: tabla.c tabla.h
	g++ -Wall -c tabla.c
columnas.o: columnas.c columnas.h
	g++ -Wall -c columnas.c
columnaSingular.o: columnaSingular.c columnaSingular.h
	g++ -Wall -c columnaSingular.c
atributo_simple.o: atributo_simple.c atributo_simple.h
	g++ -Wall -c atributo_simple.c
clean:
	rm -f *.o
	rm -f main

