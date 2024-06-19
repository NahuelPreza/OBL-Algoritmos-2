#include <iostream>
#include <string>
#include <limits>

using namespace std;

bool sonLosTresIguales(int* numeros, int medio, int tamano) {
    if (medio <= 0 || medio >= tamano - 1) return false;
    return numeros[medio] == numeros[medio + 1] && numeros[medio] == numeros[medio - 1];
}

int encontrarNumeroUnico(int* numeros, int izquierda, int derecha, int tamano) {
    if (izquierda > derecha) {
        return -1;
    }

    int medio = (izquierda + derecha) / 2;

    if (sonLosTresIguales(numeros, medio, tamano)) {
        int resultadoIzquierda = encontrarNumeroUnico(numeros, izquierda, medio - 2, tamano);
        
        if (resultadoIzquierda != -1) {
            return resultadoIzquierda;
        } else {
            int resultadoDerecha = encontrarNumeroUnico(numeros, medio + 2, derecha, tamano);
            return resultadoDerecha;
        }
    } else if (medio > 0 && sonLosTresIguales(numeros, medio - 1, tamano)) {
        int resultadoIzquierda = encontrarNumeroUnico(numeros, izquierda, medio - 3, tamano);
        
        if (resultadoIzquierda != -1) {
            return resultadoIzquierda;
        } else {
            int resultadoDerecha = encontrarNumeroUnico(numeros, medio + 1, derecha, tamano);
            return resultadoDerecha;
        }
    } else if (medio < tamano - 1 && sonLosTresIguales(numeros, medio + 1, tamano)) {
        int resultadoIzquierda = encontrarNumeroUnico(numeros, izquierda, medio - 1, tamano);
        
        if (resultadoIzquierda != -1) {
            return resultadoIzquierda;
        } else {
            int resultadoDerecha = encontrarNumeroUnico(numeros, medio + 3, derecha, tamano);
            return resultadoDerecha;
        }
    } else {
        return numeros[medio];
    }
}

int main() {
    int cantidadEntradas;
    cin >> cantidadEntradas;
    
    if (cantidadEntradas == 1) {
        int unico;
        cin >> unico;
        cout << unico << endl;
        return 0;
    }
    
    int* numeros = new int[cantidadEntradas];

    for (int i = 0; i < cantidadEntradas; i++) {
        cin >> numeros[i];
    }

    cout << encontrarNumeroUnico(numeros, 0, cantidadEntradas - 1, cantidadEntradas) << endl;

    delete[] numeros;
    return 0;
}
