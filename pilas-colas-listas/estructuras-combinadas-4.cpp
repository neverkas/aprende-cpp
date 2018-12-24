/*
* Array de Registros con un campo puntero a lista
* (sin templates)
*/

#include <iostream>

using namespace std;

//
// # Variables Globales
//
#define CANT_CURSOS 3

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
    Nodo *inscriptos;
};

//
// # Prototipos 
//
// prototipos necesarios para listas
void agregar(Nodo *&l, Alumno v);
void listarLista(Nodo *l);
// prototipos básicos
void listarVector(Curso v[], int len);
void mostrarDatos(Alumno a);
Alumno crearAlumno(int legajo, string nombre);
Curso crearCurso(int id, string nombre, Nodo *inscriptos);

//
// # Main
//
int main(){
    Curso cursos[CANT_CURSOS];

    Nodo *inscriptos = NULL,  *inscriptos2 = NULL,  *inscriptos3 = NULL;

    agregar(inscriptos, crearAlumno(001, "Ramiro"));
    agregar(inscriptos, crearAlumno(002, "Julian"));    
    cursos[0] = crearCurso(0, "Fisica", inscriptos);

    agregar(inscriptos2, crearAlumno(005, "Fede"));
    agregar(inscriptos2, crearAlumno(007, "Horacio"));
    cursos[1] = crearCurso(1, "Discreta", inscriptos2);

    agregar(inscriptos3, crearAlumno(011, "Juan"));
    agregar(inscriptos3, crearAlumno(012, "Manu"));
    cursos[2] = crearCurso(2, "Discreta", inscriptos3);

    return 0;
}

//
// # Funciones
//
void agregar(Nodo *&p, Alumno v){
    Nodo *nuevo = new Nodo();
    nuevo->info = v;
    nuevo->sig = NULL;

    if(p == NULL){
        p = nuevo;
    }
    else{
        Nodo *aux = p;
        // recorro hasta llegar al ultimo nodo y me detengo
        while(aux->sig != NULL){
            // avanzo al siguiente nodo
            aux = aux->sig;
        }
        // le asigno al ultimo nodo el nuevo elemento
        aux->sig  = nuevo;
    }
}

void listarLista(Nodo *l){
    while(l != NULL){
        mostrarDatos(l->info);
        l = l->sig;
    }
}

//
// # Funciones básicas
//
void listarVector(Curso v[], int len){
    for(int i=0; i < len; i++){
        Curso c = v[i];

        cout << "ID:" << c.id;
        cout << ", NOMBRE: " << c.nombre;
        cout << endl;

        listarLista(v[i].inscriptos);
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

Curso crearCurso(int id, string nombre, Nodo *inscriptos){
    Curso c;
    c.id = id;
    c.nombre = nombre;
    c.inscriptos = inscriptos;

    return c;
}
