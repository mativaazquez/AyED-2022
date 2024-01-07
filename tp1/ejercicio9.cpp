#include <iostream>
using namespace std;
int main(){

    int numero;
    const int base {10};
    cout << "Ingrese un numero para determinar cuantas cifras tiene: ";
    cin >> numero;
    int cifras = 0;

    do{
        numero /= base;
        ++cifras;
    } while (numero != 0);

    cout << "Su numero tiene " << cifras << " cifras";

    return 0;
}