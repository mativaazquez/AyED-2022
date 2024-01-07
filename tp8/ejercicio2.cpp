#include <iostream>
#include <fstream>
#include "listas.hpp"
#include "rwstring.hpp"
using namespace std;

struct Compras{
    int id;
    string cliente;
    string producto;
    int cantidad;
};

const int lcli{8};
const int lprod{10};

ostream& operator << (ostream &os, Compras& a){
    os << "id: " << a.id << "  -  " << a.cliente << "  -  " << a.producto << "  -  " << a.cantidad;
    return os;
}

fstream& operator >> (fstream &fs, Compras& ord)
{
	fs.read(reinterpret_cast<char *>(&ord.id), sizeof(ord.id));
	ord.cliente = readstring(fs, lcli);
	ord.producto = readstring(fs, lprod);
	fs.read(reinterpret_cast<char *>(&ord.cantidad), sizeof(ord.cantidad));
	return fs;
}

int critcli(Compras a, Compras b){
    if (a.cliente == b.cliente)
        return a.producto.compare(b.producto);
    else
        return a.cliente > b.cliente ? 1 : -1;
}

int critid(Compras a, Compras b)
{
    return a.id - b.id;
}

int main(){

    fstream archi;
    Nodo<Compras>* listauno = nullptr;
    Nodo<Compras>* listados = nullptr;
    Compras orden;

    archi.open("G06E02.bin", ios::in | ios::binary);
    if (!archi)
    {
        cout << "No encontramos el archivo 06E02.bin en el dispositivo.";
        return 1;
    }

    //Punto 1

    while (archi >> orden)
    {
        insertar(orden, listauno, critcli);
        insertar(orden, listados, critid);
    }
    archi.close();

    cout << "Listado ordenado por id:" << endl;
    mostrar(listados);

    cout << endl << "============================" << endl;
    cout << "Listado ordenado por cliente-producto:" << endl;
    mostrar(listauno);

    //Punto 2

    cout << endl << "Ingrese un id a buscar: ";
    Nodo<Compras> *cptr;
    while (cin >> orden.id && orden.id != 0)
    {
        cptr = buscar(orden, listados, critid);
        if (cptr)
            cout << "Encontramos a: " << cptr->dato << endl;
        else
            cout << "No logramos encontrar a nadie con " << orden.id << " como id." << endl;
        cout << "Ingrese otro id a buscar (0 para terminar): ";
    }  
    cout << "============================" << endl;

    //Punto 3

    cin.clear();
    cout <<  endl <<"============================" << endl;
    cout << "Eliminacion por Nombre - Producto" << endl;
    cout << endl << "Ingrese un nombre de cliente: ";
    if (cin >> orden.cliente)
        cout << "Ingrese el nombre de un producto: ";
    while (cin >> orden.producto && orden.producto != "EOF")
    {
        cout << endl << "Fila/s eliminada/s: " << endl;
        while (cptr = extraer(orden, listauno, critcli)){
            cout << cptr->dato << endl;
            orden.id = cptr->dato.id; 
            delete cptr;
            if (!borrar(orden, listados, critid)) 
                cout << "Problema Inesperado! No encontramos nada acorde a lo solicitado." << endl;
        }

        cout << endl << "============================";
        cout << endl << "Mostrando lista modificada" << endl;
        mostrar(listauno);

        cout << endl << "Ingrese un nombre de cliente: ";
        if (cin >> orden.cliente)
            cout << "ingrese el nombre de un producto: ";
    }    
    
    return 0;
}