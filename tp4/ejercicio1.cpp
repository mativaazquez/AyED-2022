/*
Armar un vector con 10 valores enteros en la inicialización. Hallar la sumatoria de los valores.
Si prueba con los pares comenzando en 2, la suma debe dar 110
*/

#include <iostream>
using namespace std;

void PedirDatos();
void Suma(int vec[], int);

int vec[100], tam{10};

int main(){

    PedirDatos();
    Suma(vec, tam);


    return 0;
}

void PedirDatos(){
    cout << endl << "Debe digitar una serie de 10 numeros" << endl;

    cout << endl;

    for(int i = 0; i < tam; i++)
    {
        cout << i + 1 << ". Digite un numero: ";
        cin >> vec[i];
    }
}

void Suma(int vec[], int){
    
int suma{0};

    for (int i = 0; i < tam; i++)
    {
        suma = suma + vec[i];
    }

 cout << endl << "La suma de sus valores es igual a: " << suma << endl;

}