#include <iostream>
#include "Menu.cpp"
#include "Nota.h"
#include "RegistroActa.h"
#include "Persona.h"
#include "Nota.h"
#include "Criterio.h"
#include "ActaGrado.h"



int main(){ 
	RegistroActa registro;
	int salida = 1;
	do{
		int opcionUsuario = menu();
		switch(opcionUsuario){
			case 0:
				salida = 0;
				break;

			case 1:
				registro.guardarActas();
				salida = 1;
				break;

			case 2: 
				registro.modificarActa();
				salida = 1;
				break;

			case 3:
				registro.cerrarActaTotal();
				salida = 1;
				break;
				
			case 4:
				registro.eliminarActa();
				salida = 1;
				break;
			case 5:
				int salida2 = 1;
				int varOpcion2;
				int varSalida2 = 1;
				int varOpcion;
				int varSalida = 1;
				do{
					int opcionUsuario2 = menu2();
					switch(opcionUsuario2){

						case 0:
							salida2 = 0;
							salida = 1;
							break;

						case 1:
							registro.cantTrabajosAplicado();
							salida2 = 1;
							break;

						case 2:
							registro.cantTrabajosInvestigacion();
							salida2 = 1;
							break;

						case 3: 
							registro.cantTrabajosDirigidos();
							salida2 = 1;
							break;

						case 4:
							registro.cantTrabajosJurado();
							salida2 = 1;
							break;

						case 5:
							registro.participacionJurado();
							salida2 = 1;
							break;

						case 6: 
							cout << "Elige una opcion: \n 1. Ver los jurados internos\n 2. Ver los jurados externos " << endl;
							cin >> varOpcion2;

							while( varSalida2 == 1 ){
								if( varOpcion2 < 1 ){
									cout << " Opcion no valida " << endl;
									varSalida2 = 1;
								}
								else if( varOpcion2 == 1 ){
									registro.juradosInternos();
									varSalida2 = 0;
								}
								else if( varOpcion2 == 2 ){
									registro.juradosExternos();
									varSalida2 = 0;
								}
								else if( varOpcion2 > 2 ){
									cout << " Opcion no valida " << endl;
									varSalida2 = 1;
								}
							}
							salida2 = 1;
							break;

							

						case 7: 
									registro.mostrarCriteriosActa();
							salida2 = 1;
							break;
					}

				}while( salida2 == 1 );
		}
	}while(salida == 1);
    return 0;
}

					
			