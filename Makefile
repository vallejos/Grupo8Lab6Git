# compilador
CC=g++
# flags para el compiler
CFLAGS=-c -Wall -Wextra -Wunreachable-code -ggdb -O0
LFLAGS=-Wall

all: lab6

lab6:  Aprobacion.o Asignatura.o Carrera.o cmdAltaEntrevista.o cmdAltaOfertaLaboral.o cmdAnotarBorrarNotificaciones.o cmdAsignacionDeOfertaAEstudiante.o cmdCargarDatosDePrueba.o cmdConsultarDatosEstudiantes.o cmdDarDeBajaLlamado.o cmdEstablecerHoraSistema.o cmdInscripcionOfertaLaboral.o cmdListarNotificacionesEstudiante.o cmdListarOfertasActivas.o cmdModificarEstudiante.o cmdModificarLlamado.o Criterio1.o Criterio2.o DataAprobada.o DataAsignatura.o DataCarrera.o DataDatosEstudiante.o DataEmpresa.o DataEncargado.o DataEstudiante.o DataOfertaEmpresa.o DataOfertaLaboral.o DataSeccion.o DataSucursal.o Date.o Efectivizacion.o EmpresaController.o Empresa.o Encargado.o Entrevista.o EstrategiaAsignaturas.o EstudianteController.o Estudiante.o FabricaComando.o Fabrica.o IComando.o IEmpresaController.o IEstudianteController.o Inscripcion.o Integer.o IObserver.o IOfertaLaboralController.o main.o ManejadorEmpresa.o ManejadorEstudiante.o ManejadorOfertaLaboral.o OfertaLaboralController.o OfertaLaboral.o Rango.o Seccion.o String.o Sucursal.o Tiempo.o interfaces/ICollectible.o interfaces/ICollection.o interfaces/IDictionary.o interfaces/IIterator.o interfaces/IKey.o interfaces/OrderedKey.o collections/List.o collections/ListIterator.o collections/ListNode.o collections/OrderedDictionary.o collections/OrderedDictionaryEntry.o
	$(CC) $(LFLAGS)  Aprobacion.o Asignatura.o Carrera.o cmdAltaEntrevista.o cmdAltaOfertaLaboral.o cmdAnotarBorrarNotificaciones.o cmdAsignacionDeOfertaAEstudiante.o cmdCargarDatosDePrueba.o cmdConsultarDatosEstudiantes.o cmdDarDeBajaLlamado.o cmdEstablecerHoraSistema.o cmdInscripcionOfertaLaboral.o cmdListarNotificacionesEstudiante.o cmdListarOfertasActivas.o cmdModificarEstudiante.o cmdModificarLlamado.o Criterio1.o Criterio2.o DataAprobada.o DataAsignatura.o DataCarrera.o DataDatosEstudiante.o DataEmpresa.o DataEncargado.o DataEstudiante.o DataOfertaEmpresa.o DataOfertaLaboral.o DataSeccion.o DataSucursal.o Date.o Efectivizacion.o EmpresaController.o Empresa.o Encargado.o Entrevista.o EstrategiaAsignaturas.o EstudianteController.o Estudiante.o FabricaComando.o Fabrica.o IComando.o IEmpresaController.o IEstudianteController.o Inscripcion.o Integer.o IObserver.o IOfertaLaboralController.o main.o ManejadorEmpresa.o ManejadorEstudiante.o ManejadorOfertaLaboral.o OfertaLaboralController.o OfertaLaboral.o Rango.o Seccion.o String.o Sucursal.o Tiempo.o interfaces/ICollectible.o interfaces/ICollection.o interfaces/IDictionary.o interfaces/IIterator.o interfaces/IKey.o interfaces/OrderedKey.o collections/List.o collections/ListIterator.o collections/ListNode.o collections/OrderedDictionary.o collections/OrderedDictionaryEntry.o -o lab6


Aprobacion.o: Aprobacion.h Aprobacion.cpp
	$(CC) $(CFLAGS) Aprobacion.cpp -o Aprobacion.o

Asignatura.o: Asignatura.h Asignatura.cpp
	$(CC) $(CFLAGS) Asignatura.cpp -o Asignatura.o

Carrera.o: Carrera.h Carrera.cpp
	$(CC) $(CFLAGS) Carrera.cpp -o Carrera.o

