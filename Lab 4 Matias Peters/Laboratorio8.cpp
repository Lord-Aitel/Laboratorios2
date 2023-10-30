#include <iostream>
#include <vector>
using namespace std;

// Clase del arbol general
class GeneralTree {
private:
    // Estructura del nodo del arbol
    struct Node {
        int data;
        vector<Node*> children;
    };

    Node* root;

    Node* createNode(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        return newNode;
    }

    Node* findNode(Node* current, int value) {
        if (current == nullptr) {
            return nullptr;
        }

        if (current->data == value) {
            return current;
        }

        for (Node* child : current->children) {
            Node* result = findNode(child, value);
            if (result != nullptr) {
                return result;
            }
        }

        return nullptr;
    }

    void printTree(Node* current) {
        if (current != nullptr) {
            cout << current->data << " -> ";

            for (Node* child : current->children) {
                printTree(child);
            }
        }
    }

public:
    GeneralTree() : root(nullptr) {}

    void insertNode(int parentValue, int value) {
        if (root == nullptr) {
            root = createNode(value);
            return;
        }

        Node* parentNode = findNode(root, parentValue);
        if (parentNode == nullptr) {
            cout << "El nodo padre " << parentValue << " no existe en el arbol." << endl;
            return;
        }

        Node* newNode = createNode(value);
        parentNode->children.push_back(newNode);
    }

    bool searchValue(int value) {
        return findNode(root, value) != nullptr;
    }

    void printWholeTree() {
        cout << "Arbol: ";
        printTree(root);
        cout << endl;
    }
};

// Clase para el arbol binario
class BinaryTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    Node* root;

    Node* insertNode(Node* current, int value) {
        if (current == nullptr) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }

        if (value < current->data) {
            current->left = insertNode(current->left, value);
        } else if (value > current->data) {
            current->right = insertNode(current->right, value);
        }

        return current;
    }

    bool searchValue(Node* current, int value) {
        if (current == nullptr) {
            return false;
        }

        if (current->data == value) {
            return true;
        }

        if (value < current->data) {
            return searchValue(current->left, value);
        } else {
            return searchValue(current->right, value);
        }
    }

    void printInOrder(Node* current) {
        if (current != nullptr) {
            printInOrder(current->left);
            cout << current->data << " ";
            printInOrder(current->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void addNode(int value) {
        root = insertNode(root, value);
    }

    bool findValue(int value) {
        return searchValue(root, value);
    }

    void printOrderedValues() {
        cout << "Elementos en el arbol en orden: ";
        printInOrder(root);
        cout << endl;
    }
};

// Clase para la lista enlazada
class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void addNodeToList(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    bool findValueInList(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void removeValueFromList(int value) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->data != value) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "El elemento no se encuentra en la lista." << endl;
            return;
        }

        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
    }

    void printListElements() {
        Node* current = head;
        cout << "Elementos en la lista: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    // Ejemplo de uso de la clase GeneralTree
    GeneralTree arbol;
    arbol.insertNode(-1, 1);
    arbol.insertNode(1, 2);
    arbol.insertNode(1, 3);
    arbol.insertNode(2, 4);
    arbol.insertNode(2, 5);

    arbol.printWholeTree();
    cout << "El valor 3 esta en el arbol? " << (arbol.searchValue(3) ? "Si" : "No") << endl;
    cout << "El valor 6 esta en el arbol? " << (arbol.searchValue(6) ? "Si" : "No") << endl;

    // Ejemplo de uso de la clase BinaryTree
    BinaryTree arbolBinario;
    arbolBinario.addNode(50);
    arbolBinario.addNode(30);
    arbolBinario.addNode(20);
    arbolBinario.addNode(40);
    arbolBinario.addNode(70);
    arbolBinario.addNode(60);
    arbolBinario.addNode(80);

    arbolBinario.printOrderedValues();
    cout << "El valor 40 esta en el arbol? " << (arbolBinario.findValue(40) ? "Si" : "No") << endl;
    cout << "El valor 90 esta en el arbol? " << (arbolBinario.findValue(90) ? "Si" : "No") << endl;

    // Ejemplo de uso de la clase LinkedList
    LinkedList lista;
    lista.addNodeToList(5);
    lista.addNodeToList(10);
    lista.addNodeToList(15);
    lista.addNodeToList(20);

    lista.printListElements();
    cout << "El valor 10 esta en la lista? " << (lista.findValueInList(10) ? "Si" : "No") << endl;
    lista.removeValueFromList(10);
    lista.printListElements();
    lista.removeValueFromList(100);

    return 0;
}