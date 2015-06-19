#include <iostream>
#include <string>
#include "cmdCargarDatosDePrueba.h"
#include "interfaces/IDictionary.h"
#include "interfaces/ICollection.h"
#include "ManejadorEmpresa.h"
#include "Empresa.h"
#include "Sucursal.h"

using namespace std;

// cmdCargarDatosDePrueba
void cmdCargarDatosDePrueba::ejecutarComando()
{
	ManejadorEmpresa *me = ManejadorEmpresa::getInstance();

	// cargar empresas
	IDictionary *empresas = me->getEmpresas();
	Empresa *e1, *e2, *e3, *e4, *e5;

	e1 = new Empresa("1112335684","Segurol S.A.");
	e2 = new Empresa("1298865497","RoboTI");
	e3 = new Empresa("1265498765","MiniSoft Uy");
	e4 = new Empresa("5464897986","Ingenieros Electricos Unidos");
	e5 = new Empresa("1326548654","Academia Yotexplico");

	empresas->add("1112335684", e1);
	empresas->add("1298865497", e2);
	empresas->add("1265498765", e3);
	empresas->add("5464897986", e4);
	empresas->add("1326548654", e5);

	// cargar sucursales
	IDictionary *sue1, *sue2, *sue3, *sue4, *sue5;

	sue1 = e1->getSucursales();
	sue2 = e2->getSucursales();
	sue3 = e3->getSucursales();
	sue4 = e4->getSucursales();
	sue5 = e5->getSucursales();

	Sucursal *su1, *su2, *su3, *su4, *su5, *su6, *su7;

	su1 = new Sucursal("Casa central","24598765","Ciudad Vieja");
	su2 = new Sucursal("Sucursal comercial","25225323","Malvin");
	su3 = new Sucursal("Sucursal San Carlos","42668350","San Carlos");
	su4 = new Sucursal("Sede Montevideo","25468932","Buceo");
	su5 = new Sucursal("Sede Ciudad de la Costa","43764232","Solymar");
	su6 = new Sucursal("Oficina central","25495878","Centro");
	su7 = new Sucursal("Academia","24594565","Parque Rodo");

	sue1->add(su1);
	sue2->add(su2);
	sue2->add(su3);
	sue3->add(su4);
	sue3->add(su5);
	sue4->add(su6);
	sue5->add(su7);

	// cargar secciones
	Seccion *se1, *se2, *se3, *se4, *se5, *se6, *se7, *se8, *se9, *se10, *se11, *se12, *se13, *se14, *se15, 
			*se16, *se17, *se18, *se19, *se20, *se21, *se22, *se23;

	se1 = new Seccion("Contaduria","101");
	se2 = new Seccion("Recursos humanos","102");
	se3 = new Seccion("Recepcion","103");
	se4 = new Seccion("Desarrollo","104");
	se5 = new Seccion("Pentesting","105");
	se6 = new Seccion("Marketing","1201");
	se7 = new Seccion("Atencion al cliente","1202");
	se8 = new Seccion("Tesoreria","1203");
	se9 = new Seccion("Ventas","1204");
	se10 = new Seccion("Seccion tecnica","1205");
	se11 = new Seccion("Seccion tecnica","1009");
	se12 = new Seccion("I+D","1008");
	se13 = new Seccion("Recepcion","1000");
	se14 = new Seccion("Secretaria","100");
	se15 = new Seccion("Desarrollo","1001");
	se16 = new Seccion("Testing","1002");
	se17 = new Seccion("Secretaria","100");
	se18 = new Seccion("Desarrollo","1001");
	se19 = new Seccion("Testing","1002");
	se20 = new Seccion("Laboratorio","10");
	se21 = new Seccion("Atencion comercial","11");
	se22 = new Seccion("Direccion","101");
	se23 = new Seccion("Inscripciones","102");

	IDictionary *su1se, *su2se, *su3se, *su4se, *su5se, *su6se, *su7se;

	su1se = su1->getSecciones();
	su2se = su2->getSecciones();
	su3se = su3->getSecciones();
	su4se = su4->getSecciones();
	su5se = su5->getSecciones();
	su6se = su6->getSecciones();
	su7se = su7->getSecciones();

	su1se->add(se1);
	su1se->add(se2);
	su1se->add(se3);
	su1se->add(se4);
	su1se->add(se5);

	su2se->add(se6);
	su2se->add(se7);
	su2se->add(se8);
	su2se->add(se9);
	su2se->add(se10);

	su3se->add(se11);
	su3se->add(se12);
	su3se->add(se13);

	su4se->add(se14);
	su4se->add(se15);
	su4se->add(se16);

	su5se->add(se17);
	su5se->add(se18);
	su5se->add(se19);

	su6se->add(se20);
	su6se->add(se21);

	su7se->add(se22);
	su7se->add(se23);

	// cargar encargados
	se1->setEncargado(new Encargado("3156454","Alberto","Garcia",new Date(10, 02, 1980)));
	se2->setEncargado(new Encargado("1975324","Florencia","Estevez",new Date(05,03, 1968)));
	se3->setEncargado(new Encargado("4568983","Joaquin","Torres",new Date(08, 09, 1985)));
	se4->setEncargado(new Encargado("2654998","Jenifer","Normendi",new Date(10, 12, 1974)));
	se5->setEncargado(new Encargado("3598756","Esteban","Sanchez",new Date(01, 01, 1980)));
	se6->setEncargado(new Encargado("2987656","Luis","Souza",new Date(03, 02, 1972)));
	se7->setEncargado(new Encargado("4864321","Maria","Alonso",new Date(04, 04, 1987)));
	se8->setEncargado(new Encargado("3246898","Camila","Ferrer",new Date(08, 01, 1980)));
	se9->setEncargado(new Encargado("2165489","Nicolas","Soler",new Date(09, 12, 1977)));
	se10->setEncargado(new Encargado("3216549","Guadalupe","Vila",new Date(10, 10, 1980)));
	se11->setEncargado(new Encargado("2165498","Bruno","Luna",new Date(12, 12, 1974)));
	se12->setEncargado(new Encargado("2315649","Daniel","Castro",new Date(18, 06, 1974)));
	se13->setEncargado(new Encargado("1924568","Natalia","Martinez",new Date(15, 07, 1966)));
	se14->setEncargado(new Encargado("2216578","Emilia","Ruiz",new Date(10, 03, 1971)));
	se15->setEncargado(new Encargado("2165498","Ivana","Herrera",new Date(04, 12, 1970)));
	se16->setEncargado(new Encargado("1895432","Lucas","Pereira",new Date(16, 10, 1963)));
	se17->setEncargado(new Encargado("3216548","Adrian","Moreno",new Date(05, 05, 1980)));
	se18->setEncargado(new Encargado("1489623","Laura","Pereira",new Date(01, 12, 1964)));
	se19->setEncargado(new Encargado("4231568","Benjamin","Gomez",new Date(20, 03, 1984)));
	se20->setEncargado(new Encargado("4123465","Mia","Costa",new Date(31, 12, 1988)));
	se21->setEncargado(new Encargado("3216585","Alejandro","Roche",new Date(30, 08, 1976)));
	se22->setEncargado(new Encargado("3333112","Paula","Guelbenzu",new Date(16, 06, 1975)));
	se23->setEncargado(new Encargado("1999532","Antonia","Stroustrup",new Date(20, 02, 1969)));





	// cargar asignaturas

	// cargar aprobaciones

	// cargar ofertas

	// cargar carreras

	// cargar carreras_estudiantes

	// cargar estudiantes

	// cargar asignaturas_requeridas_oferta

}

// constructor
cmdCargarDatosDePrueba::cmdCargarDatosDePrueba()
{

}

// destructor
cmdCargarDatosDePrueba::~cmdCargarDatosDePrueba()
{

}
