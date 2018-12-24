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
Nodo *frente = NULL; // (opcional, puede usarse como variable local)
Nodo *cola = NULL; // (opcional, puede usarse como variable local)

//
// # Prototipos
//
// prototipos necesarios para una la Cola
void encolar(Nodo *&frente, Nodo *&cola, Estudiante e);
Estudiante desencolar(Nodo *&frente, Nodo *&cola);
void listarCola(Nodo *&frente, Nodo *&cola);
// prototipos básicos
Estudiante crearEstudiante(int dni, string nombre);
void mostrarDatos(Estudiante e);
void cargarDatos(Nodo *&frente, Nodo *&cola);

//
// # Main
//
int main(){
    // Cargo datos la cola con la función encolar()
    cargarDatos(frente, cola);
    // Listo el contenido de los nodos con el método desencolar()
    listarCola(frente, cola);

    return 0;
}

//
// # Funciones necesarias para una cola
//

// Los nodos ingresan por la "cola" ó por el "fin" de una lista tipo cola
void encolar(Nodo *&frente, Nodo *&cola, Estudiante e){
    // Creo un puntero del tipo Nodo y le asigno espacio en la memoria
    Nodo *nuevo = new Nodo;
    // guardo el contenido que le pasa por parametro a la función
    nuevo->info = e;
    // cada nodo apunta como siguiente a NULL, porque este será el nuevo último elemento
    nuevo->sgte = NULL;

    // si el frente está vacío
    if(frente == NULL){
        // entonces no hay elementos en la cola
        // hago que el puntero "frente" apunte al primer nodo
        frente = nuevo; 
    }
    // si la cola no está vacía (si tiene 1 o más nodos)
    else{
        // hago que el último nodo al que apunta la cola
        // apunte al nuevo nodo que agregaré
        cola->sgte = nuevo;        
    }
    // hago que el puntero "cola" apunte al nuevo nodo
    cola = nuevo;
}

// Los nodos se sacan por el  "frente" ó "principio" de una lista tipo cola
Estudiante desencolar(Nodo *&frente, Nodo *&cola){
    // Creo un nodo auxiliar donde guardo el primer nodo que apunta el puntero "frente"
    Nodo *aux = frente;
    // guardo el contenido del primer nodo al que apunta el puntero "frente"
    // es el que luego retornaré para imprimir en pantalla
    Estudiante e = frente->info;
    
    // Si el frente está vacío entonces no hay elementos
    if(frente == NULL){
        // y si no hay elementos en el frente que es de donde se sacan los elementos de una cola
        // entonces tampoco lo habrá en la cola
        cola = NULL;
    }
    // si el frente no está vacío (si aún hay 1 o más elementos)
    else{
        // hago que "frente" apunte al siguiente
        frente = frente->sgte;        
        // borro de memoria el nodo al que apuntaba "frente"
        delete aux;
    }
    // retorno los datos que guardé al principio, para luego mostrarlos por pantalla
    return e;
}

void listarCola(Nodo *&frente, Nodo *&cola){
    // Con el bucle tipo while, itero al metodo desencolar() y mostrarDatos()
    // mientras el "frente" de la "cola" no esté vacío.
    // Nota: En una lista tipo Cola que dispone de "frente/cola" los nodos se remueven del frente
    // de la lista.
    while(frente != NULL){
        // Guardo en una variable del mismo tipo que retorna el desencolar()
        Estudiante e = desencolar(frente, cola);
        // lo que se guardó lo paso como parametro a mostrarDatos() que imprime por pantalla la información
        mostrarDatos(e);
    }

    cout << endl;
}

//
// # Funciones básicas
//

void cargarDatos(Nodo *&frente, Nodo *&cola){
    // Por cada llamado a "encolar" agrego un nuevo nodo a la "Cola"
    // crearEstudiante() es una función que retorna un struct del tipo Estudiante
    // Nota: En una lista tipo Cola que tiene "frente/cola" los nodos se agregan al final de 
    // la lista es decir en la cola
    encolar(frente, cola, crearEstudiante(100, "carlos"));
    encolar(frente, cola, crearEstudiante(103, "fede"));
    encolar(frente, cola, crearEstudiante(105, "mariano"));
    encolar(frente, cola, crearEstudiante(101, "julian"));
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
