#include <stdio.h>
#include <stdlib.h>

int main()
{
    //
    // # Defino variables
    //
    int numero1,numero2;
    int sumatoria_numero1 = 0;
    int sumatoria_numero2 = 0;

    /**********************************************************************************/

    //
    // # Datos de entrada
    //
    printf("ingrese el primer numero: ");
    scanf("%d", & numero1);
    printf("ingrese el segundo numero: ");
    scanf("%d", & numero2);
    
    /**********************************************************************************/
    
    //
    // Proceso la informacion
    //
    // El while itera siempre que ambos numeros naturales
    while(numero1 != 0 && numero2 != 0){
        // Itero x veces segun el valor de numero1
        for(int i=1; i < numero1; i++){
            // Determino si el numero es divisible por el incremental
             if(numero1%i == 0){
                 // Si se cumple lo guardo, y lo sumo con sus valores anteriores
                sumatoria_numero1 += i;
             }
        } // end for
        
        printf("sumar: %i\n", sumatoria_numero1);
        // Itero x veces segun el valor de numero1
        for(int j=1;j < numero2;j++){
            // Determino si el numero es divisible por el incremental
            if(numero2%j == 0){
                 // Si se cumple lo guardo, y lo sumo con sus valores anteriores
                sumatoria_numero2 += j;
            }
        } // end for            
        /**********************************************************************************/
        
        //
        // # Datos de salida
        //
        // Determino si se cumple la condicion
        if(sumatoria_numero1 == numero2 && sumatoria_numero2 == numero1){
            printf("los numeros son amigos");
        }
        else{
            printf("no son amigos");
        }
        
        // Inicializo los acumuladores en cero por cada iteracion del while
        
        sumatoria_numero1 = 0;
        sumatoria_numero2 = 0;
        
        printf("\ningrese el primer numero: ");
        scanf("%d", & numero1);
        printf("ingrese el segundo numero: ");
        scanf("%d", & numero2);
    } // end while


    return 0;
}
