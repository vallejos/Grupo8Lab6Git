#include <iostream>
#include <string>
#include "cmdCargarDatosDePrueba.h"
#include "interfaces/IDictionary.h"
#include "interfaces/ICollection.h"
#include "ManejadorEmpresa.h"
#include "ManejadorEstudiante.h"
#include "ManejadorOfertaLaboral.h"
#include "Empresa.h"
#include "Sucursal.h"
#include "Asignatura.h"
#include "Carrera.h"
#include "Date.h"
#include "Aprobacion.h"
#include "Estudiante.h"
#include "Seccion.h"
#include "Encargado.h"
#include "OfertaLaboral.h"
#include "Integer.h"
#include "String.h"
#include <stdio.h>
#include "IObserver.h"

using namespace std;

// cmdCargarDatosDePrueba
void cmdCargarDatosDePrueba::ejecutarComando()
{
	ManejadorEmpresa *me = ManejadorEmpresa::getInstance();
	ManejadorEstudiante *mest = ManejadorEstudiante::getInstance();
	ManejadorOfertaLaboral *mol = ManejadorOfertaLaboral::getInstance();

// CARGA: EMPRESAS
	IDictionary *empresas = me->getEmpresas();
	Empresa *e1, *e2, *e3, *e4, *e5;

	e1 = new Empresa("1112335684", "Segurol S.A.");
	e2 = new Empresa("1298865497","RoboTI");
	e3 = new Empresa("1265498765","MiniSoft Uy");
	e4 = new Empresa("5464897986","Ingenieros Electricos Unidos");
	e5 = new Empresa("1326548654","Academia Yotexplico");
        
	empresas->add(new String("1112335684"), e1);
	empresas->add(new String("1298865497"), e2);
	empresas->add(new String("1265498765"), e3);
	empresas->add(new String("5464897986"), e4);
	empresas->add(new String("1326548654"), e5);

// CARGA: SUCURSALES
	IDictionary *sue1, *sue2, *sue3, *sue4, *sue5;

	sue1 = e1->getSucursales();
	sue2 = e2->getSucursales();
	sue3 = e3->getSucursales();
	sue4 = e4->getSucursales();
	sue5 = e5->getSucursales();

	Sucursal *su1, *su2, *su3, *su4, *su5, *su6, *su7;

	su1 = new Sucursal("Casa central","Ciudad Vieja","24598765", NULL, e1);
	su2 = new Sucursal("Sucursal comercial","Malvin","25225323", NULL, e2);
	su3 = new Sucursal("Sucursal San Carlos","San Carlos","42668350", NULL, e2);
	su4 = new Sucursal("Sede Montevideo","Buceo","25468932", NULL, e3);
	su5 = new Sucursal("Sede Ciudad de la Costa","Solymar","43764232", NULL, e3);
	su6 = new Sucursal("Oficina central","Centro","25495878", NULL, e4);
	su7 = new Sucursal("Academia","Parque Rodo","24594565", NULL, e5);

	sue1->add(new String("Casa central"), su1);
	sue2->add(new String("Sucursal comercial"), su2);
	sue2->add(new String("Sucursal San Carlos"), su3);
	sue3->add(new String("Sede Montevideo"), su4);
	sue3->add(new String("Sede Ciudad de la Costa"), su5);
	sue4->add(new String("Oficina central"), su6);
	sue5->add(new String("Academia"), su7);

// CARGA: SECCIONES
	Seccion *se1, *se2, *se3, *se4, *se5, *se6, *se7, *se8, *se9, *se10, *se11, *se12, *se13, *se14, *se15,
			*se16, *se17, *se18, *se19, *se20, *se21, *se22, *se23;

	se1 = new Seccion("Contaduria","101", NULL);
	se2 = new Seccion("Recursos humanos","102", NULL);
	se3 = new Seccion("Recepcion","103", NULL);
	se4 = new Seccion("Desarrollo","104", NULL);
	se5 = new Seccion("Pentesting","105", NULL);
	se6 = new Seccion("Marketing","1201", NULL);
	se7 = new Seccion("Atencion al cliente","1202", NULL);
	se8 = new Seccion("Tesoreria","1203", NULL);
	se9 = new Seccion("Ventas","1204", NULL);
	se10 = new Seccion("Seccion tecnica","1205", NULL);
	se11 = new Seccion("Seccion tecnica","1009", NULL);
	se12 = new Seccion("I+D","1008", NULL);
	se13 = new Seccion("Recepcion","1000", NULL);
	se14 = new Seccion("Secretaria","100", NULL);
	se15 = new Seccion("Desarrollo","1001", NULL);
	se16 = new Seccion("Testing","1002", NULL);
	se17 = new Seccion("Secretaria","100", NULL);
	se18 = new Seccion("Desarrollo","1001", NULL);
	se19 = new Seccion("Testing","1002", NULL);
	se20 = new Seccion("Laboratorio","10", NULL);
	se21 = new Seccion("Atencion comercial","11", NULL);
	se22 = new Seccion("Direccion","101", NULL);
	se23 = new Seccion("Inscripciones","102", NULL);

	IDictionary *su1se, *su2se, *su3se, *su4se, *su5se, *su6se, *su7se;

	su1se = su1->getSecciones();
	su2se = su2->getSecciones();
	su3se = su3->getSecciones();
	su4se = su4->getSecciones();
	su5se = su5->getSecciones();
	su6se = su6->getSecciones();
	su7se = su7->getSecciones();

        se1->setSucursal(su1);
        se2->setSucursal(su1);
        se3->setSucursal(su1);
        se4->setSucursal(su1);
        se5->setSucursal(su1);
	su1se->add(new String("Contaduria"), se1);
	su1se->add(new String("Recursos humanos"), se2);
	su1se->add(new String("Recepcion"), se3);
	su1se->add(new String("Desarrollo"), se4);
	su1se->add(new String("Pentesting"), se5);

        se6->setSucursal(su2);
        se7->setSucursal(su2);
        se8->setSucursal(su2);
        se9->setSucursal(su2);
        se10->setSucursal(su2);
	su2se->add(new String("Marketing"), se6);
	su2se->add(new String("Atencion al cliente"), se7);
	su2se->add(new String("Tesoreria"), se8);
	su2se->add(new String("Ventas"), se9);
	su2se->add(new String("Seccion tecnica"), se10);

        se11->setSucursal(su3);
        se12->setSucursal(su3);
        se13->setSucursal(su3);
	su3se->add(new String("Seccion tecnica"), se11);
	su3se->add(new String("I+D"), se12);
	su3se->add(new String("Recepcion"), se13);

        se14->setSucursal(su4);
        se15->setSucursal(su4);
        se16->setSucursal(su4);
	su4se->add(new String("Secretaria"), se14);
	su4se->add(new String("Desarrollo"), se15);
	su4se->add(new String("Testing"), se16);

        se17->setSucursal(su5);
        se18->setSucursal(su5);
        se19->setSucursal(su5);
	su5se->add(new String("Secretaria"), se17);
	su5se->add(new String("Desarrollo"), se18);
	su5se->add(new String("Testing"), se19);

        se20->setSucursal(su6);
        se21->setSucursal(su6);
	su6se->add(new String("Laboratorio"), se20);
	su6se->add(new String("Atencion comercial"), se21);

        se22->setSucursal(su7);
        se23->setSucursal(su7);
	su7se->add(new String("Direccion"), se22);
	su7se->add(new String("Inscripciones"), se23);

// CARGA: ENCARGADOS
	se1->setEncargado(new Encargado("3156454","Alberto","Garcia",new Date(10, 2, 1980)));
	se2->setEncargado(new Encargado("1975324","Florencia","Estevez",new Date(5, 3, 1968)));
	se3->setEncargado(new Encargado("4568983","Joaquin","Torres",new Date(8, 9, 1985)));
	se4->setEncargado(new Encargado("2654998","Jenifer","Normendi",new Date(10, 12, 1974)));
	se5->setEncargado(new Encargado("3598756","Esteban","Sanchez",new Date(1, 1, 1980)));
	se6->setEncargado(new Encargado("2987656","Luis","Souza",new Date(3, 2, 1972)));
	se7->setEncargado(new Encargado("4864321","Maria","Alonso",new Date(4, 4, 1987)));
	se8->setEncargado(new Encargado("3246898","Camila","Ferrer",new Date(8, 1, 1980)));
	se9->setEncargado(new Encargado("2165489","Nicolas","Soler",new Date(9, 12, 1977)));
	se10->setEncargado(new Encargado("3216549","Guadalupe","Vila",new Date(10, 10, 1980)));
	se11->setEncargado(new Encargado("2165498","Bruno","Luna",new Date(12, 12, 1974)));
	se12->setEncargado(new Encargado("2315649","Daniel","Castro",new Date(18, 6, 1974)));
	se13->setEncargado(new Encargado("1924568","Natalia","Martinez",new Date(15, 7, 1966)));
	se14->setEncargado(new Encargado("2216578","Emilia","Ruiz",new Date(10, 3, 1971)));
	se15->setEncargado(new Encargado("2165498","Ivana","Herrera",new Date(4, 12, 1970)));
	se16->setEncargado(new Encargado("1895432","Lucas","Pereira",new Date(16, 10, 1963)));
	se17->setEncargado(new Encargado("3216548","Adrian","Moreno",new Date(5, 5, 1980)));
	se18->setEncargado(new Encargado("1489623","Laura","Pereira",new Date(1, 12, 1964)));
	se19->setEncargado(new Encargado("4231568","Benjamin","Gomez",new Date(20, 3, 1984)));
	se20->setEncargado(new Encargado("4123465","Mia","Costa",new Date(31, 12, 1988)));
	se21->setEncargado(new Encargado("3216585","Alejandro","Roche",new Date(30, 8, 1976)));
	se22->setEncargado(new Encargado("3333112","Paula","Guelbenzu",new Date(16, 6, 1975)));
	se23->setEncargado(new Encargado("1999532","Antonia","Stroustrup",new Date(20, 2, 1969)));

//CARGA: OFERTAS LABORALES
    IDictionary *ofertas = mol->getOfertasLaborales();
    OfertaLaboral *o1, *o2, *o3, *o4;

    o1 = se2->addOferta("45896", "Auditor de seguridad part-time junior", "Segurol S.A. busca estudiantes de Ingenieria en Computacion para unirse a su equipo. Se requiere un nivel minimo de conocimiento en seguridad informatica y programacion. Interesados enviar cv a oportunidades@segurol.com.uy",
                        20, new Rango(2000, 3000), new Date(1, 6, 2015), new Date(20, 7, 2015), 5, NULL);
    o2 = se10->addOferta("12356", "Ayudante de Ingeniero", "Estamos buscando estudiantes avanzados de Ingenieria Electrica con perfil potencia. Es imprescindible tener disponibilidad para viajar al interior del pais una vez por mes. Se pagan viaticos ademas de sueldo. Llamar al 25225323 int 1205 para mas detalles.",
                        30, new Rango(4000, 5000), new Date(20, 5, 2015), new Date(30, 6, 2015), 2, NULL);
    o3 = se15->addOferta("88890", "Desarrollador C++", "Buscamos desarrollador C++ para importante proyecto internacional. Llenar formulario con datos personales y cv en minisoft.uy/careers.",
                        40, new Rango(5000, 6000), new Date(5, 6, 2015), new Date(6, 8, 2015), 4, NULL);
    o4 = se22->addOferta("49563", "Estudiantes para dictar clases de Calculo I y II", "Buscamos estudiantes de Ingenieria con Calculo 1 y 2 aprobadas. Deben tener disponibilidad horaria y gusto por enseñar. Enviar mail a academiayotexplico@gmail.com.",
                        5, new Rango(500, 2000), new Date(10, 9, 2015), new Date(20, 12, 2015), 10, NULL);
    o1->setSeccion(se2);
    o2->setSeccion(se10);
    o3->setSeccion(se15);
    o4->setSeccion(se22);

    ofertas->add(new String("45896"), o1);
    ofertas->add(new String("12356"), o2);
    ofertas->add(new String("88890"), o3);
    ofertas->add(new String("49563"), o4);

//CARGA: ESTUDIANTES
	IDictionary *estudiantes = mest->getEstudiantes ();
	Estudiante *es1, *es2, *es3, *es4, *es5, *es6, *es7, *es8, *es9, *es10, *es11, *es12;

	es1 = new Estudiante("4516231", "Esteban", "Perez", "099111222", new Date(10, 2, 1990), 56, "esteban.perez@fing.edu.uy", NULL, NULL, NULL, NULL, NULL);
	es2 = new Estudiante("5111235", "Felipe", "Garcia", "24035612", new Date(20, 8, 1992), 47, "felipe.garcia@fing.edu.uy", NULL, NULL, NULL, NULL, NULL);
	es3 = new Estudiante("3594561", "Juan", "Wolf", "091222223", new Date(30, 1, 1980), 146, "juan.wolf@fing.edu.uy", NULL, NULL, NULL, NULL, NULL);
	es4 = new Estudiante("2784531", "Alfonsina", "Ramirez", "43712345", new Date(5, 6, 1975), 22, "alfonsina.ramirez@fing.edu.uy", NULL, NULL, NULL, NULL, NULL);
	es5 = new Estudiante("1956234", "Hector", "Otonello", "098334456", new Date(10, 10, 1969), 52, "hector.otonello@fing.edu.uy", NULL, NULL, NULL, NULL, NULL);
	es6 = new Estudiante("5005684", "Lorena", "Nuñez", "092659878", new Date(3, 1, 1994), 0, "lorena.nuñez@fing.edu.uy", NULL, NULL, NULL, NULL, NULL);
	es7 = new Estudiante("4686231", "Hector", "Lorenzo", "21656498", new Date(9, 3, 1993), 26, "hector.lorenzo@fing.edu.uy", NULL, NULL, NULL, NULL, NULL);
	es8 = new Estudiante("4987623", "Julio", "Lee", "26984899", new Date(5, 8, 1992), 110, "julio.lee@fing.edu.uy", NULL, NULL, NULL, NULL, NULL);
	es9 = new Estudiante("4986313", "Rodrigo", "Fernandez", "22233346", new Date(7, 9, 1990), 16, "rodrigo.fernandez@fing.edu.uy", NULL, NULL, NULL, NULL, NULL);
	es10 = new Estudiante("3659532", "Noelia", "Pereira", "099112233", new Date(2, 9, 1990), 38, "noelia.pereira@fing.edu.uy", NULL, NULL, NULL, NULL, NULL);
	es11 = new Estudiante("3665492", "Cecilia", "Garrido", "094698568", new Date(30, 3, 1984), 112, "cecilia.garrido@fing.edu.uy", NULL, NULL, NULL, NULL, NULL);
	es12 = new Estudiante("3335689", "Roman", "Gul", "096677889", new Date(9, 12, 1983), 32, "roman.gul@fing.edu.uy", NULL, NULL, NULL, NULL, NULL);

    //las carreras y las aprobadas son cargadas más abajo (al final)
    //los creditos se calcularon y se ingresaron en base a las aprobadas que se cargan despues
	estudiantes->add(new String("4516231"), es1);
	estudiantes->add(new String("5111235"), es2);
	estudiantes->add(new String("3594561"), es3);
	estudiantes->add(new String("2784531"), es4);
	estudiantes->add(new String("1956234"), es5);
	estudiantes->add(new String("5005684"), es6);
	estudiantes->add(new String("4686231"), es7);
	estudiantes->add(new String("4987623"), es8);
	estudiantes->add(new String("4986313"), es9);
	estudiantes->add(new String("3659532"), es10);
	estudiantes->add(new String("3665492"), es11);
	estudiantes->add(new String("3335689"), es12);

// CARGA: CARRERAS
	IDictionary *carreras = mest->getCarreras();
	Carrera *c1, *c2;

	c1= new Carrera(1010, "Ingenieria Electrica");
	c2= new Carrera(1011, "Ingenieria en Computacion");

	carreras->add(new Integer(1010), c1);
	carreras->add(new Integer(1011), c2);

// CARGA: ASIGNATURAS
    IDictionary *asignaturas = mest->getAsignaturas();
    Asignatura *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8, *a9, *a10, *a11, *a12, *a13, *a14, *a15;

    a1 = new Asignatura(1686, "Calculo I", 16);
    a2 = new Asignatura(6598, "Programacion 1",10);
    a3 = new Asignatura(5698, "Programacion 2",12);
    a4 = new Asignatura(4875, "Programacion 3",15);
    a5 = new Asignatura(1689, "Calculo II",16);
    a6 = new Asignatura(8683, "Electromagnetismo",12);
    a7 = new Asignatura(6943, "Bases de datos",15);
    a8 = new Asignatura(6879, "Redes de computadoras",12);
    a9 = new Asignatura(3216, "Ecuaciones diferenciales",12);
    a10 = new Asignatura(9171, "Fundamentos de seguridad informatica",12);
    a11 = new Asignatura(1698, "Robotica basada en comportamientos",15);
    a12 = new Asignatura(6416, "Ciencia tecnologia y sociedad",8);
    a13 = new Asignatura(6587, "Proyecto de Ingenieria de software",15);
    a14 = new Asignatura(5498, "Arquitectura de computadoras",12);
    a15 = new Asignatura(1889, "Taller de programacion",15);

    asignaturas->add(new Integer(1686), a1);
    asignaturas->add(new Integer(6598), a2);
    asignaturas->add(new Integer(5698), a3);
    asignaturas->add(new Integer(4875), a4);
    asignaturas->add(new Integer(1689), a5);
    asignaturas->add(new Integer(8683), a6);
    asignaturas->add(new Integer(6943), a7);
    asignaturas->add(new Integer(6879), a8);
    asignaturas->add(new Integer(3216), a9);
    asignaturas->add(new Integer(9171), a10);
    asignaturas->add(new Integer(1698), a11);
    asignaturas->add(new Integer(6416), a12);
    asignaturas->add(new Integer(6587), a13);
    asignaturas->add(new Integer(5498), a14);
    asignaturas->add(new Integer(1889), a15);

    IDictionary *a1c, *a2c, *a3c, *a4c, *a5c, *a6c, *a7c, *a8c, *a9c, *a10c, *a11c, *a12c, *a13c, *a14c, *a15c;

    a1c = a1->getCarreras();
    a2c = a2->getCarreras();
    a3c = a3->getCarreras();
    a4c = a4->getCarreras();
    a5c = a5->getCarreras();
    a6c = a6->getCarreras();
    a7c = a7->getCarreras();
    a8c = a8->getCarreras();
    a9c = a9->getCarreras();
    a10c = a10->getCarreras();
    a11c = a11->getCarreras();
    a12c = a12->getCarreras();
    a13c = a13->getCarreras();
    a14c = a14->getCarreras();
    a15c = a15->getCarreras();

    a1c->add(new Integer(1010), c1);
    a1c->add(new Integer(1011), c2);
    a2c->add(new Integer(1010), c1);
    a2c->add(new Integer(1011), c2);
    a3c->add(new Integer(1011), c2);
    a4c->add(new Integer(1011), c2);
    a5c->add(new Integer(1010), c1);
    a5c->add(new Integer(1011), c2);
    a6c->add(new Integer(1010), c1);
    a7c->add(new Integer(1011), c2);
    a8c->add(new Integer(1011), c2);
    a9c->add(new Integer(1010), c1);
    a10c->add(new Integer(1011), c2);
    a11c->add(new Integer(1010), c1);
    a11c->add(new Integer(1011), c2);
    a12c->add(new Integer(1010), c1);
    a12c->add(new Integer(1011), c2);
    a13c->add(new Integer(1011), c2);
    a14c->add(new Integer(1011), c2);
    a15c->add(new Integer(1011), c2);

    IDictionary *c1a, *c2a;

    c1a = c1->getAsignaturas();
    c2a = c2->getAsignaturas();

    c1a->add(new Integer(1686), a1);
    c1a->add(new Integer(6598), a2);
    c1a->add(new Integer(1689), a5);
    c1a->add(new Integer(8683), a6);
    c1a->add(new Integer(3216), a9);
    c1a->add(new Integer(1698), a11);
    c1a->add(new Integer(6416), a12);
    c2a->add(new Integer(1686), a1);
    c2a->add(new Integer(6598), a2);
    c2a->add(new Integer(5698), a3);
    c2a->add(new Integer(4875), a4);
    c2a->add(new Integer(1689), a5);
    c2a->add(new Integer(6943), a7);
    c2a->add(new Integer(6879), a8);
    c2a->add(new Integer(9171), a10);
    c2a->add(new Integer(1698), a11);
    c2a->add(new Integer(6416), a12);
    c2a->add(new Integer(6587), a13);
    c2a->add(new Integer(5498), a14);
    c2a->add(new Integer(1889), a15);

// CARGA: ASIGNATURAS REQUERIDAS POR OFERTAS
    IDictionary *o1a, *o2a, *o3a, *o4a;

    o1a = o1->getAsignaturas();
    o2a = o2->getAsignaturas();
    o3a = o3->getAsignaturas();
    o4a = o4->getAsignaturas();

    o1a->add(new Integer(6598), a2);
    o1a->add(new Integer(5698), a3);
    o1a->add(new Integer(4875), a4);
    o1a->add(new Integer(9171), a10);
    o2a->add(new Integer(8683), a6);
    o2a->add(new Integer(3216), a9);
    o3a->add(new Integer(6598), a2);
    o3a->add(new Integer(5698), a3);
    o3a->add(new Integer(4875), a4);
    o3a->add(new Integer(6943), a7);
    o3a->add(new Integer(6587), a13);
    o3a->add(new Integer(1889), a15);
    o4a->add(new Integer(1686), a1);
    o4a->add(new Integer(1689), a5);

// CARGA: APROBACIONES
    ICollection *ap1,*ap2, *ap3, *ap4, *ap5, *ap7, *ap8, *ap9, *ap10, *ap11, *ap12;

    ap1 = es1->getAprobadas();
    ap2 = es2->getAprobadas();
    ap3 = es3->getAprobadas();
    ap4 = es4->getAprobadas();
    ap5 = es5->getAprobadas();
    ap7 = es7->getAprobadas();
    ap8 = es8->getAprobadas();
    ap9 = es9->getAprobadas();
    ap10 = es10->getAprobadas();
    ap11 = es11->getAprobadas();
    ap12 = es12->getAprobadas();

    ap1->add(new Aprobacion(new Date(10, 11, 2013), 8, a1));
    ap1->add(new Aprobacion(new Date(20, 8, 2014), 5, a5));
    ap1->add(new Aprobacion(new Date(12, 11, 2014), 10, a6));
    ap1->add(new Aprobacion(new Date(10, 12, 2014), 11, a9));
    ap2->add(new Aprobacion(new Date(10, 6, 2014), 9, a2));
    ap2->add(new Aprobacion(new Date(15, 6, 2014), 12, a3));
    ap2->add(new Aprobacion(new Date(2, 2, 2015), 7, a4));
    ap2->add(new Aprobacion(new Date(11, 8, 2014), 6, a12));
    ap3->add(new Aprobacion(new Date(20, 7, 2005), 3, a1));
    ap3->add(new Aprobacion(new Date(12, 12, 2005), 10, a2));
    ap3->add(new Aprobacion(new Date(30, 7, 2006), 9, a3));
    ap3->add(new Aprobacion(new Date(2, 2, 2007), 7, a4));
    ap3->add(new Aprobacion(new Date(10, 12, 2007), 8, a5));
    ap3->add(new Aprobacion(new Date(5, 12, 2008), 10, a7));
    ap3->add(new Aprobacion(new Date(15, 12, 2008), 11, a8));
    ap3->add(new Aprobacion(new Date(12, 2, 2009), 8, a12));
    //ap3->add(new Aprobacion(new Date(20, 11, 2010), 10, a13));
    ap3->add(new Aprobacion(new Date(15, 11, 2007), 6, a14));
    ap3->add(new Aprobacion(new Date(25, 11, 2009), 10, a15));
    ap4->add(new Aprobacion(new Date(10, 6, 2010), 8, a2));
    ap4->add(new Aprobacion(new Date(30, 7, 2010), 6, a3));
    ap5->add(new Aprobacion(new Date(10, 11, 1993), 3, a1));
    ap5->add(new Aprobacion(new Date(20, 8, 1994), 3, a5));
    ap5->add(new Aprobacion(new Date(10, 12, 1994), 10, a9));
    ap5->add(new Aprobacion(new Date(11, 8, 1995), 12, a12));
    ap7->add(new Aprobacion(new Date(10, 11, 2013), 10, a1));
    ap7->add(new Aprobacion(new Date(10, 6, 2014), 8, a2));
    ap8->add(new Aprobacion(new Date(10, 7, 2011), 8, a1));
    ap8->add(new Aprobacion(new Date(10, 11, 2011), 7, a2));
    ap8->add(new Aprobacion(new Date(30, 7, 2012), 10, a3));
    ap8->add(new Aprobacion(new Date(25, 11, 2012), 9, a4));
    ap8->add(new Aprobacion(new Date(5, 12, 2013), 10, a7));
    ap8->add(new Aprobacion(new Date(15, 12, 2013), 12, a8));
    ap8->add(new Aprobacion(new Date(15, 11, 2014), 12, a11));
    ap8->add(new Aprobacion(new Date(25, 11, 2013), 10, a15));
    ap9->add(new Aprobacion(new Date(10, 11, 2014), 5, a1));
    ap10->add(new Aprobacion(new Date(10, 11, 2007), 8, a1));
    ap10->add(new Aprobacion(new Date(10, 6, 2008), 9, a2));
    ap10->add(new Aprobacion(new Date(30, 7, 2009), 3, a3));
    ap11->add(new Aprobacion(new Date(10, 11, 2003), 4, a1));
    ap11->add(new Aprobacion(new Date(10, 6, 2004), 5, a2));
    ap11->add(new Aprobacion(new Date(30, 7, 2004), 10, a3));
    ap11->add(new Aprobacion(new Date(2, 2, 2005), 8, a4));
    ap11->add(new Aprobacion(new Date(20, 8, 2004), 7, a5));
    ap11->add(new Aprobacion(new Date(12, 11, 2005), 10, a6));
    ap11->add(new Aprobacion(new Date(4, 12, 2005), 9, a7));
    ap12->add(new Aprobacion(new Date(10, 11, 2003), 7, a1));
    ap12->add(new Aprobacion(new Date(10, 12, 2003), 8, a5));

// CARGA: CARRERAS_ESTUDIANTES
    IDictionary *car1,*car2, *car3, *car4, *car5, *car6, *car7, *car8, *car9, *car10, *car11, *car12;

    car1 = es1->getCarreras();
    car2 = es2->getCarreras();
    car3 = es3->getCarreras();
    car4 = es4->getCarreras();
    car5 = es5->getCarreras();
    car6 = es6->getCarreras();
    car7 = es7->getCarreras();
    car8 = es8->getCarreras();
    car9 = es9->getCarreras();
    car10 = es10->getCarreras();
    car11 = es11->getCarreras();
    car12 = es12->getCarreras();

    car1->add(new Integer(1010), c1);
    car2->add(new Integer(1011), c2);
    car3->add(new Integer(1011), c2);
    car4->add(new Integer(1011), c2);
    car5->add(new Integer(1010), c1);
    car6->add(new Integer(1010), c1);
    car7->add(new Integer(1010), c1);
    car8->add(new Integer(1011), c2);
    car9->add(new Integer(1010), c1);
    car9->add(new Integer(1011), c2);
    car10->add(new Integer(1011), c2);
    car11->add(new Integer(1010), c1);
    car11->add(new Integer(1011), c2);
    car12->add(new Integer(1010), c1);

    cout << "\nDatos cargados correctamente!\n\n";
    
}

// constructor
cmdCargarDatosDePrueba::cmdCargarDatosDePrueba()
{

}

// destructor
cmdCargarDatosDePrueba::~cmdCargarDatosDePrueba()
{

}
