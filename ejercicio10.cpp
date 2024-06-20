#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

// Definición de los posibles movimientos del caballo en el ajedrez
const int movimientosCaballo[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

// Función para verificar si una posición es válida y no ha sido visitada aún
bool esPosValida(int x, int y, int N, int** tablero) {
    return (x >= 0 && x < N && y >= 0 && y < N && tablero[x][y] == -1);
}

// Función recursiva que intenta resolver el Tour del Caballo
bool resolverTourCaballo(int x, int y, int conteoMovimientos, int N, int** tablero) {
    if (conteoMovimientos == N * N) {
        return true;
    }

    // Intentar todos los movimientos posibles del caballo
    for (int i = 0; i < 8; ++i) {
        int siguienteX = x + movimientosCaballo[i][0];
        int siguienteY = y + movimientosCaballo[i][1];
        if (esPosValida(siguienteX, siguienteY, N, tablero)) {
            tablero[siguienteX][siguienteY] = conteoMovimientos;
            if (resolverTourCaballo(siguienteX, siguienteY, conteoMovimientos + 1, N, tablero)) {
                return true;
            }
            tablero[siguienteX][siguienteY] = -1; // retroceder
        }
    }
    return false;
}

// Función principal que inicializa el tablero y llama a la función recursiva
bool tourCaballo(int N, int inicioX, int inicioY) {
    
    int** tablero = new int*[N];
    for (int i = 0; i < N; ++i) {
        tablero[i] = new int[N];
    }
    
    // Inicializar el tablero con -1 (no visitado)
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            tablero[i][j] = -1;
        }
    }

    tablero[inicioX][inicioY] = 0;
    return resolverTourCaballo(inicioX, inicioY, 1, N, tablero);
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;

    if (tourCaballo(N, r, c)) {
        cout << "SI" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
