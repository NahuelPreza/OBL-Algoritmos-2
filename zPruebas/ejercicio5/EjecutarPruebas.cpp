#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    // Archivos de prueba
    vector<string> inputFiles = {
    "10.in.txt", "13.in.txt", "100.in.txt", 
    "1000.in.txt", "2000.in.txt", "3000.in.txt", 
    "4000.in.txt"
    };
    vector<string> outputFiles = {
        "10.out.txt", "13.out.txt", "100.out.txt", 
        "1000.out.txt", "2000.out.txt", "3000.out.txt", 
        "4000.out.txt"
    };
    vector<string> generatedFiles = {
        "10.myOut.txt", "13.myOut.txt", "100.myOut.txt", 
        "1000.myOut.txt", "2000.myOut.txt", "3000.myOut.txt", 
        "4000.myOut.txt"
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
        string command = "ejercicio5.exe < " + inputFilePath + " > " + generatedFilePath;
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
