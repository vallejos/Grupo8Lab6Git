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

	FabricaComando *fab = FabricaComando::getInstance();
	IComando* cmd;

	while (!salir) {
		try {
			imprimirMenu();
			cin >> opcion;

			switch (opcion) {
				//------------------------
				// ALTA ENTREVISTA
				//------------------------
				case '1':
				    cmd = fab->obtenerComando('B');
					cmd->ejecutarComando();
					break;

				//------------------------
				// ALTA OFERTA LABORAL
				//------------------------
				case '2':
				    cmd = fab->obtenerComando('A');
					cmd->ejecutarComando();
					break;

				//------------------------
				// ASIGNACION DE OFERTA A ESTUDIANTE
				//------------------------
				case '3':
				    cmd = fab->obtenerComando('C');
					cmd->ejecutarComando();
					break;

				//------------------------
				// CONSULTAR DATOS DE ESTUDIANTE
				//------------------------
				case '4':
				    cmd = fab->obtenerComando('D');
					cmd->ejecutarComando();
					break;

				//------------------------
				// DAR DE BAJA LLAMADO
				//------------------------
				case '5':
				    cmd = fab->obtenerComando('H');
					cmd->ejecutarComando();
					break;

				//------------------------
				// INSCRIPCION DE OFERTA LABORAL
				//------------------------
				case '6':
				    cmd = fab->obtenerComando('I');
					cmd->ejecutarComando();
					break;

				//------------------------
				// LISTAR OFERTAS ACTIVAS
				//------------------------
				case '7':
				    cmd = fab->obtenerComando('E');
					cmd->ejecutarComando();
					break;

				//------------------------
				// MODIFICAR ESTUDIANTE
				//------------------------
				case '8':
				    cmd = fab->obtenerComando('F');
					cmd->ejecutarComando();
					break;

				//------------------------
				// MODIFICAR LLAMADO
				//------------------------
				case '9':
				    cmd = fab->obtenerComando('G');
					cmd->ejecutarComando();
					break;

                //------------------------
				// LISTAR NOTIFICACIONES
				//------------------------
				case 'L':
				    cmd = fab->obtenerComando('K');
					cmd->ejecutarComando();
					break;

                //------------------------
				// ANOTAR/BORRAR NOTIF
				//------------------------
				case 'A':
				    cmd = fab->obtenerComando('M');
					cmd->ejecutarComando();
					break;

				//------------------------
				// CARGAR DATOS DE PRUEBA
				//------------------------
				case 'C':
					// TODO: poner comandos para carga de pruebas
					cmd = fab->obtenerComando('J');
					cmd->ejecutarComando();
					break;

				//------------------------
				// ESTABLECER HORA SISTEMA
				//------------------------
				case 'E':
					// TODO: poner comandos para carga de pruebas
					cmd = fab->obtenerComando('L');
					cmd->ejecutarComando();
					break;


				//------------------------
				// SALIR
				//------------------------
				case 'S':
					salir = true;
					break;
			}
		} catch (char const *e) {
			cout << e;
			cout << "\n";
		}
	}

	// TODO: liberar memoria


    return 0;
}
