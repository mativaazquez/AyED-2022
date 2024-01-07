#include <iostream>
using namespace std;

double celsius(double far){
    double respuesta = (far - 32) * 5/9;
    return respuesta;
}

int main(){
    double far;
    cout << "Ingrese sus grados en fahrenheit: ";
    cin >> far;
    cout << far << " grados fahrenheit son iguales a " << celsius(far) << " grados celsius.";
    return 0;
}