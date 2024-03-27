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
		case 3:{
			int i=0, n=3, cal, acum=0, cal_fin, trab_final;
			float prom, porc, porc2, porc3, total;
			for(i=0; i<n; i++){
				printf("¿Calificacion parcial %d?", i+1);
				scanf("%d" ,&cal);
				acum=acum+cal;
			}
			printf("Calficacion examen final?");
			scanf("%d", &cal_fin);
			printf("Calificacion trabajo final?");
			scanf("%d", &trab_final);
			prom=acum/3;
			porc=55*prom/100;	
			porc2=30*cal_fin/100;
			porc3=15*trab_final/100;
			total=porc+porc2+porc3;
			printf("La nota final es %f" ,total);
			break;
		}
		case 4:{
			int num1, num2, i=0, interval;
			printf("ingresar primer numero");
			scanf("%d", &num1);
			printf("ingresar segundo numero");
			scanf("%d", &num2);
			
			interval=num2-num1;
			
			for(i=0; i<=interval; i++){
				if(num1%2 == 0){
					printf("El numero %d es par\n" ,num1);
				}
				num1++;
			}
			break;
		}
		case 5:{
			float km;
			printf("Una persona se encuentra en el kilómetro 70 de una carretera, otra se encuentra en el km 150\n los coches tienen sentido opuesto y tienen la misma velocidad\n");
			km=70 + (150 - 70)/2;
			printf("Se encontraran en el kilometro %f" ,km);
			break;
		}
	}
}