cmdAltaEntrevista.o: cmdAltaEntrevista.h cmdAltaEntrevista.cpp
	$(CC) $(CFLAGS) cmdAltaEntrevista.cpp -o cmdAltaEntrevista.o

cmdAltaOfertaLaboral.o: cmdAltaOfertaLaboral.h cmdAltaOfertaLaboral.cpp
	$(CC) $(CFLAGS) cmdAltaOfertaLaboral.cpp -o cmdAltaOfertaLaboral.o

cmdAnotarBorrarNotificaciones.o: cmdAnotarBorrarNotificaciones.h cmdAnotarBorrarNotificaciones.cpp
	$(CC) $(CFLAGS) cmdAnotarBorrarNotificaciones.cpp -o cmdAnotarBorrarNotificaciones.o

cmdAsignacionDeOfertaAEstudiante.o: cmdAsignacionDeOfertaAEstudiante.h cmdAsignacionDeOfertaAEstudiante.cpp
	$(CC) $(CFLAGS) cmdAsignacionDeOfertaAEstudiante.cpp -o cmdAsignacionDeOfertaAEstudiante.o

cmdCargarDatosDePrueba.o: cmdCargarDatosDePrueba.h cmdCargarDatosDePrueba.cpp
	$(CC) $(CFLAGS) cmdCargarDatosDePrueba.cpp -o cmdCargarDatosDePrueba.o

cmdConsultarDatosEstudiantes.o: cmdConsultarDatosEstudiantes.h cmdConsultarDatosEstudiantes.cpp
	$(CC) $(CFLAGS) cmdConsultarDatosEstudiantes.cpp -o cmdConsultarDatosEstudiantes.o

cmdDarDeBajaLlamado.o: cmdDarDeBajaLlamado.h cmdDarDeBajaLlamado.cpp
	$(CC) $(CFLAGS) cmdDarDeBajaLlamado.cpp -o cmdDarDeBajaLlamado.o

cmdEstablecerHoraSistema.o: cmdEstablecerHoraSistema.h cmdEstablecerHoraSistema.cpp
	$(CC) $(CFLAGS) cmdEstablecerHoraSistema.cpp -o cmdEstablecerHoraSistema.o

cmdInscripcionOfertaLaboral.o: cmdInscripcionOfertaLaboral.h cmdInscripcionOfertaLaboral.cpp
	$(CC) $(CFLAGS) cmdInscripcionOfertaLaboral.cpp -o cmdInscripcionOfertaLaboral.o

cmdListarNotificacionesEstudiante.o: cmdListarNotificacionesEstudiante.h cmdListarNotificacionesEstudiante.cpp
	$(CC) $(CFLAGS) cmdListarNotificacionesEstudiante.cpp -o cmdListarNotificacionesEstudiante.o

cmdListarOfertasActivas.o: cmdListarOfertasActivas.h cmdListarOfertasActivas.cpp
	$(CC) $(CFLAGS) cmdListarOfertasActivas.cpp -o cmdListarOfertasActivas.o

cmdModificarEstudiante.o: cmdModificarEstudiante.h cmdModificarEstudiante.cpp
	$(CC) $(CFLAGS) cmdModificarEstudiante.cpp -o cmdModificarEstudiante.o

cmdModificarLlamado.o: cmdModificarLlamado.h cmdModificarLlamado.cpp
	$(CC) $(CFLAGS) cmdModificarLlamado.cpp -o cmdModificarLlamado.o

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

Efectivizacion.o: Efectivizacion.h Efectivizacion.cpp
	$(CC) $(CFLAGS) Efectivizacion.cpp -o Efectivizacion.o

EmpresaController.o: EmpresaController.h EmpresaController.cpp
	$(CC) $(CFLAGS) EmpresaController.cpp -o EmpresaController.o

Empresa.o: Empresa.h Empresa.cpp
	$(CC) $(CFLAGS) Empresa.cpp -o Empresa.o

Encargado.o: Encargado.h Encargado.cpp
	$(CC) $(CFLAGS) Encargado.cpp -o Encargado.o

Entrevista.o: Entrevista.h Entrevista.cpp
	$(CC) $(CFLAGS) Entrevista.cpp -o Entrevista.o

