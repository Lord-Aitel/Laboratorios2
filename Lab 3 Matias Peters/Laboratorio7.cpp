#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* hijoIzquierdo;
    Nodo* hijoDerecho;

    Nodo(int val) : valor(val), hijoIzquierdo(nullptr), hijoDerecho(nullptr) {}
};

class ArbolBinario {
public:
    ArbolBinario() : raiz(nullptr) {}

    Nodo* crearNodo(int valor) {
        return new Nodo(valor);
    }

    void insertarNodo(int valor) {
        Nodo* nuevoNodo = crearNodo(valor);
        if (raiz == nullptr) {
            raiz = nuevoNodo;
        } else {
            insertarEnArbol(raiz, nuevoNodo);
        }
    }

    void insertarEnArbol(Nodo* padre, Nodo* nuevoNodo) {
        if (nuevoNodo->valor < padre->valor) {
            if (padre->hijoIzquierdo == nullptr) {
                padre->hijoIzquierdo = nuevoNodo;
            } else {
                insertarEnArbol(padre->hijoIzquierdo, nuevoNodo);
            }
        } else {
            if (padre->hijoDerecho == nullptr) {
                padre->hijoDerecho = nuevoNodo;
            } else {
                insertarEnArbol(padre->hijoDerecho, nuevoNodo);
            }
        }
    }

    void imprimirEnOrden(Nodo* nodo) {
        if (nodo != nullptr) {
            imprimirEnOrden(nodo->hijoIzquierdo);
            cout << nodo->valor << " ";
            imprimirEnOrden(nodo->hijoDerecho);
        }
    }

    bool buscarValor(Nodo* nodo, int valor) {
        if (nodo == nullptr) {
            return false;
        }

        if (nodo->valor == valor) {
            return true;
        }

        if (valor < nodo->valor) {
            return buscarValor(nodo->hijoIzquierdo, valor);
        } else {
            return buscarValor(nodo->hijoDerecho, valor);
        }
    }

    bool buscar(int valor) {
        return buscarValor(raiz, valor);
    }

    Nodo* obtenerRaiz() {
        return raiz;
    }

private:
    Nodo* raiz;
};

int obtenerEnteroValidado() {
    int num;
    while (!(cin >> num)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Entrada invalida. Introduzca un numero entero: ";
    }
    return num;
}

int main() {
    ArbolBinario arbol;

    int opcion = 0;
    while (opcion != 4) {
        cout << "        ----Menu---        " << endl;
        cout << "/[1]   Insertar nodo     \\" << endl;
        cout << "/[2]  Imprimir en orden  \\" << endl;
        cout << "/[3]    Buscar valor     \\" << endl;
        cout << "/[4]       Salir         \\" << endl;
        cout << "Seleccione una opcion: ";
        opcion = obtenerEnteroValidado();

        switch (opcion) {
            case 1: {
                cout << "Insertar nodo - Ingrese el valor del nodo: ";
                int valor = obtenerEnteroValidado();
                arbol.insertarNodo(valor);
                cout << "Nodo insertado" << endl;
                break;
            }
            case 2: {
                cout << "Imprimir en orden:" << endl;
                arbol.imprimirEnOrden(arbol.obtenerRaiz());
                cout << endl;
                break;
            }
            case 3: {
                cout << "Buscar valor - Ingrese el valor a buscar: ";
                int valor = obtenerEnteroValidado();
                if (arbol.buscar(valor)) {
                    cout << "El valor " << valor << " se encuentra en el arbol" << endl;
                } else {
                    cout << "El valor " << valor << " no se encuentra en el arbol" << endl;
                }
                break;
            }
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    }

    return 0;
}