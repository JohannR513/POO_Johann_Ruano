#include "Criterio.h"


Criterio::Criterio(){
}


Criterio::Criterio(int idCriterio, double porcentajeNota, string observaciones){
	this->idCriterio = idCriterio;
	this->porcentajeNota = porcentajeNota; 
	this->observaciones = observaciones;
}

void Criterio::crearCriterio(int idCriterio){
	this->idCriterio = idCriterio;

	cout << " Escribe el porcentaje de la ponderacion: " << endl;
	cin >> porcentajeNota;

	cout << " Escribe una descripcion: " << endl;
	fflush(stdin);
	getline(cin, observaciones);
	fflush(stdin);

}


void Criterio::mostrarCriterio(){
	cout << " Descripcion: " << observaciones << endl;
	cout << " Id: " << idCriterio<< endl;
	cout << " Porcentaje nota: " << porcentajeNota << endl;
}

double Criterio::getPorcentajeNota(){
	return porcentajeNota;
}


