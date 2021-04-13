#ifndef NOTA_H
#define NOTA_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include "Criterio.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;


class Nota{

private:
	Criterio criterio;
	string observacion1, observacion2;
	double notaJuradoUno;
	double notaJuradoDos;
	

public:
	Nota();  
	Nota(Criterio, string, string, double, double);  
	void crearNota(int idNota);  
	void mostrarNota(); 
	double getNotaJuradoUno();  
	double getNotaJuradoDos();  
	double getPorcentajeNota(); 
  	string getObservacionJuradoUno();
  	string getObservacionJuradoDos();

};

#endif
