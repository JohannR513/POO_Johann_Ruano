#ifndef CRITERIO_H
#define CRITERIO_H

#include <iostream>
#include <stdlib.h>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;


class Criterio{

private:
	int idCriterio;
	double porcentajeNota;
	string observaciones;

public:
	Criterio();  
	Criterio( int, double, string );  
	void crearCriterio( int idCriterio );  
	void mostrarCriterio();  
	double getPorcentajeNota();
 
};

#endif