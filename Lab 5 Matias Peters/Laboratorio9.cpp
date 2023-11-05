#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int val) : valor(val), izquierda(nullptr), derecha(nullptr) {}
};

// Implementación manual de una cola para BFS
struct Cola {
    struct NodoCola {
        Nodo* nodo;
        NodoCola* siguiente;
    };

    NodoCola* frente;
    NodoCola* final;

    Cola() : frente(nullptr), final(nullptr) {}

    void encolar(Nodo* nodo) {
        NodoCola* nuevo = new NodoCola{ nodo, nullptr };
        if (final != nullptr) {
            final->siguiente = nuevo;
        }
        final = nuevo;
        if (frente == nullptr) {
            frente = final;
        }
    }

    Nodo* desencolar() {
        if (frente == nullptr) {
            return nullptr;
        }
        Nodo* nodo = frente->nodo;
        frente = frente->siguiente;
        if (frente == nullptr) {
            final = nullptr;
        }
        return nodo;
    }

    bool vacia() {
        return frente == nullptr;
    }
};

class ArbolBinario {
public:
    Nodo* raiz;

    ArbolBinario() : raiz(nullptr) {}

    void agregarNodo(int valor) {
        raiz = agregarRecursivo(raiz, valor);
    }

    Nodo* agregarRecursivo(Nodo* nodo, int valor) {
        if (nodo == nullptr) {
            return new Nodo(valor);
        }

        if (valor < nodo->valor) {
            nodo->izquierda = agregarRecursivo(nodo->izquierda, valor);
        } else if (valor > nodo->valor) {
            nodo->derecha = agregarRecursivo(nodo->derecha, valor);
        }

        return nodo;
    }

    void preOrder(Nodo* nodo) {
        if (nodo != nullptr) {
            cout << nodo->valor << " ";
            preOrder(nodo->izquierda);
            preOrder(nodo->derecha);
        }
    }

    void inOrder(Nodo* nodo) {
        if (nodo != nullptr) {
            inOrder(nodo->izquierda);
            cout << nodo->valor << " ";
            inOrder(nodo->derecha);
        }
    }

    void postOrder(Nodo* nodo) {
        if (nodo != nullptr) {
            postOrder(nodo->izquierda);
            postOrder(nodo->derecha);
            cout << nodo->valor << " ";
        }
    }

    void BFS() {
        if (raiz == nullptr) return;

        Cola cola;
        cola.encolar(raiz);

        while (!cola.vacia()) {
            Nodo* nodoActual = cola.desencolar();

            cout << nodoActual->valor << " ";

            if (nodoActual->izquierda != nullptr) {
                cola.encolar(nodoActual->izquierda);
            }
            if (nodoActual->derecha != nullptr) {
                cola.encolar(nodoActual->derecha);
            }
        }
    }
};

int main() {
    ArbolBinario arbol;
    int valores[] = { 10, 5, 15, 3, 7, 12, 18 };

    for (int valor : valores) {
        arbol.agregarNodo(valor);
    }

    cout << "Recorrido pre-order: ";
    arbol.preOrder(arbol.raiz);
    cout << "\nRecorrido in-order: ";
    arbol.inOrder(arbol.raiz);
    cout << "\nRecorrido post-order: ";
    arbol.postOrder(arbol.raiz);

    cout << "\nBusqueda por amplitud (BFS): ";
    arbol.BFS();

    return 0;
}