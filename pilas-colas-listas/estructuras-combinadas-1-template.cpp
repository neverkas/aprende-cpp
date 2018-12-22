/*
* Array de Registros con un campo puntero a lista
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
template <typename T>
struct Nodo{
    T info;
    Nodo<T> *sig;
};

struct Alumno{
    int legajo;
    string nombre;
};

struct Curso{
    int id;
    string nombre;
    Nodo<Alumno> *inscriptos;
};

//
// # Prototipos
//
template <typename T> void agregar(Nodo<T> *&p, T v);
void mostrarInfo(Alumno a);
template <typename T> void mostrar(Nodo<T> *p);
Alumno crearAlumno(int legajo, string nombre);
Curso crearCurso(int id, string nombre, Nodo<Alumno> *inscriptos);

//
// # Main
//
int main(){
    Curso cursos[CANT_CURSOS];

    Nodo<Alumno> *inscriptos = NULL,  *inscriptos2 = NULL,  *inscriptos3 = NULL;

    agregar(inscriptos, crearAlumno(001, "Ramiro"));
    agregar(inscriptos, crearAlumno(002, "Julian"));    
    cursos[0] = crearCurso(0, "Fisica", inscriptos);

    agregar(inscriptos2, crearAlumno(005, "Fede"));
    agregar(inscriptos2, crearAlumno(007, "Horacio"));
    cursos[1] = crearCurso(1, "Discreta", inscriptos2);

    agregar(inscriptos3, crearAlumno(011, "Juan"));
    agregar(inscriptos3, crearAlumno(012, "Manu"));
    cursos[2] = crearCurso(2, "Discreta", inscriptos3);

    for(int i=0; i < CANT_CURSOS; i++){
        Curso c = cursos[i];

        cout << "ID:" << c.id;
        cout << ", NOMBRE: " << c.nombre;
        cout << endl;

        mostrar(cursos[i].inscriptos);
        cout << endl;
    }

    return 0;
}

//
// # Funciones
//
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

void mostrarInfo(Alumno a){
    cout << "LEGAJO: " << a.legajo;
    cout << ", NOMBRE: " << a.nombre;

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

Alumno crearAlumno(int legajo, string nombre){
    Alumno a;
    a.legajo = legajo;
    a.nombre = nombre;

    return a;
}

Curso crearCurso(int id, string nombre, Nodo<Alumno> *inscriptos){
    Curso c;
    c.id = id;
    c.nombre = nombre;
    c.inscriptos = inscriptos;

    return c;
}
