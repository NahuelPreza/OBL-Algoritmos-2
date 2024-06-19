#ifndef TABLA_IMP
#define TABLA_IMP
#include <iostream>
#include <string>

using namespace std;

class TablaHash {
private:

    struct Nodo {
        int clave;
        string valor;
        Nodo* sig;
        Nodo(int k, string v) : clave(k), valor(v), sig(NULL) {}
    };

    int capacidad;
    Nodo** buckets;

  
    int hash(int clave) {
        return clave*7 % capacidad;
    }

public:
    TablaHash(int tableCapacidad) : capacidad(tableCapacidad) {
        buckets = new Nodo*[capacidad];
        for (int i = 0; i < capacidad; ++i) {
            buckets[i] = NULL;
        }
    }

   
    void insertar(int clave, string valor) {
        int pos = hash(clave);
        Nodo* nuevoNodo = new Nodo(clave, valor);
        if (buckets[pos] == NULL) {
            buckets[pos] = nuevoNodo;
        } else {
          
            nuevoNodo->sig = buckets[pos];
            buckets[pos] = nuevoNodo;
        }
    }

   
    string buscar(int clave) {
        int pos = hash(clave);
        Nodo* nodoActual = buckets[pos];
        while (nodoActual != NULL) {
            if (nodoActual->clave == clave) {
                return nodoActual->valor;
            }
            nodoActual = nodoActual->sig;
        }
        return "Pedido no encontrado";
    }
};
#endif