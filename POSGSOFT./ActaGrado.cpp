#include "ActaGrado.h"


ActaGrado::ActaGrado(){
}


ActaGrado::ActaGrado( int numeroActa, string fechaAct, Persona autor, string nombreTrabajo, string tipoTrabajo, string periodo, Persona director, Persona codirector, Persona juradoUno, Persona juradoDos, string estadoProyecto,string estadoActa,string comentarioAprobacion, double notaFinal ){
	this->numeroActa = numeroActa;
	this->fechaAct = fechaAct;
	this->autor = autor;
	this->nombreTrabajo = nombreTrabajo;
	this->tipoTrabajo = tipoTrabajo;
	this->periodo = periodo;
	this->director = director;
	this->codirector = codirector;
	this->juradoUno = juradoUno;
	this->juradoDos = juradoDos;
	this->estadoActa = estadoActa;
}

void ActaGrado::crearActa (int numeroActa ){
  
  ActaGrado actaGrado;
  int opcionCodirector, opcionUsuario;
  this-> numeroActa = numeroActa;
  int bandera1 = 1, bandera2 = 1;
  cout << "Digita la fecha: " << endl;
	fflush(stdin);  
	getline(cin, fechaAct);
	fflush(stdin);

  cout << "Escribe los datos del autor: " << endl;
	autor.crearPersona(3); 

  fflush(stdin);
	cout << " Escribe el nombre del trabajo: " << endl;
	getline(cin, nombreTrabajo);
	fflush(stdin);

  while( bandera1 == 1 ){
    cout << "De que tipo es tu trabajo?:\n 1. Investigacion\n 2. Aplicado\n" << endl;  
		cin >> opcionUsuario;
    if(opcionUsuario == 1){
			tipoTrabajo = "Investigacion";
			bandera1 = 0;
		} 
		else if(opcionUsuario == 2){
			tipoTrabajo = "Aplicado";
			bandera1 = 0;
		}
    else if( opcionUsuario < 1 || opcionUsuario > 2){
			cout << " Error!, la opcion que acabas de digitar no es valida" << endl;  
			bandera1 = 1;
		}
  }
  fflush(stdin);
	cout << " Escribe el periodo: " << endl;
	getline(cin, periodo);
	fflush(stdin);

  cout << "Digite los datos del Director: " << endl;
	director.crearPersona(1);
 
  cout << "Digite la informacion del codirector: ";
  while( bandera2 == 1){
    cout << " Existe un codirector?\n 1. Si\n 2. No\n " << endl;
		cin >> opcionCodirector;
    if(opcionCodirector == 1){
			existeCodirector = true;
			codirector.crearPersona(2);  // se crea un autor de tipo codirector, y se le pasa por parametro el entero que hace referencia al codirector
			bandera2 = 0;
		}
		else if(opcionCodirector == 2){
			cout << " No hay codirector" << endl;
			bandera2 = 0;
		}
    else if( opcionCodirector < 1 || opcionCodirector > 2){
			cout << " Error!, la opcion que acabas de digitar no es valida" << endl;  
			bandera2 = 1;
		}

  cout << " Digite la informacion del Jurado 1" << endl;
	juradoUno.crearPersona(4); 

	cout << " Digite la informacion del Jurado 2" << endl;
	juradoDos.crearPersona(4);  
	}

	estadoProyecto = "";  

	comentarioAprobacion = "";  
 
	estadoActa = "Abierto";  
  }
  


