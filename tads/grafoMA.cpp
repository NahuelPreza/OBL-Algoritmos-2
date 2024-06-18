#include <iostream>
#include <string>
#include <limits>
#include <climits>
using namespace std;


template<class T>
class NodoLista{
    public:
    T dato;
    NodoLista * sig;
    NodoLista(T _dato,NodoLista * _sig ): dato(_dato), sig(_sig){};
    NodoLista(T _dato): dato(_dato), sig(NULL){};

};

class Arista {

public:
    //int origen; (opcional)
    int destino;
    int peso;
    Arista(int _destino, int _peso = 1): destino (_destino), peso(_peso){};

};

#define inf INT_MAX;

class Grafo_MA {

private:
    int **grafo;
    int V;
    //int A; (Opcional)
    bool esDirigido;

public:
    Grafo_MA(int _V, bool _esDirigido){
        this->V= _V;
        this->esDirigido = _esDirigido;
        grafo = new int*[_V];
    for (int i = 0; i < _V; i++)
    {
        grafo[i] =new int [_V]; 
        for (int j = 0; j < _V; j++)
        {
            grafo[i][j]= inf;
        }
        
    }

    }

    void agregarArista(int origen,int destino, int peso=1){
      grafo[origen][destino]=peso;
      if(!esDirigido){
        grafo[destino][origen]=peso;

      }
    }

    NodoLista<Arista>* adyacentesA(int origen){
       
       //Clono la lista asi no me clonanan
        NodoLista<Arista>* ret =NULL;
         int internalInf =inf;
        for (int destino  = 0; destino < V; destino++)
        {
           
            if(grafo[origen][destino]!=internalInf){

                Arista a(destino,grafo[origen][destino]);
                ret = new NodoLista<Arista>(a,ret);
            }
        }
        return ret;
    }
        
};