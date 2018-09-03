#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//
// # Structs
//
struct Empleado{
    char nombre[30];
};

/********************************************************************************/

//
// # Variables Globales
//
#define ARCHIVO_NOMBRE "empleados.dat"
#define EMPLEADOS_CANT_MAX 5

/********************************************************************************/

//
// # Prototipos
//
Empleado agregar_empleado(Empleado [], int &, const char []);
Empleado agregar_empleados(Empleado [], int);
Empleado listado_empleados(Empleado [], int);

/********************************************************************************/

//
// # Main
//
int main(){
    Empleado empleados[EMPLEADOS_CANT_MAX];

    int empleados_num = 0;
    agregar_empleado(empleados, empleados_num, "pedro");
    agregar_empleado(empleados, empleados_num, "roberto");
    
    agregar_empleados(empleados, empleados_num);

    listado_empleados(empleados, empleados_num);

    return 0;
}

/********************************************************************************/

//
// # Funciones
//
Empleado agregar_empleado(Empleado listado[], int &empleados_num, const char nombre[]){		
    strcpy(listado[empleados_num].nombre, nombre);
		
    empleados_num++;
}

Empleado agregar_empleados(Empleado listado[], int empleados_num){
    FILE *archivo;
    archivo = fopen(ARCHIVO_NOMBRE, "wb");
    fwrite(listado, sizeof(Empleado), 3, archivo);
    fclose(archivo);
}

Empleado listado_empleados(Empleado listado[], int empleados_num){
    FILE *archivo;
    archivo = fopen(ARCHIVO_NOMBRE, "rb");

    fread(listado, sizeof(Empleado), 1, archivo);
    int id=0;
    while(!feof(archivo)){
			printf("%i %s \n", id, listado[id].nombre);
				
        fread(listado, sizeof(Empleado), 1, archivo);
        id++;
    }

    fclose(archivo);
}
