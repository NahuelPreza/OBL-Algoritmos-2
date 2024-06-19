#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/AVL.cpp"

using namespace std;

int main()
{
   int largoDeListaN;
   
    cin >> largoDeListaN;
     
    int* N = new int[largoDeListaN];
    for (int i = 0; i < largoDeListaN; ++i) {
        cin >> N[i];
    }


    int largoDeListaM;
    cin >> largoDeListaM;


    AVL arbol;
    int elementoDeM;
    
    for (int i = 0; i < largoDeListaM; ++i) {
        cin >> elementoDeM;
        arbol.insertar(elementoDeM);
    }
    
    int k;
    cin >> k;

    int counter =0;
    for (int j = 0; j < largoDeListaN; j++)
    {
        if(arbol.ExisteQueSumeK(N[j], k)){

            counter++;
        };
    }
    
    cout << counter << endl;

    delete[] N;
    return 0;
}