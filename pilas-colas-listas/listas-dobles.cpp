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
// prototipos necesarias para una Lista doblemente enlazada
void insertarAlFinal(Nodo *&ultimo, Estudiante v);
void insertarAlPrincipio(Nodo *&primero, Estudiante v);
void eliminar(Nodo *nodo);
void listarPrimeroAlUltimo(Nodo *primero);
void listarUltimoAlPrimero(Nodo *ultimo);
// prototipos básicos
void cargarDatos(Nodo *&primero, Nodo *&ultimo);
Nodo *buscarPorDni(Nodo *primero, int dni);
void mostrarDatos(Estudiante v);
Estudiante crearEstudiante(int dni, string nombre);

//
// # Main
//
int main(){
    // creo los nodos del principio y fin
    // y les asigno espacio en memoria
    Nodo *primero = new Nodo, *ultimo = new Nodo;
    // los extremos siempre se les asigna NULL para poder ingresar elementos 
    // por cualquiera de ellos y poder recorrer desde el principio o final también
    primero->ant = NULL;
    ultimo->sgte = NULL;
    // enlazo ambos extremos
    primero->sgte = ultimo;
    ultimo->ant = primero;

    // cargo los datos al principio ó al final
    // se puede agregar elementos desde donde quieras
    cargarDatos(primero, ultimo);

    // pruebo buscar un elemento para luego eliminarlo
    Nodo *nodoEncontrado = buscarPorDni(primero, 102);
    // para eliminar un elemento sólo necesito pasar el nodo
    // saco el enlace que tiene con sus extremos, y enlazo únicamente sus extremos
    // para eso creo un puntero y luego los enlazo
    eliminar(nodoEncontrado);

    // listo el contenido desde el princio y desde el final
    // se puede recorrer tanto desde el principio como desde el final de la lista
    listarPrimeroAlUltimo(primero);
    listarUltimoAlPrimero(ultimo);

    return 0;
}

//
// # Funciones necesarias para una Lista doblemente enlazada
//
void eliminar(Nodo *nodo){
    // Creo un puntero para el nodo siguiente y anterior del nodo que borraré
    // para poder enlazarlos entre ellos
    Nodo *sgte = nodo->sgte;
    Nodo *ant = nodo->ant;
    // enlazo el siguiente con anterior
    sgte->ant = ant;
    // enlazo el anterior con el siguiente
    ant->sgte = sgte;
    // borro de memoria el nodo que pasé por parametro
    delete nodo;
}

void listarPrimeroAlUltimo(Nodo *primero){
    // avanzo al siguiente porque el primero siempre es NULL al ser lista doblemente enlazada
    primero = primero->sgte;

    // recorro solo hasta el anteúltimo porque el ultimo siempre es NULL
    while(primero->sgte != NULL){
        // guardo el contenido que voy a imprimir por pantalla
        Estudiante e = primero->info;
        // lo paso por parametro a una función que lo imprimirá
        mostrarDatos(e);
        // hago que la lista avance al siguiente
        primero = primero->sgte;
    }
}
void insertarAlPrincipio(Nodo *&primero, Estudiante v){
    // creo un nuevo nodo del tipo Struct y le asigno espacio en memoria
    Nodo *nuevo = new Nodo;
    // le cargo la información que es pasada por parametro de la función
    nuevo->info = v;
    // como voy a insertarlo al principio de la lista
    // le asigno como anterior el principio de la lista
    nuevo->ant = primero;
    // y le asigno como siguiente al que era antes el primer nodo
    nuevo->sgte = primero->sgte;

    // creo un nuevo puntero para poder enlazarlo con el nuevo
    Nodo *sgte = primero->sgte;
    // el que era primer elemento ahora le enlazo como anterior el nuevo
    // ya que ahora pasará como segundo
    // (más arriba enlazé al nuevo con el primero, pero no al revés, por eso lo hago ahora)
    sgte->ant = nuevo;
    // y ahora hago que el principio de la lista apunte al nuevo nodo
    // (más arriba enlazé al nuevo con el principio, pero no al revés, por eso lo hago ahora)
    primero->sgte = nuevo;
}

void insertarAlFinal(Nodo *&ultimo, Estudiante v){
    // creo un nuevo puntero del tipo struct que le asigno espacio en memoria
    Nodo *nuevo = new Nodo;
    // le cargo la información que paso por parametro de la función
    nuevo->info = v;
    // como voy a agregar el nodo a lo último
    // le asigno como siguiente el final de la lista
    // (luego voy a hacer que último apunte al nuevo)
    nuevo->sgte = ultimo;
    // y lo enlazo como anterior al que antes era el último de la lista
    // (luego voy a enlazar el último con el nuevo)
    nuevo->ant = ultimo->ant;

    // creo un nuevo puntero para poder enlazarlo con el nuevo
    Nodo *ant = ultimo->ant;
    // al que antes era el último elemento, ahora sera el anteúltimo
    // y lo enlazo con el nuevo (que ahora será el último elemento)
    ant->sgte = nuevo;
    // hago que el final de la lista apunte al nuevo nodo
    ultimo->ant = nuevo;
}

//
// # Funciones básicas
//
void cargarDatos(Nodo *&primero, Nodo *&ultimo){
    // inserto al principio
    insertarAlPrincipio(primero, crearEstudiante(101, "mario")); // el primero
    insertarAlPrincipio(primero, crearEstudiante(102, "rober")); // el anterior ahora es segundo
    insertarAlPrincipio(primero, crearEstudiante(103, "pedro")); // el anterior ahora es segundo
    // inserto al final
    insertarAlFinal(ultimo, crearEstudiante(104, "carlos")); // el ultimo
    insertarAlFinal(ultimo, crearEstudiante(105, "fede")); // el anterior ahora es ante-ultimo
}

Nodo *buscarPorDni(Nodo *primero, int dni){
    // avanzo porque el primer elemento como el último siempre son NULL
    // (extremos de una lista doblemente enlazada)
    primero = primero->sgte;
    // itero mientras se cumplan las sig. condiciones:
    // 1. que no haya llegado al primer elemento (null)
    // 2. que el contenido del nodo sea distinto al que estoy buscando
    // *La primera condición es para recorrer sólo hasta el final de la lista en caso
    // que no se encuentre el dato que se busca
    // *La segunda condición es únicamente para que siga recorriendo hasta encontrar el dato
    while(primero->sgte != NULL && primero->info.dni != dni){
        // avanzo al siguiente nodo (desde el principio hasta el final)
        primero = primero->sgte;
    }

    // si el nodo fue encontrado lo retonará, sino sólo retorna NULL
    return primero;
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