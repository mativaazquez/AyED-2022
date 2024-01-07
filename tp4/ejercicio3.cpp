#include <iostream>
#include <fstream>

using namespace std;

float promediototal{0};
/*
void mostrar(float vec[], int dim)
{
	for (int i = 0; i < dim; ++i)
		cout << "vec[" << i << "]= " << vec[i] << endl;
}
*/
//Descomentar si se quiere cargar por pantalla
//void cargar_pant(float vec[], int dim)
//{
//	for (int i = 0; i < dim; ++i) {
//		cout << "Ingrese el elemento "<< i << ": ";
//		cin >> vec[i];
//	}
//}

//NOTA: cuando se pasa un archivo como parámetro es necesario
//pasarlo por referencia (por valor no compila)
void cargar_arch(float vec[], int dim, ifstream& ifs)
{
	for (int i = 0; i < dim && ifs >> vec[i]; ++i);
//	for (int i = 0; i < dim; ++i)
//		ifs >> vec[i];
}

float promedio(float vec[], int dim)
{
	float sum {0};

	for (int i = 0; i < dim; ++i)
		sum += vec[i];
		promediototal = sum / dim;
	return promediototal; //Nota: los vectores no pueden tener dimensión cero
}

int cantmay(float vec[], int dim)
{
	int cant {0};
	for (int  i = 0; i < dim; ++i)
		if (vec[i] > promediototal)
			++cant;
	return cant;
}

int main()
{
	const int dimvec {10};
	float notas[dimvec];

	//Si se quiere cargar por consola en lugar de archivo
//	cout << "Ingrese las notas:" << endl;
//	cargar_pant(notas, dimvec);

	cout << "Leyendo datos del archivo" << endl;
	ifstream archilec;
	archilec.open("ejercicio3.txt");
	if (!archilec) {
		cout << "Error al tratar de abrir el archivo para lectura" << endl;
		return 1;
	}
	//for (int i = 0; i < dimvec && archilec >> notas[i]; ++i);v
	cargar_arch(notas, dimvec, archilec);
	archilec.close();

	float prom = promedio(notas, dimvec);
	cout << "El promedio es " << prom << endl;

	int cuantos = cantmay(notas, dimvec);
	cout << "La cantidad de alumnos sobre el promedio es " << cuantos << endl;
	return 0;
}