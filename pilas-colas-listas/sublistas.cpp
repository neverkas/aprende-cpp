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
// prototipos básicos
Estudiante crearEstudiante(int dni, string nombre);
Escuela crearEscuela(int numero);
void mostrarDatos(Escuela v);
void mostrarDatos(Estudiante v);
// prototipos para listas-sublistas
void insertarEscuela(nodoEscuela *&l, Escuela e);
void insertarEstudiante(nodoEstudiante *&l, Estudiante e);
void crearEstudiantesPorNombre(estudiantesPorNombre *&l, Estudiante e);

void agruparEstudiantesPorNombre(nodoEstudiante *l1, estudiantesPorNombre *&l2);

estudiantesPorNombre *buscarEstudiantePorNombre(estudiantesPorNombre *&l, string nombre);
estudiantesPorNombre *buscaEinserta(estudiantesPorNombre *&l, Estudiante e);
nodoEscuela *buscarEscuela(nodoEscuela *&l, int numero);

void listarEscuelas(nodoEscuela *l);
void listarEstudiantes(nodoEstudiante *l);
void listarEstudiantesPorNombre(estudiantesPorNombre *l);

//
// # Variables Globales
//
nodoEscuela *LISTA = NULL;

//
// # Main
//
int main(){
    insertarEscuela(LISTA, crearEscuela(1));
    insertarEscuela(LISTA, crearEscuela(2));
    insertarEscuela(LISTA, crearEscuela(3));

    listarEscuelas(LISTA);
    nodoEscuela *escuela = buscarEscuela(LISTA, 3);
    insertarEstudiante(escuela->estudiantes, crearEstudiante(100, "pedrito"));
    insertarEstudiante(escuela->estudiantes, crearEstudiante(101, "marito"));
    insertarEstudiante(escuela->estudiantes, crearEstudiante(104, "marito"));
    insertarEstudiante(escuela->estudiantes, crearEstudiante(102, "robertito"));
    insertarEstudiante(escuela->estudiantes, crearEstudiante(107, "robertito"));

    listarEstudiantes(escuela->estudiantes);

    cout << endl;

    estudiantesPorNombre *estudiantesPorNombre = NULL;
    agruparEstudiantesPorNombre(escuela->estudiantes, estudiantesPorNombre);
    listarEstudiantesPorNombre(estudiantesPorNombre);

    return 0;
}

//
// # Funciones
//
// funciones para listas-sublistas
void listarEstudiantesPorNombre(estudiantesPorNombre *l){
    while(l != NULL){        
        cout << "#estudiantes con nombre: " << l->nombre << endl;

        listarEstudiantes(l->estudiantes);
        
        l = l->sgte;
    }
}

estudiantesPorNombre *buscaEinserta(estudiantesPorNombre *&l, Estudiante e){
    estudiantesPorNombre *nodo = buscarEstudiantePorNombre(l, e.nombre);

    if(nodo == NULL){
        crearEstudiantesPorNombre(l, e);
        nodo = buscarEstudiantePorNombre(l, e.nombre);
    }
    
    insertarEstudiante(nodo->estudiantes, e);

    return nodo;
}

estudiantesPorNombre *buscarEstudiantePorNombre(estudiantesPorNombre *&l, string nombre){
    estudiantesPorNombre *aux = l;

    while(aux != NULL && aux->nombre != nombre){
        aux = aux->sgte;    
    }

    return aux;
}

void agruparEstudiantesPorNombre(nodoEstudiante *estudiantes, estudiantesPorNombre *&l){    
    while(estudiantes != NULL){    
        /*
        // esta seria otra manera, pero buscaEinserta() lo reduce a una linea
        estudiantesPorNombre *nodo = buscarEstudiantePorNombre(l, estudiantes->info.nombre);

        if(nodo == NULL){
            crearEstudiantesPorNombre(l, estudiantes->info);
            nodo = buscarEstudiantePorNombre(l, estudiantes->info.nombre);
            insertarEstudiante(nodo->estudiantes, estudiantes->info);
        }
        */
        buscaEinserta(l, estudiantes->info);
        estudiantes = estudiantes->sgte;
    }
}

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

void listarEstudiantes(nodoEstudiante *l){
    while(l != NULL){
        mostrarDatos(l->info);
        l = l->sgte;
    }
}

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

nodoEscuela *buscarEscuela(nodoEscuela *&l, int numero){
    nodoEscuela *aux = l;

    while(aux != NULL && aux->info.numero != numero){
        aux = aux->sgte;
    }

    return aux;
}

void listarEscuelas(nodoEscuela *l){
    while(l != NULL){
        mostrarDatos(l->info);

        l = l->sgte;
    }
}

void insertarEscuela(nodoEscuela *&l, Escuela e){
    nodoEscuela *nuevo = new nodoEscuela();
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