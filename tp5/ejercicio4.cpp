/*************************************************************************************
Dada dos listas enlazadas programe una función que arme una nueva lista que contenga la
concatenación de los elementos de la primer lista, seguida de los de la segunda.
**************************************************************************************/

#include <iostream>
#include "listas.hpp"
#include "mostrar.cpp"

using namespace std;

template <typename T> Nodo<T> *armar(Nodo<T>*& luno, Nodo<T>*& ldos)
{
    Nodo<T>* lista = nullptr;

    while (luno != nullptr)
    {
        agregar(lista, pop(luno));
    }

    while (ldos != nullptr)
    {
        agregar(lista, pop(ldos));
    }
    
    return lista;
    
}

int main(){

    Nodo<int> *listauno = nullptr;
	Nodo<int> *listados = nullptr;

    agregar(listauno, 1);
    agregar(listauno, 2);
    agregar(listauno, 3);

    agregar(listados, 4);
    agregar(listados, 5);
    agregar(listados, 6);
    
    Nodo<int> *listar = armar(listauno, listados);
    mostrar(listar);
}