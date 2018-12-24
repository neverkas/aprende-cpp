/*
* 
* LISTA ARBOL
* 
* Agregar al programa anterior las funciones inOrden() y postOrden() probar con el conjunto de datos:
* 7,8,0,6,14,1,0,13,0,7
*
* Para obtener los siguientes resultados:
* inOrden: 0(3), 1, 6, 7(2), 8, 13, 14
* postOrden: 1, 6, 0(3), 13, 14, 8, 7(2)
* preOrden: 7(2), 0(3), 6, 1, 8, 14, 13
* 
*/
#include <iostream>
#include <stdio.h> // printf

using namespace std;

struct Nodo{
    Nodo *izq;
    Nodo *der;

    int contador;
    int dato;
};

void insertar(Nodo *&nodo, int v){
    if(nodo == NULL){
        nodo = new Nodo();
        //if(nodo!=NULL){
        nodo->izq = NULL;
        nodo->der = NULL;
        nodo->dato = v;
        nodo->contador = 1;
        //}
    }
    else{
        if(v < nodo->dato){
            insertar(nodo->izq, v);
        }
        else if(v > nodo->dato){
            insertar(nodo->der, v);
        }
        else{
            nodo->contador++;
        }
    }
}

void preOrden(Nodo *nodo){
    if(nodo != NULL){
        printf("%i (%i), ", nodo->dato, nodo->contador);
        preOrden(nodo->izq);
        preOrden(nodo->der);
    }
}

int main(){
    Nodo *raiz = NULL;

    int datos[] = {7,8,0,6,14,1,0,13,0,7};
    int len = sizeof(datos) / sizeof(datos[0]);

    for(int i=0; i < len; i++){
        insertar(raiz, datos[i]);
    }

    preOrden(raiz);
    cout << endl;

    return 0;
}