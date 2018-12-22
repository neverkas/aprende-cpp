#include <iostream>

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
Nodo *frente = NULL; // variable global
Nodo *cola = NULL; // variable global

//
// # Prototipos
//
void encolar(Nodo *&frente, Nodo *&cola, Estudiante e);
Estudiante desencolar(Nodo *&frente, Nodo *&cola);
Estudiante crearEstudiante(int dni, string nombre);
void mostrarDatos(Estudiante e);
void listarCola(Nodo *&frente, Nodo *&cola);

//
// # Main
//
int main(){
    encolar(frente, cola, crearEstudiante(100, "carlos"));
    encolar(frente, cola, crearEstudiante(103, "fede"));
    encolar(frente, cola, crearEstudiante(105, "mariano"));
    encolar(frente, cola, crearEstudiante(101, "julian"));

    listarCola(frente, cola);

    return 0;
}

//
// # Funciones
//
void listarCola(Nodo *&frente, Nodo *&cola){
    while(frente != NULL){
        Estudiante e = desencolar(frente, cola);
        mostrarDatos(e);
    }
    cout << endl;
}

void encolar(Nodo *&frente, Nodo *&cola, Estudiante e){
    Nodo *nuevo = new Nodo;
    nuevo->info = e;
    nuevo->sgte = NULL;

    if(frente == NULL){
        frente = nuevo; 
    }else{
        cola->sgte = nuevo;        
    }

    cola = nuevo;
}

Estudiante desencolar(Nodo *&frente, Nodo *&cola){
    Nodo *aux = frente;
    Estudiante e;
    e = frente->info;
    
    if(frente == NULL){
        cola = NULL;
    }else{
        frente = frente->sgte;        

        delete aux;
    }

    return e;
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
