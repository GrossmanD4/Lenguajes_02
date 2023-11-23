#ifndef LN_2_FUNCIONES_APLICATIVO_H
#define LN_2_FUNCIONES_APLICATIVO_H
#endif

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace this_thread;

string producto, producto_menor, producto_mayor;
float cant, precio, base_menor, base_mayor, precio_tot, *dir_precio;
int posibilidad;

double product();
float validacion(float n);
float descuento(string nombre, float n);


float validacion(float n) {
    cin >> n;
    while (n <= 0) {
        cout << "--- ERROR ---" << endl;
        cin >> n;
    }
    return n;
}

double product() {
    cout << "--- Ingrese la cantidad de productos que comprara ---" << endl;
    cant = validacion(cant);
    base_menor = 0;
    base_mayor = 0;
    precio_tot = 0;
    for (int x = 1; x < cant + 1; ++x) {
        cout << "--- Ingrese el producto ---" << endl;
        cin >> producto;
        cout << "--- Ingrese el precio del producto ---" << endl;
        precio = validacion(precio);
        precio_tot += precio;
        if (x == 1){
            producto_menor = producto;
            base_menor = precio;
        }
        if (precio > base_mayor){
            producto_mayor = producto;
            base_mayor = precio;
        }
        if (precio < base_menor){
            producto_menor = producto;
            base_menor = precio;
        }
    }
    dir_precio = &precio_tot;
    sleep_for(std::chrono::seconds(2));
    cout << "Producto con menor precio --> " << producto_menor << " -- " << base_menor << endl;
    sleep_for(std::chrono::seconds(2));
    cout << "Producto con mayor precio --> " << producto_mayor << " -- " << base_mayor << endl;
    sleep_for(std::chrono::seconds(2));
    cout << "El precio a pagar es --> " << precio_tot << endl;
    return 0;
}

float descuento(string nombre, float n){
    if (*dir_precio>=151 and *dir_precio<=301){
        posibilidad = rand() % 4 + 1;
        if (posibilidad == 4){
            cout << "--- Obtuvo un descuento ---" << endl;
            n *= 0.15;
            cout << "--- El precio total a pagar es --> " << precio_tot-n << "con un descuento del 15% ---" << endl;
            cout << "Tenga un buen dia " << nombre << endl;
            return precio_tot-n;
        }
    }
    if (*dir_precio>=301){
        posibilidad = rand() % 2 + 1;
        if (posibilidad == 2) {
            cout << "--- Obtuvo un descuento ---" << endl;
            n *= 0.15;
            cout << "--- El precio total a pagar es --> " << precio_tot-n << " con un descuento del 15% ---" << endl;
            cout << "Tenga un buen dia " << nombre << endl;
            return precio_tot-n;
        }
    } else {
        cout << "No obtuvo ni un descuento, su precio a pagar sigue siendo el mismo." << endl;
        cout << "Tenga un buen dia " << nombre << endl;
        return 0;
    }
    return 0;
}
