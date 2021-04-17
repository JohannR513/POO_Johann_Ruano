#include <iostream>
#include "Menu.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

int menu()
{
    int opcion;
    std::cout << "Hola, Bienvedido!"<< std::endl;
    std::cout << "Menu Principal"<< std::endl;
    std::cout << "Por favor, elige una opcion:\n "<< std::endl;
    
    cout << "1. Crear un acta" << endl;
    cout << "2. Modificar un acta" << endl;
    cout << "3. Cerrar acta y mostrar txt " << endl;
    cout << "4. Eliminar acta" << endl;
    cout << "5. Desplegar menu de otras funcionalidades" << endl;
    cout << "0. Salir" << endl;
    
    std::cin >> opcion;
    return opcion;
} 
int menu2(){
	int opcion2;

	cout << "1. Cuantas actas existen de tipo aplicado  " << endl;
	cout << "2. Cuantas actas existen de tipo  investigacion " << endl;
	cout << "3. Consultar cuantos trabajo han sido dirigidos por un profesor " << endl;
	cout << "4. Consultar en cuales actas ha sido jurado un profesor " << endl;
	cout << "5. Ver la lista de jurados que han trabajo en las actas  " << endl;
	cout << "6. Consultar cuales jurados son internos y cuales son externos " << endl;
	cout << "7. Consultar la lista de criterios de un acta " << endl;
 	cout << "0. Volver al menu anterior " << endl;
	cin >> opcion2;
	
  return opcion2;
}
