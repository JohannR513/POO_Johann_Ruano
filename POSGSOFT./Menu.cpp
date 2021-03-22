#include <iostream>
#include "menu.h"

int menu()
{
    int opcion;
    std::cout << "Hola, Bienvedido!"<< std::endl;
    std::cout << "Menu Principal"<< std::endl;
    std::cout << "Por favor, elige una opcion:\n "<< std::endl;
    
    std::cout << "1. OPC 1" << std::endl;
    std::cout << "2. OPC 2" << std::endl;
    std::cout << "3. OPC 3" << std::endl;
    std::cout << "4. OPC 4" << std::endl;
    std::cout << "5. OPC 5" << std::endl;
    std::cout << "0. Salir\n"<< std::endl;
    
    std::cin >> opcion;
    return opcion;
} 