EstrategiaAsignaturas.o: EstrategiaAsignaturas.h EstrategiaAsignaturas.cpp
	$(CC) $(CFLAGS) EstrategiaAsignaturas.cpp -o EstrategiaAsignaturas.o

EstudianteController.o: EstudianteController.h EstudianteController.cpp
	$(CC) $(CFLAGS) EstudianteController.cpp -o EstudianteController.o

Estudiante.o: Estudiante.h Estudiante.cpp
	$(CC) $(CFLAGS) Estudiante.cpp -o Estudiante.o

FabricaComando.o: FabricaComando.h FabricaComando.cpp
	$(CC) $(CFLAGS) FabricaComando.cpp -o FabricaComando.o

Fabrica.o: Fabrica.h Fabrica.cpp
	$(CC) $(CFLAGS) Fabrica.cpp -o Fabrica.o

IComando.o: IComando.h IComando.cpp
	$(CC) $(CFLAGS) IComando.cpp -o IComando.o

IEmpresaController.o: IEmpresaController.h IEmpresaController.cpp
	$(CC) $(CFLAGS) IEmpresaController.cpp -o IEmpresaController.o

IEstudianteController.o: IEstudianteController.h IEstudianteController.cpp
	$(CC) $(CFLAGS) IEstudianteController.cpp -o IEstudianteController.o

Inscripcion.o: Inscripcion.h Inscripcion.cpp
	$(CC) $(CFLAGS) Inscripcion.cpp -o Inscripcion.o

Integer.o: Integer.h Integer.cpp
	$(CC) $(CFLAGS) Integer.cpp -o Integer.o

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

String.o: String.h String.cpp
	$(CC) $(CFLAGS) String.cpp -o String.o

Sucursal.o: Sucursal.h Sucursal.cpp
	$(CC) $(CFLAGS) Sucursal.cpp -o Sucursal.o

Tiempo.o: Tiempo.h Tiempo.cpp
	$(CC) $(CFLAGS) Tiempo.cpp -o Tiempo.o

collections/List.o: collections/List.h collections/List.cpp
	$(CC) $(CFLAGS) collections/List.cpp -o collections/List.o

collections/ListIterator.o: collections/ListIterator.h collections/ListIterator.cpp
	$(CC) $(CFLAGS) collections/ListIterator.cpp -o collections/ListIterator.o

collections/ListNode.o: collections/ListNode.h collections/ListNode.cpp
	$(CC) $(CFLAGS) collections/ListNode.cpp -o collections/ListNode.o

collections/OrderedDictionaryEntry.o: collections/OrderedDictionaryEntry.h collections/OrderedDictionaryEntry.cpp
	$(CC) $(CFLAGS) collections/OrderedDictionaryEntry.cpp -o collections/OrderedDictionaryEntry.o

collections/OrderedDictionary.o: collections/OrderedDictionary.h collections/OrderedDictionary.cpp
	$(CC) $(CFLAGS) collections/OrderedDictionary.cpp -o collections/OrderedDictionary.o

interfaces/ICollectible.o: interfaces/ICollectible.h interfaces/ICollectible.cpp
	$(CC) $(CFLAGS) interfaces/ICollectible.cpp -o interfaces/ICollectible.o

interfaces/ICollection.o: interfaces/ICollection.h interfaces/ICollection.cpp
	$(CC) $(CFLAGS) interfaces/ICollection.cpp -o interfaces/ICollection.o

interfaces/IDictionary.o: interfaces/IDictionary.h interfaces/IDictionary.cpp
	$(CC) $(CFLAGS) interfaces/IDictionary.cpp -o interfaces/IDictionary.o

interfaces/IIterator.o: interfaces/IIterator.h interfaces/IIterator.cpp
	$(CC) $(CFLAGS) interfaces/IIterator.cpp -o interfaces/IIterator.o

interfaces/IKey.o: interfaces/IKey.h interfaces/IKey.cpp
	$(CC) $(CFLAGS) interfaces/IKey.cpp -o interfaces/IKey.o

interfaces/OrderedKey.o: interfaces/OrderedKey.h interfaces/OrderedKey.cpp
	$(CC) $(CFLAGS) interfaces/OrderedKey.cpp -o interfaces/OrderedKey.o

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

clean:
	rm *.o interfaces/*.o collections/*.o lab6 lab6.exe

