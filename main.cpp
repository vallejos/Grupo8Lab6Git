#include <iostream>
#include <string>
#include "Sistema.h"
#include "Date.h"
#include "Rango.h"
#include "DataEstudiante.h"
#include "DataOfertaLaboral.h"
#include "DataSeccion.h"
#include "DataSucursal.h"
#include "DataEmpresa.h"

using namespace std;

// Imprime el Menu Principal
void imprimirMenu() {
	cout << "1. Alta Oferta Laboral \n";
	cout << "2. Crear Entrevista \n";
	cout << "3. Salir \n";
	cout << "Elija una opcion:\n";
	cout << ">";
}


// main
int main() {
	char opcion;
	bool salir = false;

	Sistema *Sys;

	string rutEmpresa, nombreSucursal, nombreSeccion;
	DataEmpresa **listaEmpresas;
	DataSucursal **listaSucursales;
	DataSeccion **listaSecciones;

	DataOfertaLaboral **listaOfertasPublicadas;
	string numExpediente, cedula;
	Date *fechaEntrevista;
	DataEstudiante **listaEstudiantes;

	string titulo, descripcion, asignaturas;
	int sueldoMaximo, sueldoMinimo, cantidadHorasSemanales, cantidadPuestosNecesarios, dd, mm, aaaa;

	Date *fechaComienzo, *fechaFin;
	Rango *rangoSalarial;

	// TODO: inicializar sistema
	Sys = new Sistema();

	while (!salir) {
		imprimirMenu();
		cin >> opcion;

		switch (opcion) {
			//------------------------
			// ALTA OFERTA LABORAL
			//------------------------
			case '1':
				listaEmpresas = Sys->ListarEmpresas();
				// mostrar en pantalla
				for (int i=0; i<Sys->getCantidadEmpresas(); i++) {
					cout << listaEmpresas[i]->getNombre();
				}

				cout << "Seleccionar Empresa (rut):\n";
				cin >> rutEmpresa;
				Sys->SeleccionarEmpresa(rutEmpresa);

				listaSucursales = Sys->ListarSucursales();
				// mostrar en pantalla
				for (int i=0; i<Sys->getCantidadSucursales(); i++) {
					cout << listaSucursales[i]->getNombre();
				}

				cout << "Seleccionar Sucursal (nombre):\n";
				cin >> nombreSucursal;
				Sys->SeleccionarSucursal(nombreSucursal);

				listaSecciones = Sys->ListarSecciones();
				// mostrar en pantalla
				for (int i=0; i<Sys->getCantidadSecciones(); i++) {
					cout << listaSecciones[i]->getNombre();
				}

				cout << "Seleccionar Seccion (nombre):\n";
				cin >> nombreSeccion;
				Sys->SeleccionarSeccion(nombreSeccion);

				cout << "Ingrese Expediente";
				cin >> numExpediente;

				cout << "Ingrese Titulo";
				cin >> titulo;

				cout << "Ingrese Descripcion";
				cin >> descripcion;

				cout << "Ingrese Cantidad de Horas Semanales";
				cin >> cantidadHorasSemanales;

				cout << "Ingrese Codigos de Asignaturas separadas por coma";
				cin >> asignaturas; // ej: 1122, 1023, 155

				cout << "Ingrese Sueldo Minimo";
				cin >> sueldoMinimo;

				cout << "Ingrese Sueldo Maximo";
				cin >> sueldoMaximo;

				rangoSalarial = new Rango (sueldoMinimo, sueldoMaximo);

				cout << "Ingrese Fecha Comienzo (DD MM AAAA)";
				cin >> dd >> mm >> aaaa;

				fechaComienzo = new Date(dd, mm, aaaa);

				cout << "Ingrese Fecha Fin (DD MM AAAA)";
				cin >> dd >> mm >> aaaa;

				fechaFin = new Date(dd, mm, aaaa);

				cout << "Ingrese Cantidad de Puestos";
				cin >> cantidadPuestosNecesarios;

				// TODO: ver parametros que faltan
				Sys->AltaOfertaLaboral(numExpediente, titulo, descripcion, cantidadHorasSemanales, rangoSalarial, fechaComienzo, fechaFin, cantidadPuestosNecesarios, asignaturas);

				break;

			//------------------------
			// CREAR ENTREVISTA
			//------------------------
			case '2':
				listaOfertasPublicadas = Sys->ListarOfertasPublicadas();
				// mostrar en pantalla
				for (int i=0; i<Sys->getCantidadOfertasLaborales(); i++) {
					cout << listaOfertasPublicadas[i]->getNumExpediente();
				}

				cout << "Seleccionar Oferta (expediente):\n";
				cin >> numExpediente;
				Sys->SeleccionarOferta(numExpediente);

				listaEstudiantes = Sys->ListarEstudiantes();
				// mostrar en pantalla
				for (int i=0; i<Sys->getCantidadEstudiantes(); i++) {
					cout << listaEstudiantes[i]->getCedula();
				}

				cout << "Seleccionar Estudiante (cedula):\n";
				cin >> cedula;
				Sys->SeleccionarEstudiante(cedula);

				// TODO: que fecha usamos?
				fechaEntrevista = new Date();

				// TODO: ver parametros que faltan
				Sys->AltaEntrevista(fechaEntrevista);

				break;

			//------------------------
			// SALIR
			//------------------------
			case '3':
				salir = true;
				break;
		}
	}

	// TODO: liberar memoria


    return 0;
}
