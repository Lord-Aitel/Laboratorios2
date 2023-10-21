#include <iostream>
#include <string>

using namespace std;

// Estructura Registro
struct Registro {
    double nota1;
    double nota2;
    double nota3;
    double promedio;
};

// Estructura Alumno
struct Alumno {
    string nombre;
    int edad;
    string matricula;
    Registro registro;
};

// Función para ingresar datos de un alumno
void ingresarDatos(Alumno &alumno) {
    cout << "Ingrese el nombre del alumno: ";
    cin >> alumno.nombre;
    cout << "Ingrese la edad del alumno: ";
    cin >> alumno.edad;
    cout << "Ingrese el numero de matricula del alumno: ";
    cin >> alumno.matricula;
    cout << "Ingrese la nota 1: ";
    cin >> alumno.registro.nota1;
    cout << "Ingrese la nota 2: ";
    cin >> alumno.registro.nota2;
    cout << "Ingrese la nota 3: ";
    cin >> alumno.registro.nota3;
}

// Función para calcular el promedio de un alumno
void calcularPromedio(Alumno &alumno) {
    alumno.registro.promedio = (alumno.registro.nota1 + alumno.registro.nota2 + alumno.registro.nota3) / 3.0;
}

// Función para imprimir los datos de un alumno
void imprimirDatos(Alumno &alumno) {
    cout << "Nombre del alumno: " << alumno.nombre << endl;
    cout << "Edad: " << alumno.edad << " anios" << endl;
    cout << "Numero de matrícula: " << alumno.matricula << endl;
    cout << "Notas: " << alumno.registro.nota1 << ", " << alumno.registro.nota2 << ", " << alumno.registro.nota3 << endl;
    cout << "Promedio: " << alumno.registro.promedio << endl;
}

int main() {
    Alumno alumno1, alumno2;

    cout << "Ingrese los datos del primer alumno:" << endl;
    ingresarDatos(alumno1);
    calcularPromedio(alumno1);

    cout << "Ingrese los datos del segundo alumno:" << endl;
    ingresarDatos(alumno2);
    calcularPromedio(alumno2);

    cout << "\nDatos del primer alumno:" << endl;
    imprimirDatos(alumno1);

    cout << "\nDatos del segundo alumno:" << endl;
    imprimirDatos(alumno2);

    return 0;
}
