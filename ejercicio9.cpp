#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

// Función para generar primos utilizando la Criba de Eratóstenes
int* generarPrimos(int maxN, int &cantidadPrimos) {
    bool* esPrimo = new bool[maxN + 1];
    
    for (int i = 0; i <= maxN; ++i) {
        esPrimo[i] = true;
    }
    
    esPrimo[0] = esPrimo[1] = false;

    for (int i = 2; i * i <= maxN; ++i) {
        if (esPrimo[i]) {
            for (int j = 2; j*i <= maxN; j ++) {
                esPrimo[i*j] = false;
            }
        }
    }

    // Contar primos
    cantidadPrimos = 0;
    for (int i = 2; i <= maxN; ++i) {
        if (esPrimo[i]) {
            ++cantidadPrimos;
        }
    }

    // Almacenar primos en un array
    int* primos = new int[cantidadPrimos];
    int idx = 0;
    for (int i = 2; i <= maxN; ++i) {
        if (esPrimo[i]) {
            primos[idx++] = i;
        }
    }

    delete[] esPrimo;
    return primos;
}

int contarFormas(int X, int Y) {
    // Generar primos hasta el máximo de X o Y
    int N = (X > Y) ? X : Y;
    int cantidadPrimos = 0;
    int* primos = generarPrimos(N, cantidadPrimos);
    
    // Crear matriz para almacenar las formas de llegar a cada celda
    int** formasDellegarA = new int*[X];

    for (int i = 0; i < X; ++i) {

        formasDellegarA[i] = new int[Y];
        for (int j = 0; j < Y; ++j) {
            formasDellegarA[i][j] = 0;
        }
        
    }
    
    formasDellegarA[0][0] = 1;
    
    // Rellenar la matriz formasDellegarA
    for (int i = 0; i < X; ++i) {
        for (int j = 0; j < Y; ++j) {
            if (formasDellegarA[i][j] > 0) {
                for (int k = 0; k < cantidadPrimos; ++k) {
                    int p = primos[k];
                    if (i + p < X) {
                        formasDellegarA[i + p][j] += formasDellegarA[i][j];
                    }
                    if (j + p < Y) {
                        formasDellegarA[i][j + p] += formasDellegarA[i][j];
                    }
                }
            }
        }
    }
    
    // Guardar el resultado
    int resultado = formasDellegarA[X-1][Y-1];
    
    // Liberar memoria
    for (int i = 0; i < X; ++i) {
        delete[] formasDellegarA[i];
    }
    delete[] formasDellegarA;
    delete[] primos;
    
    return resultado;
}

int main() {
    int X, Y;
    cin >> X >> Y;
    cout << contarFormas(X, Y) << endl;
    return 0;
}
