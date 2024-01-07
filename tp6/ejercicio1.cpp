#include <iostream>

using namespace std;

template <typename T> struct Nodo {
	T dato; 
	Nodo<T>* sig; 
};

template <typename T> void mostrar(Nodo<T>* lista)
{
	while (lista != nullptr) {
		cout << lista->dato << endl;
		lista = lista->sig;
	}
}

template <typename T> void insertar(T valor, Nodo<T>*& lista, int (*criterio)(T, T))
{
	Nodo<T>* nuevo = new Nodo<T>;
	nuevo->dato = valor;

	Nodo<T>* anterior = nullptr;
	Nodo<T>* actual = lista;

	while (actual != nullptr && criterio(nuevo->dato, actual->dato) >= 0) {
		anterior = actual;
		actual = actual->sig;
	}

	if (anterior == nullptr) {
		lista = nuevo;
	} else {
		anterior->sig = nuevo;
	}
	nuevo->sig = actual;
}

template <typename T> Nodo<T>* extraer(T clave, Nodo<T>*& lista, int (*criterio)(T, T))
{
	Nodo<T>* anterior = nullptr;
	Nodo<T>* actual = lista;

	while (actual != nullptr && criterio(clave, actual->dato) > 0) {
		anterior = actual;
		actual = actual->sig;
	}

	if(actual != nullptr && criterio(clave, actual->dato) == 0) {
		if (anterior == nullptr) 
			lista = actual->sig;
		else
			anterior->sig = actual->sig;
		actual->sig = nullptr; 
		return actual; 
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

struct Alumno {
    string nombre;
    int legajo;
    double promedio;
};

int criterioalum(Alumno a, Alumno b){
    if (a.promedio == b.promedio)
    {
        a.nombre.compare(b.nombre); //Si empatan en la clave "promedios" resuelvo por nombres
    }
    else
    {
        return a.promedio > b.promedio ? -1 : 1;
    }
}

ostream& operator << (ostream &os, const Alumno& a){
    os << a.nombre << "\t(legajo: " << a.legajo << ") : " << a.promedio;
    return os;
}

int main(){
    const int lrepre = 9;
    const int lbaja = 3;

    Alumno vrepre[lrepre] = {{"Maria", 721, 8.4}, 
            {"Pedro", 847, 7.2}, 
            {"Ana", 614, 9.1}, 
            {"Jose", 578, 8.9}, 
            {"Juan", 927, 8.4}, 
            {"Unai", 325, 8.1}, 
            {"Ramon", 418, 8.4}, 
            {"Elaia", 892, 9.6}, 
            {"Carlos", 733, 8.5}};

    Alumno vbaja[lbaja] = {{"Pedro", 847, 7.2},
            {"Ramon", 418, 8.4}, 
            {"Unai", 325, 8.1}};

    Nodo<Alumno>* lista = nullptr;

    cout << "Los alumnos que represen a la facultad en orden descendente: " << endl;

    for (int i = 0; i < lrepre; i++)
    {
        insertar(vrepre[i], lista, criterioalum);
    }
    
    mostrar(lista);

    cout << endl << "Los alumnos dados de baja: " << endl;
    
    for (int i {}; i < lbaja; ++i){
		cout << vbaja[i] << endl;   //Esto solo puede ejecutarse si se hace una sobrecarga
    }

    cout << endl << "Lista final de alumnos sin los que fueron dados de baja: " << endl;

    for (int i {}; i < lbaja; ++i){
		borrar(vbaja[i], lista, criterioalum); 
    }
    mostrar(lista);

    return 0;
}