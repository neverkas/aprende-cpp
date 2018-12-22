/*
* Array de Registros con un campo puntero a lista
*/

#include <iostream>

using namespace std;

//
// # Variables Globales
//
#define CANT_CURSOS 2

//
// # Structs
//
struct Alumno{
    int legajo;
    string nombre;
};

struct Nodo{
    Alumno info;
    Nodo *sig;
};

struct Curso{
    int id;
    string nombre;

    Nodo *alumnos;
};

//
// # Prototipos
//
// prototipos necesarios para listas
void agregarAlumno(Nodo *&l, Alumno v);
void listarLista(Nodo *l);
// prototipos básicos
void listarVector(Curso v[], int len);
void cargarDatos(Curso v[]);
void mostrarDatos(Alumno a);
Alumno crearAlumno(int legajo, string nombre);
Curso crearCurso(int id, string nombre, Nodo *alumnos);

//
// # Main
//
int main(){
    Curso cursos[CANT_CURSOS];

    cargarDatos(cursos);
    listarVector(cursos, CANT_CURSOS);

    return 0;
}

//
// # Funciones necesarias para Listas
//
void agregarAlumno(Nodo *&l, Alumno v){
    // Creo un nuevo nodo y le asigno espacio en memoria
    Nodo *nuevo = new Nodo;
    // le guardo el contenido que paso por parametro a la función
    nuevo->info = v;
    // le asigno como siguiente NULL, ya que cada nuevo nodo lo agrego al final
    // de la lista, y me permite delimitar su fin al momento de recorrerla    
    nuevo->sig = NULL;

    // si la lista está vacía
    if(l == NULL){
        // entonces apunto la lista al nuevo nodo que será el primero
        l = nuevo;
    }
    // si la lista no está vacía
    // entonces tiene uno o más elementos
    else{
        // creo un puntero auxiliar para luego recorrer la lista
        // sin modificar o alterar la lista original
        Nodo *aux = l;
        // itero mientras no haya llegado hasta el anteultimo nodo
        while(aux->sig != NULL){
            // avanzo al siguiente nodo
            aux = aux->sig;
        }
        // le asigno como siguiente del que era el último nodo, el nuevo
        // quedando el ultimo como anteultimo, y el nuevo como último
        aux->sig  = nuevo;
    }
}

void listarLista(Nodo *l){
    // itero mientras la lista no esté vacía
    // no necesito pasar por referencia el puntero de la lista, sólo voy a recorrer los nodos
    while(l != NULL){
        // cada vez que se ejecute la instrucción
        // guardo en una variable de mismo tipo de info
        Alumno a = l->info;
        // llamo a la función mostrarDatos() que le paso por parametro el contenido
        // y que imprimira por pantalla los datos
        mostrarDatos(a);
        // avanzo al siguiente nodo de la lista
        l = l->sig;
    }
}

//
// # Funciones básicas
//
void cargarDatos(Curso v[]){
    Nodo *alumnos1 = NULL,  *alumnos2 = NULL;

    agregarAlumno(alumnos1, crearAlumno(001, "Ramiro"));
    agregarAlumno(alumnos1, crearAlumno(002, "Julian"));    
    v[0] = crearCurso(0, "Fisica", alumnos1);

    agregarAlumno(alumnos2, crearAlumno(005, "Fede"));
    agregarAlumno(alumnos2, crearAlumno(007, "Horacio"));
    v[1] = crearCurso(1, "Discreta", alumnos2);
}

void listarVector(Curso v[], int len){
    for(int i=0; i < len; i++){
        Curso c = v[i];

        cout << "ID:" << c.id;
        cout << ", NOMBRE: " << c.nombre;
        cout << endl;

        listarLista(v[i].alumnos);
        cout << endl;
    }
}

void mostrarDatos(Alumno a){
    cout << "LEGAJO: " << a.legajo;
    cout << ", NOMBRE: " << a.nombre;

    cout << endl;
}

Alumno crearAlumno(int legajo, string nombre){
    Alumno a;
    a.legajo = legajo;
    a.nombre = nombre;

    return a;
}

Curso crearCurso(int id, string nombre, Nodo *alumnos){
    Curso c;
    c.id = id;
    c.nombre = nombre;
    c.alumnos = alumnos;

    return c;
}
