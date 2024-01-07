#include <iostream>
#include <fstream>
#include "listas.hpp"
#include "rwstring.hpp"
using namespace std;

struct Registro
{
    string ciudad;
    string modelo;
    int cant;
};

struct Listado
{
    string modelo;
    int cant;
};

struct Ventas
{
    string ciudad;
    int totvta = 0;
    int totuni = 0;
    Nodo<Listado>* listados = nullptr;
};

const int lciu = 12;
const int lmod = 10;

ostream& operator << (ostream &os, const Ventas& a){
    os << a.ciudad << "\t" << a.totvta << "\t" << a.totuni;
    return os;
}

ostream& operator << (ostream &os, const Listado& a){
    os << a.modelo << "\t" << a.cant;
    return os;
}

fstream& operator >> (fstream &fs, Registro& a){
    a.ciudad = readstring(fs, lciu);
    a.modelo = readstring(fs, lmod);
    fs.read(reinterpret_cast<char *>(&a.cant), sizeof(a.cant));
    return fs;
}

int critvta (Ventas a, Ventas b){
    return a.ciudad.compare(b.ciudad);
}

int main(){

    fstream archi;
    Nodo<Ventas>* listavta = nullptr;
    Nodo<Ventas>* vtaptr;
    Ventas vta;
    Registro reg;
    Listado list;

    archi.open("G07E02.bin", ios::in | ios::binary);
    if (!archi)
    {
        cout << "El archivo G07E02.bin no se encuentra disponible." << endl;
        return 1;
    }

    while (archi >> reg)
    {
        vta.ciudad = reg.ciudad;
        vtaptr = insertar_unico(vta, listavta, critvta);
        vtaptr->dato.totvta++;
        vtaptr->dato.totuni += reg.cant;
        list.modelo = reg.modelo;
        list.cant = reg.cant;
        agregar(vtaptr->dato.listados, list);
    }
    archi.close();

    cout << "Listado de ciudades con totales de ventas y cantidades vendidas:" << endl;
    cout << "Ciudad\t\tVentas\tUnidades" << endl;
    mostrar(listavta);

    cout << endl << "============================" << endl;
    cout << "Ingrese la ciudad a listar: ";
    while (cin >> vta.ciudad && vta.ciudad != "EOF")
    {
        vtaptr = buscar(vta, listavta, critvta);
        if (vtaptr)
        {
            cout << "Ventas en la ciudad " << vta.ciudad << endl;
            cout << "Modelo\tCantidad" << endl;
            mostrar(vtaptr->dato.listados);
        }
        else
        {
            cout << "No hay datos de la ciudad " << vta.ciudad;
        }
        cout << endl << "Ingrese la ciudad a listar: ";
    }

    cout << "============================" << endl;
    cout << endl << "Ingrese Ciudad: ";
    if (cin >> vta.ciudad && vta.ciudad != "EOF")
    {
        cout << "Ingrese cantidad minima: ";
        int cantmin = 0;
        while (cin >> cantmin && cantmin != 0)
        {
            vtaptr = buscar(vta, listavta, critvta);
            if (vtaptr){
                Nodo<Listado>* p = vtaptr->dato.listados;
                int cantsuperada = 0;
                while (p)
                {
                    if (p->dato.cant > cantmin)
                    {
                        cantsuperada++;
                    }
                    p = p->sig;
                }
                cout << "Ventas en " << vta.ciudad << " con cantidad mayor a " 
                << cantmin << ": " << cantsuperada;
            }
            else{
                cout << "No hay datos de la ciudad " << vta.ciudad << "." << endl;
            }
            cout << endl << "Ingrese Ciudad: ";
            if (cin >> vta.ciudad)
            {
                cout << "Ingrese cantidad minima: ";
            }
        }     
    }
    
    return 0;
}