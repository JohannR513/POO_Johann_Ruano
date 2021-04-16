#include "RegistroActa.h"


RegistroActa::RegistroActa(){
}

void RegistroActa::guardarActas(){
	ActaGrado acta;
	acta.crearActa(listaActas.size());
	acta.agregarCriterio();
	acta.calcularNotaFinal();
	listaActas.push_back(acta);	
}


void RegistroActa::visualizarActas(){
	list<ActaGrado>::iterator itActa;
	for( itActa = listaActas.begin(); itActa != listaActas.end(); itActa++ ){
		itActa->visualizarActa();
	}
}


void RegistroActa::eliminarActa(){
	int idBorrar;               
	cout << "Escribe el numero del acta que deseas borrar: " << endl;
	cin >> idBorrar; 
	list<ActaGrado>::iterator itBorrar;
	for( itBorrar = listaActas.begin(); itBorrar != listaActas.end(); itBorrar++){
		if(idBorrar == itBorrar->getNumeroActa()){
			if(itBorrar->getEstadoActa()!= "Cerrado"){
				listaActas.erase(itBorrar);
				cout << "Esta actq fue eliminada exitosamente" << endl;
			}
			else{
				cout << "El acta que digitaste ya esta cerrada, entonces no se puede eliminar " << endl;
			}
		}
	}
}

void RegistroActa::modificarActa(){
	int idModificar, opcionUsuario, salida = 1;
	cout << "Escribe el numero del acta que deseas modificar: " << endl;
	cin >> idModificar;

	list<ActaGrado>::iterator itModificar;
	for(itModificar = listaActas.begin(); itModificar != listaActas.end(); itModificar++ ){
		if( idModificar == itModificar->getNumeroActa() && itModificar->getEstadoActa() == "Abierto" ){
			if( itModificar->getNotaDefinitiva() >= 3.5 ){
				while(salida == 1){
					cout << "Deseas agregar un comentario de aprobacion? " << endl;
					cout << "Digite: \n 1. SI\n 2. NO " << endl;
					cin >> opcionUsuario;

					if( opcionUsuario < 1 || opcionUsuario > 2 ){
						cout << "Error, el numero que dijitaste no es una opcion valida" << endl;
						salida = 1;
					}

					else if( opcionUsuario == 1 ){
						itModificar->setComentarioAprobacion();
						salida = 0;
					}

					else if( opcionUsuario == 2 ){
						salida = 0;
					}

					else if( opcionUsuario > 2){
						cout << "Error, el numero que dijitaste no es una opcion valida" << endl;
						salida = 1;
					}

				}
				
			}
		}
		else{
			cout << "Esta acta no puede ser modificada" << endl;
		}
	}
}


void RegistroActa::cerrarActaTotal(){
	int idCerrarActa; 
	cout << "Escribe el numero del acta que deseas cerrar: " << endl;
	cin >> idCerrarActa;

	list<ActaGrado>::iterator itCerrar;
	for(itCerrar = listaActas.begin(); itCerrar != listaActas.end(); itCerrar++ ){
		if(idCerrarActa == itCerrar->getNumeroActa()){
			itCerrar->cerrarActa();
			itCerrar->crearTxtActaCerrada();
			cout << "Acta cerrada exitosamente " << endl;
		}
	}
}


void RegistroActa::cantTrabajosAplicado(){
	int acumAplicado = 0;
	list<ActaGrado>::iterator it;
	for( it = listaActas.begin(); it != listaActas.end(); it++ ){
		if(it->getTipoTrabajo() == "Aplicado"){
			cout << "los trabajos Id de tipo aplicado son: " << it->getNumeroActa() << endl;
			acumAplicado++;
		}
	}
	cout << "La cantidad de trabajos tipo aplicado es: " << acumAplicado << endl;
}


void RegistroActa::cantTrabajosInvestigacion(){
	int acumInvestigacion = 0;
	list<ActaGrado>::iterator it;
	for( it = listaActas.begin(); it != listaActas.end(); it++ ){
		if(it->getTipoTrabajo() == "Investigacion"){
			cout << "los trabajos de tipo Investigacion organizados por id son: " << it->getNumeroActa() << endl;
			acumInvestigacion++;
		}
	}
	cout << "La cantidad de trabajos tipo Investigacion es: " << acumInvestigacion << endl;
}


