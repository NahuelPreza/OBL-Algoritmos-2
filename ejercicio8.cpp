#include <iostream>
#include <string>
#include <limits>
#include "tads/AVlConRepetidos.cpp"

using namespace std;

int main() {
    int cantidadEntradas;
    cin >> cantidadEntradas;
    AVL arbol = AVL();
    
    for (int i = 0; i < cantidadEntradas; i++) {
        int numero;
        cin >> numero;
        arbol.insertar(numero);
    }
    
    cout << arbol.encontrarNumeroUnico() << endl;

    return 0;
}
