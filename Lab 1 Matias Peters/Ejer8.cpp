#include <iostream>
#include <string>

using namespace std;

// Función para verificar el inicio de sesión
bool Login(const string& usuario, const string& contrasena) {
    return (usuario == "user1" && contrasena == "1234");
}

int main() {
    int intentosMaximos = 3;
    bool accesoExitoso = false;

    cout << "Por favor, ingrese sus credenciales." << endl;

    for (int intento = 1; intento <= intentosMaximos; intento++) {
        string usuario, contrasena;

        cout << "Nombre de usuario: ";
        cin >> usuario;

        cout << "Contrasenia: ";
        cin >> contrasena;

        if (Login(usuario, contrasena)) {
            accesoExitoso = true;
            break; // Acceso exitoso, salir del bucle
        } else {
            cout << "Acceso no autorizado. Intentelo de nuevo." << endl;
        }
    }

    if (accesoExitoso) {
        cout << "!Acceso exitoso! Bienvenido, " << "user1" << "." << endl;
    } else {
        cout << "Se agotaron los intentos. Acceso denegado." << endl;
    }

    return 0;
}