#include <iostream>

using namespace std;

//
// # Structs
//

// Sublista
struct Estudiante{
    int dni;
    string nombre;    
    char sexo; // m/f
};

struct nodoEstudiante{
    Estudiante info;
    nodoEstudiante *sgte;
};

// Lista
struct Escuela{
    int numero;
};

struct nodoEscuela{
    Escuela info;
    nodoEstudiante *estudiantes; // sublista
    nodoEscuela *sgte;
};


// Agrupo listas por un campo
struct estudiantesPorNombre{
    string nombre;
    
    nodoEstudiante *estudiantes;
    estudiantesPorNombre *sgte;
};

struct estudiantesPorSexo{
    char sexo;

    nodoEstudiante *estudiantes;
    estudiantesPorSexo *sgte;
};

//
// # Prototipos
//
// prototipos para listas-sublistas
void insertarEscuela(nodoEscuela *&l, Escuela e);
void insertarEstudiante(nodoEstudiante *&l, Estudiante e);
void crearEstudiantesPorNombre(estudiantesPorNombre *&l, Estudiante e);

void agruparEstudiantesPorNombre(nodoEscuela *l1, estudiantesPorNombre *&l2);

estudiantesPorNombre *buscarEstudiantePorNombre(estudiantesPorNombre *&l, string nombre);
estudiantesPorNombre *buscaEinserta(estudiantesPorNombre *&l, Estudiante e);
nodoEscuela *buscarEscuelaPorNumero(nodoEscuela *&l, int numero);

void listarEscuelas(nodoEscuela *l);
void listarEstudiantes(nodoEstudiante *l);
void listarEstudiantesPorNombre(estudiantesPorNombre *l);

// prototipos básicos
Estudiante crearEstudiante(int dni, string nombre);
Escuela crearEscuela(int numero);
void mostrarDatos(Escuela v);
void mostrarDatos(Estudiante v);

void cargarEscuelas(nodoEscuela *&l);
void cargarEstudiantes(nodoEscuela *&n);

//
// # Variables Globales
//
nodoEscuela *LISTA = NULL; // (opcional, puede usarse como variable local)

//
// # Main
//
int main(){
    cargarEscuelas(LISTA);

    cout << "ESCUELAS:" << endl;
    listarEscuelas(LISTA);

    // suponiendo que existe la escuela con id=3
    nodoEscuela *escuela = buscarEscuelaPorNumero(LISTA, 3);
    // le cargo estudiantes
    cargarEstudiantes(escuela);

    cout << "Estudiantes de la ESCUELA (ID=3): " << endl;
    // listo los estudiantes de una escuela especifica
    listarEstudiantes(escuela->estudiantes);
    cout << endl;

    // creo un puntero donde voy a agrupar los nodos de una lista
    estudiantesPorNombre *estudiantesPorNombre = NULL;
    // los agrupo
    agruparEstudiantesPorNombre(escuela, estudiantesPorNombre);
    // listo los nodos agrupados
    cout << "Estudiantes Agrupados por nombre:" << endl;
    listarEstudiantesPorNombre(estudiantesPorNombre);

    return 0;
}

//
// # Funciones
//
// funciones para listas-sublistas
void listarEstudiantesPorNombre(estudiantesPorNombre *l){
    // itero mientras no haya llegado al final de la lista
    while(l != NULL){        
        // muestro info adicional
        cout << "#estudiantes con nombre: " << l->nombre << endl;
        // listo la sublista
        listarEstudiantes(l->estudiantes);
        // avanzo al siguiente nodo
        l = l->sgte;
    }
}

// esta función reduce el llamado a funciones
estudiantesPorNombre *buscaEinserta(estudiantesPorNombre *&l, Estudiante e){
    // busco en la lista si existe un elemento con el dato que paso por parametro    
    // si existe un elemento el puntero apunta al nodo, sino apunta a NULL
    estudiantesPorNombre *nodo = buscarEstudiantePorNombre(l, e.nombre);
    // guardo un indicador de estado de (true/false) si se cumple o no la condición
    bool enc = (nodo != NULL);

    // si el nodo no fue encontrado, lo crearé
    // (sino lo encontró no es necesario crearlo, solo se iran agrupando los nodos en la sublista)
    if(!enc){
        // creo un nodo que utilizaré como lista, donde agruparé nodos por un campo
        crearEstudiantesPorNombre(l, e);
        // busco el nodo que agregué en la linea anterior
        // para poder insertar los nodos que iré agrupando
        nodo = buscarEstudiantePorNombre(l, e.nombre);
    }
    
    // inserto el nuevo nodo en la sublista donde estoy agrupando
    insertarEstudiante(nodo->estudiantes, e);

    // retorno el nodo por si lo necesito reutilizar a posterior
    return nodo;
}

estudiantesPorNombre *buscarEstudiantePorNombre(estudiantesPorNombre *&l, string nombre){
    // creo un puntero auxiliar para poder recorrer la lista original sin generar cambio alguno
    estudiantesPorNombre *aux = l;

    // itero mientras que:
    // 1. no haya llegado al final de la lista
    // 2. los nodos recorridos no tengan el mismo dato que paso por parametro a la función
    // *La primer condición permite delimitar que el bucle itere solo tantas veces como elementos 
    // haya en la lista
    // *La segunda condición permite recorrer la lista hasta que alguno de los elementos 
    // coincida con la información que paso por parametro a la función
    // *Si alguna de las condiciones no se cumple, se detiene la ejecución del while
    while(aux != NULL && aux->nombre != nombre){
        // avanzo al siguiente nodo mientras se cumplan las condiciones
        aux = aux->sgte;    
    }

    // si el nodo fue encontrado, lo retorno
    // si no fue encontrado retorna NULL
    return aux;
}

