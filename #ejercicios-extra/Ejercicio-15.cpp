/*
* 
* RECURSIVIDAD
* 
* A partir del algoritmo propuesto y el siguiente array:
* int array[] = {23, 43, 35, 38, 67, 12, 76, 10, 34, 8};
* Crear la función recursiva mayor() que reciba como parámetros: el array, el índice
* inferior, el índice superior y retorne el mayor valor del array. La función main debe
* inicializar el array y mostrar el resultado.
* 
*/
#include <iostream>

using namespace std;

struct Elem{
    int dato;
};

struct Nodo{
    Elem info;
    Nodo *ant;
    Nodo *sig;
};

//
// # Prototipos
// 
void agregar(Nodo *&, Elem);
void insertar(); //
void mostrar(Nodo *);
void mostrarInfo(Elem);
void eliminar(Nodo *);
bool vacia(Nodo *);

Elem frente(Nodo *); 
//
// # Main
// 
int main(){
    Nodo *primero = new Nodo;
    Nodo *ultimo = new Nodo;

    //  
    primero->ant = NULL;
    ultimo->sig = NULL;
    
    // enlazo los extremos
	primero->sig = ultimo;
	ultimo->ant = primero;

    // agrego los elementos
    Elem e1;
    e1.dato = 2;
    agregar(ultimo, e1);

    Elem e2;
    e2.dato = 1;
    agregar(ultimo, e2);

    Elem e3;
    e3.dato = 3;
    agregar(ultimo, e3);

    mostrar(primero);

    cout << "primero: ";
    cout << frente(primero).dato << endl;
    //eliminar(e3)

    return 0;
}

//
// # Funciones
//
Elem frente(Nodo *cabecera){
    return cabecera->sig->info;
}

bool vacia(Nodo *cabecera){
    return (cabecera->sig->sig == NULL);
}

void agregar(Nodo *&ultimo, Elem e){
    Nodo *nuevo = new Nodo;
    // agrego el dato
    nuevo->info = e;
    // al nuevo nodo lo enlazo por adelante con el ultimo
    nuevo->sig = ultimo;
    // al nuevo nodo lo enlazo por detras con el primero
    nuevo->ant = ultimo->ant;

    // guardo el enlaze que tiene detras el ultimo
    Nodo *ant = ultimo->ant;
    // enlazo al ultimo elemento por detras el nuevo nodo
    ultimo->ant = nuevo;
    //  enlazo al que tenia detras el ultimo, por delante con el nuevo nodo
    ant->sig = nuevo;
}

void eliminar(Nodo *objetivo){
    // guardo el nodo anterior y siguiente del que voy a borrar
    // para que no se pierdan y los pueda enlazar
    Nodo *ant = objetivo->ant;
    Nodo *sig = objetivo->sig;
    // enlazo el siguiente con el anterior y viceversa
    ant->sig = sig;
    sig->ant = ant;
    // borro el nodo
    delete objetivo;
}

void mostrar(Nodo *primero){
    //Nodo *aux = primero->sig;
    // primero->sig, porque el primer nodo es NULL
    Nodo *aux = primero->sig;
    // recorro la lista
    // analizo el siguiente de cada elemento para no llegar al ultimo que siempre es null
    while(aux->sig != NULL){
        mostrarInfo(aux->info);
        // recorro cada nodo desde el principio
        aux = aux->sig;
    }
}

void mostrarInfo(Elem e){
    cout << e.dato << endl;
}