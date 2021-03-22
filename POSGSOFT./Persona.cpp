#include "Persona.h"


Persona::Persona(){
}


Persona::Persona( string nombre, string apellido, string correoElectronico, int id, int telefono, rolPersona rol){
	this -> nombre = nombre;
	this->apellido = apellido;
	this->correoElectronico = correoElectronico;
	this->id = id;
	this->telefono = telefono;
	this->rol = rol;
}


void Persona::crearPersona( int opcion1 ){  
	int opcionJurado;   
	int salida = 1;  
	int temp; 
	fflush( stdin );
	cout << " Escribe tu(s) nombre(s): " << endl;
	getline( cin, nombre );  

	fflush(stdin);
	cout << " Escribe tu(s) apellido(s): " << endl;
	getline( cin, apellido );
	fflush( stdin );

	fflush( stdin );
	cout << " Escribe tu correo correo electronico: " << endl;
	getline(cin, correoElectronico);
	fflush( stdin );

	fflush( stdin );
	cout << " Digita tu identificacion: " << endl;
	cin >> id;
	fflush( stdin );
	
	fflush(stdin);
	cout << " Digita tu numero de telefono: " << endl;
	cin >> telefono;
	fflush( stdin );
 	
 	
	if(opcion1 == 1){
		rolPersona = "Director";
	}
	else if(opcion1 == 2){
		rolPersona = "Codirector";
	}
	else if(opcion1 == 3){
		rolPersona = "Estudiante";
	}
	else if(opcion1 == 4){
		while(salida == 1){
			cout << " Digite: \n 1. Si es jurado interno\n 2. Si es jurado externo\n" << endl;  
			cin >> opcionJurado;
			if(opcionJurado < 1){
				cout << " Error!, esta no es una opcion valida" << endl; 
				salida == 1;
			}
			else if(opcionJurado == 1){
				rolPersona = "Jurado Interno";
				salida = 0;
			}
			else if(opcionJurado == 2){
				rolPersona = "Jurado Externo";
				salida = 0;
			}
			else if(opcionJurado > 2){
				cout << " Error!, esta no es una opcion valida" << endl;  
		}
	}
}

void Persona::mostrarPersona(){
	cout << "Nombres: " << this->nombres << endl;
	cout << "Apellidos: " << this->apellidos << endl;
	cout << "Rol: " << this->rolPersona << endl;
}
