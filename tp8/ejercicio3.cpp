#include <iostream>
#include <fstream>
#include "listas.hpp"
#include "rwstring.hpp"
using namespace std;

struct Deuda{
    string cliente;
    int mes;
    int cantidad;
};

const int lcli {8};

fstream& operator >> (fstream &fs, Deuda& deu)
{
    deu.cliente = readstring(fs, lcli);
	fs.read(reinterpret_cast<char *>(&deu.mes), sizeof(deu.mes));
	fs.read(reinterpret_cast<char *>(&deu.cantidad), sizeof(deu.cantidad));
	return fs;
}

ostream& operator << (ostream &os, Deuda &a){
    os << a.cliente << "  -  mes: " << a.mes << "  -  cant: " << a.cantidad;
    return os;
}

int criterio(Deuda a, Deuda b){
    if (a.cliente == b.cliente)
        return a.mes - b.mes;
    else
        return a.cliente.compare(b.cliente);
}

template <typename T> void borrarsiguiente(Nodo<T>* lista){
    if (lista->sig != nullptr)
    {
        Nodo<T>* aux = lista->sig;
        lista->sig = lista->sig->sig;
        delete aux;                     //No retorna nada?
    }
}

template <typename T> void consolidar(Nodo<T>* lista){

    while (lista != nullptr)
    {
        while (lista->sig && criterio(lista->dato, lista->sig->dato) == 0)  //Si son iguales
        {
            lista->dato.cantidad += lista->sig->dato.cantidad;
            borrarsiguiente(lista);
        }
        lista = lista->sig;
    }
}

int main(){

    fstream archi;
    Nodo<Deuda>* lista = nullptr;
    Deuda reg;

    //Punto 1

    archi.open("G06E03.bin", ios::in | ios::binary);
    if (!archi){
        cout << "No encontramos el archivo solicitado.";
        return 1;
    }   
    while (archi >> reg){
        insertar(reg, lista, criterio);
    }
    cout << "Lista ordenada por nombre de cliente" << endl;
    mostrar(lista);

    //Punto 2

    consolidar(lista);
    cout << endl << "============================" << endl;
    cout << "Listado de deudas consolidado:" << endl;
    mostrar(lista);

    return 0;
}