void agruparEstudiantesPorNombre(nodoEscuela *l, estudiantesPorNombre *&l2){    
    // creo un puntero del mismo tipo de la sublista
    // que recorrere para agrupar los datos en la segunda lista
    nodoEstudiante *estudiantes = l->estudiantes;

    // itero mientras no haya llegado al final de la sublista
    while(estudiantes != NULL){    
        // guardo el contenido del nodo que voy a agrupar
        Estudiante e = estudiantes->info;
        // busco e inserto en la nueva lista, donde agrupo los datos
        buscaEinserta(l2, e);
        // avanzo al siguiente nodo de la sublista
        estudiantes = estudiantes->sgte;
    }
}

// esta función actua como un insertar() pero personalizado
// *se puede evitar utilizando templates
void crearEstudiantesPorNombre(estudiantesPorNombre *&l, Estudiante e){
    estudiantesPorNombre *nuevo = new estudiantesPorNombre;
    nuevo->nombre = e.nombre;
    nuevo->sgte = NULL;

    if(l == NULL){
        l = nuevo;
    }
    else{
        estudiantesPorNombre *aux = l;

        while(aux->sgte != NULL){
            aux = aux->sgte;
        }

        aux->sgte = nuevo;
    }
}

// al ser una lista simplemente enlazada, no necesito pasar por referencia el puntero de la lista
void listarEstudiantes(nodoEstudiante *l){    
    // itero mientras que no haya llegado al final de la lista
    while(l != NULL){
        // guardo el contenido del nodo que recorro
        Estudiante e = l->info;
        // lo paso por parametro a una función que imprimirá por pantalla los datos
        mostrarDatos(e);
        // avanzo al siguiente nodo de la lista
        l = l->sgte;
    }
}

// este funciona como un insertar() pero personalizado
// *se puede evitar utilizando templates
void insertarEstudiante(nodoEstudiante *&l, Estudiante e){
    nodoEstudiante *nuevo = new nodoEstudiante;
    nuevo->info = e;
    nuevo->sgte = NULL;

    if(l == NULL){
        l = nuevo;
    }
    else{
        nodoEstudiante *aux = l;

        while(aux->sgte != NULL){
            aux = aux->sgte;
        }

        aux->sgte = nuevo;
    }
}

nodoEscuela *buscarEscuelaPorNumero(nodoEscuela *&l, int numero){
    // creo un puntero auxiliar para recorrer los elementos sin generar cambios
    nodoEscuela *aux = l;

    // itero mientras que:
    // 1. la lista no esté vacía
    // 2. los elementos recorridos no coincidan con el dato que paso por parametro a la función
    // *La primera condición sirve para delimitar no ejecutar el while más veces de las necesarias
    // *La segunda condición me permite detener la iteración en caso que encuentre el dato a buscar
    while(aux != NULL && aux->info.numero != numero){
        // avanzo al siguiente nodo
        aux = aux->sgte;
    }

    // si el nodo fue encontrado, lo retorna
    // caso contrario retorna solo "null"
    return aux;
}

// al ser una lista simplemente enlazada, no necesito pasar por referencia el puntero a la lista
void listarEscuelas(nodoEscuela *l){
    // itero mientras no haya llegado al final de la lista
    while(l != NULL){
        // guardo la informacion del nodo en una variable del mismo tipo
        Escuela e = l->info;
        // lo paso como parametro a una función que imprimirá los datos por pantalla
        mostrarDatos(e);
        // avanzo al siguiente nodo
        l = l->sgte;
    }
}

// funciona como el insertar() pero personalizado
// *se puede evitar utilizando templates
void insertarEscuela(nodoEscuela *&l, Escuela e){
    nodoEscuela *nuevo = new nodoEscuela;
    nuevo->info = e;
    nuevo->sgte = NULL;

    if(l == NULL){
        l = nuevo;
    }
    else{
        nodoEscuela *aux = l;

        while(aux->sgte != NULL){
            aux = aux->sgte;
        }

        aux->sgte = nuevo;
    }
}


// funciones basicas
void cargarEstudiantes(nodoEscuela *&n){
    insertarEstudiante(n->estudiantes, crearEstudiante(100, "pedrito"));
    insertarEstudiante(n->estudiantes, crearEstudiante(101, "marito"));
    insertarEstudiante(n->estudiantes, crearEstudiante(104, "marito"));
    insertarEstudiante(n->estudiantes, crearEstudiante(102, "robertito"));
    insertarEstudiante(n->estudiantes, crearEstudiante(107, "robertito"));
}

void cargarEscuelas(nodoEscuela *&l){
    insertarEscuela(l, crearEscuela(1));
    insertarEscuela(l, crearEscuela(2));
    insertarEscuela(l, crearEscuela(3));
}

void mostrarDatos(Estudiante v){
    cout << v.dni << ", " << v.nombre << endl;
}

void mostrarDatos(Escuela v){
    cout << v.numero << endl;
}

Estudiante crearEstudiante(int dni, string nombre){
    Estudiante e;
    e.dni = dni;
    e.nombre = nombre;

    return e;
}

Escuela crearEscuela(int numero){
    Escuela e;
    e.numero = numero;

    return e;
}