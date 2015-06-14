#!/bin/bash

# Intento de generar Makefile automaticamente a partir de los archivos existentes en la carpeta

rm -f AutoMakefile

echo "# compilador
CC=g++
# flags para el compiler
CFLAGS=-c -Wall
LFLAGS=-Wall

all: lab6
" >> AutoMakefile

for FILE in $(ls *.cpp); do
	FILE=`echo "$FILE" | cut -d'.' -f1`
	LISTA_FILES="$LISTA_FILES $FILE.o"
done
	echo "lab6: $LISTA_FILES
	\$(CC) \$(LFLAGS) $LISTA_FILES -o lab6

" >> AutoMakefile

for FILE in $(ls *.h); do
	NOMBRE=`echo "$FILE" | cut -d'.' -f1`
	echo "$NOMBRE.o: $NOMBRE.h $NOMBRE.cpp
	\$(CC) \$(CFLAGS) $NOMBRE.cpp -o $NOMBRE.o
" >> AutoMakefile
done

echo "main.o: main.cpp
	\$(CC) \$(CFLAGS) main.cpp -o main.o

clean:
	rm *.o lab6
" >> AutoMakefile

mv Makefile Makefile.bak
mv AutoMakefile Makefile
