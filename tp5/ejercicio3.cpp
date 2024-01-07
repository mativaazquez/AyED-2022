/***********************************************************************************************
Dada una pila programe un función rot (por rotar) tal que si la lista tiene al menos 3 elementos
ponga el tercero al tope y sino deje inalterada la pila. Ejemplo, si la tiene 1, 2, 3, 4 luego de
llamar a esta función la pila quedará: 3, 1, 2, 4
************************************************************************************************/

#include <iostream>
#include "listas.hpp"
#include "mostrar.cpp"

using namespace std;

template <typename T> void rot(Nodo<T>*& pila)
{
    T primero, segundo, tercero;
    Nodo<T>* paux = pila;
    int i;
    for (i = 0; paux != nullptr && i < 3; i++)
    {
        paux = paux -> sig;
    }

    if (i < 3)
    {
        return;
    }

    primero = pop(pila);
    segundo = pop(pila);
    tercero = pop(pila);
    push(pila, segundo);
    push(pila, primero);
    push(pila, tercero);

}

int main(){

	Nodo<int> *pilaint = nullptr;

    push(pilaint, 3);
    push(pilaint, 2);

    cout << "Mostrando pila con DOS DATOS" << endl;
    mostrar(pilaint);

    rot(pilaint);
	cout << endl << "Mostrando pila DE DOS DATOS modificada" << endl;
    mostrar(pilaint);

    push(pilaint, 1);
	cout << endl << "Mostrando pila con datos" << endl;
	mostrar(pilaint);

	rot(pilaint);
	cout << endl << "Mostrando pila modificada" << endl;
	mostrar (pilaint);

	return 0;
}