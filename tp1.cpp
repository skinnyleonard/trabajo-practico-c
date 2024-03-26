#include <stdio.h>

main()
{
	int alumnos, total, opcion;
	
	printf("Seleciona entre el ejercicio 1, 2, 3, 4 o 5");
	scanf("%d" ,&opcion);
	
	switch(opcion){
		case 1:{
			printf("Cuantos alumnos van a viajar");
			scanf("%d" ,&alumnos);
	
			if(alumnos >= 100){
				total=alumnos*500;
				printf("El coste total del alquiler es %d" ,total);
			}
			else if(alumnos >=50 && alumnos <= 99){
				total=alumnos*400;
				printf("El coste total del alquiler es %d" ,total);
			}
			else if(alumnos >=30 && alumnos <= 49){
				total=alumnos*300;
				printf("El coste total del alquiler es %d" ,total);
			}
			else if(alumnos <= 30){
				total=alumnos*6000;
				printf("El coste total del alquiler es %d" ,total);
			}
			break;
		}
		case 2:{
			int sueldo;
			float comi, total;
			printf("¿Cuanto cobro este este mes?");
			scanf("%d" ,&sueldo);
			comi=sueldo/10;
			total=sueldo + comi;
			printf("El 10 porciento de comision por ventas es de %f pesos\n", comi);
			printf("El sueldo mas comisiones es de %f pesos", total);
			break;
		}
	}
}

