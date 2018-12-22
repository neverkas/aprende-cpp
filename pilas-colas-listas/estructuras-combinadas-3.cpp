/*
* Array de Estructuras
*/

#include <iostream>

using namespace std;

struct Alumno{
    int legajo;
    string nombre;
    int nota;
};

Alumno crearAlumno(int legajo, string nombre, int nota){
    Alumno a;
    a.legajo = legajo;
    a.nombre = nombre;
    a.nota = nota;

    return a;
}

void mostrarAlumno(Alumno a){
    cout << a.nombre << endl;
}

int main(){
    Alumno alumnos[3];
    alumnos[0] = crearAlumno(01, "Carlos", 10);
    alumnos[1] = crearAlumno(02, "Fede", 3);
    alumnos[2] = crearAlumno(03, "Mariano", 1);

    for(int i=0; i < 3; i++){
        mostrarAlumno(alumnos[i]);
    }

    return 0;
}