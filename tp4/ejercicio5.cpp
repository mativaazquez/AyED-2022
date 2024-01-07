/*
Se tiene un vector de 8 elementos enteros. Sus valores deben cargarse por consola en forma
estrictamente creciente, verificando y volviendo a pedir un valor si no cumple la condición
(Arme una función de carga con verificación). Programe una función que encuentre, cuál es la
máxima diferencia entre dos elementos sucesivos. Informe el valor de la misma y entre que
elementos se produce.
Si los datos son: 2, 4, 8, 9, 35, 40, 50, 55 la máxima diferencia es 26 y se da entre los elementos
3 y 4 (tomados como subíndices del arreglo, no como ordinales)
*/

#include<iostream>
using namespace std;

void PedirDatos();
void MostrarNumeros(int vec[], int);
void MaxEntreSucesivos(int vec[], int);

int vec[100], tam{8}; 

int main(){

    PedirDatos();
    MostrarNumeros(vec, tam);
    MaxEntreSucesivos(vec, tam);

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

        while (vec[i] <= vec[i - 1])
        {
            cout << endl << "El numero ingresado no acompania a la funcion CRECIENTE, digite otro numero" << endl;
            cout << i + 1 << ". Digite un numero: ";
            cin >> vec[i];

        }

    }

}

void MostrarNumeros(int vec[], int){

    cout << endl << "El vector final es = {";

    for (int i = 0; i < tam; i++)
    {
        cout << vec[i];
        
        if (vec[i+1])
        {
            cout << ", ";
        };

    }
    
    cout << "}";
 
}

void MaxEntreSucesivos(int vec[], int tam){

    int MaxDif{vec[1] - vec[0]};
    int contador{0};
    int x{0};

    for (int i = 0; i < tam; i++)
    {
        if (vec[i + 1] - vec[i] > MaxDif)
        {
            MaxDif = vec[i + 1] - vec[i];
        }
    
    }    
    
    while (MaxDif != vec[contador + 1] - vec[contador])
    {
        contador++;

    }

    cout << endl << "La maxima diferencia entre dos numeros sucesivos del vector es igual a: " << MaxDif << endl;
    
    cout << "Se da entre las posiciones: " << contador + 1 << " y " << contador + 2;
    
}

