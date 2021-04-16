#ifndef REGISTROACTA_H
#define REGISTROACTA_H

#include <iostream>
#include <stdlib.h>
#include "ActaGrado.h"
#include <list>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::list;


class RegistroActa{

private:
	list<ActaGrado> listaActas;
	

public:
	RegistroActa();  
	void guardarActas();  
	void visualizarActas(); 
	void eliminarActa();  
	void cerrarActaTotal();  
  	void modificarActa();
	void cantTrabajosAplicado(); 
	void cantTrabajosInvestigacion(); 
	void cantTrabajosDirigidos(); 
	void cantTrabajosJurado(); 
	void participacionJurado(); 
	void juradosInternos(); 
	void juradosExternos(); 
	void mostrarCriteriosActa(); 
};

#endif
