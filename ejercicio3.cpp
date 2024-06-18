#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/AVL.cpp"

using namespace std;

int main()
{
   int nLen;
   
    cin >> nLen;
     
    int* N = new int[nLen];
    for (int i = 0; i < nLen; ++i) {
        cin >> N[i];
    }


    int mLen;
    cin >> mLen;

    int* M = new int[mLen];
    for (int i = 0; i < mLen; ++i) {
        cin >> M[i];
    }
    
    int k;
    cin >> k;


    AVL arbol;
    
    
    for (int i = 0; i < mLen; i++)
    {
        arbol.insertar(M[i]);
    }
    
    int counter =0;
    for (int j = 0; j < nLen; j++)
    {
        if(arbol.ExisteQueSumeK(N[j], k)){

            counter++;
        };
    }
    
    cout << counter << endl;

    return 0;
}