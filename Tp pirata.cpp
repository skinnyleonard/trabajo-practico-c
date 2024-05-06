#include <stdio.h>
#include <stdlib.h>
#include <time.h>
main(){
	char isla[n][n];
	int fila_aleatorio, columna_aleatorio, n=8, menu, pirata, tesoro;
	
	
	do{
		printf ("\n1: Inicializar tablero\n2: Dinujar tablero\n3: Buscar tesoro\n0: Salir\nQue opcion desea escojer: ");
		scanf ("%d", &menu);
		switch (menu){
		case 1:
			fila_aleatorio = rand() %  (n-2)+1;
			columna_aleatorio = rand() % (n-2)+1;
			isla[][]
			printf("fila %d columna %d",fila_aleatorio, columna_aleatorio);
			break;
		}
	}while (menu != 0);
}
