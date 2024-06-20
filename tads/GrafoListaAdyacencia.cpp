#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>

using namespace std;

const int INF = 1e9;

// Estructura para representar una arista ponderada.
struct Arista {
    int destino;
    int peso;
    Arista* siguiente;

    Arista(int d, int p) : destino(d), peso(p), siguiente(nullptr) {}
};

// Estructura para representar la lista de adyacencia.
struct ListaAdyacencia {
    Arista* cabeza;

    ListaAdyacencia() : cabeza(nullptr) {}

    // Añadir una arista al principio de la lista
    void agregarArista(int destino, int peso) {
        Arista* nuevaArista = new Arista(destino, peso);
        nuevaArista->siguiente = cabeza;
        cabeza = nuevaArista;
    }

    // Liberar memoria de la lista de adyacencia
    ~ListaAdyacencia() {
        Arista* actual = cabeza;
        while (actual != nullptr) {
            Arista* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }
};

class Grafo {
private:
    int vertices;
    ListaAdyacencia* listaAdyacencia;


    bool DFS(int origen, int destino, bool* visitado) {
        if (origen == destino) {
            return true;
        }
    
        visitado[origen] = true;
        Arista* actual = listaAdyacencia[origen].cabeza;
        while (actual != nullptr) {
            if (!visitado[actual->destino] && DFS(actual->destino, destino, visitado)) {
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    void BFS(int inicio, int* distancia) {
        bool* visitado = new bool[vertices + 1]();

        for (int i = 0; i <= vertices; ++i) {
            distancia[i] = INF;
        }

        int cola[vertices + 1];
        int actual = 0, final = 0;

        cola[final++] = inicio;
        visitado[inicio] = true;
        distancia[inicio] = 0;

        while (actual < final) {
            int u = cola[actual++];
            Arista* actual = listaAdyacencia[u].cabeza;
            while (actual != nullptr) {
                int v = actual->destino;

                if (!visitado[v]) {

                    distancia[v] = distancia[u] + 1;
                    cola[final++] = v;
                    visitado[v] = true;

                }

                actual = actual->siguiente;

            }
        }
    }


public:
    Grafo(int V) : vertices(V) {
        listaAdyacencia = new ListaAdyacencia[V + 1];
    }

    ~Grafo() {
        delete[] listaAdyacencia;
    }

    // Añadir una arista con peso al grafo (por defecto el peso es 1)
    void agregarArista(int u, int v, int p = 1) {
        listaAdyacencia[u].agregarArista(v, p);
    }



    // Verificar si se puede llegar del vértice origen al vértice destino por defecto el vertice origen es 1
    bool sePuedeLlegar(int destino, int origen = 1) {
        bool resultado = DFS(origen, destino, new bool[vertices + 1]());
        return resultado;
    }

    // Imprimir el grafo en consola
    void imprimirGrafo() {
        for (int i = 1; i < vertices+1; i++) {
            cout << "Vertice " << i << ": ";
            Arista* actual = listaAdyacencia[i].cabeza;
            while (actual != nullptr) {
                cout << "(" << actual->destino<< ") ";
                if (actual->siguiente != nullptr)
                {
                    cout << "-> ";
                }
                
                actual = actual->siguiente;
            }
            cout << endl;
        }
    }

    bool* importantes() {
        int* llegadas = new int[vertices + 1]();
        bool* importantes = new bool[vertices + 1]();

        for (int i = 1; i <= vertices; ++i) {
            Arista* actual = listaAdyacencia[i].cabeza;
            while (actual != nullptr) {
                llegadas[i]++;
                llegadas[actual->destino]++;
                actual = actual->siguiente;
            }
        }

        for (int i = 1; i <= vertices; ++i) {
            if (llegadas[i] >= 2) {
                importantes[i] = true;
            }
            cout << "Parada " << i << " es importante: " << importantes[i] << " llegadas: " << llegadas[i] << endl;
        }

        delete[] llegadas;
        return importantes;
    }


    int SeEncuentraEn() {
        bool* importantes = this->importantes();
        int distanciaMinPromedio = INF;
        int estaAqui = -1;
        int* dist = new int[vertices + 1];

        for (int i = 1; i <= vertices; ++i) {
            if (importantes[i]) {
                BFS(i, dist);
                double distanciaPromedioActual = 0;
                for (int j = 1; j <= vertices; ++j) {
                    if (dist[j] != INF) {
                        distanciaPromedioActual += dist[j];
                    }
                }

                distanciaPromedioActual = distanciaPromedioActual / vertices;

                if (distanciaPromedioActual == 0) {
                    distanciaPromedioActual = INF;
                }

                cout << "Parada " << i << " tiene distancia promedio: " << distanciaPromedioActual << endl;

                if (distanciaPromedioActual < distanciaMinPromedio) {
                    distanciaMinPromedio = distanciaPromedioActual;
                    estaAqui = i;
                }
            }
        }

        delete[] dist;
        delete[] importantes;
        return estaAqui;
    }
};
#endif // GRAFO_H