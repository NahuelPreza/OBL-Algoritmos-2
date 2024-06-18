#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    // Archivos de prueba
    vector<string> inputFiles = {
    "3_1.in.txt","3_2.in.txt","3_3.in.txt","3_4.in.txt","3_5.in.txt",
    "4_1.in.txt","4_2.in.txt","4_3.in.txt","4_4.in.txt","4_5.in.txt",
    "5_1.in.txt","5_2.in.txt","5_3.in.txt","5_4.in.txt","5_5.in.txt"
};

vector<string> outputFiles = {
    "3_1.out.txt","3_2.out.txt","3_3.out.txt","3_4.out.txt","3_5.out.txt",
    "4_1.out.txt","4_2.out.txt","4_3.out.txt","4_4.out.txt","4_5.out.txt",
    "5_1.out.txt","5_2.out.txt","5_3.out.txt","5_4.out.txt","5_5.out.txt"
};

vector<string> generatedFiles = {
    "3_1.myOut.txt","3_2.myOut.txt","3_3.myOut.txt","3_4.myOut.txt","3_5.myOut.txt",
    "4_1.myOut.txt","4_2.myOut.txt","4_3.myOut.txt","4_4.myOut.txt","4_5.myOut.txt",
    "5_1.myOut.txt","5_2.myOut.txt","5_3.myOut.txt","5_4.myOut.txt","5_5.myOut.txt"
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
        string command = "ejercicio10.exe < " + inputFilePath + " > " + generatedFilePath;
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
    } else {
        cout << "Pruebas no pasadas" << endl;
    }
    

    return 0;
}
