#include <iostream>
using namespace std;

int main(){

    unsigned long long int num = 1;

    for (int i = 1; i <= 64; i++){
	    num = 2 * num;
        cout << "Casillero numero " << i << ". Granos: " << num - 1 << endl;
    }

    return 0;
}