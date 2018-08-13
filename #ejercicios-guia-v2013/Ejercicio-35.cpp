/*
 * AVISO:
 * Si tenes errores de compilacion con <string> debes ejecutar la siguiente
 * linea de comando en tu terminal de linux: g++ -std=c++0x Exercise-40a.cpp
 * 
 *****************************************************************************
 * 
 * El gobierno de la Ciudad de Bueno Aires realiza una encuesta en casas
 * de familia. De cada familia se conoce:
 * -Domicilio
 * -Tipo de vivienda
 *	('C': casa, 'D': departamento)
 * -Cantidad de integrantes
 *
 * De cada integrante de la familia se conoce:
 * -Nombre
 * -Apellido
 * -Edad
 * -Sexo
 *	('F': Feminino, 'M': Masculino)
 * -Nivel de estudios alcanzados 
 *	('N': No posee, 'P': Primario, 'S': Secundario, 'T': Terciario, 'U': Universitario)
 * -Indicador
 *	('I': Incompleto, 'C': Completo) que se refiere al item anterior
 *
 * Los datos finalizan cuando la cantidad de integrantes sea igual a cero.
 * Se pide un listado con los resultados:
 * -Los datos de los encuestados que hayan completado los estudios primarios.
 * -El porcentaje de analfabetismo en la ciudad (se considera analfabetos a los
 * mayores de 10 aC1os que no posean estudios)
 * -El domicilio de la familia con mayor cantidad de integrantes que viven
 * en departamento.
 * -La edad promedio de cada familia y de la ciudad.
 * -La cantidad de encuestados en cada tipo de nivel de estudios alcanzados incompletos.
 * -El porcentaje de encuestados de sexo femenino y masculino.
 * 
*/
#include <iostream>
#include <string>

using namespace std;
using std::string;

