/********************************************************************************************
Dada una pila programe una función swap que inverta los dos elementos tope. Si la pila tiene 1,
2, 3 luego de llamar a esta función tendrá 2, 1 , 3. Si la pila tiene menos de dos elementos la
función la deja inalterada 
*********************************************************************************************/

#include <iostream>
#include "listas.hpp"
#include "mostrar.cpp"

using namespace std;

template <typename T> void swap(Nodo<T>*& pila)
{
	T primero;
    T segundo;
	if (pila != nullptr)
	{
		primero = pop(pila);

        if (pila == nullptr)
        {
            push(pila, primero);
            return;
        }

        segundo = pop(pila);
		push(pila, primero);
		push(pila, segundo);
	}	
}

int main(){

	Nodo<int> *pilaint = nullptr;

	push(pilaint, 3);
    cout << "Mostrando pila con UN SOLO DATO" << endl;
    mostrar(pilaint);

    swap(pilaint);
	cout << endl << "Mostrando pila DE UN DATO modificada" << endl;
    mostrar(pilaint);

	push(pilaint, 2);
    push(pilaint, 1);
	cout << endl << "Mostrando pila con datos" << endl;
	mostrar(pilaint);

	swap(pilaint);
	cout << endl << "Mostrando pila modificada" << endl;
	mostrar (pilaint);

	return 0;
}