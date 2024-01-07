#ifndef LISTAS_HPP_INCLUDED
#define LISTAS_HPP_INCLUDED
using namespace std;

template <typename T> struct Nodo
{
	T dato;
	Nodo *sig;
};

template <typename T> void mostrar(Nodo<T> *lista)
{
	while (lista != nullptr) {
		cout << "dato: " << lista->dato << endl;
		lista = lista->sig;
	}
}

template <typename T> void push(Nodo<T> *&lista, T dato)
{
	Nodo<T> *nuevo = new Nodo<T>;
	nuevo->dato = dato;
	nuevo->sig = lista;
	lista = nuevo;
}

template <typename T> T pop(Nodo<T> *&lista)
{
	T dato = lista->dato;
	Nodo<T> *aux = lista;
	lista = lista->sig;
	delete aux;
	return dato;
}

template <typename T> void agregar(Nodo<T> *&lista, T valor)
{
	Nodo<T> *nuevo = new Nodo<T>;
	nuevo->dato = valor;
	nuevo->sig = nullptr;
	if(lista == nullptr){
		lista = nuevo;
	} else{
		Nodo<T> *aux = lista;
		while (aux->sig != nullptr){
			aux = aux->sig;
        }
		aux->sig = nuevo;
	}
}

template <typename T> Nodo<T>* buscar(T clave, Nodo<T>* lista, int (*criterio)(T, T))
{
	while (lista != nullptr && criterio(clave, lista->dato) > 0){
		lista = lista->sig;
    }
	return lista != nullptr && criterio(clave, lista->dato) == 0 ? lista : nullptr;
}

template <typename T> void insertar(T valor, Nodo<T>*& lista, int (*criterio)(T, T))
{
	Nodo<T>* nuevo = new Nodo<T>;
	nuevo->dato = valor;

	Nodo<T>** pp = &lista;
	while (*pp != nullptr && criterio(nuevo->dato, (*pp)->dato) >= 0)
		pp = &((*pp)->sig);
	nuevo->sig = *pp;
	*pp = nuevo;
}

template <typename T> Nodo<T>* extraer(T clave, Nodo<T>*& lista, int (*criterio)(T, T))
{
	Nodo<T> *aux;
	Nodo<T> **pp = &lista;

	while (*pp != nullptr && criterio(clave, (*pp)->dato) > 0)
		pp = &((*pp)->sig);

	if (*pp != nullptr && criterio(clave, (*pp)->dato) == 0) {
		aux = *pp;
		*pp = (*pp)->sig;
		return aux;
	} else {
		return nullptr;
	}
}

template <typename T> bool borrar(T clave, Nodo<T>*& lista, int (*criterio)(T, T))
{
	Nodo<T>* extraido = extraer(clave, lista, criterio);
	if (extraido) {
		delete extraido;
		return true;
	} else {
		return false;
	}
}

template <typename T> Nodo<T>* insertar_unico(T valor, Nodo<T>*& lista, int (*criterio)(T, T))
{
	Nodo<T>** pp = &lista;
	while (*pp != nullptr && criterio(valor, (*pp)->dato) > 0)
		pp = &((*pp)->sig);
	if (*pp != nullptr && criterio(valor, (*pp)->dato) == 0) {
		return *pp;
	} else {
		Nodo<T>* nuevo = new Nodo<T>;
		nuevo->dato = valor;
		nuevo->sig = *pp;
		*pp = nuevo;
		return nuevo;
	}
}

#endif // LISTAS_HPP_INCLUDED