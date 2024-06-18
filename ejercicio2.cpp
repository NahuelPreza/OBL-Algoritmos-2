#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/MaxHeap.cpp"

using namespace std;

int main()
{
    int n;
    cin >> n;

    MaxHeapBinario* Heap = new MaxHeapBinario(n);
    int piedra;
    for (int i = 0; i < n; ++i) {
        cin >> piedra;
        Heap->insertar(piedra);
    }

    while (Heap->cantidadElementos() > 1)
    {
        int maximo = Heap->eliminarMax();
        int segundo = Heap->eliminarMax();
        maximo = maximo - segundo;
        if (maximo > 0)
        {
            Heap->insertar(maximo);
        }
    }

    if (Heap->estaVacio())
    {
        cout << "0" << endl;
    }
    else
    {
        cout << Heap->eliminarMax() << endl;
    }
    
}