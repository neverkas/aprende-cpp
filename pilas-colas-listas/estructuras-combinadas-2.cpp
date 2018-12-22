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

struct Nodo{
    Alumno info;
    Nodo *sig;
};

//
// # Prototipos
//
// prototipos necesarios para listas
void listarLista(Nodo *l);
void agregarAlumno(Nodo *&l, Nodo v);
// prototipos básicos
void cargarDatos(Nodo *&l);
void listarVector(int v[], int len);
void mostrarDatos(Alumno a);
Alumno crearAlumno(int dni, string nombre, int notas[]);
void asignarNotas(int notas[], int n1, int n2, int n3);

//
// # Main
//
int main(){
    Nodo *alumnos = NULL;
    
    // cargo los datos a la lista
    cargarDatos(alumnos);
    // imprimo la información de los nodos de la lista
    listarLista(alumnos);

    return 0;
}

//
// # Funciones para Listas
//
void agregarAlumno(Nodo *&l, Alumno v){
    // creo un nuevo nodo y le asigno espacio en memoria
    Nodo *nuevo = new Nodo;
    // guardo la informacion que le paso por parametro a la función
    nuevo->info = v;
    // le asigno como siguiente NULL
    // ya que cada nuevo nodo lo agregaré al final de la lista, y permitirá delimitar
    // el fin de la lista
    nuevo->sig = NULL;

    // si la lista está vacía
    if(l == NULL){
        // entonces hago que apunte al nuevo nodo (que será el primero)
        l = nuevo;
    }
    else{
        // creo un puntero auxiliar, que me permite recorrer los nodos de la lista
        // sin alterar el contenido
        Nodo *aux = l;
        // itero mientras no hay llegado al último
        while(aux->sig != NULL){
            // avanzo al siguiente nodo
            aux = aux->sig;
        }
        // le asigno al que era el último nodo, como siguiente el nuevo
        // quedando el ultimo como anteultimo, y el nuevo como último
        aux->sig  = nuevo;
    }
}

void listarLista(Nodo *l){
    // itero mientras la lista no esté vacía
    // al no pasar por referencia el puntero, no lo modifica
    // solo de manera local, dentro de la función
    while(l != NULL){
        // guardo la información de cada nodo, en una variable del mismo tipo
        Alumno a = l->info;
        // y le paso por parametro a una función que imprimirá por pantalla la información
        mostrarDatos(a);
        // avanzo al siguiente nodo
        l = l->sig;
    }
}

//
// # Funciones básicas
//
void cargarDatos(Nodo *&l){
    int notas[CANTIDAD_NOTAS];

    asignarNotas(notas, 4,4,7);
    agregarAlumno(l, crearAlumno(35216118, "ramiro", notas));

    asignarNotas(notas, 3,3,5);
    agregarAlumno(l, crearAlumno(34216118, "fede", notas));

    asignarNotas(notas, 2,2,9);
    agregarAlumno(l, crearAlumno(31216218, "pablo", notas));
}

void listarVector(int v[], int len){
    for(int i=0; i < len; i++){
        cout << v[i] << " ";
    }
}

void mostrarDatos(Alumno a){
    cout << "DNI: " << a.dni;
    cout << ", NOMBRE: " << a.nombre;

    cout << ", NOTAS: ";
    listarVector(a.notas, CANTIDAD_NOTAS);

    cout << endl;
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
