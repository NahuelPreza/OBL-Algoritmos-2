#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    // Archivos de prueba
    vector<string> inputFiles = {
        "5_6.in.txt", "30_40.in.txt", "30_60.in.txt", 
        "50_70_1.in.txt", "50_70_2.in.txt", "50_100_1.in.txt", 
        "50_100_2.in.txt", "100_300_1.in.txt", "100_300_2.in.txt", 
        "300_600_1.in.txt", "300_600_2.in.txt"
    };
    vector<string> outputFiles = {
        "5_6.out.txt", "30_40.out.txt", "30_60.out.txt", 
        "50_70_1.out.txt", "50_70_2.out.txt", "50_100_1.out.txt", 
        "50_100_2.out.txt", "100_300_1.out.txt", "100_300_2.out.txt", 
        "300_600_1.out.txt", "300_600_2.out.txt"
    };
    vector<string> generatedFiles = {
        "5_6.myOut.txt", "30_40.myOut.txt", "30_60.myOut.txt", 
        "50_70_1.myOut.txt", "50_70_2.myOut.txt", "50_100_1.myOut.txt", 
        "50_100_2.myOut.txt", "100_300_1.myOut.txt", "100_300_2.myOut.txt", 
        "300_600_1.myOut.txt", "300_600_2.myOut.txt"
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
        string command = "ejercicio4.exe < " + inputFilePath + " > " + generatedFilePath;
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
