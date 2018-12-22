/*
* Lista con Array
*/

#include <iostream>

using namespace std;

//
// # Variables Globales
//
#define CANTIDAD_NOTAS 3

//
// # Structs
//
struct Alumno{
    int dni;
    string nombre;
    int notas[CANTIDAD_NOTAS];
};

template <typename T>
struct Nodo{
    T info;
    Nodo *sig;
};

//
// # Prototipos
//
void mostrarInfo(Alumno a);
template <typename T> void mostrar(Nodo<T> *p);
template <typename T> void agregar(Nodo<T> *&p, T v);
Alumno crearAlumno(int dni, string nombre, int notas[]);
void asignarNotas(int notas[], int n1, int n2, int n3);

//
// # Main
//
int main(){
    Nodo<Alumno> *alumnos = NULL;
    
    int notas[CANTIDAD_NOTAS];

    asignarNotas(notas, 4,4,7);
    agregar(alumnos, crearAlumno(35216118, "ramiro", notas));

    asignarNotas(notas, 3,3,5);
    agregar(alumnos, crearAlumno(34216118, "fede", notas));

    asignarNotas(notas, 2,2,9);
    agregar(alumnos, crearAlumno(31216218, "pablo", notas));

    mostrar(alumnos);

    return 0;
}

//
// # Funciones
//
void mostrarInfo(Alumno a){
    cout << "DNI: " << a.dni;
    cout << ", NOMBRE: " << a.nombre;

    cout << ", NOTAS: ";
    for(int i=0; i < CANTIDAD_NOTAS; i++){
        cout << a.notas[i] << " ";
    }

    cout << endl;
}

template <typename T>
void mostrar(Nodo<T> *p){
    Nodo<T> *aux = p;

    while(aux != NULL){
        mostrarInfo(aux->info);

        aux = aux->sig;
    }
}

template <typename T>
void agregar(Nodo<T> *&p, T v){
    Nodo<T> *nuevo = new Nodo<T>();
    nuevo->info = v;
    nuevo->sig = NULL;

    if(p == NULL){
        p = nuevo;
    }
    else{
        Nodo<T> *aux = p;
        // recorro hasta llegar al ultimo nodo y me detengo
        while(aux->sig != NULL){
            // avanzo al siguiente nodo
            aux = aux->sig;
        }
        // le asigno al ultimo nodo el nuevo elemento
        aux->sig  = nuevo;
    }
}

Alumno crearAlumno(int dni, string nombre, int notas[]){
    Alumno a;
    a.dni = dni;
    a.nombre = nombre;
    for(int i=0; i < CANTIDAD_NOTAS; i++){
        a.notas[i] = notas[i];        
    }

    return a;
}

void asignarNotas(int notas[], int n1, int n2, int n3){
    notas[0] = n1;
    notas[1] = n2;
    notas[2] = n3;
}
