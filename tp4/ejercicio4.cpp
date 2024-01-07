#include <iostream>
using namespace std;

void PedirDatos();
void EncontrarMaximo(int vec[], int);

int vec[100], tam{10};

int main(){

PedirDatos();
EncontrarMaximo(vec, tam);

    return 0;
}

void PedirDatos(){

    cout << "Ingrese 10 valores para completar su vector: " << endl;

    for (int i = 0; i < tam; i++)
    {
        cout << i + 1 << ". Digite un numero: ";
        cin >> vec[i];
    }

}

void EncontrarMaximo(int vec[], int tam){

    int max{vec[0]};
    int contador{0};

    for (int i = 0; i < tam; i++)
    {
        if (vec[i] > max)
        {
            max = vec[i];
        }

    }    
    
    while (max != vec[contador])
    {
        contador++;
    }

    cout << endl << "El valor maximo del vector es igual a: " << max;
    cout << endl << "El valor maximo del vector esta ubicado en la posicion: " << contador + 1 << " del vector";

}