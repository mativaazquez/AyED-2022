#include <iostream>
#include <cmath>
using namespace std;

//Ingresar un valor en mm y convertirlo a pulgadas (Dato: 1" = 25,4 mm)

int main(){

    double numero, pulgadas;

    cout << "ingrese su numero en milimetros para pasarlo a pulgadas porfavor: ";
    cin >> numero;

    pulgadas = numero / 25.4;

    cout<< "su numero transformado en pulgadas es: " << pulgadas;

    return 0;
}