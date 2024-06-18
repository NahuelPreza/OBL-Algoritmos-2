#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/MinHeap.cpp"

using namespace std;

int main()
{
    // Leer la potencia inicial y el número de virus
    int potenciaInicial, cantidadDeVirus;
    cin >> potenciaInicial >> cantidadDeVirus;

    // Crear un MinHeap para almacenar los virus
    MinHeapBinario monticuloVirus = MinHeapBinario(cantidadDeVirus);

    // Leer las potencias de los virus e insertarlas en el montículo
    for (int i = 0; i < cantidadDeVirus; i++) {
        int potenciaDeVirus;
        cin >> potenciaDeVirus;
        monticuloVirus.insertar(potenciaDeVirus);
    }

    if (monticuloVirus.puedeDestruirVirus(potenciaInicial))
    {
        cout << "true" << endl;
    } else{
        cout << "false" << endl;
    }
    return 0;
}