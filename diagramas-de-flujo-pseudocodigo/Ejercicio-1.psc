Algoritmo DETECTOVE
	// defino variables
	Definir policias,mafiosos,mentirosos Como Entero
	Definir total,porcentaje Como Entero
	// entrada de datos
	Escribir 'Cantidad de policias'
	Leer policias
	Escribir 'Cantidad de mafiosos'
	Leer mafiosos
	Escribir 'Cantidad de mentirosos'
	Leer mentirosos
	// proceso informacion
	total = policias+mafiosos
	porcentaje = (mentirosos/total) * 100
	// salida de datos
	Escribir 'Personas entrevistadas  ',total
	Escribir "Porcentaje de mentirosos ", porcentaje
FinAlgoritmo

