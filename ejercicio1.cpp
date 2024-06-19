#include <iostream>
#include <string>
#include "tads/TablaHash.cpp"
using namespace std;

int main() {
    string input;
    int n;
    cin >> n;
    cin.ignore();
    TablaHash tabla(n+7);
    for (int i = 0; i < n; i++)
    {

        getline(cin, input);
        // Variables para almacenar las partes
        string part1;
        string part2;
        string part3;

        // Encontrar el primer espacio (después de la letra)
        size_t firstSpacePos = input.find(' ');
        if (firstSpacePos != string::npos) {
            // Extraer la primera parte (letra)
            part1 = input.substr(0, firstSpacePos);

            // El resto de la cadena después del primer espacio
            string remaining = input.substr(firstSpacePos + 1);

            // Encontrar el segundo espacio (después del número)
            size_t secondSpacePos = remaining.find(' ');
            if (secondSpacePos != string::npos) {
                // Extraer la segunda parte (número)
                part2 = remaining.substr(0, secondSpacePos);

                // El resto de la cadena (lista de palabras)
                part3 = remaining.substr(secondSpacePos + 1);
            } else {
                // Si no hay un segundo espacio, asume que el resto es la segunda parte
                part2 = remaining;
            }
        } else {
            // Si no hay un primer espacio, es una entrada incompleta
            part1 = input;
        }

        int identificador = stoi(part2);

        if (part1 == "A")
            {
                tabla.insertar(identificador, part3);

            } else if (part1 == "Q")
            {
                cout << tabla.buscar(identificador) << endl;

            } else if (!(tabla.buscar(identificador) == "Pedido no encontrado"))
            {
                tabla.insertar(identificador, "Entregado");
            }   
    }
    
    return 0;
}
