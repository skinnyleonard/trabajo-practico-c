#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
	char isla[8][8], movi;
	int n=8, menu, columna_pirata, fila_pirata, columna_tesoro, fila_tesoro, columna_v, fila_v, j=0, i=0, mov=0;
	
	static void inicializarTablero(){
	srand(time(NULL));
			
			for (i = 0; i < n; i++){
				for (j = 0; j < n; j++){
					isla[i][j] = 'X';
				}
			}
			
			isla [0][0] = 'P';
			isla [7][7] = 'P';
			
			fila_pirata = rand() %  (n-2)+1;
			columna_pirata = rand() % (n-2)+1;
			isla[fila_pirata][columna_pirata]  = 'R';
			
			do {
				fila_tesoro = rand() %  (n-2)+1;
				columna_tesoro = rand() % (n-2)+1;	
			} while (fila_tesoro == fila_pirata && columna_tesoro == columna_pirata);	
			
			for (i=0; i<n-1; i++){
			    isla[0][i+1] = 'A';
			}
			for(i=0; i<n; i++){
			    isla[i][8] = 'A';
			}
			for(i=0; i<n; i++){
			    isla[7][i-1] = 'A';
			}
			for(i=0; i<n; i++){
			    isla[i-1][7] = 'A';
			}
		};
			
	static void dibujarTablero(){
			for (i=0; i<n; i++){
				for(j=0; j<n; j++){
					printf("%c " ,isla[i][j]);
				}
				printf("\n");
			}
		};
		
	static void BuscarTesoro(){
			do{
				printf ("A donde se quiere mover n (norte), s (sur), o (oeste), e (este): ");
				scanf (" %c", & movi);
				columna_v = columna_pirata;
				fila_v = fila_pirata;
				switch (movi){
				case 'n':
					fila_pirata = fila_pirata - 1;
				
					isla[fila_pirata][columna_pirata] = 'R';
					for (i=0; i<n; i++){
						for(j=0; j<n; j++){
							printf("%c " ,isla[i][j]);
						}
					printf("\n");
					isla[fila_v][columna_v] = 'X';						
					}
					break;
				case 's':
					fila_pirata = fila_pirata + 1;
					isla[fila_pirata][columna_pirata] = 'R';
					for (i=0; i<n; i++){
						for(j=0; j<n; j++){
							printf("%c " ,isla[i][j]);
						}
					printf("\n");
					isla[fila_v][columna_v] = 'X';						
					}					
				break;
				case 'o':
					columna_pirata = columna_pirata - 1;
					isla[fila_pirata][columna_pirata] = 'R';
					for (i=0; i<n; i++){
						for(j=0; j<n; j++){
							printf("%c " ,isla[i][j]);
						}
					printf("\n");
					isla[fila_v][columna_v] = 'X';						
					}				
				break;
				case 'e':
					columna_pirata = columna_pirata + 1;
					isla[fila_pirata][columna_pirata] = 'R';
					for (i=0; i<n; i++){
						for(j=0; j<n; j++){
							printf("%c " ,isla[i][j]);
						}
					printf("\n");
					isla[fila_v][columna_v] = 'X';				
					}				
				break;
				default:
					printf ("Opcion no valida\n");						
			}

			mov ++;
			if (fila_tesoro == fila_pirata && columna_tesoro == columna_pirata){
				printf("\nEncontraste el tesoro. �jfelicitaciones ganaste!\n");
				break;
			}
			/*fila superior*/
			else if(isla[fila_pirata][columna_pirata] == isla[0][1] ||
                isla[fila_pirata][columna_pirata] == isla[0][2] ||
                isla[fila_pirata][columna_pirata] == isla[0][3] ||
                isla[fila_pirata][columna_pirata] == isla[0][4] ||
                isla[fila_pirata][columna_pirata] == isla[0][5] ||
                isla[fila_pirata][columna_pirata] == isla[0][6] ||
                isla[fila_pirata][columna_pirata] == isla[0][7] ||
                /*fila inferior*/
                isla[fila_pirata][columna_pirata] == isla[7][1] ||
                isla[fila_pirata][columna_pirata] == isla[7][2] ||
                isla[fila_pirata][columna_pirata] == isla[7][3] ||
                isla[fila_pirata][columna_pirata] == isla[7][4] ||
                isla[fila_pirata][columna_pirata] == isla[7][5] ||
                isla[fila_pirata][columna_pirata] == isla[7][6] ||
                isla[fila_pirata][columna_pirata] == isla[7][7] ||
                /*columna izquierda*/
                isla[fila_pirata][columna_pirata] == isla[1][0] ||
                isla[fila_pirata][columna_pirata] == isla[2][0] ||
                isla[fila_pirata][columna_pirata] == isla[3][0] ||
                isla[fila_pirata][columna_pirata] == isla[4][0] ||
                isla[fila_pirata][columna_pirata] == isla[5][0] ||
                isla[fila_pirata][columna_pirata] == isla[6][0] ||
                isla[fila_pirata][columna_pirata] == isla[7][0] ||
                /*columna derecha*/
                isla[fila_pirata][columna_pirata] == isla[1][7] ||
                isla[fila_pirata][columna_pirata] == isla[2][7] ||
                isla[fila_pirata][columna_pirata] == isla[3][7] ||
                isla[fila_pirata][columna_pirata] == isla[4][7] ||
                isla[fila_pirata][columna_pirata] == isla[5][7] ||
                isla[fila_pirata][columna_pirata] == isla[6][7] ||
                isla[fila_pirata][columna_pirata] == isla[7][7]){
    			    printf("\nperdiste el juego\n");
    			    break;
    			}
			} while (mov < 50);
			printf("alcanzaste el limite de movimientos\n");
	    };
	    
int main(){
		do{
    		printf ("\n1: Inicializar tablero\n2: Dinujar tablero\n3: Buscar tesoro\n0: Salir\nQue opcion desea escojer: ");
    		scanf ("%d", & menu);
    		switch (menu){
    		    case 1:{
    		        inicializarTablero();
    		        break;
    		    }
    		    case 2:{
    		        dibujarTablero();
    		        break;
    		    }
    		    case 3:{
    		        BuscarTesoro();
    		        break;
    		    }
		    }
	    }while (menu != 0);
}
