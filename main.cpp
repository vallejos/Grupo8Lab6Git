#include <iostream>
#include <string>
#include "FabricaComando.h"
#include "cmdAltaEntrevista.h"
#include "cmdInscripcionOfertaLaboral.h"
#include "cmdAltaOfertaLaboral.h"
#include "cmdListarOfertasActivas.h"
#include "cmdAsignacionDeOfertaAEstudiante.h"
#include "cmdModificarEstudiante.h"
#include "cmdConsultarDatosEstudiantes.h"
#include "cmdModificarLlamado.h"
#include "cmdDarDeBajaLlamado.h"
#include "cmdCargarDatosDePrueba.h"


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
	cout << "-\n";
	cout << "L. Listar Notificaciones de Estudiante \n";
	cout << "A. Anotar/Borrar a Notificaciones\n";
	cout << "-\n";
	cout << "C. Cargar datos de prueba \n";
	cout << "E. Establecer hora del sistema \n";
	cout << "S. Salir \n";
	cout << "-\n";
	cout << "Elija una opcion:\n";
	cout << "> ";
}


// main
int main() {
	char opcion;
	bool salir = false;

	FabricaComando *cmd = FabricaComando::getInstance();

	while (!salir) {
		try {
			imprimirMenu();
			cin >> opcion;

			switch (opcion) {
				//------------------------
				// ALTA ENTREVISTA
				//------------------------
				case "1":
					cmd->ejecutarComando('B');
					break;

				//------------------------
				// ALTA OFERTA LABORAL
				//------------------------
				case "2":
					cmd->ejecutarComando('A');
					break;

				//------------------------
				// ASIGNACION DE OFERTA A ESTUDIANTE
				//------------------------
				case "3":
					cmd->ejecutarComando('C');
					break;

				//------------------------
				// CONSULTAR DATOS DE ESTUDIANTE
				//------------------------
				case "4":
					cmd->ejecutarComando('D');
					break;

				//------------------------
				// DAR DE BAJA LLAMADO
				//------------------------
				case "5":
					cmd->ejecutarComando('H');
					break;

				//------------------------
				// INSCRIPCION DE OFERTA LABORAL
				//------------------------
				case "6":
					cmd->ejecutarComando('I');
					break;

				//------------------------
				// LISTAR OFERTAS ACTIVAS
				//------------------------
				case "7":
					cmd->ejecutarComando('E');
					break;

				//------------------------
				// MODIFICAR ESTUDIANTE
				//------------------------
				case "8":
					cmd->ejecutarComando('F');
					break;

				//------------------------
				// MODIFICAR LLAMADO
				//------------------------
				case "9":
					cmd->ejecutarComando('G');
					break;

                //------------------------
				// LISTAR NOTIFICACIONES
				//------------------------
				case "L":
					cmd->ejecutarComando('K');
					break;

                //------------------------
				// ANOTAR/BORRAR NOTIF
				//------------------------
				case "A":
					cmd->ejecutarComando('M');
					break;

				//------------------------
				// CARGAR DATOS DE PRUEBA
				//------------------------
				case "C":
					// TODO: poner comandos para carga de pruebas
					cmd->ejecutarComando('J');
					break;

				//------------------------
				// ESTABLECER HORA SISTEMA
				//------------------------
				case "E":
					// TODO: poner comandos para carga de pruebas
					cmd->ejecutarComando('L');
					break;


				//------------------------
				// SALIR
				//------------------------
				case "S":
					salir = true;
					break;
			}
		} catch (exception &e) {
			cout << e.what();
		}
	}

	// TODO: liberar memoria


    return 0;
}
