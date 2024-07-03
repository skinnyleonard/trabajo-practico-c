#include <stdio.h>
//Fernandez Martinez Jesus 5to 2da
int opt;

int main(){
	printf("ejercicio 1\nejercicio 2\nejercicio 3\nejercicio 4\nejercicio 5\n : ");
	scanf("%d" ,&opt);
	
	switch(opt){
		case 1:{
			int hora_entrada, hora_salida, cant=0, total=0;
			printf("ingrese hora de entrada\n : ");
			scanf("%d" ,&hora_entrada);
			printf("ingrese hora de salida\n : ");
			scanf("%d" ,&hora_salida);
			
			if(hora_entrada > hora_salida){
				cant = (hora_entrada - hora_salida + 100)/100;
			}
			else{
				cant = (hora_salida - hora_entrada + 100)/100;
			}
			total = ((cant-1)*250)+500;
			printf("horas totales %d\n" ,cant);
			printf("total %d" ,total);
			
			break;
		}
		case 2:{
			int num1, num2, i=0, n=9, total=0;
			printf("ingrese el primer numero a multiplicar : ");
			scanf("%d" ,&num1);
			printf("ingrese el segundo numero a multiplicar : ");
			scanf("%d" ,&num2);
			
			for(i=0; i<num2; i++){
				total = total + num1;
			}
			printf("el producto por sumas sucesivas es %d" ,total);

			break;
		}
		case 3:{
			int km, precio_combu, tiempo1;
			float tiempo2, total100=0, combu, velocidad, horas, total=0;
			printf("km recorridos totales? : ");
			scanf("%d" ,&km);
			printf("combustible consumido en total (en litros)? : ");
			scanf("%f" ,&combu);
			printf("costo del combustible (por litro)? : ");
			scanf("%d" ,&precio_combu);
			printf("horas totales del viaje? : ");
			scanf("%d" ,&tiempo1);
			printf("minutos finales del viaje? : ");
			scanf("%f" ,&tiempo2);
			
			//consumo de combustible cada 100km
			total100=(combu/100)*precio_combu;
			printf("-----------------------------\nconsumo cada 100km %f litros\n" ,combu/100);
			printf("cada 100km %f pesos\n-----------------------------\n" ,total100);
			
			//consumo de combustible por km
			total=(combu/km)*precio_combu;
			printf("en total se pago %f pesos de combustible por km\n" ,total);
			printf("total del viaje en combustible %f\n" ,total*km);
			
			//velocidad
			horas = (tiempo1)+(tiempo2/60);
			velocidad = km / horas;
			printf("velocidad de %f km/h" ,velocidad);
			break;
		}
		case 4:{
			int i=0, porc=0;
			float total, entrada=0, descuento;
			
			do{
				printf("coste de la entrada? : ");
				scanf("%f" ,&entrada);
				total=total+entrada;
				i=i+1;
				if(i>=4){
					break;
				}
			}while(entrada!=0);
			i=i-1;
			if(i==2){
				descuento = total-(10*total/100);
				porc=10;
			}
			else if(i==3){
				descuento = total-(15*total/100);
				porc=15;
			}
			else if(i==4){
				descuento = total-(20*total/100);
				porc=20;
			}
			printf("descuento de %d, y en total paga %f" ,porc, descuento);
			break;
		}
		case 5:{
			int personas, total;
			printf("personas en total? : ");
			scanf("%d" ,&personas);
			if(personas <= 200){
				total = personas * 6500;
			}
			else if(personas > 200 || personas <= 300){
				total = personas * 5500;
			}
			else if(personas > 300){
				total = personas * 4500;
			}
			printf("total a pagar %d pesos" ,total);
			break;
		}
	}
}
