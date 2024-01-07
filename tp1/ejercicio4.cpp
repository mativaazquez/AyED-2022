#include <iostream>
using namespace std;
int main(){

    double num1, num2, num3;

    cout << "Ingrese la medida del primer angulo de su triangulo: ";
    cin >> num1;

    cout << "Ahora la segunda: ";
    cin >> num2;

    num3 = 180 - (num1 + num2);

    cout << "La medida del tercer angulo es igual a: " << num3;

    return 0;
}