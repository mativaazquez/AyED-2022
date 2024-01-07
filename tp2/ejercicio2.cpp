#include <iostream>
using namespace std;

int dia (int fecha){
    int respuesta1 = fecha;
    return respuesta1;
}

int mes (int fecha){
    int respuesta2 = fecha * 100;
    return respuesta2;
}

int anio (int fecha){
    int respuesta3 = fecha * 10000;
    return respuesta3;
}

int main(){
    int diaa, mess, anioo, fecha;
    cout << "ingrese el dia: ";
    cin >> diaa;
    cout << "ingrese el mes: ";
    cin >> mess;
    cout << "ingrese el anio: ";
    cin >> anioo;

    fecha = dia(diaa) + mes(mess) + anio(anioo);

    cout << fecha;

    return 0;
}