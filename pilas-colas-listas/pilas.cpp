#include <iostream>
#include <string.h>

using namespace std;

//
// # Structs
//
struct Estudiante{
    int dni;
    string nombre;    
};

struct Nodo{
    Estudiante info;
    Nodo *sgte;
};


//
// # Variables Globales
//
Nodo *estudiantes = NULL; // (opcional, puede usarse como variable local)

//
// # Prototipos
//
// prototipos necesarios de una PILA
void push(Nodo *&p, Estudiante v);
Estudiante pop(Nodo *&p);
void listarPila(Nodo *&p);
// prototipos básicos
Estudiante crearEstudiante(int dni, string nombre);
void mostrarDatos(Estudiante e);
void cargarDatos(Nodo *&p);

//
// # Main
//
int main(){    
    cargarDatos(estudiantes);
    listarPila(estudiantes);
    cout << endl;

    return 0;
}

//
// # Funciones necesarias para una PILA
//
void push(Nodo *&p, Estudiante v){
    // Creo un nuevo nodo y le asigno espacio en memoria
    Nodo *nuevo = new Nodo;
    // guardo en el nodo el contenido que le paso por parametro a la función
    nuevo->info = v;
    // le asigno como siguiente del nuevo nodo al que esté en la cima de la pila
    // es decir el nodo que se haya insertado antes de este
    // *En una pila los elementos se apilan uno encima del otro, por lo que el nuevo estará
    // encima del anterior, y asi.. quedando encima el nuevo, y debajo de todo el primero agregado
    nuevo->sgte = p;
    // hago que la pila apunte al nuevo nodo
    // ya que ahora es el que está en la cima de la pila
    p = nuevo;
}

Estudiante pop(Nodo *&p){
    // guardo en una variable del mismo tipo que tiene los nodos de la pila
    // el contenido del nodo que se encuentra en la cima
    // y que luego borraré, pero retornaré su contenido
    Estudiante e = p->info;
    // creo un puntero auxiliar que apunta al nodo que está en la cima y eliminaré
    Nodo *aux = p;
    // hago que la pila apunte al siguiente nodo, es decir al que esté debajo del que está arriba de todo    
    p = p->sgte;
    // borro de memoria el nodo del que guardé el contenido
    delete aux;
    // retorno la información del nodo que ya borré, para reutilizar e imprimir por pantalla
    // si es que se requiere
    return e;
}

void listarPila(Nodo *&p){
    // itero mientras que:
    // 1. La pila no esté vacía
    // *No necesito crear un puntero auxiliar en este caso, ya que quiero modificar
    // la pila al recorrerla    
    while(p != NULL){
        // guardo el contenido del nodo que removeré
        // la guardo en una variable del mismo tipo que retorna pop()
        Estudiante e = pop(p);
        // la paso por parametro a una función que imprimirá por pantalla su contenido
        mostrarDatos(e);
    }
}

//
// # Funciones básicas
//
void cargarDatos(Nodo *&p){
    push(p, crearEstudiante(105, "Carlos"));
    push(p, crearEstudiante(100, "Fede"));
    push(p, crearEstudiante(101, "Mariano"));
    push(p, crearEstudiante(102, "Roberto"));
}

void mostrarDatos(Estudiante e){
    cout << e.dni << ", " << e.nombre << endl;
}

Estudiante crearEstudiante(int dni, string nombre){
    Estudiante e;
    e.dni = dni;
    e.nombre = nombre;

    return e;
}

