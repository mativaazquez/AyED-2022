#include <iostream>
using namespace std;

template <typename T> void mostrar(Nodo<T>* lista)
{
	while (lista != nullptr) {
		cout << lista->dato << endl;
		lista = lista->sig;
	}
};