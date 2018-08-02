/*
 *
 * Se realiza una inspección en una fábrica de pinturas, y se detectaron algunas
 * infracciones. De cada infraccion se tomó nota de los siguientes datos:
 * -Tipo de infracción 1,2,3 ò 4: tInfr
 * -Motivo de la infracción: motivo
 * -Valor de la multa: valor
 * -Gravedad de la infracción('L','M','G'): gravedad
 *
 * Los dato finalizan cuando se ingrese un tInfr iguala cero. Se pide informar
 * al final del proceso:
 * -Los valores totales de la multaa pagar de acuerdo a la gravedad de las
 * infracciones registradas.
 * -La leyenda "Clausurar Fábrica" si la cantidad de infracciones 3 y 4
 * con gravedad "G" es mayor a 3.
 * -Informar el motivo correspondiente la infracción de menor valor.
 * 
*/

#include <iostream>
#include <string>

using namespace std;
using std::string;

// # Main
//
int main(){
	//
	// # 1. Defino las variables
	//
	int tInfr; // tipo de infracción
	string motivo;
	int valor;
	char gravedad;
	int gravedad_valor;
	int infracciones_cantidad = 0;

	int valor_multa = 0;
	int valor_multa_total = 0;
	int infraccion_menor_valor = 0;
	string infraccion_menor_valor_motivo;

	bool clausurar = false;
	
	/*********************************************************************/
		
	//
	// # 2. Entrada de datos && Proceso la información
	//
	cout << "Tipo de infracción (1,2,3,4): ";
	cin >> tInfr;
	
	while(tInfr != 0){
		if(tInfr != 0){
			cout << "Motivo: ";
			cin >> motivo;

			cout << "Valor: ";
			cin >> valor;

			cout << "Gravedad (L, M ,G): ";
			cin >> gravedad;
		
			switch(gravedad){
				case 'L': case 'l':
					gravedad_valor = 100;
					break;
				case 'M': case 'm':
					gravedad_valor = 500;
					break;
				case 'G': case 'g':
					gravedad_valor = 800;
					break;			
			} // end switch

			// Acumulo y sumo cada valor segun la gravedad
			valor_multa = valor + gravedad_valor;
			valor_multa_total += valor_multa;
		
			// Si no hubo cambios en la variable
			// guardos los datos
			if(infraccion_menor_valor == 0){
				infraccion_menor_valor = valor_multa;
				infraccion_menor_valor_motivo = motivo;
			}
			else if(valor_multa < infraccion_menor_valor){
				infraccion_menor_valor = valor_multa;
				infraccion_menor_valor_motivo = motivo;
			}

			// Si la cantidad es mayor a 3
			if(infracciones_cantidad > 3)
				clausurar == true;
			else if(clausurar == false){
				// Si la infracción es del tipo 3 o 4 y gravedad G
				if((gravedad == 'G' || gravedad == 'g') && (tInfr == 3 || tInfr == 4))
					infracciones_cantidad+=1;
			} // end if
						
		}
		
		cout << "Tipo de infracción (1,2,3,4): ";
		cin >> tInfr;
	} // end while
	cout << endl;
	
	/*********************************************************************/

	//
	// # 3. Salida de datos
	//
	cout << "Valor total de la multa es: $" << valor_multa_total << endl;																														
	cout << "El motivo de la menor infracción es: " << infraccion_menor_valor_motivo << endl;
																			
	if(clausurar == true)
		cout << "Clausurar Fabrica" << endl;
		
	return 0;
}
