#include <iostream>
#include <stdio.h> // null
#include <string.h> // strcpy()

using namespace std;

//
// # Struct
//
template<typename T>
struct Nodo{
    T dato;
    Nodo<T> *sig;    
};

struct Personaje{
    char nombre[30];
    int fuerza;
};

//
// # Prototipos
//
template<typename T> void push(Nodo<T> *&, T);
template<typename T> T pop(Nodo<T> *&);

template<typename T>void agregar(Nodo<T> *&pila, T (*metodo)(T v));
template<typename T>void mostrar(Nodo<T> *&pila, T (*metodo)(T v, int));

Personaje crearPersonaje(Personaje);
Personaje mostrarPersonaje(Personaje p, int);

//
// # Main
//
int main(){
    int cantidad;
    Nodo<Personaje> *pila = NULL;    

    cout << "Cantidad de personajes: ";
    cin >> cantidad;

    for(int i=0; i < cantidad;i++){
        agregar<Personaje>(pila, crearPersonaje);
    }
    
    cout << endl;

    mostrar<Personaje>(pila, mostrarPersonaje);

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

template<typename T>void agregar(Nodo<T> *&pila, T (*metodo)(T v)){    
    T v;
    T dato = metodo(v);
    push<T>(pila, dato);
}

template<typename T>void mostrar(Nodo<T> *&pila, T (*metodo)(T v, int i)){
    int i = 0;

    while(pila != NULL){
        T v;
        v = pop<T>(pila);        
        metodo(v, i);

        i++;
    }
}

Personaje mostrarPersonaje(Personaje p, int i){
    printf("#%i %s %i\n", i+1, p.nombre, p.fuerza);
}

Personaje crearPersonaje(Personaje p){
    cout << "Nombre: ";
    cin >> p.nombre;

    cout << "Fuerza: ";
    cin >> p.fuerza;

    return p;
}