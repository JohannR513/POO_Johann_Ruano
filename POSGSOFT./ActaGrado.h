#ifndef ACTAGRADO_H
#define ACTAGRADO_H

#include <iostream>
#include <stdlib.h>
#include "Persona.h"
#include "Nota.h"
#include <list>

using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;



class ActaGrado{

private:
	int numeroActa;
	string fechaAct, nombreTrabajo, tipoTrabajo, periodo, estadoActa, estadoProyecto, comentarioAprobacion;
	Persona autor, director, codirector, juradoUno, juradoDos;
	bool existeCodirector = false;
	double notaFinal;
	list<Nota> listaNotas;



public:
	ActaGrado();  
  ActaGrado( int, string, Persona, string, string, string, Persona, Persona, Persona, Persona, string, string, string, string, double );
  void crearActa( int numeroActa );
}; 

#endif