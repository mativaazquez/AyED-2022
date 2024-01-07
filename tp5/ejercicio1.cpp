/*****************************************************************************************
Dada una pila programe una función dup (por duplicar) que reciba la pila y duplique el
elemento que está en el tope (a menos que la pila esté vacía). Por ejemplo si la pila un 1 al tope
seguido más abajo de un 2 (Notación: 1, 2) luego de invocar esta función debe tener 1, 1, 2
******************************************************************************************/

#include <iostream>
#include "listas.hpp"
#include "mostrar.cpp"

using namespace std;

template <typename T> void dup(Nodo<T>*& pila)
{
	T primero;
	if (pila != nullptr)
	{
		primero = pop(pila);
		push(pila, primero);
		push(pila, primero);

	}
	
}

int main(){

	Nodo<int> *pilaint = nullptr;

	push(pilaint, 2);
	push(pilaint, 1);
	cout << "Mostrando pila con datos" << endl;
	mostrar(pilaint);

	dup(pilaint);
	cout << endl << "Mostrando pila modificada" << endl;
	mostrar (pilaint);

	return 0;
}