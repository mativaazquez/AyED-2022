#include <iostream>
using namespace std;

int main(){

    char numero;

    cout << "Ingrese un numero del 1 al 7: ";
    cin >> numero;

    switch (numero){
        case '1':
            cout << "El lunes es el dia numero 1";
        break;

        case '2':
            cout << "El martes es el dia numero 2";
        break;

        case '3':
            cout << "El miercoles es el dia numero 3";
        break;

        case '4':
            cout << "El jueves es el dia numero 4";
        break;

        case '5':
            cout << "El viernes es el dia numero 5";
        break;

        case '6':
            cout << "El sabado es el dia numero 6";
        break;

        case '7':
            cout << "El domingo es el dia numero 7";
        break;

        default:
            cout << "El operador es incorrecto, vuelva a intentar.";
        break;
}

return 0;
}