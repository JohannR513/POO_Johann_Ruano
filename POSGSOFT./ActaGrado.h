#ifndef ACTAGRADO_H
#define ACTAGRADO_H

#include <iostream>
#include <stdlib.h>
#include "Persona.h"
#include "Nota.h"
#include <list>
#include <fstream>

using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;



class ActaGrado{

private:
	int numeroActa;
	string fechaAct, nombreTrabajo, tipoTrabajo, periodo, estadoActa, comentarioAprobacion;
	Persona autor, director, codirector, juradoUno, juradoDos;
	bool existeCodirector = false;
	double notaFinal;
	list<Nota> listaNotas;



public:
	ActaGrado();  
  	ActaGrado( int, string, Persona, string, string, string, Persona, Persona, Persona, Persona, string, double );
  	void crearActa( int numeroActa );
  	void agregarCriterio();
	void mostrarNotas();
	void calcularNotaFinal();
	void setComentarioAprobacion();
	string getTipoTrabajo();
	string getNombreDirector();
	string getNombrejuradoUno();
	string getNombrejuradoDos();
	void cerrarActa();
	double getNotaDefinitiva();
	string getComentarioAprobacion();
	int getNumeroActa();
	void visualizarActa();
	void crearTxtActa();
    	string getEstadoActa();
 	void crearTxtActaCerrada();
  	int getIdjuradoUno();
	int getIdjuradoDos();
	string getEstadoProyecto();
	string getRoljuradoUno();
	string getRoljuradoDos();
  	void mostrarCriteriosEvaluacion();
}; 

#endif
