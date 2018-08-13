/*
 *
 * Un buque de carga traslada 100 contenedores a 3 diferentes puertos del
 * pais, identificados con los numeros 1, 2 y 3.
 * Por cada uno de los contenedores trasladados por el buque se registran
 * los siguientes datos:
 * 1. Identificación del contenedor: idCont
 * 2. Peso del contenedor en kilos: peso
 * 3. Puerto de arribo (un valor de 1 a 3): idPuerto
 *
 * Se pide calcular e informar:
 * 1. El peso total que el buque debe trasladar
 * 2. El contenedor de mayor peso
 * 3. La cantidad de contenedores que se trasladarán a cada puerto
 *
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <iomanip>

using namespace std;

//
// # Main
//
int main(){
	srand(time(NULL));
	cout << setprecision(0)<<fixed;
	
	//
	// # 1. Defino las variables
	//
	int contenedores_cantidad = 10;
	int puertos_cantidad = 3; //
	
	puertos_cantidad-=1; // Se resta 1, porque el indice cero cuenta también
		
	int buque_peso = 0;
	int contenedor_mayor_peso = 0;
	int contenedor_mayor_peso_id = 0;
	int contenedores_por_puerto[puertos_cantidad];

	int contenedor_id = 0; // idCont
	int contenedor_peso = 0;
	
	int puerto_id = 0; // idPuerto

	int	contador = 0;
	
	/*********************************************************************/

	//
	// # 2. Proceso la información
	//
	// inicializo cada elemento en cero
	for(int puerto_id=0; puerto_id <= puertos_cantidad; puerto_id++)
		contenedores_por_puerto[puerto_id] = 0;
	
	while(contador < contenedores_cantidad){
		contador++;
		
		contenedor_id = contador; //idCont
		contenedor_peso = (rand() % 200 + 1); // peso
		puerto_id = (rand() % 3 + 0);// 
		
		buque_peso += contenedor_peso; // peso total del buque
		// cantidad contenedores que se trasladaran a cada puerto
		if(puerto_id >= 0 && puerto_id < 3)
			contenedores_por_puerto[puerto_id] += 1;
		
		if(contenedor_peso > contenedor_mayor_peso){
			contenedor_mayor_peso = contenedor_peso;
			contenedor_mayor_peso_id = contenedor_id;
		}

		printf("Contenedor %i, Peso %i kg, Puerto %i \n", contenedor_id, contenedor_peso, puerto_id+1);		
	} // end while	
	cout << endl;
	
	/*********************************************************************/
	
	//
	// # 3. Salida de datos
	//
	cout << "Peso total del buque: " << buque_peso << " kg" << endl;

	cout << "El contenedor de mayor peso es el " << contenedor_mayor_peso_id;
	cout << " con " << contenedor_mayor_peso << "kg"	<< endl;

	for(int puerto_id=0; puerto_id <= puertos_cantidad; puerto_id++)
		printf("Puerto %i con %i contenedores \n", puerto_id+1, contenedores_por_puerto[puerto_id]);
	
	return 0;
}
