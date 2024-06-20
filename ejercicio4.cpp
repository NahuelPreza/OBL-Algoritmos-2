#include <cassert>
#include <string>
#include <iostream>
#include "tads/GrafoListaAdyacencia.cpp"

using namespace std;

int main() {
    int numVertices, numAristas, cantidadDestinos;
    cin >> numVertices;
    cin >> numAristas;

    Grafo grafo(numVertices);

    for (int i = 0; i < numAristas; ++i) {
        int origen, destino;
        cin >> origen >> destino;
        grafo.agregarArista(origen, destino);
    }

    cin >> cantidadDestinos;
    for (int i = 0; i < cantidadDestinos; ++i) {
        int destino;
        cin >> destino;
        if (grafo.sePuedeLlegar(destino)) {
            cout << destino << " si" << endl;
        } else {
            cout << destino << " no" << endl;
        }
    }
    return 0;
}
