# compilador
CC=g++
# flags para el compiler
CFLAGS=-c -Wall
LFLAGS=-Wall

all: lab6

lab6:  Aprobacion.o Asignatura.o Carrera.o Criterio1.o Criterio2.o DataAprobada.o DataAsignatura.o DataCarrera.o DataDatosEstudiante.o DataEmpresa.o DataEncargado.o DataEstudiante.o DataOfertaEmpresa.o DataOfertaLaboral.o DataSeccion.o DataSucursal.o Date.o EmpresaController.o Empresa.o Encargado.o EstudianteController.o Estudiante.o Fabrica.o IEstudianteController.o Inscripcion.o IObserver.o main.o ManejadorEmpresa.o ManejadorEstudiante.o ManejadorOfertaLaboral.o OfertaLaboralController.o OfertaLaboral.o Rango.o Seccion.o Sistema.o Sucursal.o Tiempo.o
	$(CC) $(LFLAGS)  Aprobacion.o Asignatura.o Carrera.o Criterio1.o Criterio2.o DataAprobada.o DataAsignatura.o DataCarrera.o DataDatosEstudiante.o DataEmpresa.o DataEncargado.o DataEstudiante.o DataOfertaEmpresa.o DataOfertaLaboral.o DataSeccion.o DataSucursal.o Date.o EmpresaController.o Empresa.o Encargado.o EstudianteController.o Estudiante.o Fabrica.o IEstudianteController.o Inscripcion.o IObserver.o main.o ManejadorEmpresa.o ManejadorEstudiante.o ManejadorOfertaLaboral.o OfertaLaboralController.o OfertaLaboral.o Rango.o Seccion.o Sistema.o Sucursal.o Tiempo.o -o lab6


Aprobacion.o: Aprobacion.h Aprobacion.cpp
	$(CC) $(CFLAGS) Aprobacion.cpp -o Aprobacion.o

Asignatura.o: Asignatura.h Asignatura.cpp
	$(CC) $(CFLAGS) Asignatura.cpp -o Asignatura.o

Carrera.o: Carrera.h Carrera.cpp
	$(CC) $(CFLAGS) Carrera.cpp -o Carrera.o

Criterio1.o: Criterio1.h Criterio1.cpp
	$(CC) $(CFLAGS) Criterio1.cpp -o Criterio1.o

Criterio2.o: Criterio2.h Criterio2.cpp
	$(CC) $(CFLAGS) Criterio2.cpp -o Criterio2.o

DataAprobada.o: DataAprobada.h DataAprobada.cpp
	$(CC) $(CFLAGS) DataAprobada.cpp -o DataAprobada.o

DataAsignatura.o: DataAsignatura.h DataAsignatura.cpp
	$(CC) $(CFLAGS) DataAsignatura.cpp -o DataAsignatura.o

DataCarrera.o: DataCarrera.h DataCarrera.cpp
	$(CC) $(CFLAGS) DataCarrera.cpp -o DataCarrera.o

DataDatosEstudiante.o: DataDatosEstudiante.h DataDatosEstudiante.cpp
	$(CC) $(CFLAGS) DataDatosEstudiante.cpp -o DataDatosEstudiante.o

DataEmpresa.o: DataEmpresa.h DataEmpresa.cpp
	$(CC) $(CFLAGS) DataEmpresa.cpp -o DataEmpresa.o

DataEncargado.o: DataEncargado.h DataEncargado.cpp
	$(CC) $(CFLAGS) DataEncargado.cpp -o DataEncargado.o

DataEstudiante.o: DataEstudiante.h DataEstudiante.cpp
	$(CC) $(CFLAGS) DataEstudiante.cpp -o DataEstudiante.o

DataOfertaEmpresa.o: DataOfertaEmpresa.h DataOfertaEmpresa.cpp
	$(CC) $(CFLAGS) DataOfertaEmpresa.cpp -o DataOfertaEmpresa.o

DataOfertaLaboral.o: DataOfertaLaboral.h DataOfertaLaboral.cpp
	$(CC) $(CFLAGS) DataOfertaLaboral.cpp -o DataOfertaLaboral.o

