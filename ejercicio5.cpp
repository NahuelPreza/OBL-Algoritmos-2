#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/GrafoListaAdyacencia.cpp"

using namespace std;

int main() {
    int verticesParadas, aristasLineas;
    cin >> verticesParadas >> aristasLineas;

    Grafo grafo(verticesParadas);
    int* lineas = new int[verticesParadas + 1]();

    for (int i = 0; i < aristasLineas; ++i) {
        int parada;
        cin >> parada;

        while (parada != 0) {

            int paradaSiguiente;
            cin >> paradaSiguiente;
            if (paradaSiguiente != 0) {
                grafo.agregarArista(parada, paradaSiguiente);
                lineas[parada]++;
            }

            parada = paradaSiguiente;
        }
    }

    int paradaResultado = grafo.SeEncuentraEn();

    cout << "El fugitivo está en: " << paradaResultado << endl;

    return 0;
}
