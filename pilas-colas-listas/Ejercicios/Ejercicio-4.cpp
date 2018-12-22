#include <iostream>
#include <stdio.h> // null

using namespace std;

//
// # Struct
//
template<typename T>
struct Nodo{
    T dato;
    Nodo<T> *sig;    
};
//
// # Prototipos
//
template<typename T> void push(Nodo<T> *&, T);
template<typename T> T pop(Nodo<T> *&);

//
// # Main
//
int main(){
    Nodo<int> *numeros = NULL;

    push<int>(numeros, 1);
    push<int>(numeros, 2);
    push<int>(numeros, 5);

    while(numeros != NULL){
        cout << pop<int>(numeros) << endl;
    }    

    return 0;
}

//
// # Funciones
//
template<typename T> void push(Nodo<T> *&pila, T dato){
    Nodo<T> *nuevo = new Nodo<T>();
    nuevo->dato = dato;
    nuevo->sig = pila;
    pila  = nuevo;
}

template<typename T> T pop(Nodo<T> *&pila){
    Nodo<T> *aux = pila;
    T dato = aux->dato;
    pila = aux->sig;

    delete aux;
    return dato;
}