//
// # Main
//
int main(){
	//
	// # 1. Defino las variables
	//
	string encuestadosEstudiosPrimariosCompleto[50];
	string encuestadoInfo;
	
	string domicilio;
	char tipoDeVivienda; // 'C':Casa, 'D':Departamento
	int cantidadIntegrantes;

	string nombre, apellido;
	int edad;
	char sexo; // 'F' o 'M'
	string sexoTexto;
	// 'N' no posee, 'P': primario, 'S': secundario, 'T': terciario, 'U': universitario
	char nivelDeEstudiosAlcanzados;
	char indicador; // 'i': incompleto, 'c': completo // ref. al item anterior
	
	int cantidadAnalfabetos = 0;
	bool hayAnalfabetos = false;
	int cantidadEncuestadosTotal = 0;
	float porcentajeAnalfabetismo = 0;

	int mayorCantidadIntegrantesDepartamento = 0;
	string domicilioMayorCantidadIntegrantesDepartamento;

	int sumatoriaEdadPorFamilia = 0;
	int edadPromedioPorFamilia[50];
	int sumatoriaEdadTotal = 0;
	float edadPromedioPorCiudad = 0;

	int encuestadosPrimarioIncompleto = 0;
	int encuestadosSecundarioIncompleto = 0;
	int encuestadosTerciarioIncompleto = 0;
	int encuestadosUniversidadIncompleta = 0;

	int encuestadosSexoFemenino = 0;
	int encuestadosSexoMasculino = 0;
	int contadorEncuestadosPrimario = 0;
	int contadorEncuestadoTotal = 0;
	int contadorPorEncuesta = 0;

	/*********************************************************************/

	//
	// # 2. Entrada de datos && Proceso la información
	//
	// Iterar mientras cantidad de integrantes sea mayor a 0
	while(cantidadIntegrantes > 0){
		cout << "ENCUESTA #" << (contadorPorEncuesta + 1) << endl << endl;
		cout << "Domicilio: ";
		cin >> domicilio;
		cout << "Tipo de vivienda(d/c): ";
		cin >> tipoDeVivienda;
		cout << "Cantidad de integrantes: ";
		cin >> cantidadIntegrantes;

		if(cantidadIntegrantes > 0){
			// Inicializo dentro del while para volver a cero el contador
			// por cada encuesta
			//contadorEncuestadosPrimario = 0;
			sumatoriaEdadPorFamilia = 0;
			
			cout << "Informacion de los integrantes: " << endl;
			for(int i=0; i < cantidadIntegrantes; i++){			
				cout << "\tINTEGRANTE #" << (i + 1) << endl << endl;
				cout << "\tNombre: ";
				cin >> nombre;
				cout << "\tApellido: ";
				cin >> apellido;
				cout << "\tEdad: ";
				cin >> edad;
				cout << "\tSexo: (m/f) ";
				cin >> sexo;
				cout << "\tNivel de estudios alcanzados(n/p/s/t/u): ";
				cin >> nivelDeEstudiosAlcanzados;

				if(nivelDeEstudiosAlcanzados != 'n'){
    				cout << "\tIndicar si se finalizaron(i/c): ";
    				cin >> indicador;
				}
				
				cout << "\t------------------------------------------" << endl;

				// Se reutiliza para calcular promedio edad por familia
				sumatoriaEdadPorFamilia += edad;

				// Determino la cantidad de encuestados de cada sexo, y paso a texto 
				if(sexo == 'f'){
				    sexoTexto = "Femenino";
					encuestadosSexoFemenino++;
				}
				else if(sexo == 'm'){
				    sexoTexto = "Masculino";
					encuestadosSexoMasculino++;
				}
				
				// Contar encuestados sin estudios mayores a 10 anios
				if(edad > 10 && nivelDeEstudiosAlcanzados == 'n'){
					cantidadAnalfabetos++;			
				}
				// Contar y guardar informacion de los encuestados que
				// hayan completado sus estudios primarios
				if(nivelDeEstudiosAlcanzados == 'p' && indicador == 'c'){
					contadorEncuestadosPrimario++;
                    
                    // Concateno los datos y los transformo a String si se requiere
					encuestadoInfo = nombre + " " + apellido + ", " + to_string(edad) + ", " + sexo;
					encuestadosEstudiosPrimariosCompleto[contadorEncuestadosPrimario] = encuestadoInfo;
				}

				// Contar quienes tengan los estudios incompletos
				// y categorizar por Nivel de estudios alcanzados
				if(indicador == 'i'){
					switch(nivelDeEstudiosAlcanzados){
					case 'p':
						encuestadosPrimarioIncompleto++;
						break;
					case 's':
						encuestadosSecundarioIncompleto++;
						break;
					case 't':
						encuestadosTerciarioIncompleto++;
						break;
					case 'u':
						encuestadosUniversidadIncompleta++;
						break;
					}
				}
			
			} // end for
            
            // Acumulo la cantidad de integrantes agregados por cada Encuesta
			cantidadEncuestadosTotal += cantidadIntegrantes;
            // Guardo el domicilio de la familia con mayor cantidad integrantes y que viva en Departamento 
			if(tipoDeVivienda == 'd' && cantidadIntegrantes > mayorCantidadIntegrantesDepartamento){
				domicilioMayorCantidadIntegrantesDepartamento = domicilio;
			}
    		// Para calcular el promedio de edad por Ciudad
    		sumatoriaEdadTotal += sumatoriaEdadPorFamilia;
    		// Caculo la edad promedio por familia y lo guardo
    		edadPromedioPorFamilia[contadorPorEncuesta] = sumatoriaEdadPorFamilia / cantidadIntegrantes;
            //    		
    		contadorPorEncuesta++;
		} // end if

	} // end while
    
	edadPromedioPorCiudad = (sumatoriaEdadTotal / cantidadEncuestadosTotal);
    
    // Utilizo 'hayAnalfabetos' como bandera, para evitar errores al dividir por cero en 'porcentajeAnalfabetismo'
    if(cantidadAnalfabetos > 0)
        hayAnalfabetos = true;
    
    if(hayAnalfabetos)
        porcentajeAnalfabetismo = (cantidadEncuestadosTotal / cantidadAnalfabetos);
        
	/*********************************************************************/
        
	//
	// # 3. Salida de datos
	//
	cout << "Edad promedio por Ciudad: " << edadPromedioPorCiudad << endl;
    
	cout << "Edad promedio de cada familia: ";
	for(int i=0; i < contadorPorEncuesta; i++)
		cout << edadPromedioPorFamilia[i] << ", ";
    cout << endl;
        
	cout << "Porcentaje de analfabetismo: " << porcentajeAnalfabetismo << endl;
	cout << "Domicilio con mayor cantidad de integrantes que viven en departamento: ";
	cout << domicilioMayorCantidadIntegrantesDepartamento << endl;
    
	cout << "Encuestados con estudios incompletos: " << endl;
	cout << "\tPrimario: " << encuestadosPrimarioIncompleto << endl;
	cout << "\tSecundario: " << encuestadosSecundarioIncompleto << endl;
	cout << "\tTerciario: " << encuestadosTerciarioIncompleto << endl;
	cout << "\tUniversitario: " << encuestadosUniversidadIncompleta << endl;

	cout << "Encuestados segun su Sexo: " << endl;
	cout << "\tFemenino: " << encuestadosSexoFemenino << endl;
	cout << "\tMasculino: " << encuestadosSexoMasculino << endl;

	cout << "Encuestados con estudios primarios completo";
	for(int i=0; i < contadorEncuestadosPrimario; i++)
		cout << "\t " << encuestadosEstudiosPrimariosCompleto[i] << endl;
	
	return 0;
}
