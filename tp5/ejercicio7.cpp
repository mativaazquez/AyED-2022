/*****************************************************************************
Dada una lista que contiene enteros programe una función que devuelva:
1. Variante a: el mayor valor en la lista
2. Variante b: un puntero al nodo que contiene el mayor elemento en la lista.
*****************************************************************************/

#include <iostream>
#include "listas.hpp"
#include "mostrar.cpp"
using namespace std;

int MayorValor(Nodo<int>* lista){

    int mayor;
    if (lista != nullptr)
    {
        mayor = lista->dato;
        lista = lista->sig;
    }
    else
    {
        return 0;
    }
    while (lista->dato > mayor)
    {
        mayor = lista->dato;
        lista = lista->sig;
    }    
    return mayor;
}

int main(){

    Nodo<int>* lista = nullptr;
    agregar(lista, 1);
    agregar(lista, 4);
    agregar(lista, 7);
    agregar(lista, 5);
    agregar(lista, 2);
    agregar(lista, 3);

    cout << "El mayor valor de la lista es: " << MayorValor(lista) << endl;

    return 0;
}
