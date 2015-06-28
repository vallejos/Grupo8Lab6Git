#!/bin/bash

# Intento de generar Makefile automaticamente a partir de los archivos existentes en la carpeta

rm -f AutoMakefile

echo "# compilador
CC=g++
# flags para el compiler
CFLAGS=-c -Wall -Wextra -Wunreachable-code -ggdb -O0
LFLAGS=-Wall

all: lab6
" >> AutoMakefile

for FILE in $(ls *.cpp); do
	FILE=`echo "$FILE" | cut -d'.' -f1`
	LISTA_FILES="$LISTA_FILES $FILE.o"
done

for FILE in $(ls interfaces/*.cpp); do
	FILE=`echo "$FILE" | cut -d'.' -f1`
	LISTA_FILES="$LISTA_FILES $FILE.o"
done

for FILE in $(ls collections/*.cpp); do
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

for FILE in $(ls collections/*.h); do
	NOMBRE=`echo "$FILE" | cut -d'.' -f1`
	echo "$NOMBRE.o: $NOMBRE.h $NOMBRE.cpp
	\$(CC) \$(CFLAGS) $NOMBRE.cpp -o $NOMBRE.o
" >> AutoMakefile
done

for FILE in $(ls interfaces/*.h); do
	NOMBRE=`echo "$FILE" | cut -d'.' -f1`
	echo "$NOMBRE.o: $NOMBRE.h $NOMBRE.cpp
	\$(CC) \$(CFLAGS) $NOMBRE.cpp -o $NOMBRE.o
" >> AutoMakefile
done

echo "main.o: main.cpp
	\$(CC) \$(CFLAGS) main.cpp -o main.o

clean:
	rm *.o interfaces/*.o collections/*.o lab6 lab6.exe
" >> AutoMakefile

mv Makefile Makefile.bak
mv AutoMakefile Makefile
