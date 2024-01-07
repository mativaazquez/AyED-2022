#include <iostream>
#include <fstream>
#include "listas.hpp"
#include "rwstring.hpp"
using namespace std;

struct Modelo{
    string modelo;
    int cant;
};

const int lmodelo = 10;

ostream& operator << (ostream& os, Modelo& a){
    os << a.modelo << ": " << a.cant;
    return os;
}

ostream& operator >> (fstream& fs, Modelo& a){
    a.modelo = readstring(fs, lmodelo);
    fs.read(reinterpret_cast<char*>(&a.cant), sizeof(a.cant));
    return fs;
}

int critmod(Modelo a, Modelo b){
    return a.modelo.compare(b.modelo);
}

int main(){

    Modelo lista;
    Nodo<Modelo>* listamodelo = nullptr;
    fstream archivo;

    archivo.open("G07E01.bin", ios::binary | ios::in);
    if (!archivo)
    {
        cout << "No se encuentra el archivo de lectura" << endl;
        return EXIT_FAILURE;
    }

    Modelo mod0;
    mod0.cant = 0;
    Nodo<Modelo>* pnodo;
    
    while (archivo >> lista) //ASÍ se hacen lo "ciclos" con archivos binarios
    {
        mod0.modelo = lista.modelo; //Para que no se cambien los nombres de los modelos
        pnodo = insertar_unico(mod0, listamodelo, critmod);
        pnodo->dato.cant += lista.cant;
    }    
    archivo.close();

    cout << endl << "======> Mostrando lista CONSOLIDADA <======" << endl;
    mostrar(listamodelo);

    return 0;
}