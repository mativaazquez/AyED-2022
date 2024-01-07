/*
Se pide ingresar por teclado 8 valores que se cargarán en un vector, pero se controlará que
todos los valores sean distintos. Si el valor ingresado ya se encuentra en los cargados previamente, vuelva a solicitar el valor para esa posición. 
*/

#include<iostream>
using namespace std;

void PedirDatos();
void MostrarResultado(int vec[], int);

int vec[100], tam{8};

int main(){

    PedirDatos();
    MostrarResultado(vec, tam);

    return 0;
}

void PedirDatos(){

    cout << endl << "Debe ingresar 8 numeros" << endl;
    cout << endl;

    cout << 1 << ". Digite un numero: ";
    cin >> vec[0];
    
    for (int i = 1; i < tam; i++)
    {      
        cout << i + 1 << ". Digite un numero: ";
        cin >> vec[i];

        while (vec[i] == vec[i - 1] || vec[i] == vec[i - 2] || vec[i] == vec[i - 3] || vec[i] == vec[i - 4] || vec[i] == vec[i - 5] || vec[i] == vec[i - 6] || vec[i] == vec[i - 7])
        {
            cout << endl << "El numero ingresado es igual a otro ingresado, digite otro numero" << endl;
            cout << i + 1 << ". Digite un numero: ";
            cin >> vec[i];

        }

    }

}

void MostrarResultado(int vec[], int){

    cout << "El vector final es: {";

    for (int i = 0; i < tam; i++)
    {
        cout << vec[i];

        if (vec[i + 1])
        {
            cout << ", ";
        }
        
    }

    cout << "}";

}