#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <limits>

using namespace std;

unsigned long long factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return static_cast<unsigned long long>(n) * factorial(n - 1);
    }
}

unsigned long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

bool esPalindromo(const string &cadena) {
    if (cadena.length() <= 1) {
        return true;
    }

    char primerCaracter = tolower(cadena[0]);
    char ultimoCaracter = tolower(cadena[cadena.length() - 1]);

    if (!isalnum(primerCaracter)) {
        return esPalindromo(cadena.substr(1, cadena.length() - 1));
    } else if (!isalnum(ultimoCaracter)) {
        return esPalindromo(cadena.substr(0, cadena.length() - 1));
    } else if (primerCaracter != ultimoCaracter) {
        return false;
    } else {
        return esPalindromo(cadena.substr(1, cadena.length() - 2));
    }
}

int main() {
    int opcion;
    
    do {
        cout << "     ----Menu de ejercicios---" << endl;
        cout << "/[1]   para Calcular factoriales \\" << endl;
        cout << "/[2]    para Calcular Fibonacci  \\" << endl;
        cout << "/[3] para Verificar un palindromo\\" << endl;
        cout << "/[4] para Operaciones matematicas\\" << endl;
        cout << "/[5]            para Salir       \\" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1: {
                int n;
                cout << "Ingrese un nemero para calcular su factorial: ";
                if (!(cin >> n)) {
                    cout << "Entrada invalida. Por favor, ingrese un numero entero." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                cout << "El factorial de " << n << " es " << factorial(n) << endl;
                break;
            }
            case 2: {
                int n;
                cout << "Ingrese un valor de n para calcular el n-esimo numero de Fibonacci: ";
                if (!(cin >> n)) {
                    cout << "Entrada invalida. Por favor, ingrese un numero entero." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                cout << "El " << n << "-esimo numero de Fibonacci es " << fibonacci(n) << endl;
                break;
            }
            case 3: {
                cin.ignore(); // Limpiar el buffer de entrada
                string entrada;
                cout << "Ingrese una palabra o oracion para verificar si es un palindromo: ";
                getline(cin, entrada);
                if (esPalindromo(entrada)) {
                    cout << "Es un palindromo." << endl;
                } else {
                    cout << "No es un palindromo." << endl;
                }
                break;
            }
            case 4: {
                int n;
                cout << "Ingrese la cantidad de numeros: ";
                cin >> n;
                if (n <= 0) {
                    cout << "La cantidad de nmeros debe ser un entero positivo." << endl;
                    break;
                }

                vector<double> numeros;
                for (int i = 0; i < n; i++) {
                    double numero;
                    cout << "Ingrese el numero " << (i + 1) << ": ";
                    cin >> numero;
                    numeros.push_back(numero);
                }

                double suma = 0;
                double producto = 1;
                for (double numero : numeros) {
                    suma += numero;
                    producto *= numero;
                }

                double promedio = suma / n;

                cout << "La suma de los numeros es: " << suma << endl;
                cout << "El promedio de los numeros es: " << promedio << endl;
                cout << "El producto de los numeros es: " << producto << endl;
                break;
            }
            case 5:
                cout << "Fin del Ejercicio" << endl;
                break;
            default:
                cout << "Opcion no valida, ingresa una opcion valida." << endl;
                break;
        }
    } while (opcion != 5);

    return 0;
}