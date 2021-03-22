#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <stdlib.h>

using std::string;
using std::cin;
using std::cout;
using std::endl;


class Persona{

private:
	string nombre;
	string apellido;
	string correoElectronico;
	int id;
	int telefono;
	enum rolPersona { Director = 1, Codirector = 2, Estudiante = 3, Jurado = 4 }; 
  rolPersona rol;

public:
	Persona(); 
	Persona( string, string, string, int, int, rolPersona );  
	void crearPersona( int opcion1 );   
	void mostrarPersona();  

};

#endif