void RegistroActa::cantTrabajosDirigidos(){
	int acumDireccionTrabajos = 0;
	string busqueda;
	cout << " Digite el nombre del director: " << endl;
	cin >> busqueda;
	list<ActaGrado>::iterator it;
	for( it = listaActas.begin(); it != listaActas.end(); it++ ){
		if(it->getNombreDirector() == busqueda){
			acumDireccionTrabajos++;
		}
	}
	cout << "La cantidad de trabajos dirigidos por este docente es: " << acumDireccionTrabajos << endl;
}


void RegistroActa::cantTrabajosJurado(){
	int acumTrabajosJurado = 0;
	string busqueda;
	cout << " Digite el nombre del jurado: " << endl;
	cin >> busqueda;

	list<ActaGrado>::iterator it;
	for( it = listaActas.begin(); it != listaActas.end(); it++ ){
		if(it->getNombrejuradoUno()  == busqueda){
			cout << "los trabajos que ha participado este jurado sus id actas son: " << it->getNumeroActa() << endl;
			acumTrabajosJurado++;
		}
		if(it->getNombrejuradoDos() == busqueda){
			cout << "los trabajos que ha participado este jurado sus id actas son: " << it->getNumeroActa() << endl;
			acumTrabajosJurado++;
		}
	}
	cout << "La cantidad de trabajos que ha participado este jurado es: " << acumTrabajosJurado << endl;
}


void RegistroActa::participacionJurado(){
	bool validador1 = true, validador2 = true;
	list<int> listaIdJurados;
	list<ActaGrado>::iterator it;
	for( it = listaActas.begin(); it != listaActas.end(); it++ ){
		list<int>::iterator it2;
		for (it2 = listaIdJurados.begin(); it2 != listaIdJurados.end(); it2++ ){
			if(*it2 == it->getIdjuradoUno()){
				validador1 = false;
			}
			if(*it2 == it->getIdjuradoDos()){
				validador2 = false;
			}
		}
		if(validador1){
			listaIdJurados.push_back(it->getIdjuradoUno());
			cout << "Nombre: " << it->getNombrejuradoUno() << endl;
			cout << "Id: " << it->getIdjuradoUno() << endl;
		}
		if(validador2){
			listaIdJurados.push_back(it->getIdjuradoDos());
			cout << "Nombre: " << it->getNombrejuradoDos() << endl;
			cout << "Id: " << it->getIdjuradoDos() << endl;
		}
	}
	listaIdJurados.clear();
}

void RegistroActa::juradosInternos(){
	list<ActaGrado>::iterator it;
	for( it = listaActas.begin(); it != listaActas.end(); it++ ){
		if(it->getRoljuradoUno() == "Jurado Interno"){
			cout << "Id del jurado interno: " << it->getIdjuradoUno() << endl;
			cout << "Nombre del jurado interno: " << it->getNombrejuradoUno() << endl;
		}
		if(it->getRoljuradoDos() == "Jurado Interno"){
			cout << "Id del jurado interno: " << it->getIdjuradoDos() << endl;
			cout << "Nombre del jurado interno: " << it->getNombrejuradoDos() << endl;
		}

	}
}

void RegistroActa::juradosExternos(){
	list<ActaGrado>::iterator it;
	for( it = listaActas.begin(); it != listaActas.end(); it++ ){
		if(it->getRoljuradoUno() == "Jurado Externo"){
			cout << "Id del jurado externo: " << it->getIdjuradoUno() << endl;
			cout << "Nombre del jurado externo: " << it->getNombrejuradoUno() << endl;
		}
		if(it->getRoljuradoDos() == "Jurado Externo"){
			cout << "Id del jurado externo: " << it->getIdjuradoDos() << endl;
			cout << "Nombre del jurado externo: " << it->getNombrejuradoDos() << endl;
		}

	}
}

void RegistroActa::mostrarCriteriosActa(){
	int idActaImprimirCriterios;
	cout << "Digite el id del acta al cual desea conocer sus criterios: " << endl;
	cin >> idActaImprimirCriterios;

	list<ActaGrado>::iterator itActa;
	for( itActa = listaActas.begin(); itActa != listaActas.end(); itActa++ ){
		if( idActaImprimirCriterios == itActa->getNumeroActa() ){
			itActa->mostrarCriteriosEvaluacion();
		}
		else{
			cout << "No se encontro el acta " << endl;
		}
	}
}