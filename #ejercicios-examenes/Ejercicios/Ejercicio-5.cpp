#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define ARCHIVO_NOMBRE "mensajes.dat"

struct Mensaje{
    //string texto;
    int id_mensaje;
};

void crearMensajes(){
    FILE *f = fopen(ARCHIVO_NOMBRE, "wb+"); // abro
    Mensaje m;

    m.id_mensaje = 2;
    fwrite(&m, sizeof(Mensaje), 1, f); // grabo

    m.id_mensaje = 3;
    fwrite(&m, sizeof(Mensaje), 1, f); // grabo

    m.id_mensaje = 1;
    fwrite(&m, sizeof(Mensaje), 1, f); // grabo

    m.id_mensaje = 5;
    fwrite(&m, sizeof(Mensaje), 1, f); // grabo

    fclose(f); // cierro
}

void leerMensajes(){
    FILE *f = fopen(ARCHIVO_NOMBRE, "rb"); // abro
    Mensaje m;

    fread(&m, sizeof(Mensaje), 1, f);
    while(!feof(f)){
        cout << m.id_mensaje << " ";
        fread(&m, sizeof(Mensaje), 1, f);
    }
    cout << endl;

    fclose(f); // cierro
}

int cantidadRegistrosArchivo(){
    FILE *f = fopen(ARCHIVO_NOMBRE, "rb"); // abro
    fseek(f, 0, SEEK_END);
    return ftell(f) / sizeof(Mensaje);
}

void cargarBinarioAVector(Mensaje arr[], int len){
    FILE *f = fopen(ARCHIVO_NOMBRE, "rb"); // abro
    Mensaje m;

    fread(&m, sizeof(Mensaje), 1, f);
    int i = 0;
    while(!feof(f)){
        arr[i] = m; 

        fread(&m, sizeof(Mensaje), 1, f);

        i++;
    }

    fclose(f); // cierro    
}
void leerVector(Mensaje arr[], int len){
    for(int i=0; i < len; i++){
        cout << arr[i].id_mensaje << " ";
    }
    cout << endl;
}

int main(){
    //crearMensajes();
    leerMensajes();
    int len = cantidadRegistrosArchivo();
    Mensaje mensajes[len];
    cargarBinarioAVector(mensajes, len);
    leerVector(mensajes, len);

    return 0;
}