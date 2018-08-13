#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

// STRUCTS
struct Empleado{
    char nombre[30];
};

// VARIABLES GLOBALES
char ARCHIVO_NOMBRE[30] = "empleados.dat";
const int EMPLEADOS_CANT_MAX = 5;

// PROTOTIPOS
Empleado agregar_empleado(FILE *, const char []);
Empleado actualizar_empleado_nombre(int, const char []);
Empleado listado_empleados();
int buscar_empleado_nombre(const char []);

// MAIN
int main(){
    FILE *archivo;
    int posicion;
    
    // escritura
    archivo = fopen(ARCHIVO_NOMBRE, "wb");
    agregar_empleado(archivo, "carlos");
    agregar_empleado(archivo, "roberto");
    agregar_empleado(archivo, "federico");
    fclose(archivo);

    listado_empleados();
    posicion = buscar_empleado_nombre("roberto");
    actualizar_empleado_nombre(posicion, "samuel");
    listado_empleados();
    
    return 0;
}

// FUNCIONES
Empleado agregar_empleado(FILE *archivo, const char nombre[]){
    Empleado empleado;
    strcpy(empleado.nombre, nombre);
    fwrite(&empleado, sizeof(Empleado), 1, archivo);
}

Empleado actualizar_empleado_nombre(int posicion, const char texto[]){
    FILE *archivo = fopen(ARCHIVO_NOMBRE, "r+b");
    Empleado empleado;
    fseek(archivo, posicion, SEEK_SET); //me posiciono en el registro encontrado
    strcpy(empleado.nombre, texto);
    fwrite(&empleado, sizeof(Empleado), 1, archivo);
    fclose(archivo);
}
int buscar_empleado_nombre(const char texto[]){
    FILE *archivo = fopen(ARCHIVO_NOMBRE, "rb");
    Empleado empleado;
    long posicion;
    
    fread(&empleado, sizeof(Empleado), 1, archivo);
    while(!feof(archivo)){
        //printf("%s %i \n", empleado.nombre, ftell(archivo));
        if(string(empleado.nombre) == texto){
            posicion = ftell(archivo);
        }
        
        fread(&empleado, sizeof(Empleado), 1, archivo);
    }
    
    fclose(archivo);
    return posicion - sizeof(Empleado);    
    //return posicion / sizeof(Empleado);    
}

Empleado listado_empleados(){
    FILE *archivo = fopen(ARCHIVO_NOMBRE, "rb");
    
    Empleado empleado;
    fread(&empleado, sizeof(Empleado), 1, archivo);
    while(!feof(archivo)){
        printf("%s (%lo),", empleado.nombre, ftell(archivo));
        fread(&empleado, sizeof(Empleado), 1, archivo);
    }
    cout<<endl;
    
    fclose(archivo);
}
