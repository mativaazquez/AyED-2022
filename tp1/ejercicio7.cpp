#include <iostream>
using namespace std;
int main(){

    int lado1, lado2, lado3;

    cout << "Ingrese tres lados de un triangulo: " << endl;
    cin >> lado1 >> lado2 >> lado3;

    if (lado1 == lado2 && lado1 == lado3){
        cout << "Su triangulo es equilatero";
    }

    else if (lado1 != lado2 && lado1 != lado3 && lado2 != lado3){
        cout << "Su triangulo es escaleno";
    }

    else{
        cout << "Su triangulo es isoseles";
    }

    return 0;
}