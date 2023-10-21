#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    
    int numeroSecreto = rand() % 100 + 1;
    int intento;
    int intentosRealizados = 0;

    cout << "!Adivina el numero secreto entre 1 y 100!" << endl;

    do {
        cout << "Ingresa tu intento: ";
        cin >> intento;
        intentosRealizados++;

        if (intento < numeroSecreto) {
            cout << "El numero secreto es mayor. Intenta de nuevo." << endl;
        } else if (intento > numeroSecreto) {
            cout << "El numero secreto es menor. Intenta de nuevo." << endl;
        } else {
            cout << "!Felicitaciones! Adivinaste el numero secreto (" << numeroSecreto << ") en " << intentosRealizados << " intentos." << endl;
        }
    } while (intento != numeroSecreto);

    return 0;
}