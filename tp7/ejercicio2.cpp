#include <iostream>
#include <fstream>
#include "listas.hpp"
#include "rwstring.hpp"
using namespace std;

struct Registro {                   //Su utilidad es para leer el archivo binario correctamente
	string ciudad;
	string modelo;
	int cant;
};
const int lciu = 12;
const int lmod = 10;

struct Venta {                      //Meramente para el punto 2
	string modelo;
	int cant;
};

struct Ciudad {
	string ciudad;
	int totvtas = 0;                //A estos les da valores "0" para poder hacer lo del insertar_unico
	int totcant = 0;
	Nodo<Venta> *lisvtas = nullptr; //Esto es un puntero a la estructura de Ventas que está arriba
};                                  //al estar declarado solo el modelo y la cant, va a servir para el punto 2

ostream& operator << (ostream &os, const Ciudad& ciu)
{
	os << ciu.ciudad << "\t" << ciu.totvtas << "\t" << ciu.totcant;
	return os;
}

ostream& operator << (ostream &os, const Venta& vta)
{
	os << vta.modelo << "\t" << vta.cant;
	return os;
}

fstream& operator >> (fstream &fs, Registro& reg)
{
	reg.ciudad = readstring(fs, lciu);
	reg.modelo = readstring(fs, lmod);;
	fs.read(reinterpret_cast<char *>(&reg.cant), sizeof(reg.cant));
	return fs;
}

//por ciudad ascendente
int critciu(Ciudad a, Ciudad b)
{
	return a.ciudad.compare(b.ciudad);
}

int main()
{
	Nodo<Ciudad> *listaciu = nullptr;
	fstream archi;

	archi.open("G07E02.bin", ios::in | ios::binary);
	if (!archi) {
		cout << "No se pudo abrir el primer archivo de lectura "
		     "G07E02.bin" << endl;
		return EXIT_FAILURE;
	}
	Registro reg;
	Ciudad ciu;
	Venta vta;
	Nodo<Ciudad> *pnodciu;
	while (archi >> reg) {                                  //Mientras que el archivo esté en el Registro
		ciu.ciudad = reg.ciudad;                            //Para que no se cambien los nombres de las ciudades
		pnodciu = insertar_unico(ciu, listaciu, critciu);   //ciu(cumplirá el rol de ser el "0"), listaciu(la que le sumará lo demás en el ciclo) y critciu para el orden ascendente
		pnodciu->dato.totvtas++;                            //Lo anterior se guarda en el puntero de Ciudad y hace un contador para ver el total de las ventas
		pnodciu->dato.totcant += reg.cant;                  //Hace la suma iterativa con lo que venga del insertar_unico con la cantidad que ya estaba en la lista original
		vta.modelo = reg.modelo;                            //Le copio a VENTAS lo que hay en el archivo
		vta.cant = reg.cant;                                //Le copio a VENTAS lo que hay en el archivo
		agregar(pnodciu->dato.lisvtas, vta);                //Para el punto 2? PREGUNTAR (un poco me perdí que hizo acá)
	}
	archi.close();

	cout << "Listado de ciudades con totales de ventas y cantidades vendidas:" << endl;
	cout << "Ciudad\t\tVentas\tUnidades" << endl;
	mostrar(listaciu);                                      //Muestra la lista del punto 1 como tiene que ser

	cout << endl << "============================" << endl;
	cout << "Ingrese la ciudad a listar: ";
	while (cin >> ciu.ciudad) {
		pnodciu = buscar(ciu, listaciu, critciu);
		if (pnodciu) {
			cout << "Ventas en la ciudad " << ciu.ciudad  << endl;
			cout << "Modelo\tCantidad" << endl;
			mostrar(pnodciu->dato.lisvtas);
			cout << endl;
		} else {
			cout << "No hay datos de la ciudad " << ciu.ciudad << endl;
		}
		cout << "Ingrese la ciudad a listar: ";
	}
	cin.clear();
	cout << endl << "============================" << endl;
	int cantmin;
	cout << "Ingrese Ciudad: ";
	if (cin >> ciu.ciudad)
		cout << "Ingrese cantidad mínima: ";
		while (cin >> cantmin) {
			pnodciu = buscar(ciu, listaciu, critciu);
			if (pnodciu) {
				Nodo<Venta> *p = pnodciu->dato.lisvtas;         //Por qué el puntero a Nodo es de struct Venta?
				int cantsup = 0;
				while (p) {
					if (p->dato.cant > cantmin)
						cantsup++;
					p = p->sig;
				}
				cout << "Ventas en " << ciu.ciudad << " con cantidad "
					"mayor a " << cantmin << ": " << cantsup << endl;
			} else {
				cout << "No hay datos de la ciudad " << ciu.ciudad << endl;
			}
			cout << "Ingrese Ciudad: ";
			if (cin >> ciu.ciudad)
				cout << "Ingrese cantidad mínima: ";
	}
	return 0;
}
