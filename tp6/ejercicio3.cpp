#include <iostream>
#include <fstream>
#include "listas.hpp"
#include "rwstring.hpp"

using namespace std;

struct Deuda
{
    string cliente;
    int mes;
    int cant;
};

const int lcli = 8;

ostream& operator << (ostream& os, Deuda& a){
    os << "cliente: " << a.cliente << " - mes: " << a.mes << " - cant: " << a.cant;
    return os;
}

fstream& operator >> (fstream &fs, Deuda& a){
    a.cliente = readstring(fs, lcli);
    fs.read(reinterpret_cast<char*>(&a.mes), sizeof(a.mes));
    fs.read(reinterpret_cast<char*>(&a.cant), sizeof(a.cant));
    return fs;
}

int critcli(Deuda a, Deuda b){
    if (a.cliente == b.cliente)
        return a.mes - b.mes;
    else
        a.cliente > b.cliente ? 1 : -1;
}

template <typename T> void borrarSiguiente(Nodo<T>* lista){
    if (lista->sig)
    {
        Nodo<T>* aux = lista->sig;
        lista->sig = lista->sig->sig;
        delete aux;
    }   
}

void consolidar(Nodo<Deuda>* lista){

    while (lista) {
		while (lista->sig &&
		       critcli(lista->dato, lista->sig->dato) == 0) {
			   //criterio equivalente a
		       //lista->dato.cliente == lista->sig->dato.cliente &&
		       //lista->dato.mes == lista->sig->dato.mes

			lista->dato.cant += lista->sig->dato.cant;
			borrarSiguiente(lista);
		}
		lista = lista->sig;
	}

}

int main(){

    Deuda lista;
    Nodo<Deuda>* listadeudas = nullptr;
    fstream archivo;

    archivo.open("G06E03.bin", ios::binary | ios::in);
    if (!archivo)
    {
        cout << "No se pudo abrir el archivo de lectura" << endl;
        return EXIT_FAILURE;
    }
    while (archivo >> lista)
    {
        insertar(lista, listadeudas, critcli);
    }
    archivo.close();

    cout << "=======================================" << endl;
    cout << "---- Mostrando lista ORDENADA ----" << endl;
    mostrar(listadeudas);
    cout << endl << "=======================================" << endl;
    cout << "---- Mostrando lista CONSOLIDADA ----" << endl;
    consolidar(listadeudas);
    mostrar(listadeudas);

    return 0;
}