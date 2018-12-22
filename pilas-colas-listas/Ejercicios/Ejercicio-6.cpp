#include <iostream>
#include <stdio.h> // printf()

using namespace std;

void insertar(int *&p, int v){
    int *n = new int(v);
    p = n;
}

int main()
{
    // declaro puntero donde guardare multiples punteros
    int *p; 
    // reservo espacio en memoria para el numero entero 5
    int *n1 = new int(5);
    // guardo en el puntero el otro puntero 'n1' que tiene valor 5
    p = n1;
    // declaro puntero y guardo la direccion de memoria que apunta a n1
    // que luego borrarè
    int *n = p;
    // imprimo el valor de n1 que es 5
    cout << *p << endl;
    // borro la direccion en memoria de n1 que se guardó en 'n'
    delete n;
    // 
    cout << *p << endl;

    /**********************************************************************************/
    
    int n3;
    
    // le asigno al puntero 'p' la direccion de memoria de 'n1'
    p=&n3;
    // asigno el valor 3 a 'n1'
    // este cambio se hara en 'n1'
    *p=3;
    // imprime la direccion en memoria de n1
    cout << "direccion en memoria de n1: " << p << endl;
    // imprime el valor de n1 que es 3
    cout << "valor asignado a n1: " << *p << endl;


    return 0;
}
