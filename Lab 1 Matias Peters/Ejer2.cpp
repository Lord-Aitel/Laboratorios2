#include <iostream>
#include <string>

using namespace std;

int main() {
    // Declaración e inicialización de las variables
    int entero = 42;
    float decimal = 3.14f;
    double doblePrecision = 2.71828;
    char caracter = 'A';
    string cadena = "Hola, mundo!";
    bool booleano = true;

    // Mostrar los valores de las variables
    cout << "Valor de la variable entero: " << entero << endl;
    cout << "Valor de la variable decimal: " << decimal << endl;
    cout << "Valor de la variable doblePrecision: " << doblePrecision << endl;
    cout << "Valor de la variable caracter: " << caracter << endl;
    cout << "Valor de la variable cadena: " << cadena << endl;
    cout << "Valor de la variable booleano: " << (booleano ? "true" : "false") << endl;

    return 0;
}