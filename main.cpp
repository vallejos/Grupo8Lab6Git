#include <iostream>
#include <string>
#include "cmdAltaEntrevista.h"
#include "cmdInscripcionOfertaLaboral.h"
#include "cmdAltaOfertaLaboral.h"
#include "cmdListarOfertasActivas.h"
#include "cmdAsignacionDeOfertaAEstudiante.h"
#include "cmdModificarEstudiante.h"
#include "cmdConsultarDatosEstudiantes.h"
#include "cmdModificarLlamado.h"
#include "cmdDarDeBajaLlamado.h"


using namespace std;

// Imprime el Menu Principal
void imprimirMenu() {
	cout << "1. Alta Entrevista \n";
	cout << "2. Alta Oferta Laboral \n";
	cout << "3. Asignacion de Oferta a Estudiante \n";
	cout << "4. Consultar Datos de Estudiante \n";
	cout << "5. Dar de Baja Llamado \n";
	cout << "6. Inscripcion Oferta Laboral \n";
	cout << "7. Listar Ofertas Activas \n";
	cout << "8. Modificar Estudiante \n";
	cout << "9. Modificar Llamado \n";
	cout << "-";
	cout << "C. Cargar datos de prueba \n";
	cout << "S. Salir \n";
	cout << "-";
	cout << "Elija una opcion:\n";
	cout << "> ";
}


// main
int main() {
	char opcion;
	bool salir = false;

	Sistema *Sys;

	// TODO: inicializar sistema
	Sys = new Sistema();

	while (!salir) {
		imprimirMenu();
		cin >> opcion;

		switch (opcion) {
			//------------------------
			// ALTA ENTREVISTA
			//------------------------
			case '1':
				cmdAltaEntrevista::ejecutarComando();
				break;

			//------------------------
			// ALTA OFERTA LABORAL
			//------------------------
			case '2':
				cmdAltaOfertaLaboral::ejecutarComando();
				break;

			//------------------------
			// ASIGNACION DE OFERTA A ESTUDIANTE
			//------------------------
			case '3':
				cmdAsignacionDeOfertaAEstudiante::ejecutarComando();
				break;

			//------------------------
			// CONSULTAR DATOS DE ESTUDIANTE
			//------------------------
			case '4':
				cmdConsultarDatosEstudiantes::ejecutarComando();
				break;

			//------------------------
			// DAR DE BAJA LLAMADO
			//------------------------
			case '5':
				cmdDarDeBajaLlamado::ejecutarComando();
				break;

			//------------------------
			// INSCRIPCION DE OFERTA LABORAL
			//------------------------
			case '6':
				cmdInscripcionOfertaLaboral::ejecutarComando();
				break;

			//------------------------
			// LISTAR OFERTAS ACTIVAS
			//------------------------
			case '7':
				cmdListarOfertasActivas::ejecutarComando();
				break;

			//------------------------
			// MODIFICAR ESTUDIANTE
			//------------------------
			case '8':
				cmdModificarEstudiante::ejecutarComando();
				break;

			//------------------------
			// MODIFICAR LLAMADO
			//------------------------
			case '9':
				cmdModificarLlamado::ejecutarComando();
				break;

			//------------------------
			// CARGAR DATOS DE PRUEBA
			//------------------------
			case 'C':
				// TODO: poner comandos para carga de pruebas
			
				break;

			//------------------------
			// SALIR
			//------------------------
			case 'S':
				salir = true;
				break;
		}
	}

	// TODO: liberar memoria


    return 0;
}
