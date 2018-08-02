/*
 *
 * Dado dos numeros, mostrar los numeros primos entre ellos,
 * Ej.: a=1, b=11, muestra {1,3,5,7,11}
 * 
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  int intervalo_inicio, intervalo_final;
  int numeros_divisibles;
  int repetir_loop = 0;
  int numero_primo;
  bool es_compuesto;

  // Mensaje informativo
  cout << "Mostrar numeros primos a partir un intervalo de 2 numeros" << endl;

  cout << "Intervalo - Inicio: ";
  cin >> intervalo_inicio;

  cout << "Intervalo - Final: ";
  cin >> intervalo_final;

  while(intervalo_inicio <= intervalo_final){
    intervalo_inicio++;
    
    for(int x = 1; x < intervalo_inicio; x++){
      es_compuesto = ((intervalo_inicio % x) == 0);
      
      if(es_compuesto) numeros_divisibles++;
    }
      
    if(numeros_divisibles == 2){
      cout << i << endl;
      //numero_primo = intervalo_inicio;
    }
    
    //cout << numero_primo << endl;
  }

  cout << '\n'; // new line
  
  return 0;
}
