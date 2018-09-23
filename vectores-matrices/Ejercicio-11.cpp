#include <iostream>
#include <stdio.h> // printf, NULL
#include <stdlib.h> // srand
#include <time.h> // time

using namespace std;

//
// # Prototipos
//
void rellenarConjunto(int [], int);
void imprimirConjunto(int [], int);
void crearProductoCartesiano(int [][2], int, int [], int, int [], int);
void imprimirProductoCartesiano(int [][2], int);

bool criterio_Relacion_A(int, int);
template<typename T> void crearRelacionBinaria(int [][2], int, int **&, int &, bool (*)(int, int));
void borrarRelacion(int **, int);
void imprimirRelacion(int **, int);

//
// # Main
//
int main()
{
    /* initialize random seed: */
    srand (time(NULL));
      // 
    // # Entrada de datos
    //
    
    // Conjuntos A, B, C
    // asigno a cada conjunto la cantidad de elementos que tendran
    int A_cardinal = 3, A[A_cardinal] = {0};    
    int B_cardinal = 2, B[B_cardinal] = {0};    
    int C_cardinal = 3, C[C_cardinal] = {0};    
    
    // cantidad de combinaciones entre los elementos de los conjuntos A y b
    int AxB_cardinal = (A_cardinal * B_cardinal);
    int BxC_cardinal = (B_cardinal * C_cardinal);

    // relaciones
    int **relacion_A, relacion_A_cardinal;

    // cada fila representa un par ordenado, y cada columna si es la 1ra o 2da componente
    int AxB[AxB_cardinal][2] = {0};
    int BxC[BxC_cardinal][2] = {0};

    /************************************************************************************/    

    //
    // # Proceso la informacion
    // 
    rellenarConjunto(A, A_cardinal);
    rellenarConjunto(B, B_cardinal);
    rellenarConjunto(C, C_cardinal);
    // int AxB_orden // tururu... pendiente (?)
    
    crearProductoCartesiano(AxB, AxB_cardinal, A, A_cardinal, B, B_cardinal);
    crearProductoCartesiano(BxC, BxC_cardinal, B, B_cardinal, C, C_cardinal);

    // RELACION (a+b es par)
    crearRelacionBinaria<int>(AxB, AxB_cardinal, relacion_A, relacion_A_cardinal, criterio_Relacion_A);
    
    int matriz_relacion_A[A_cardinal][B_cardinal];
    for(int i=0; i < A_cardinal; i++){
        for(int j=0; j < B_cardinal; j++){            
            matriz_relacion_A[i][j] = ((A[i]+B[j]) % 2 == 0);
        }
    }

    /************************************************************************************/    
    
    //
    // # Salida de datos
    //
    cout << "Conjunto A: " << endl;
    imprimirConjunto(A, A_cardinal);
    cout << endl;

    cout << "Conjunto B: " << endl;
    imprimirConjunto(B, B_cardinal);
    cout << endl;

    cout << "Producto cartesiano AxB: " << endl;
    imprimirProductoCartesiano(AxB, AxB_cardinal);
    cout << endl;

    cout << "Producto cartesiano BxC: " << endl;
    imprimirProductoCartesiano(BxC, BxC_cardinal);
    cout << endl;

    cout << "Relacion A (a+b es par): " << endl;
    imprimirRelacion(relacion_A, relacion_A_cardinal);
    borrarRelacion(relacion_A, relacion_A_cardinal);
    cout << endl;
   
    cout << "Matriz de Relacion (a+b es par):" << endl;
    for(int i=0; i < A_cardinal; i++){
        for(int j=0; j < B_cardinal; j++){
            cout << matriz_relacion_A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    

    return 0;
}

//
// # Funciones
//
void rellenarConjunto(int arr[], int len){
    int numeroAleatorio;

    for(int i=0; i < len; i++){
        // rand() devuelve numeros aleatorios
        // rand() % 9, retorna numeros del 0 al 9
        // rand() % 9 +1, retorna del 1 al 9
        
        numeroAleatorio = rand() % 9 + 1;
        arr[i] = numeroAleatorio;
        //arr[i] = i;        
    }
}

void imprimirConjunto(int arr[], int len){
    cout << "{";
    for(int i=0; i < len; i++){
        cout << arr[i];
        
        if(i < len-1)
            cout << ", ";
    }
    cout << "}";
    
    cout << endl;
}

void crearProductoCartesiano(int AxB[][2], int AxB_cardinal, int A[], int A_cardinal, int B[], int B_cardinal){
    int x = 0; // reutilizo para 1ra componente del par ordenado
    int z = 0; // reutilizo para 2da componente del par ordenado
    
    // cantidad de pares ordenados ó cantidad combinaciones posibles entre elementos de A y B
    for(int i=0; i < AxB_cardinal; i++){
        // columnas (componentes de los pares ordenados)
        for(int j=0; j < 2; j++){
            // si 'i' supera el numero de elementos de A o B 
            // vuelvo a contar desde el principio utilizando el operador % (módulo)
            x = (i < A_cardinal) ? i : (i % A_cardinal);
            z = (i < B_cardinal) ? i : (i % B_cardinal);
            
            // determino los valores de la primera y segunda componente del par ordenado
            // si j==0, es la primera columna, entonces retorno elementos de A (1ra componente)
            // si j==1, es la segunda columna, entonces retorno elementos de B (2da componente)
            AxB[i][j] = (j == 0) ? A[x] : B[z];
        }
    }
}

void imprimirRelacion(int **relacion, int relacion_cardinal){
    // filas
    cout << "{";
    for(int i=0; i < relacion_cardinal; i++){
        cout << "(";
        // columnas
        for(int j=0; j < 2; j++){
            // imprimo cada elemento

            cout << relacion[i][j];
            // agrego un separador de cada componente
            if(j == 0) cout << ";";
        }
        
        cout << ")";
        // agrego un separador para cada par ordenado        
        if(i < relacion_cardinal-1) cout << ",";
    }

    cout << "}";
    cout << endl;
}

void imprimirProductoCartesiano(int AxB[][2], int AxB_cardinal){
    // filas
    cout << "{";
    for(int i=0; i < AxB_cardinal; i++){
        cout << "(";
        // columnas
        for(int j=0; j < 2; j++){
            // imprimo cada elemento

            cout << AxB[i][j];
            // agrego un separador de cada componente
            if(j == 0) cout << ";";
        }
        
        cout << ")";
        // agrego un separador para cada par ordenado        
        if(i < AxB_cardinal-1) cout << ",";
    }

    cout << "}";
    cout << endl;
}

void borrarRelacion(int **relacion, int relacionCardinal){
    if(relacionCardinal > 0){
        // 2 columnas porque son pares ordenados (x;y) con 2 componentes
        int columnas = 2;
    
        for(int i=0; i < columnas; i++){
            delete [] relacion[i];
        }
    
        delete [] relacion;
    }
}

bool criterio_Relacion_A(int a, int b){
    // determino si "a+b es par"
    return ( ( (a + b) % 2) == 0);
}

template<typename T> void crearRelacionBinaria(int AxB[][2], int AxB_cardinal, int **&relacion, int &relacionCardinal, bool (*criterio)(int a, int b)){
    bool existeRelacion;
    relacionCardinal = 0;

    // determino la cantidad de filas que tendra la matriz
    // segun cuantas coincidencias haya respecto de la relacion
    for(int i=0; i < AxB_cardinal; i++){
        for(int j=0; j < 2; j++){
            if(criterio(AxB[i][0], AxB[i][1]) && j == 1){ // criterio(a,b)
                relacionCardinal++;
            } // end if
        } // end for
    } // end for

    // determino si la relacion tiene al menos 1 o mas elementos
    existeRelacion = (relacionCardinal > 0);
    // si se cumple, entonces reservo espacio en memoria por cada Par Ordenado encontrado
    if(existeRelacion){
        /****************** RESERVO MEMORIA - INICIO **********************/
            // creo una matriz dinamica MxN con M filas y 2 columnas
            // reservo cantidad de filas a la matriz
            relacion = new int*[relacionCardinal];
            // reservo espacio en memoria para las columnas
            for(int i=0; i < relacionCardinal; i++){
                relacion[i] = new int[2];
            }
        /****************** RESERVO MEMORIA - FIN **********************/
        
        // lo reutilizo para las filas de los pares ordenados        
        int contarFilas = 0;
        // filas (pares ordenados)
        for(int i=0; i < AxB_cardinal; i++){
            // columnas (primera y segunda componente)
            for(int j=0; j < 2; j++){
                if(criterio(AxB[i][0], AxB[i][1]) && j == 1){ // criterio(a,b)
                    relacion[contarFilas][0] = AxB[i][0]; // (a) 1ra componente
                    relacion[contarFilas][1] = AxB[i][1]; // (b) 2da componente

                    // incremento para asignar el numero de la fila
                    contarFilas++;            
                } // end if
            } // end for
        } // end for
    } // end if
}