#include <iostream>
#include <fstream>
#include "listas.hpp"
#include "rwstring.hpp"
using namespace std;

struct Registro
{
    string cereal;
    string pais;
    string naviera;
    double peso;
    int compras;
};

struct Pedidos
{
    string pais;
    string cereal;
    double peso;
};

struct PaisPed
{
    string pais;
    int compras;
};

struct Naviera
{
    string naviera;
    double totpes = 0;
    int totcomp = 0;
    Nodo<PaisPed>* listapaisped = nullptr;
};

int lcel = 8;
int lpais = 10;
int lnav = 10;

ostream& operator << (ostream& os, Registro& a){
    os << a.cereal << "\t" << a.pais << "\t" << a.naviera << "\t" 
    << a.peso << "\t" << a.compras;
    return os;
}

ostream& operator << (ostream& os, Pedidos& a){
    os << a.pais << "\t" << a.cereal << "\t" << a.peso;
    return os;
}

ostream& operator << (ostream& os, Naviera& a){
    os << a.naviera << "  -  Peso a enviar: " << a.totpes << "  - Cantidad de Compras: " << a.totcomp << " - Promedio: "
    << (a.totcomp == 0 ? 0 : a.totpes / a.totcomp) << endl; 
    mostrar(a.listapaisped);
    return os;
}

ostream& operator << (ostream& os, PaisPed& a){
    os << a.pais << "\t" << a.compras;
    return os;
}

fstream& operator >> (fstream& fs, Registro& a){
    a.cereal = readstring(fs, lcel);
    a.pais = readstring(fs, lpais);
    a.naviera = readstring(fs, lnav);
    fs.read(reinterpret_cast<char *>(&a.peso), sizeof(a.peso));
    fs.read(reinterpret_cast<char *>(&a.compras), sizeof(a.compras));
    return fs;
}

int critped(Pedidos a, Pedidos b){
    if (a.pais == b.pais){
        return a.cereal.compare(b.cereal);
    }
    else{
        return a.pais.compare(b.pais);
    }
}

int critnav(Naviera a, Naviera b){
    return a.naviera.compare(b.naviera);
}

int main(){

    fstream archi;
    Nodo<Registro>* listareg = nullptr;
    Nodo<Pedidos>* listaped = nullptr;
    Nodo<Naviera>* listanav = nullptr;
    Nodo<Naviera>* navptr;
    Registro reg;
    Pedidos ped;
    Naviera nav;
    PaisPed paisped;

    archi.open("Datos.bin", ios::in | ios::binary);
    if (!archi){
        cout << "El archivo no se encuentra disponible." << endl;
        return 1;
    }
    
    while (archi >> reg){
        //Punto 1
        agregar(listareg, reg);

        //Punto 2
        if (reg.compras > 3){
            ped.pais = reg.pais;
            ped.cereal = reg.cereal;
            ped.peso = reg.peso;
            insertar(ped, listaped, critped);
        }

        //Punto 3
        nav.naviera = reg.naviera;
        navptr = insertar_unico(nav, listanav, critnav);
        navptr->dato.totpes += reg.peso;
        navptr->dato.totcomp += reg.compras;
        paisped.pais = reg.pais;
        paisped.compras = reg.compras;
        agregar(navptr->dato.listapaisped, paisped);
    }
    archi.close();
    
    //Punto 1
    cout << "Cereal\tPais\tNaviera\t\tPeso\tCompras" << endl;
    cout << "==============================================" << endl;
    mostrar(listareg);

    //Punto 2
    cout << endl << "Pais\t\tCereal\tPeso" << endl;
    cout << "==============================" << endl;
    mostrar(listaped);

    //Punto 3
    cout << endl;
    mostrar(listanav);


    return 0;
}