#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>

using namespace std;

//
// # VARIABLES GLOBALES
//
const double X0=2, X1=-4, X2=1; // se reutilizan en f()

//
// # PROTOTIPOS
//
double f(double X);
void aproximacionRaiz(double, double, double &);
void evaluaciones(double &, double &, double, bool &);
void solicitarDatos(double &, double &, double &, int &, bool &);

//
// # MAIN
//
int main(){
    cout<<fixed<<setprecision(4);
    
    int N, contador=0; // se reutiliza en el bucle
    bool salir = false; // centinela que controla el bucle
    double a, b, xR, s;

    // Datos de entrada        
    solicitarDatos(a, b, s, N, salir);

    // Mientras que 'salir' tenga valor 'false' se sigue ejecutando
    while(!salir){
        // PASO 2: aproximacion a la raiz
        aproximacionRaiz(a, b, xR);
        // PASO 3: EVALUACIONES
        // se le pasa como parametro el centinela 'salir' para detener el bucle
        // de ser necesario
        evaluaciones(a, b, xR, salir);
        // PASO 4: NUEVA APROXIMACION
        aproximacionRaiz(a, b, xR);
        // PASO 5: VERIFICA SI LA APROXIMACION ES EXACTA
        // se compara con 's' que es la cota de error de tolerancia
        if(xR == s)
            salir = true; // habilito el centinela 'salir' que detiene el bucle
        else
            evaluaciones(a, b, xR, salir);  // sino se cumple vuelvo al paso 3

        // Iterar N veces o hasta que el error sea menor a la cota
        // Dejar de iterar si el error es menor que la cota
        if((xR < s && xR > -s) || contador == N-1)
            salir = true; // habilito el centinela 'salir' que maneja el bucle

        cout<<"ITERACION "<< contador+1 <<endl;
        cout<<"a: "<< a;
        cout<<", ";
        cout<<"b: " << b;
        cout<<", ";
        cout<<"xR: " << xR;
        cout<<endl;
        cout<<"-----------------------------"<<endl;

        contador++;
    } // end while
    
    cout<<"Criterio de parada evaluado:"<<endl;
    cout<<"Se alcanzaron las "<< contador <<" iteraciones."<<endl;
    cout<<"Raiz encontrada en X es "<<xR<<endl;

    return 0;
}

//
// # FUNCIONES
//
double f(double X){
    return X0*pow(X, 0) + X1*pow(X, 1) + X2*pow(X, 2);
}

void aproximacionRaiz(double a, double b, double &xR){
    xR = ((a + b) / 2);
}

void evaluaciones(double &a, double &b, double xR, bool &salir){
	double producto = f(a) * f(xR);
    
    if(producto < 0)
        b = xR;
    else if(producto > 0)
        a = xR;
    else if(producto == 0)
        salir = true; // habilito el centinela 'salir' que detiene el bucle
}

void solicitarDatos(double &a, double &b, double &s, int &N, bool &salir){
    cout<<"Ingrese valor a del intrevalo (0 en ambos valores para salir): ";
    cin>>a;
    
    cout<<"Ingrese valor b del intrevalo: ";
    cin>>b;
    
    // Condicion que aparece al ingresar los datos
    if(a == 0 && b == 0)
        salir = true; // habilito el centinela 'salir' que detiene el bucle
    else{
        cout<<"Ingrese el e <error>: ";
        cin>>s;
        
        cout<<"Ingrese la cantidad de iteraciones deseadas: ";
        cin>>N;        
    }
}
