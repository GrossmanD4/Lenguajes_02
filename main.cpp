#include <iostream>
#include "Funciones_aplicativo.h"
using namespace std;
string nombre;

int main() {
    cout << "--- Ingrese su nombre ---" << endl;
    cin >> nombre;
    product();
    descuento(nombre, *dir_precio);
    return 0;
}
