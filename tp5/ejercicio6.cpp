/********************************************************************************************
Dada una lista que contiene enteros programe una función que recorriendo la lista devuelva el
promedio (con decimales) de los valores guardados en la lista. 
********************************************************************************************/

#include <iostream>
#include "listas.hpp"
#include "mostrar.cpp"

using namespace std;

float promedio(Nodo<int>* lista)
{
    int cantidad{0};
    float suma{0};

    while (lista != nullptr)
    {
        cantidad++;
        suma = suma + lista->dato;
        lista = lista->sig;
    }

    float prom = suma / cantidad;

    return cantidad > 0 ? prom : 0;
}

int main(){

    Nodo<int>* lista = nullptr;

    agregar(lista, 1);
    agregar(lista, 30);
    agregar(lista, 32);
    agregar(lista, 56);
    agregar(lista, 4);
    agregar(lista, 28);
    
    cout << endl << "Mostrando lista original..." << endl;
    mostrar(lista);

    cout << endl << "Promedio de la lista: " << promedio(lista);

    while (lista != nullptr)
    {
        pop(lista);
    }
    
    return 0;
}