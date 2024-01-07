#include <iostream>
using namespace std;
int main(){

    double lado, area, perimetro;

    cout << "Ingrese el valor de un lado de su cuadrado: ";
    cin >> lado;

    perimetro = lado * 4;
    area = lado * lado;

    cout << "El perimetro de su cadrado es de " << perimetro << " y su area de " << area;

    return 0;
}