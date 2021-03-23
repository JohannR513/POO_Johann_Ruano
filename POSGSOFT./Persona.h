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
  string rol;
	//enum rolPersona { Director = 1, Codirector = 2, Estudiante = 3, Jurado = 4 }; 
  //rolPersona rol;

public:
	Persona(); 
	Persona( string, string, string, int, int, string );  
	void crearPersona( int opcion1 );   
	void mostrarPersona();  
  	string getNombre();
	void setNombre( string nombre );
	string getApellido();
	void setApellidos( string apellido );
	void setRolPersona( string rol );
  	string getRolPersona();
	int getIdPersona();
};

#endif
