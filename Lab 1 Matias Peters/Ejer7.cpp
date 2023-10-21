#include <iostream>

using namespace std;

int encontrarMayor(int numero1, int numero2) {
    if (numero1 > numero2) {
        return numero1;
    } else if (numero2 > numero1) {
        return numero2;
    } else {
        return -1;
    }
}

int main() {
    int numero1, numero2;

    do {
        cout << "Ingrese el primer numero (debe ser mayor que 0): ";
        cin >> numero1;
    } while (numero1 <= 0);

    do {
        cout << "Ingrese el segundo numero (debe ser mayor que 0): ";
        cin >> numero2;
    } while (numero2 <= 0);

    int resultado = encontrarMayor(numero1, numero2);

    if (resultado == -1) {
        cout << "Los numeros ingresados son iguales." << endl;
    } else {
        cout << "El numero mayor es: " << resultado << endl;
    }

    return 0;
}