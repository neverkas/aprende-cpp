#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define ARCHIVO "cargos.dat"

struct Cargo{
    int id;
    char titulo[20];
};

struct Nodo{
    Cargo info;
    Nodo *sgte;
};

void cargarDatos(char nombreArchivo[]);
void mostrar(char nombreArchivo[]);
void mostrarCargo(Cargo c);
int binarioCantRegistros(char nombreArchivo[]);
void binarioAVector(char nombreArchivo[], Cargo v[], int len);
void vectorALista(Cargo [], int len, Nodo *&l);
void imprimirVector(Cargo v[], int len);
void imprimirLista(Nodo *l);
void insertarOrdenado(Nodo *&l, Cargo);
int criterioId(Cargo c1, Cargo c2){
    return c1.id - c2.id;
}
int criterioTitulo(Cargo c1, Cargo c2){
    return (c1.titulo < c2.titulo) ? -1 : (c1.titulo > c2.titulo) ? 1 : 0;
}
int criterioIdTitulo(Cargo c1, Cargo c2){
    if(c1.titulo == c2.titulo)
        return c1.id - c2.id;
    else 
        return (c1.titulo < c2.titulo) ? -1 : (c1.titulo > c2.titulo) ? 1 : 0;
}

int main(){
    /************************************************/
    // probando cargar datos a archivo binario e imprimir
    cargarDatos(ARCHIVO);
    mostrar(ARCHIVO);

    cout << endl;

    /************************************************/
    // probando pasar datos de archivo binario a vector e imprimir
    int len = binarioCantRegistros(ARCHIVO);
    Cargo v[len];
    binarioAVector(ARCHIVO, v, len);
    imprimirVector(v, len);

    cout << endl;
    
    /**************************************************/
    // probando pasar vector a lista e imprimir
    Nodo *lista = NULL;
    vectorALista(v, len, lista);
    
    imprimirLista(lista);

    return 0;
}

void imprimirLista(Nodo *l){
    while(l != NULL){
        mostrarCargo(l->info);

        l = l->sgte;
    }
}

void vectorALista(Cargo v[], int len, Nodo *&l){
    for(int i=0; i < len; i++){
        insertarOrdenado(l, v[i]);
    }
}

void insertarOrdenado(Nodo *&l, Cargo c){
    Nodo *n = new Nodo;
    n->info = c;
    n->sgte = NULL;

    Nodo *aux = l, *ant = NULL;

    // mientras los elementos sean menor recorre,
    // cuando un elemento sea mayor al que agrego detengo,

    while(aux != NULL && aux->info.id <= c.id){
    //while(aux != NULL && criterioId(aux->info, c) <= 0){
    //while(aux != NULL && criterioTitulo(aux->info, c) <= 0){
    //while(aux != NULL && criterioIdTitulo(aux->info, c) <= 0){
        // guardo el elemento anterior (menor al q agregare) y el siguiente a ese (mayor al q agrego)
        ant = aux;
        aux = aux->sgte;

        printf("ant:%i, aux:%i \n", ant->info.id, aux->info.id);
    }

    // si tiene un elemento anterior
    if(ant){
        // lo enlazo al nuevo
        ant->sgte = n;
    }
    // sino tiene anterior, es el elemento de menor tamaño
    else{
        // n=1
        // 2,3,4,5
        l = n;
    }

    // al ser el elemento de menor tamaño, 
    // enlazo al siguiente con el 
    n->sgte = aux;
}

void imprimirVector(Cargo v[], int len){
    for(int i=0; i < len; i++){
        mostrarCargo(v[i]);
    }
}

void binarioAVector(char nombreArchivo[], Cargo v[], int len){
    FILE *f = fopen(nombreArchivo, "rb");
    Cargo c;

    int i = 0;
    fread(&c, sizeof(Cargo), 1, f);
    while(!feof(f)){
        v[i] = c;

        i++;
        fread(&c, sizeof(Cargo), 1, f);
    }
}

int binarioCantRegistros(char nombreArchivo[]){
    FILE *f = fopen(nombreArchivo, "rb");
    fseek(f, 0, SEEK_END);
    int ultimo = ftell(f);

    return ultimo / sizeof(Cargo);
    /*
    // otra manera, no tan correcta pero funciona también
    Cargo c;
    int i = 0;
    fread(&c, sizeof(Cargo), 1, f);
    while(!feof(f)){
        i ++;
        fread(&c, sizeof(Cargo), 1, f);
    }

    return i;
    */
}

void mostrarCargo(Cargo c){
    printf("%i - %s\n", c.id, c.titulo);
}

void mostrar(char nombreArchivo[]){
    FILE *f = fopen(nombreArchivo, "rb");

    Cargo c;
    fread(&c, sizeof(Cargo), 1, f);
    while(!feof(f)){
        mostrarCargo(c);
        fread(&c, sizeof(Cargo), 1, f);
    }
}

void cargarDatos(char nombreArchivo[]){
    FILE *f = fopen(nombreArchivo, "wb");
    Cargo c;

    c.id = 3;
    strcpy(c.titulo, "profesor");
    fwrite(&c, sizeof(Cargo), 1, f);

    c.id = 2;
    strcpy(c.titulo, "estudiante");
    fwrite(&c, sizeof(Cargo), 1, f);

    c.id = 1;
    strcpy(c.titulo, "decano");
    fwrite(&c, sizeof(Cargo), 1, f);

    fclose(f);
}
