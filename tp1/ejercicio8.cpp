#include <iostream>
using namespace std;
int main(){

    int a, b, c;

    cout << "Ingrese tres numeros enteros:" << endl;
    cin >> a >> b >> c;

    cout << "Se ingreso: " << a << " - " << b << " - " << c << endl;
    cout << "Asi seria si los ordenamos de mayor a menor: ";

    if (a > b && b > c){
        cout << a << " - " << b << " - " << c;
    }

    else if (b > a && a > c){
        cout << b << " - " << a << " - " << c;
    }

    else if (c > b && b > a){
        cout << c << " - " << b << " - " << a;
    }

    else if (b > c && c > a){
        cout << b << " - " << c << " - " << a;
    }

    else if (c > a && a > b){
        cout << c << " - " << a << " - " << b;
    }

    else{
        cout << a << " - " << c << " - " << b;
    }

    return 0;
}