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
Nodo *LISTA = NULL; // (opcional, puede usarse como variable local)

//
// # Prototipos
//
// prototipos para listas simplemente enlazadas
Nodo *insertarAlFinal(Nodo *&l, Estudiante e);
Nodo *insertarAlPrincipio(Nodo *&l, Estudiante e);
Nodo *insertarOrdenado(Nodo *&l, Estudiante e);
void ordenarLista(Nodo *&l);
void listarLista(Nodo *l);
void eliminar(Nodo *&l, int v);
Estudiante eliminarPrimerNodo(Nodo *&l);
Nodo *buscar(Nodo *&l, int v);
Nodo *buscaEInserta(Nodo *&l, int v);

// prototipos básicos
void cargarDatos(Nodo *&l);
Estudiante crearEstudiante(int dni, string nombre);
void mostrarDatos(Estudiante e);

//
// # Main
//
int main(){
    cargarDatos(LISTA);

    eliminar(LISTA, 109);
    ordenarLista(LISTA);    
    listarLista(LISTA);

    Nodo *estudiante = buscar(LISTA, 101);
    mostrarDatos(estudiante->info);

    buscaEInserta(LISTA, 104);
    buscaEInserta(LISTA, 102);

    listarLista(LISTA);

    return 0;
}

//
// # Funciones necesarias para Listas simplemente enlazadas
//
Estudiante eliminarPrimerNodo(Nodo *&l){
    // Guardo el contenido del nodo que voy a eliminar, luego lo retornaré
    Estudiante e = l->info;
    // creo un puntero auxiliar para guardar el primer nodo que apunta la lista
    Nodo *aux = l;
    // hago que la lista apunte al siguiente nodo
    l = l->sgte;
    // elimino de memoria el primer nodo
    delete aux;
    // retorno los datos del elemento que al principio guardé los datos y luego eliminé de memoria
    return e;
}

void ordenarLista(Nodo *&l){
    // creo un puntero y le asigno NULL, para agregar de forma ordenada los elementos
    // que pertenecen a la lista original
    Nodo *listaOrdenada = NULL;

    // itero mientras la vacía no esté vacía
    while(l != NULL){
        // guardo el contenido que retorna al eliminar el primer nodo de la lista
        Estudiante e = eliminarPrimerNodo(l);
        // para luego insertarlo de forma ordenada en la lista que cree al principio y que estaba vacía
        insertarOrdenado(listaOrdenada, e);
    }

    // como la lista original quedó vacía,
    // ahora hago que apunte a la lista auxiliar que cree al principio
    // que tiene todos los nodos de forma ordenada
    l = listaOrdenada;
}

// la función es del tipo puntero porque voy a retornar un nodo
Nodo *insertarOrdenado(Nodo *&l, Estudiante e){
    // creo un nuevo nodo y le asigno espacio en memoria
    Nodo *nuevo = new Nodo;
    // guardo el contenido que le paso por parametro a la función
    nuevo->info = e;
    // hago que siempre el final de la lista apunte a null
    nuevo->sgte = NULL;

    // creo un puntero auxiliar para guardar donde apunta la lista original
    // y poder recorrerla sin generar cambios
    Nodo *aux = l;
    // creo otro puntero que apuntará al anteúltimo elemento, 
    // ya que recorreré la lista hasta el final
    Nodo *ant = NULL;

    // itero mientras que:
    // 1. la lista no esté vacía
    // 2. que los nodos de la lista sean igual o menor al nuevo
    // *La primera condición es para recorrer hasta el final de la lista
    // *La segunda condición es para recorrer todos los nodos que sean menor o igual 
    // al nuevo nodo, y si alguno es mayor al nuevo, se detiene
    while(aux != NULL && aux->info.dni <= e.dni){
        // si llegó al final de la lista, "ant" guarda el anteúltimo
        // si ninguna de las condiciones del while se cumplió, valdrá NULL
        ant = aux;
        // Si llegó al final de la lista, "aux" valdrá NULL
        // si ninguna de las condiciones del while se cumplió, valdrá al elemento que apuntaba
        // la lista desde un principio
        // además permite avanzar al siguiente nodo
        aux = aux->sgte;
    }

    // si no hay anterior elemento, es porque no pasó por el while es decir
    // que no se cumplieron las condiciones del while
    if(ant == NULL){
        // entonces hago que la lista apunte al nuevo        
        l = nuevo;
    }
    // si existe un elemento anterior
    else{
        // hago que el anterior nodo, tenga como siguiente al nuevo
        ant->sgte = nuevo;
    }
    // y que el nuevo siempre apunte al siguiente ó a donde apuntaba la lista
    nuevo->sgte = aux;
    // retorno el nodo por si quiero reutilizarlo en otro método
    return nuevo;
}

// esta función reduce bastante el código y las llamadas a funciones
Nodo *buscaEInserta(Nodo *&l, int v){
    // creo un puntero donde voy a guardar el resultado que retorne la función buscar()
    // si encuentra en la lista lo que busco, retorna el puntero al nodo, sino 
    // retorna NULL (que no lo encontró) porque recorrió la lista hasta el final
    Nodo *nodo = buscar(l, v);
    // guardo el estado de la búsqueda
    // si se encontró se la signa TRUE, caso contrario FALSE
    bool enc = (nodo != NULL);

    // si no se encontró el nodo
    if(!enc){
        // inserto el nodo
        insertarAlFinal(l, crearEstudiante(v, ""));
        // NOTA: REVISAR ESTA PARTE
    }

    // retorno el nodo por si se requiere 
    return nodo;
}

