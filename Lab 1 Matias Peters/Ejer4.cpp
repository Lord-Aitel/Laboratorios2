#include <iostream>
#include <string>

using namespace std;

int main() {
    std::string nombre;
    double numero1, numero2;

    // Solicitar el nombre al usuario
    cout << "Ingrese su nombre: ";
    cin >> nombre;

    // Solicitar los dos números al usuario
    cout << "Ingrese el primer numero: ";
    cin >> numero1;

    cout << "Ingrese el segundo numero: ";
    cin >> numero2;

    // Realizar cálculos
    double suma = numero1 + numero2;
    double resta = numero1 - numero2;
    double multiplicacion = numero1 * numero2;
    double division = numero1 / numero2;
    double promedio = (suma + resta + multiplicacion + division) / 4;

    // Mostrar saludo y resultados
    cout << "Hola, " << nombre << "!" << endl;
    cout << "Suma: " << suma << endl;
    cout << "Resta: " << resta << endl;
    cout << "Multiplicacion: " << multiplicacion << endl;
    cout << "Division: " << division << endl;
    cout << "Promedio: " << promedio << endl;

    return 0;
}