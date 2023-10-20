#include <iostream>

using namespace std;

int main() {
    int edad;

    // Solicitar la edad al usuario
    cout << "Ingrese su edad: ";
    cin >> edad;

    // Verificar si la edad está dentro del rango [18 - 25]
    if (edad >= 18 && edad <= 25) {
        cout << "La edad ingresada esta dentro del rango [18 - 25]." << endl;
    } else {
        cout << "La edad ingresada no esta dentro del rango [18 - 25]." << endl;
    }

    return 0;
}