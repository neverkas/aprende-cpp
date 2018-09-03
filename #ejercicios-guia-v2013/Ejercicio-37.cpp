/*
 *
 * Desarrollar y probar una funcion que calcule el maxio comun divisor
 * de dos numeros enteros a y b con el siguiente algoritmo:
 * 1. Dividir a por b y calcular el resto (0 < r < b)
 * 2. Si r==0 entonces el MCD es b, si no seguir en (3)
 * 3. Reemplazar a por b, b por r, y volver al paso (1)
 *
 * La funcion debe tener el siguiente prototipo:
 * int mcd(int a, int b);
 *
 * a=10, b=2, r=0, mcd(10,2) = 2
 * a=10, b=3, r=1 mcd(10,3) => a=3, b=1 mcd(3,1)=1
 * a=15, b=2, r=1 mcd(15,1) => a=2, b=1 mcd(2,1)=1
 * 
 * 
*/

/*
 *
 * Desarrollar y probar una funcion que calcule el maxio comun divisor
 * de dos numeros enteros a y b con el siguiente algoritmo:
 * 1. Dividir a por b y calcular el resto (0 < r < b)
 * 2. Si r==0 entonces el MCD es b, si no seguir en (3)
 * 3. Reemplazar a por b, b por r, y volver al paso (1)
 *
 * La funcion debe tener el siguiente prototipo:
 * int mcd(int a, int b);
 *
 * a=10, b=2, r=0, mcd(10,2) = 2
 * a=10, b=3, r=1 mcd(10,3) => a=3, b=1 mcd(3,1)=1
 * a=15, b=2, r=1 mcd(15,1) => a=2, b=1 mcd(2,1)=1
 * 
 * 
*/
#include <iostream>

using namespace std; 

int mcd(int, int);

int main(){
    int a, b;
    char respuesta;
    bool repetir=true;
    
    // El bucle while se repetira mientras repetir sea true 
    // como repetir se inicializo en true se ejecuta al iniciar el programa
    while(repetir){
        cout << "Ingrese los numeros que desea calcular su mcd(a,b)" << endl;
        cout << "a:";
        cin >> a;
        cout << "b: ";
        cin >> b;
    
        cout << "El mcd entre " << a << " y " << b << " es " << mcd(a, b) << endl;
        cout << endl;
        
        cout << "Desea calcular otro mcd? (s/n) ";
        cin >> respuesta;
        
        // Si el valor ingresado en 'respuesta' es un NO        
        if(respuesta == 'n'  || respuesta == 'N'){
            // Finalizo la ejecucion del bucle while
            repetir = false;
        }
    } // end while

    return 0;
}

int mcd(int a, int b){
    int resto, resultado;
    
    // Divido 'a' por 'b' y con el % obtengo el resto de la division
    resto = (a % b);
    
    // Si el resto es igual a cero    
    if(resto == 0){
        // el mcd entre a y b es el divisor b
        resultado = b;
    }
    // Si el resto es distinto a cero
    else{
        // Ejecuto la operacion dentro del bucle while mientras 'resto' sea distino a cero
        while(resto != 0){
            // cambio el valor de las variables, a 'a' le asigno 'b', y a 'b' le asigno 'resto'
            a = b;
            b = resto;
            
            // vuelvo a obtener el resto de la division de a por b con sus nuevos valores           
            resto = (a % b);
            
            // si el resto da cero
            if(resto == 0){
                // el mcd entre a y b es el divisor b
                resultado = b;
            }
        }
    }
    
    return resultado;
}