DataSeccion.o: DataSeccion.h DataSeccion.cpp
	$(CC) $(CFLAGS) DataSeccion.cpp -o DataSeccion.o

DataSucursal.o: DataSucursal.h DataSucursal.cpp
	$(CC) $(CFLAGS) DataSucursal.cpp -o DataSucursal.o

Date.o: Date.h Date.cpp
	$(CC) $(CFLAGS) Date.cpp -o Date.o

EmpresaController.o: EmpresaController.h EmpresaController.cpp
	$(CC) $(CFLAGS) EmpresaController.cpp -o EmpresaController.o

Empresa.o: Empresa.h Empresa.cpp
	$(CC) $(CFLAGS) Empresa.cpp -o Empresa.o

Encargado.o: Encargado.h Encargado.cpp
	$(CC) $(CFLAGS) Encargado.cpp -o Encargado.o

EstrategiaAsignaturas.o: EstrategiaAsignaturas.h EstrategiaAsignaturas.cpp
	$(CC) $(CFLAGS) EstrategiaAsignaturas.cpp -o EstrategiaAsignaturas.o

EstudianteController.o: EstudianteController.h EstudianteController.cpp
	$(CC) $(CFLAGS) EstudianteController.cpp -o EstudianteController.o

Estudiante.o: Estudiante.h Estudiante.cpp
	$(CC) $(CFLAGS) Estudiante.cpp -o Estudiante.o

Fabrica.o: Fabrica.h Fabrica.cpp
	$(CC) $(CFLAGS) Fabrica.cpp -o Fabrica.o

IEmpresaController.o: IEmpresaController.h IEmpresaController.cpp
	$(CC) $(CFLAGS) IEmpresaController.cpp -o IEmpresaController.o

IEstudianteController.o: IEstudianteController.h IEstudianteController.cpp
	$(CC) $(CFLAGS) IEstudianteController.cpp -o IEstudianteController.o

Inscripcion.o: Inscripcion.h Inscripcion.cpp
	$(CC) $(CFLAGS) Inscripcion.cpp -o Inscripcion.o

IObserver.o: IObserver.h IObserver.cpp
	$(CC) $(CFLAGS) IObserver.cpp -o IObserver.o

IOfertaLaboralController.o: IOfertaLaboralController.h IOfertaLaboralController.cpp
	$(CC) $(CFLAGS) IOfertaLaboralController.cpp -o IOfertaLaboralController.o

ManejadorEmpresa.o: ManejadorEmpresa.h ManejadorEmpresa.cpp
	$(CC) $(CFLAGS) ManejadorEmpresa.cpp -o ManejadorEmpresa.o

ManejadorEstudiante.o: ManejadorEstudiante.h ManejadorEstudiante.cpp
	$(CC) $(CFLAGS) ManejadorEstudiante.cpp -o ManejadorEstudiante.o

ManejadorOfertaLaboral.o: ManejadorOfertaLaboral.h ManejadorOfertaLaboral.cpp
	$(CC) $(CFLAGS) ManejadorOfertaLaboral.cpp -o ManejadorOfertaLaboral.o

OfertaLaboralController.o: OfertaLaboralController.h OfertaLaboralController.cpp
	$(CC) $(CFLAGS) OfertaLaboralController.cpp -o OfertaLaboralController.o

OfertaLaboral.o: OfertaLaboral.h OfertaLaboral.cpp
	$(CC) $(CFLAGS) OfertaLaboral.cpp -o OfertaLaboral.o

Rango.o: Rango.h Rango.cpp
	$(CC) $(CFLAGS) Rango.cpp -o Rango.o

Seccion.o: Seccion.h Seccion.cpp
	$(CC) $(CFLAGS) Seccion.cpp -o Seccion.o

Sistema.o: Sistema.h Sistema.cpp
	$(CC) $(CFLAGS) Sistema.cpp -o Sistema.o

Sucursal.o: Sucursal.h Sucursal.cpp
	$(CC) $(CFLAGS) Sucursal.cpp -o Sucursal.o

Tiempo.o: Tiempo.h Tiempo.cpp
	$(CC) $(CFLAGS) Tiempo.cpp -o Tiempo.o

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

clean:
	rm *.o lab6
