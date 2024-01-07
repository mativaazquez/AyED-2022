#include <iostream>
using namespace std;

int dia(int fecha){
    int respuesta1 = fecha % 100;
    return respuesta1;
}

int mes(int fecha){
    int respuesta2 = (fecha % 10000) / 100;
    return respuesta2;
} 

int anio(int fecha){
    int respuesta3 = fecha / 10000;
    return respuesta3;
}

int main(){
    int feccha;
    cout << "ingrese la fecha en AAAAMMDD: ";
    cin >> feccha;
    cout << dia(feccha) << "/" << mes(feccha) << "/" << anio(feccha);
}
