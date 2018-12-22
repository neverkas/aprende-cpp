/*
* Array de Estructuras
*/

#include <iostream>

using namespace std;

//
// # Structs
//
struct Alumno{
    int legajo;
    string nombre;
    int nota;
};

//
// # Prototipos
//
Alumno crearAlumno(int legajo, string nombre, int nota);
void mostrarDatos(Alumno a);

//
// # Main
//
int main(){
    Alumno alumnos[3];
    alumnos[0] = crearAlumno(01, "Carlos", 10);
    alumnos[1] = crearAlumno(02, "Fede", 3);
    alumnos[2] = crearAlumno(03, "Mariano", 1);

    for(int i=0; i < 3; i++){
        mostrarDatos(alumnos[i]);
    }

    return 0;
}

//
// # Funciones
//
Alumno crearAlumno(int legajo, string nombre, int nota){
    Alumno a;
    a.legajo = legajo;
    a.nombre = nombre;
    a.nota = nota;

    return a;
}

void mostrarDatos(Alumno a){
    cout << a.nombre << endl;
}
