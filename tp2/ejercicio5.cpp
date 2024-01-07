#include <iostream>
using namespace std;

int valor (int n){
    int respuesta;
    for (int i = 0; i <= n; i++)
    {
        respuesta = respuesta + i;
    }
    return respuesta;
}

int main(){
    int numero;
    cout << "ingrese un valor como parametro: ";
    cin >> numero;
    cout << valor(numero);

    return 0;
}