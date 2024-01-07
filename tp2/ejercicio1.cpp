#include <iostream>
using namespace std;

bool bisiesto (int anio){
   return anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0); 
}

int main()
{
    int ano;
    cout << "Sistema de verificacion de anio bisiesto" << endl;
    cout << "Ingrese el numero que desea verificar: ";
    cin >> ano;
    string condicion = bisiesto(ano) ? "es bisiesto." : "no es bisiesto.";
    cout << ano << " " << condicion;

    return 0;
}