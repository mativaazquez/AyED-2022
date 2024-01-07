#include <iostream>
using namespace std;
int main(){

    int bultos, bulxcaja, cajas, resto;

    cout << "Ingrese la cantidad de bultos en stock: ";
    cin >> bultos;
    cout << "Ahora, ingrese la cantidad de bultos que se pueden colocar en una caja: ";
    cin >> bulxcaja;

    cajas = bultos / bulxcaja;
    resto = bultos % bulxcaja; 

    cout << "Usted cuenta con " << cajas << " cajas completas." << endl;
    cout << "Con un sobrante de " << resto << " bultos.";

    return 0;
}