#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

//
// # Variables Globales
//
#define ARCHIVO_TXT "mafiosos.txt"

/******************************************************************************/


//
// # Structs
//
struct Mafioso{
    char nombre[30];
    int edad;
};

/******************************************************************************/

//
// # Prototipos
//
void mostrarMenu();
void mostrarMenuOpciones();

void agregarMafiosos();
void mostrarMafiosos();

/******************************************************************************/

//
// # Main
//
int main(){
    mostrarMenu();
    
    return 0;
}

/******************************************************************************/

//
// # Funciones
//
void mostrarMenuOpciones(){
    cout << "Opciones del menu:" << endl;
    cout << "1. Agregar mafiosos" << endl;
    cout << "2. Mostrar listado de mafiosos" << endl;
    cout << "3. Salir" << endl;
}

void mostrarMenu(){
    int opcion;
    
    mostrarMenuOpciones();

    cout << "Ingrese el numero de la opcion del menu: ";
    cin >> opcion;
    
    while(opcion != 3){
        system("clear");
        
        switch(opcion){
            case 1:
                agregarMafiosos();
            break;
            case 2:
                mostrarMafiosos();
            break;
        }
        
        cout << endl;
        
        mostrarMenuOpciones();
        cout << "Ingrese el numero de la opcion del menu: ";
        cin >> opcion;
    }
}

void mostrarMafiosos(){
    FILE *f;
    Mafioso m;

    // Imprimo la informacion y la formateo
    cout << "# Datos con formato:" << endl;
    f = fopen(ARCHIVO_TXT, "r");
    fscanf(f, "%s %d", m.nombre, &m.edad);
    while(!feof(f)){
        printf("\tNombre: %s, Edad: %d\n", m.nombre, m.edad);
        fscanf(f, "%s %d", m.nombre, &m.edad);
    }
    fclose(f);
    cout << endl;
    
    // Imprimo todo el archivo sin formatear la informacion
    cout << "# Datos sin formatear:" << endl;
    char datos[100]; // es donde guardo la informacion a leer (buffer)
    f = fopen(ARCHIVO_TXT, "r");
    fgets(datos, 100, f);
    while(!feof(f)){
        cout << "\t" << datos;
        fgets(datos, 100, f);
    }
    fclose(f);
    cout << endl;
    
    
}

void agregarMafiosos(){
    FILE *f;
    Mafioso m;
    char respuesta;

    f = fopen(ARCHIVO_TXT, "w");
    while(respuesta != 'n'){
        //fflush (stdin);
        
        cout << "Ingrese su nombre: ";
        cin >> m.nombre;
        //gets(nombre); // ocasiona problemas con el buffer

        cout << "Ingrese su edad: ";
        scanf("%d", &m.edad); // otra manera es con cin >> m.edad;

        fprintf(f, "%s %d\n", m.nombre, m.edad); // agrega la info con formato
        //fputs (p.nombre, f); // agrega la info sin formato
        
        cout << "Desea seguir ingresando datos? (s/n): ";
        cin >> respuesta;
    }    
    fclose(f);
}
