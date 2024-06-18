#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    // Archivos de prueba
    vector<string> inputFiles = {
        "6.in.txt", "10.in.txt", "100.in.txt", "1000.in.txt",
        "10000.in.txt", "100000.in.txt", "1000000.in.txt"
    };
    vector<string> outputFiles = {
        "6.out.txt", "10.out.txt", "100.out.txt", "1000.out.txt",
        "10000.out.txt", "100000.out.txt", "1000000.out.txt"
    };
    vector<string> generatedFiles = {
        "6.myOut.txt", "10.myOut.txt", "100.myOut.txt", "1000.myOut.txt",
        "10000.myOut.txt", "100000.myOut.txt", "1000000.myOut.txt"
    };

    int tamano = generatedFiles.size();
    int* Resultados = new int[tamano];

    for (size_t i = 0; i < inputFiles.size(); ++i) {
        string inputFilePath = inputFiles[i];
        string outputFilePath = outputFiles[i];
        string generatedFilePath = generatedFiles[i];

        // Verificar que el archivo de entrada existe
        ifstream infile(inputFilePath);
        if (!infile.good()) {
            cerr << "El archivo de entrada no existe: " << inputFilePath << endl;
            continue;
        }

        // Verificar que el archivo de salida esperado existe
        ifstream outfile(outputFilePath);
        if (!outfile.good()) {
            cerr << "El archivo de salida esperado no existe: " << outputFilePath << endl;
            continue;
        }

        // Ejecutar el programa con el archivo de entrada y guardar la salida generada
        string command = "ejercicio2.exe < " + inputFilePath + " > " + generatedFilePath;
        int execResult = system(command.c_str());

        if (execResult != 0) {
            cerr << "Error al ejecutar el comando: " << command << endl;
            continue;
        }

        // Usar fc para comparar los archivos de salida
        string fcCommand = "fc " + generatedFilePath + " " + outputFilePath;
        int fcResult = system(fcCommand.c_str());
        Resultados[i] = fcResult;
    }
    int retorno = 0;
    for (int i = 0; i < tamano; i++)
    {
        retorno = retorno + Resultados[i];
    }
    if (retorno == 0)
    {
        cout << "Pasaste todas las pruebas" << endl;
    }
    else
    {
        cout << "Pruebas no pasadas" << endl;
    }
    

    return 0;
}
