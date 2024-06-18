#ifndef MIN_HEAP_BINARIO_IMP
#define MIN_HEAP_BINARIO_IMP

#include <iostream>
#include <string>

using namespace std;

class MinHeapBinario {
public:
    MinHeapBinario(int capacidad) : tamano(0), capacidad(capacidad) {
        heap = new int[capacidad + 1];
    }

    ~MinHeapBinario() {
        delete[] heap;
    }

    void insertar(int valor) {
        if (tamano >= capacidad) {
            redimensionar();
        }
        tamano++;
        heap[tamano] = valor;
        flotar(tamano);
    }

    int eliminarMin() {
        if (estaVacio()) {
            cout << "El heap está vacío" << endl;
            return 0;
        }
        int minValor = heap[1];
        intercambiar(1, tamano);
        tamano--;
        hundir(1);
        return minValor;
    }

    bool estaVacio() const {
        return tamano == 0;
    }

    int cantidadElementos() const {
        return tamano;
    }

    bool puedeDestruirVirus(int potenciaActual) {
        while (!this->estaVacio()) {
            int virusPotencia = this->eliminarMin();
            if (potenciaActual >= virusPotencia) {
                potenciaActual += virusPotencia;
            } else {
                return false;
            }
        }
        return true;
    }
    
private:
    int* heap;
    int tamano;
    int capacidad;

    void flotar(int indice) {
        while (indice > 1 && heap[indice / 2] > heap[indice]) {
            intercambiar(indice, indice / 2);
            indice = indice / 2;
        }
    }

    void hundir(int indice) {
        while (2 * indice <= tamano) {
            int j = 2 * indice;
            if (j < tamano && heap[j] > heap[j + 1]) j++;
            if (heap[indice] <= heap[j]) break;
            intercambiar(indice, j);
            indice = j;
        }
    }

    void intercambiar(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    void redimensionar() {
        int nuevaCapacidad = capacidad * 2;
        int* nuevoHeap = new int[nuevaCapacidad + 1];
        for (int i = 1; i <= tamano; ++i) {
            nuevoHeap[i] = heap[i];
        }
        delete[] heap;
        heap = nuevoHeap;
        capacidad = nuevaCapacidad;
    }
};

#endif
