#include <iostream>
#include "Nota.h"


Nota::Nota (){
}


Nota::Nota(Criterio criterio, string observacion1, string observacion2, double notaJuradoUno, double notaJur2){
	this->criterio = criterio;
	this->observacion1 = observacion1;
	this->observacion2 = observacion2;
	this->notaJuradoUno = notaJuradoUno;
	this->notaJuradoDos = notaJuradoDos;
}


void Nota::crearNota(int idNota){
	criterio.crearCriterio( int idCriterio );

	cout << " Digite la nota 1: " << endl;
	cin >> this->notaJuradoUno;

	cout << " Digite la nota 2: " << endl;
	cin >> this->notaJuradoDos;

	cout << " Comentario del jurado 1: " << endl;
	fflush(stdin);
	getline(cin, this->observacion1);  
	fflush(stdin);

	cout << " Comentario del jurado 2: " << endl;
	fflush(stdin);
	getline(cin, observacion2);  
	fflush(stdin);
}

void Nota::mostrarNota(){
	criterio.mostrarCriterio(); 
	cout << " Nota Jurado 1: " << notaJuradoUno << endl;
	cout << " Nota Jurado 2: " << notaJuradoDos << endl;
	cout << " Comentario sobre las notas: " << observacion1 << endl;
}


double Nota::getNotaJuradoUno(){
	return notaJuradoUno;
}


double Nota::getNotaJuradoDos(){
	return notaJuradoDos;
}


double Nota::getPorcentajeNota(){
	return criterio.getPorcentajeNota();
}

string Nota::getObservacionJuradoUno(){
	return observacion1;
}

string Nota::getObservacionJuradoDos(){
	return observacion2;
}
