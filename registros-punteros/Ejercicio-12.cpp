#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip>

using namespace std;

//
// # Structs
//
struct Persona{
    char nombre[30];
    char provincia[30];
    int edad;
    int dni;
};

//
// # Prototipos
//
Persona crearPersona(string, string, int, int);
void agregarPersonas(Persona []);

template <typename T> void mostrarListado(T [], int, T f(T));
Persona mostrarFila(Persona);

template <typename T> void modificarListado(T [], int, T f(T &));
Persona modificarCriterio01(Persona &);
Persona modificarCriterio02(Persona &);

//
// # Main
//
int main()
{
    Persona personas[5];
    int cantidadPersonas = 5;
    
    //
    // 1. Creo los registros y los agrego en el vector personas[?]
    // 
    agregarPersonas(personas);
    FILE *f;
    //
    // 2. Guardo todos los registros de vector en un archivo binario
    //
    f = fopen("prueba", "wb+");
    fwrite(personas, sizeof(personas), 1, f);
    fclose(f);
    
    //
    // 2. Leo el archivo que contiene los registro, lo recorro e imprimo con 'mostrarListado'
    //
    f = fopen("prueba", "rb");
    fread(personas, sizeof(personas), 1, f);
    mostrarListado<Persona>(personas, cantidadPersonas, mostrarFila);
    fclose(f);
    cout << endl;
    
    //
    // 3. Modifico el archivo segun ciertos criterios
    //
    f = fopen("prueba", "wb+");
    fread(personas, sizeof(personas), 1, f);
    modificarListado<Persona>(personas, cantidadPersonas, modificarCriterio01);
    modificarListado<Persona>(personas, cantidadPersonas, modificarCriterio02);
    fclose(f);

    //
    // 4. Leo el archivo que contiene los registro, lo recorro e imprimo con 'mostrarListado'
    //
    cout << "Listado modificado" << endl;
    f = fopen("prueba", "rb");
    fread(personas, sizeof(personas), 1, f);
    mostrarListado<Persona>(personas, cantidadPersonas, mostrarFila);
    fclose(f);
    
    return 0;
}

//
// # Funciones
//
Persona crearPersona(string nombre, string provincia, int edad, int dni){
    Persona p;
    strcpy(p.nombre, nombre.c_str());
    strcpy(p.provincia, provincia.c_str());
    p.edad = edad;
    p.dni = dni;
    
    return p;
}

void agregarPersonas(Persona personas[]){
    personas[0] = crearPersona("carlos", "argentina", 15, 35216110);
    personas[2] = crearPersona("fede", "peru", 13, 35216110);
    personas[1] = crearPersona("romero", "bolivia", 16, 35216110);
    personas[3] = crearPersona("mati", "argentina", 31, 35216110);
    personas[4] = crearPersona("mariano", "argentina", 51, 35216110);
}

template <typename T>
void mostrarListado(T arr[], int len, T mostrarFila(T)){
    for(int i=0; i < len; i ++){
        mostrarFila(arr[i]);
    }
}

Persona mostrarFila(Persona p){
    cout << p.nombre << setw(20) << p.provincia << setw(20) << setw(10) << p.edad << endl;
}

template <typename T>
void modificarListado(T arr[], int len, T modificarPorCriterio(T &)){
    for(int i=0; i < len; i ++){
        modificarPorCriterio(arr[i]);
    }
}

Persona modificarCriterio01(Persona &p){
    if(p.edad < 18){
        strcpy(p.nombre, "*");
    }
}

Persona modificarCriterio02(Persona &p){
    if(string(p.provincia) == "argentina"){
        p.edad = 0;
    }
}
