#ifndef TABLA_IMP
#define TABLA_IMP
#include <iostream>
#include <string>
#include "AVL.cpp"

using namespace std;

class TablaHash {
private:
    int capacidad;
    AVL* buckets;

  
    int hash(int clave) {
        return clave*7 % capacidad;
    }

public:
    TablaHash(int tableCapacidad) : capacidad(tableCapacidad) {
        buckets = new AVL[capacidad];
    }

   
    void insertar(int clave, string valor) {
        int pos = hash(clave);
        buckets[pos].insertar(clave, valor);
        
    }

   
    string buscar(int clave) {
        int pos = hash(clave);
        Nodo* nodoActual = buckets[pos].Obtener(clave);
        if (nodoActual != NULL) {
            return nodoActual->datosString;
        }
        return "Pedido no encontrado";
    }
};
#endif