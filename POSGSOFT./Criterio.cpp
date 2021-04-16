#include "Criterio.h"


Criterio::Criterio(){
}


Criterio::Criterio(int idCriterio, double porcentajeNota, string descripcionCriterio){
	this->idCriterio = idCriterio;
	this->porcentajeNota = porcentajeNota; 
	this->descripcionCriterio = descripcionCriterio;
}

void Criterio::crearCriterio(int idCriterio){
	this->idCriterio = idCriterio;

	cout << " Escribe el porcentaje de la ponderacion: " << endl;
	cin >> porcentajeNota;

	cout << " Escribe una descripcion: " << endl;
	fflush(stdin);
	getline(cin, descripcionCriterio);
	fflush(stdin);

}


void Criterio::mostrarCriterio(){
	cout << " Descripcion: " << descripcionCriterio << endl;
	cout << " Id: " << idCriterio<< endl;
	cout << " Porcentaje nota: " << porcentajeNota << endl;
}

double Criterio::getPorcentajeNota(){
	return porcentajeNota;
}

int Criterio::getIdCriterio(){
    return idCriterio;
}
string Criterio::getDescripcionCriterio(){
    return descripcionCriterio;
}

