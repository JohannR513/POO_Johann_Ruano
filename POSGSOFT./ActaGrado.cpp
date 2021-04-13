#include "ActaGrado.h"


ActaGrado::ActaGrado(){
}

ActaGrado::ActaGrado( int numeroActa, string fechaAct, Persona autor, string nombreTrabajo, string tipoTrabajo, string periodo, Persona director, Persona codirector, Persona juradoUno, Persona juradoDos, string comentarioAprobacion, double notaFinal ){
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

	comentarioAprobacion = "";  
 
	estadoActa = "Abierto";  
  }

void ActaGrado::agregarCriterio(){
	Nota nota;

	if(listaNotas.size() <= 8){
		cout << "No se pueden crear mas de 8 criterios " << endl;  
	}
	
	while( listaNotas.size() < 8 ){
		nota.crearNota( listaNotas.size() );
		listaNotas.push_back( nota );
	}
}

void ActaGrado ::mostrarNotas(){
	list< Nota >::iterator it;
	for( it = listaNotas.begin(); it != listaNotas.end(); it++ ){
		it->mostrarNota();
	}
}
void ActaGrado::calcularNotaFinal(){
list<Nota>::iterator it2;
	double sumatoriaNotas = 0, multNotas = 0;
	for( it2 = listaNotas.begin(); it2 != listaNotas.end(); it2++ ){
		sumatoriaNotas = ( it2->getNotaJuradoUno() + it2->getNotaJuradoDos() );
		multNotas += ( sumatoriaNotas * it2->getPorcentajeNota() );
	}
	notaFinal = multNotas/2;
}

void ActaGrado::setComentarioAprobacion(){
	string comentarioAprobacion;
	cout << " Escribe el comentario de aprobacion: " << endl;
	fflush(stdin);
	getline(cin, comentarioAprobacion);
	fflush(stdin);
	this->comentarioAprobacion = comentarioAprobacion;
}

string ActaGrado::getTipoTrabajo(){
	return tipoTrabajo;
}

string ActaGrado::getNombreDirector(){
	return director.getNombre();
}

string ActaGrado::getNombrejuradoUno(){
	return juradoUno.getNombre();
}
string ActaGrado::getNombrejuradoDos(){
	return juradoUno.getNombre();
}

void ActaGrado::cerrarActa(){
	estadoActa = "Cerrado";
}
double ActaGrado::getNotaDefinitiva(){
	return notaFinal;
}

string ActaGrado::getComentarioAprobacion(){
	return comentarioAprobacion;
}

int ActaGrado::getNumeroActa(){
	return numeroActa;
}
void ActaGrado::visualizarActa(){
	cout << "No. Acta: \n" << numeroActa << endl;
	cout << "=====================================\n" << endl;
	cout << "Fecha: \n" << fechaAct << endl;
	cout << "=====================================\n" << endl;
	cout << "Autor: \n" << endl;
	autor.mostrarPersona();
	cout << "=====================================\n" << endl;
	cout << "Nombre trabajo: \n" << nombreTrabajo << endl;
	cout << "=====================================\n" << endl;
	cout << "Tipo trabajo: \n" << tipoTrabajo << endl;
	cout << "=====================================\n" << endl;
	cout << "Periodo: \n" << periodo << endl;
	cout << "=====================================\n" << endl;
	cout << "Director: \n" << endl;
	director.mostrarPersona();
	cout << "=====================================\n" << endl;
	if( existeCodirector ){
		cout << "Codirector: \n" << endl;
		codirector.mostrarPersona();
	}
	else{
		cout << "No hay codirector para este proyecto\n" << endl;
	}
	cout << "=====================================\n" << endl;
	cout << "Jurado Uno: \n" << endl;
	juradoUno.mostrarPersona();
	cout << "=====================================\n" << endl;
	cout << " Informacion Jurado Dos: \n" << endl;
	juradoDos.mostrarPersona();
	cout << "=====================================\n" << endl;
	cout << "Comentarios de aprobacion: \n" << comentarioAprobacion << endl;
	cout << "=====================================\n" << endl;
	cout << "Estado acta: \n" << estadoActa << endl;

}
void ActaGrado::crearTxtActa(){  \
	string nombre, apellido, rol;
	if(estadoActa=="Cerrado"){  //valida si el estado del acta esta cerrada para hacer el txt 
		std::ofstream File;
  		File.open("Acta.txt");
		File << "No. Acta: " << numeroActa << endl;
		File << "Fecha: " << fechaAct << endl;
		nombre = autor.getNombre();
		File << "Autor: " << nombre << endl;;
		File << "Nombre del trabajo: " << nombreTrabajo << endl;
		File << "Tipo trabajo: " << tipoTrabajo << endl;
		File << "Periodo: " << periodo << endl;
		File << "Datos del Director: " << endl;
		nombre = director.getNombre();
		File << "Nombre: " << nombre << endl;
		apellido = director.getApellido();
		File << "Apellidos: " << apellido << endl;
		rol = director.getRolPersona();
		File << "Rol: " << rol << endl;
		if( existeCodirector ){
			File << "Informacion Codirector: " << endl;
			nombre = codirector.getNombre();
			File << "Nombres: " << nombre << endl;
			apellido = codirector.getApellido();
			File << "Apellidos: " << apellido << endl;
			rol = codirector.getRolPersona();
			File << " Rol: " << rol << endl;
		}
		else{
			cout << "Este proyecto no tuvo codirector." << endl;
		}
		File << "Datos Jurado Uno: " << endl;
		nombre = juradoUno.getNombre();
		File << "Nombres: " << nombre << endl;
		apellido = juradoUno.getApellido();
		File << "Apellidos: " << apellido << endl;
		rol = juradoUno.getRolPersona();
		File << "Rol: " << rol << endl;
		File << "Informacion Jurado Dos: " << endl;
		nombre = juradoDos.getNombre();
		File << "Nombres: " << nombre << endl;
		apellido = juradoDos.getApellido();
		File << "Apellidos: " << apellido << endl;
		rol = juradoDos.getRolPersona();
		File << "Rol: " << rol << endl;
		File << " Comentarios de aprobacion: " << comentarioAprobacion << endl;
		File << "Estado acta: " << estadoActa << endl;
		for( list<Nota>::iterator it2 = listaNotas.begin(); it2 != listaNotas.end(); it2++ ){
			File << " Id del Criterio: " << it2->getIdCriterio() << endl;
			File << " Porcentaje del criterio: " << it2->getPorcentajeNota() << endl;
			File << " Nota del jurado 1 : " << it2->getNotaJuradoUno() << endl;
			File << " Observaciones del jurado 1 : " << it2->getObservacionJuradoUno() << endl;
			File << " Nota del jurado 2 : " << it2->getNotaJuradoUno() << endl;
			File << " Observaciones del jurado 2 : " << it2->getObservacionJuradoDos() << endl;
		}
		File << " Como  resultado  de  estas  calificaciones  parciales  y  sus  ponderaciones,  la  calificación  del Trabajo  de Grado es: " << getNotaDefinitiva() << endl;
		File << " Observaciones adicionales: " << getComentarioAprobacion() << endl;
  		File.close();
	}
	else{
		cout << "El acta no esta cerrada: " << endl;
	}
	return ;
}
