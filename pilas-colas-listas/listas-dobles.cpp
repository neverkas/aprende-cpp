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
    Nodo *ant;
    Nodo *sgte;
};

//
// # Prototipos
//
void mostrarDatos(Estudiante v);
Estudiante crearEstudiante(int dni, string nombre);

void insertarAlFinal(Nodo *&ultimo, Estudiante v);
void insertarAlPrincipio(Nodo *&primero, Estudiante v);
void eliminar(Nodo *nodo);
Nodo *buscarPorDni(Nodo *primero, int dni);
void listarPrimeroAlUltimo(Nodo *primero);

//
// # Main
//
int main(){
    Nodo *primero = new Nodo, *ultimo = new Nodo;
    primero->ant = NULL;
    ultimo->sgte = NULL;

    primero->sgte = ultimo;
    ultimo->ant = primero;

    // inserto al principio
    insertarAlPrincipio(primero, crearEstudiante(101, "mario")); // el primero
    insertarAlPrincipio(primero, crearEstudiante(102, "rober")); // el anterior ahora es segundo
    insertarAlPrincipio(primero, crearEstudiante(103, "pedro")); // el anterior ahora es segundo
    // inserto al final
    insertarAlFinal(ultimo, crearEstudiante(104, "carlos")); // el ultimo
    insertarAlFinal(ultimo, crearEstudiante(105, "fede")); // el anterior ahora es ante-ultimo

    Nodo *nodoEncontrado = buscarPorDni(primero, 102);
    eliminar(nodoEncontrado);

    listarPrimeroAlUltimo(primero);

}

//
// # Funciones
//
Nodo *buscarPorDni(Nodo *primero, int dni){
    primero = primero->sgte;

    while(primero->sgte != NULL && primero->info.dni != dni){
        primero = primero->sgte;
    }

    return primero;
}

void eliminar(Nodo *nodo){
    Nodo *sgte = nodo->sgte;
    Nodo *ant = nodo->ant;

    sgte->ant = ant;
    ant->sgte = sgte;

    delete nodo;
}

void listarPrimeroAlUltimo(Nodo *primero){
    // avanzo al siguiente porque el primero siempre es NULL al ser lista doblemente enlazada
    primero = primero->sgte;

    // recorro solo hasta el anteúltimo porque el ultimo siempre es NULL
    while(primero->sgte != NULL){
        Estudiante e = primero->info;

        mostrarDatos(e);

        primero = primero->sgte;
    }
}
void insertarAlPrincipio(Nodo *&primero, Estudiante v){
    Nodo *nuevo = new Nodo;
    nuevo->info = v;
    nuevo->ant = primero;
    nuevo->sgte = primero->sgte;

    Nodo *sgte = primero->sgte;
    sgte->ant = nuevo;
    primero->sgte = nuevo;
}

void insertarAlFinal(Nodo *&ultimo, Estudiante v){
    Nodo *nuevo = new Nodo;
    nuevo->info = v;
    nuevo->sgte = ultimo;
    nuevo->ant = ultimo->ant;

    Nodo *ant = ultimo->ant;
    ant->sgte = nuevo;
    ultimo->ant = nuevo;
}

void mostrarDatos(Estudiante v){
    cout << v.dni << " " << v.nombre << endl;
}


Estudiante crearEstudiante(int dni, string nombre){
    Estudiante e;
    e.dni = dni;
    e.nombre = nombre;

    return e;
}