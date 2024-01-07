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
const int lcli = 8;		
const int lprod = 10;	//Valores para serializar ambos campos

ostream& operator << (ostream& os, Compras& a){
    os << "id: " << a.id << " - " << a.cliente << " - " << a.producto << " - cant " << a.cantidad;
    return os;
}

fstream& operator << (fstream &fs, const Compras& ord)	//Para escribir el archivo es "<<"
{
	fs.write(reinterpret_cast<const char *>(&ord.id), sizeof(ord.id));
	writestring(fs, ord.cliente, lcli);
	writestring(fs, ord.producto, lprod);
	fs.write(reinterpret_cast<const char *>(&ord.cantidad), sizeof(ord.cantidad));
	return fs;
}

fstream& operator >> (fstream &fs, Compras& ord)	//Para leer el archivo es ">>"
{
	fs.read(reinterpret_cast<char *>(&ord.id), sizeof(ord.id));
	ord.cliente = readstring(fs, lcli);
	ord.producto = readstring(fs, lprod);
	fs.read(reinterpret_cast<char *>(&ord.cantidad), sizeof(ord.cantidad));
	return fs;
}													//Vos ponelo si ves que habla de Archivos Binarios

int critid(Compras a, Compras b){
    return a.id - b.id;
}

int critcli(Compras a, Compras b){
    if (a.cliente == b.cliente)
        return a.producto.compare(b.producto);
    else
        return a.cliente > b.cliente ? 1 : -1;
}


int main() {

    Nodo<Compras>* listaid = nullptr;
    Nodo<Compras>* listaclientes = nullptr;
    Compras orden;
	fstream archivo;

    archivo.open("G06E02.bin", ios::binary | ios::in);
    if (!archivo){
		cout << "No se pudo abrir el primer archivo de lectura "
		     "G06E02.bin" << endl;
		return EXIT_FAILURE;
    }
    while (archivo >> orden)
    {
        insertar(orden, listaclientes, critcli);
        insertar(orden, listaid, critid);
    }
    archivo.close();
    
	cout << "Listado ordenado por id: " << endl;
    mostrar(listaid);

	cout << endl << "Listado ordenado por cliente-producto: "<<endl;
	mostrar(listaclientes);

	cout << endl << "============================" << endl;
	cout << "---- Busqueda por ID ----" << endl;
	cout << "Ingrese el ID: ";
	Compras comclave;
	Nodo<Compras> *cptr;
	while (cin >> comclave.id && comclave.id > 0)
	{
		cptr = buscar(comclave, listaid, critid);
		if (cptr != nullptr)
			cout << "Encontramos a: " << cptr->dato << endl;
		else
			cout << "No hay nadie con " << comclave.id << " ID."<< endl;
		cout << "Ingrese el ID: ";	
	}
	cout << endl << "====================================" << endl;

	cin.clear();
	cout << "---- Borrar por NOMBRE y PRODUCTO ----" << endl;
	cout << "Ingrese el NOMBRE del CLIENTE: ";
	if (cin >> orden.cliente)
		cout << "Ingrese el NOMBRE del PRODUCTO: ";
		while (cin >> orden.producto && orden.producto != "FIN")
		{
			cout << "Eliminados: " << endl;
			while (cptr = extraer(orden, listaclientes, critcli))
			{
				cout << cptr->dato << endl;
				orden.id = cptr->dato.id;
				delete cptr;
				if (!borrar(orden, listaclientes, critcli)){
					cout << "Problema inesperado, no se pudo borrar la orden que pidió";	
				}
			}
			/*
			cout << "====================================" << endl;		
			cout << endl << "Listado ordenado por ID: " << endl;
			mostrar(listaid);
			*/
			cout << "====================================" << endl;		
			cout << endl << "Listado ordenado por cliente-producto modificado: " << endl;
			mostrar(listaclientes);

			cout << endl << "Ingrese el NOMBRE del CLIENTE: ";
			if (cin >> orden.cliente)
				cout << "Ingrese el NOMBRE del PRODUCTO: ";
	}

    return 0;
}