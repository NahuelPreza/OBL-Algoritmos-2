#include <iostream>

using namespace std;

struct Nodo {
        int dato;
        string datosString;
        Nodo* izquierda;
        Nodo* derecha;
        int altura;

        Nodo(int valor, string menu = "") : dato(valor), izquierda(nullptr), derecha(nullptr), altura(1), datosString(menu) {}
    };

class AVL {
private:
    

    Nodo* raiz;

    int obtenerAltura(Nodo* nodo) {
        if (nodo == nullptr) {
            return 0;
        }
        return nodo->altura;
    }

    int obtenerBalance(Nodo* nodo) {
        if (nodo == nullptr) {
            return 0;
        }
        return obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha);
    }

    Nodo* rotarDerecha(Nodo* nodo) {
        Nodo* nuevaRaiz = nodo->izquierda;
        Nodo* temp = nuevaRaiz->derecha;

        nuevaRaiz->derecha = nodo;
        nodo->izquierda = temp;

        nodo->altura = 1 + max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));
        nuevaRaiz->altura = 1 + max(obtenerAltura(nuevaRaiz->izquierda), obtenerAltura(nuevaRaiz->derecha));

        return nuevaRaiz;
    }
    
    Nodo* rotarIzquierda(Nodo* nodo) {
        Nodo* nuevaRaiz = nodo->derecha;
        Nodo* temp = nuevaRaiz->izquierda;

        nuevaRaiz->izquierda = nodo;
        nodo->derecha = temp;

        nodo->altura = 1 + max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));
        nuevaRaiz->altura = 1 + max(obtenerAltura(nuevaRaiz->izquierda), obtenerAltura(nuevaRaiz->derecha));

        return nuevaRaiz;
    }

    Nodo* insertarNodo(Nodo* nodo, int dato, string menu = "") {
        if (nodo == nullptr) {
            return new Nodo(dato, menu);
        }

        if (dato < nodo->dato) {
            nodo->izquierda = insertarNodo(nodo->izquierda, dato, menu);
        } else if (dato > nodo->dato) {
            nodo->derecha = insertarNodo(nodo->derecha, dato, menu);
        } else if(dato == nodo->dato){
            nodo->datosString = menu;
            return nodo;
        }

        nodo->altura = 1 + max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));

        int factorBalance = obtenerBalance(nodo);

        // Caso Izquierda Izquierda
        if (factorBalance > 1 && dato < nodo->izquierda->dato) {
            return rotarDerecha(nodo);
        }

        // Caso Derecha Derecha
        if (factorBalance < -1 && dato > nodo->derecha->dato) {
            return rotarIzquierda(nodo);
        }

        // Caso Izquierda Derecha
        if (factorBalance > 1 && dato > nodo->izquierda->dato) {
            nodo->izquierda = rotarIzquierda(nodo->izquierda);
            return rotarDerecha(nodo);
        }

        // Caso Derecha Izquierda
        if (factorBalance < -1 && dato < nodo->derecha->dato) {
            nodo->derecha = rotarDerecha(nodo->derecha);
            return rotarIzquierda(nodo);
        }

        return nodo;
    }

    bool buscarNodo(Nodo* nodo, int dato, int k) {
        if (nodo == nullptr) {
            return false;
        }

        int suma = dato + nodo->dato;
        if (suma == k) {
            return true;
        } else if (suma < k) {
            return buscarNodo(nodo->derecha, dato, k);
        } else {
            return buscarNodo(nodo->izquierda, dato, k);
        }
    }

    Nodo* devolverNodo(Nodo* nodo, int clave) {
        if (nodo == nullptr) {
            return nullptr;
        }

        if (nodo->dato == clave) {
            return nodo;
        } else if (nodo->dato < clave) {
            return devolverNodo(nodo->derecha, clave);
        } else {
            return devolverNodo(nodo->izquierda, clave);
        }
    }

public:
    AVL() {
        raiz = nullptr;
    }

    void insertar(int dato, string menu = "") {
        raiz = insertarNodo(raiz, dato, menu);
    }

    Nodo* Obtener(int clave) {
        return devolverNodo(raiz, clave);
    }

    bool ExisteQueSumeK(int dato, int k) {
        return buscarNodo(raiz, dato, k);
    }
};