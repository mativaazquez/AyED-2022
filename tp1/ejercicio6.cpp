#include <iostream>
using namespace std;
int main(){

    double num1, num2;

    cout << "Ingrese un valor: ";
    cin >> num1;

    cout << "Ingrese otro valor: ";
    cin >> num2;

    if (num1 > num2){
        cout << num1 << " es el mayor";
    }

    else if (num1 == num2){
        cout << "son iguales, a quien le queres mentir pancho?";
    }  

    else{
        cout << num2 << " es el mayor";
    }

    return 0;
}