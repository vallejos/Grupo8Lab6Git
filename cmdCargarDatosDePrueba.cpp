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
	Sucursal *su1, *su2, *su3, *su4, *su5, *su6, *su7;

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
	e1->getDataSucursales()->add(new Sucursal(Casa central,24598765,Ciudad Vieja));
	e2->getDataSucursales()->add(new Sucursal(Sucursal comercial,25225323,Malvin));
	e2->getDataSucursales()->add(new Sucursal(Sucursal San Carlos,42668350,San Carlos));
	e2->getDataSucursales()->add(new Sucursal(Sucursal San Carlos,42668350,San Carlos));
	e3->getDataSucursales()->add(new Sucursal(Sede Montevideo,25468932,Buceo));
	e3->getDataSucursales()->add(new Sucursal(Sede Ciudad de la Costa,43764232,Solymar));
	e4->getDataSucursales()->add(new Sucursal(Oficina central,25495878,Centro));
	e5->getDataSucursales()->add(new Sucursal(Academia,24594565,Parque Rodo));


/*
Casa central,24598765,Ciudad Vieja,E1
Sucursal comercial,25225323,Malvin,E2
Sucursal San Carlos,42668350,San Carlos,E2
Sede Montevideo,25468932,Buceo,E3
Sede Ciudad de la Costa,43764232,Solymar,E3
Oficina central,25495878,Centro,E4
Academia,24594565,Parque Rodo,E5/*


	// cargar secciones

	// cargar encargados


}

// constructor
cmdCargarDatosDePrueba::cmdCargarDatosDePrueba()
{

}

// destructor
cmdCargarDatosDePrueba::~cmdCargarDatosDePrueba()
{

}
