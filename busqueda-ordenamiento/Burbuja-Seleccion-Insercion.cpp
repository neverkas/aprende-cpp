#include <iostream>
#include <stdio.h>

using namespace std;

void ordenamientoBurbuja(int v[], int len);
void ordenamientoPorSeleccion(int v[], int len);
void ordenamientoPorInsercion(int v[], int len);
void listarVector(int v[], int len);


int main(){
    //for(int i=0,j=0; i < 5; i++,j++) printf("i:%i, j:%i \n", i, j);

   int v[5] = {2,3,4,5,1};

   ordenamientoBurbuja(v, 5);
   listarVector(v, 5);

   ordenamientoPorSeleccion(v, 5);
   listarVector(v, 5);

   ordenamientoPorInsercion(v, 5);
   listarVector(v, 5);

    return 0;
}

void ordenamientoBurbuja(int v[], int len){
    int tmp;

    // itero tantas veces elementos exista
    // analizará cada elemento tantas veces como elementos hayan
    for(int iterar=0; iterar < len; iterar++){
        // recorro el vector
        for(int indice=0; indice < len; indice++){
            // si el elemento es mayor al elemento que le sigue            
            // Ej. si (x > y) entonces intercambio lugares {x,y} por {y,x}, quedando el mayor a la derecha
            if(v[indice] > v[indice+1]){
                // intercambio los elementos, el mayor a la der, y el menor a la izq
                // utilizo una variable temporal para guardar el valor que se va a perder al
                // asignarle otro
                tmp = v[indice];
                v[indice] = v[indice+1];
                v[indice+1] = tmp;
            }
        }
    }
}

void ordenamientoPorSeleccion(int v[], int len){
    int min, tmp;

    // no lo utilizo para recorrer, sino para saber el indice ó posición de cada elemento
    for(int indice=0; indice < len-1; indice++){
        // hago suponer que el elemento de menor valor es el primero
        // lo compararé con sus siguientes, y cambiará si hay otro menor a él
        min = indice;

        // recorro el vector, y acorto la cantidad de elementos a comparar a medida que avanzo
        for(int iteracion=indice+1; iteracion < len; iteracion++){
            // si el elemento siguiente es mayor al actual
            if(v[iteracion] < v[min]){
                // entonces guardo la posicion del elemento
                min = iteracion;
            }
        }
        
        // si son diferentes, entonces encontré otro elemento menor a este
        if(indice != min){
            // guardo en una variable temporal el valor del elemento a reemplazar
            tmp = v[indice];
            // intercambio los valores, el de menor valor lo ubico antes, y el de mayor donde estaba el de menor
            v[indice] = v[min];
            v[min] = tmp;
        }
    }
}

void ordenamientoPorInsercion(int v[], int len){
    // tmp, guardará el elemento a mover
    // indice, tendrá la posición donde mover el elemento
    int indice, tmp;

    // itero tantas veces como elementos existan
    for(int iteracion=0; iteracion < len; iteracion++){
        // guardo la posicion de donde comienzo
        indice = iteracion;
        // guardo el dato del elemento a insertar
        tmp = v[iteracion];

        // itero mientras:
        // 1. no haya llegado al principio del vector (limito el decremental que no llegue a negativo)
        // 2. los elementos anteriores al actual sean mayores
        // condiciono q indice sea mayor a cero, porque no hay otro elemento antes del primero
        while(indice > 0 && v[indice-1] > tmp){
            // desplazo los anteriores hacia delante (de izq a der)
            // al elemento actual le agrego el anterior, y asi tantas veces se cumpla la condición del while
            v[indice] = v[indice-1];
            // decremento (voy al elemento anterior)
            indice--;
        } // end-while

        // como ya desplazé de lugar los elementos mayores
        // ahora inserto el elemento de menor valor en la posicion correspondiente
        v[indice] = tmp;

    } // end-for    
}

void listarVector(int v[], int len){
    for(int i=0; i < len; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}