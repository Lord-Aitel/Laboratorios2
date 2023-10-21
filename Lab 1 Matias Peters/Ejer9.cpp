#include <iostream>
#include <string>

using namespace std;

// Enumeración para la categoría
enum Categoria {
    Juvenil,
    Senior,
    Veterano
};

// Estructura Ciclista
struct Ciclista {
    string nombre;
    int edad;
    string club;
    Categoria categoria;
};

// Función para determinar la categoría según la edad
Categoria determinarCategoria(int edad) {
    if (edad <= 18) {
        return Juvenil;
    } else if (edad <= 40) {
        return Senior;
    } else {
        return Veterano;
    }
}

// Función para crear una instancia de la estructura Ciclista
Ciclista crearCiclista(string nombre, int edad, string club) {
    Ciclista ciclista;
    ciclista.nombre = nombre;
    ciclista.edad = edad;
    ciclista.club = club;
    ciclista.categoria = determinarCategoria(edad);
    return ciclista;
}

int main() {
    string nombre, club;
    int edad;

    cout << "Ingrese el nombre del ciclista: ";
    cin >> nombre;
    
    cout << "Ingrese la edad del ciclista: ";
    cin >> edad;
    
    cout << "Ingrese el club del ciclista: ";
    cin >> club;

    Ciclista ciclista = crearCiclista(nombre, edad, club);

    cout << "Datos del ciclista:" << endl;
    cout << "Nombre: " << ciclista.nombre << endl;
    cout << "Edad: " << ciclista.edad << " anios" << endl;
    cout << "Club: " << ciclista.club << endl;
    cout << "Categoria: ";
    
    switch (ciclista.categoria) {
        case Juvenil:
            cout << "Juvenil";
            break;
        case Senior:
            cout << "Senior";
            break;
        case Veterano:
            cout << "Veterano";
            break;
    }
    
    cout << endl;

    return 0;
}