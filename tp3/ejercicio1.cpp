#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream archiv;
    archiv.open("archivo.txt");
    int nro;
    float suma {0};
    int cant {0};
    float promedio {suma / cant};

    if (!archiv)
    {
        cout << "El archivo seleccionado no es correcto.";
        return 1;
    }
    
    while (archiv >> nro)
    {
        cout << "Leido: " << nro << endl;
        ++cant;  
        suma = suma + cant;
        promedio = suma / cant;
    }
    
    cout << "La cantidad es de numeros escritos es de: " << cant << endl;
    cout << "La sumatoria de los mismos es igual a: " << suma << endl;
    cout << "Y el promedio es igual a: " << promedio;

    archiv.close();

    return 0;

}