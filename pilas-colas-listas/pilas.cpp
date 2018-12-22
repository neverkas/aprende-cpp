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
Nodo *estudiantes = NULL; // variable global

//
// # Prototipos
//
void push(Nodo *&p, Estudiante v);
Estudiante pop(Nodo *&p);
void listarPila(Nodo *&p);
Estudiante crearEstudiante(int dni, string nombre);
void mostrarDatos(Estudiante e);

//
// # Main
//
int main(){    
    push(estudiantes, crearEstudiante(105, "Carlos"));
    push(estudiantes, crearEstudiante(100, "Fede"));
    push(estudiantes, crearEstudiante(101, "Mariano"));
    push(estudiantes, crearEstudiante(102, "Roberto"));

    listarPila(estudiantes);
    cout << endl;

    return 0;
}

//
// # Funciones
//
void mostrarDatos(Estudiante e){
    cout << e.dni << ", " << e.nombre << endl;
}

Estudiante crearEstudiante(int dni, string nombre){
    Estudiante e;
    e.dni = dni;
    e.nombre = nombre;

    return e;
}

void listarPila(Nodo *&p){
    while(p != NULL){
        Estudiante e = pop(p);
        mostrarDatos(e);
    }
}

void push(Nodo *&p, Estudiante v){
    Nodo *nuevo = new Nodo;
    nuevo->info = v;
    nuevo->sgte = p;
    p = nuevo;
}

Estudiante pop(Nodo *&p){
    Estudiante e = p->info;
    Nodo *aux = p;
    p = p->sgte;
    delete aux;
    return e;
}
