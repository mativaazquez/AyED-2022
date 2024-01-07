#include <iostream>
#include "listas.hpp"
using namespace std;

struct Alumno{
    string nombre;
    int legajo;
    double promedio;
};

int critdescendente(Alumno a, Alumno b){
    if (a.promedio == b.promedio)
    {
        return a.nombre.compare(b.nombre);
    }
    else
    {
        return a.promedio > b.promedio ? -1 : 1;
    }
}

ostream& operator << (ostream &os, const Alumno& a){
    os << a.nombre << "\t(legajo: " << a.legajo << ")  :  " << a.promedio;
    return os;
} 

int main(){

    const int lsel{9};
    const int lbaj{3};

    Alumno vsel[lsel] = {"Maria", 721, 8.4, 
    "Pedro", 847, 7.2, 
    "Ana", 614, 9.1, 
    "Jose", 578, 8.9, 
    "Juan", 927, 8.4, 
    "Unai", 325, 8.1, 
    "Ramon", 418, 8.4, 
    "Elaia", 892, 9.6, 
    "Carlos", 733, 8.5};

    Alumno vbaj[lbaj] = {"Pedro", 847, 7.2, 
    "Ramon", 418, 8.4, 
    "Unai", 325, 8.1};

    //Punto 1

    Nodo<Alumno>* listauno = nullptr;

    for (int i = 0; i < lsel; i++)
    {
        insertar(vsel[i], listauno, critdescendente);
    }

    cout << "Listado de los seleccionados en orden:" << endl;    
    mostrar(listauno);

    //Punto 2

    Nodo<Alumno>* listados = nullptr;

    for (int i = 0; i < lbaj; i++)
    {
        agregar(listados, vbaj[i]);
    }

    cout << endl << "============================" << endl;
    cout << "Listado de bajas (sin ordenar):" << endl;
    mostrar(listados);

    //Punto 3

    for (int i = 0; i < lbaj; i++)
    {
        borrar(vbaj[i], listauno, critdescendente);
    }

    cout << endl << "============================" << endl;
    cout << "Listado definitivo sin las bajas:" << endl;
    mostrar(listauno);

    return 0;
}