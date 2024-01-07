/******************************************************************************************************
Similar al ejercicio anterior (programe solo la variante a) pero en lugar de concatenar intercale.
Por ejemplo si la primer lista tiene 1, 2, 3 y la segunda lista tiene 5, 6, 7, 8, 9 la lista resultante
debe ser 1, 5, 2, 6, 3, 7, 8, 9 
******************************************************************************************************/

#include <iostream>
#include "listas.hpp"
#include "mostrar.cpp"

using namespace std;

template <typename T> Nodo<T> *armar(Nodo<T>*& luno, Nodo<T>*& ldos)
{
    Nodo<T>* lista = nullptr;

    while (luno != nullptr && ldos != nullptr)
    {
        agregar(lista, pop(luno));
        agregar(lista, pop(ldos));  // De esta forma agrega uno a uno
    }
    
    // Habiendo hecho la intercalacion, agregamos los sobrantes de alguna de las dos listas con estos while's
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
    agregar(listados, 7);
    
    Nodo<int> *listar = armar(listauno, listados);
    mostrar(listar);
}