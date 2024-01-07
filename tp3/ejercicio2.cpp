#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream archivo;
    archivo.open("archivo.txt");

    int nro;
    int menor;
    int i = 1;
    int orden = i;

    while (archivo >> nro)
    {
        ++i;
        if (nro < menor)
        {
            menor = nro;
            orden = i;
        }
    }
    
    cout << "El numero de menor valor es: " << nro << ", de orden: " << orden;

    return 0;
}