Nodo *buscar(Nodo *&l, int v){
    // Creo un puntero auxiliar para recorrer la lista, sin generar cambios en la original
    Nodo *aux = l;
    // itero siempre que:
    // 1. No haya llegado al final de la lista
    // 2. El dato buscado no sea igual a los que se recorre
    while(aux != NULL && aux->info.dni != v){
        // avanzo al siguiente
        aux = aux->sgte;
    }

    // si lo encuentra retorna el nodo,
    // sino lo encuentra retorna NULL porque llegó al final de la lista auxiliar que apunta a NULL
    return aux;
}

// A diferencia de las "Listas doblemente enlazadas"
// cómo en las "Listas simplemente enlazadas", se enlaza con un puntero
// al siguiente de un nodo. Se debe recorrer la lista, para guardar el anterior.
void eliminar(Nodo *&l, int v){
    // creo un puntero auxiliar que apunte a lo mismo que la lista original,
    // para recorrerla sin generar cambios en la original
    Nodo *aux = l;
    // creo otro puntero para definir si el nodo que se busca tiene otro que lo preceda o no
    // tambien sirve para saber si la lista está vacía
    Nodo *ant = NULL;

    // itero mientras que:
    // 1. La lista no esté vacía
    // 2. Los elementos que se recorran sean distintos al que se busca
    // *Si no se encuentra el dato, entonces llega hasta el final de la lista
    // *Si se encuentra, el while se detiene
    // *Si la lista está vacía (aux=NULL) entonces no se ejecuta el while y pasa a la 
    // siguiente instrucción que son los condicionales que le siguen
    while(aux != NULL && aux->info.dni != v){
        // a medida que recorro, guardo el anterior al nodo encontrado
        ant = aux;
        // avanzo al siguiente
        aux = aux->sgte;
    }

    // si no tiene anterior
    // entonces la lista está vacía o es el primer elemento    
    if(ant == NULL){
        // hago que el principio de la lista apunte al siguiente del primer nodo (el segundo)
        l = aux->sgte;
    }
    // si se encontró un nodo anterior al encontrado
    else{
        // al anterior nodo del encontrado, le asigno como siguiente, el que le siga al que voy a eliminar
        // ej. 1,2,3. si voy a eliminar el 2, conecto el 1 con el 3
        ant->sgte = aux->sgte;
    }

    // elimino de memoria el dato que quería borrar
    delete aux;
}

// a diferencia de las "pilas" y "colas"
// no necesito pasar por referencia la lista, ya que no se requiere
// hacer un pop() ni dequeue(), solo recorrer
void listarLista(Nodo *l){
    // itero mientras no haya llegado al final de la lista
    while(l != NULL){
        // guardo el contenido en una variable del mismo tipo que tenga el nodo
        Estudiante e = l->info;
        // llamo a la función mostrarDatos() que imprimirá por pantalla el contenido del nodo
        mostrarDatos(e);
        // avanzo al siguiente hasta llegar al final, uno por uno
        l = l->sgte;
    }
}

Nodo *insertarAlFinal(Nodo *&l, Estudiante v){
    // creo un puntero del tipo nodo, y le asigno espacio en memoria
    Nodo *nuevo = new Nodo;
    // guardo el contenido de lo que le paso por parametro a la función
    nuevo->info = v;
    // a cada nodo nuevo le asigno como siguiente NULL ya que los agregaré al final
    // de la lista, y al momento de recorrerla servirá como tope de cuando detenerme al listarla
    nuevo->sgte = NULL;

    // si la lista está vacía,
    // entonces no hay elementos
    if(l == NULL){
        // hago que la lista apunte al nuevo nodo (el primero)
        l = nuevo;
    }
    // si la lista no está vacía
    // entonces hay 1 o más elementos
    else{
        // creo un puntero auxiliar, que me permite recorrer la lista original
        // sin generar cambios al recorrerla
        Nodo *aux = l;

        // itero mientras que:
        // 1. Los elementos que recorra no sean el último elemento (que no sea NULL)
        // *Recorda que el final de la lista apunta a NULL
        // *Recorrer sólo hasta el último, me permite luego enlazarlo con el nuevo,
        // quedando el último como anteúltimo, y el nuevo como último
        while(aux->sgte != NULL){
            // avanzo al siguiente
            aux = aux->sgte;
        }

        // al último elemento le asigno como siguiente el nuevo
        // quedando el que era último como anteúltimo, 
        // y el nuevo como último de la lista
        aux->sgte = nuevo;
    } // end if
}

//
// # Funciones básicas
//
void cargarDatos(Nodo *&l){
    insertarAlFinal(l, crearEstudiante(109, "pedro"));
    insertarAlFinal(l, crearEstudiante(105, "carlos"));
    insertarAlFinal(l, crearEstudiante(104, "meme"));
    insertarAlFinal(l, crearEstudiante(101, "julian"));
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