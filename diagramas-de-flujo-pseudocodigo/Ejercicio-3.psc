Algoritmo Superman
	// defino variables
	Definir vitalidad,kriptonita Como Real
	Definir contar Como Entero
	// asigno valor a las variables
	contar <- 0
	vitalidad <- 100
	kriptonita <- 25
	// proceso informacion
	Mientras vitalidad > 0 Hacer
		contar <- contar+1
		vitalidad <- vitalidad-kriptonita
	FinMientras
	// salida de datos
	Escribir 'Kriptonita necesaria son ',contar
FinAlgoritmo

