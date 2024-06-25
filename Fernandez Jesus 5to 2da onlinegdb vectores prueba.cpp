//Fernandez Martinez Jesus 5to 2da, programado en onlinegdb.com
#include <stdio.h>
#include <iostream>
#include <time.h>

//defino los colores
#define RESET "\x1b[0m"
#define VERDE_L "\x1b[32m"
#define VERDE_B "\x1b[42m"
#define AMARILLO_L "\x1b[33m"
#define AMARILLO_B "\x1b[43m"
#define AZUL_B "\x1b[44m"
#define VIOLETA_B "\x1b[45m"

//defino las variables
char tablero[15][15];
int i=0, j=0, n=15, pozo_col, pozo_row, bonus_col, bonus_row, tortuga=0, tortuga_col=0, tortuga_life=3, liebre=0, liebre_life=3, liebre_col=0, dado, confirm;
    
static void inicializarTablero(){

srand(time(NULL));
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            tablero[i][j] = 'X';
        }
    }
    //crea los pozos
    for(i=0; i<2; i++){
        pozo_row = rand() % (15 - 0);
        pozo_col = rand() % (15 - 0);
        tablero[pozo_col][pozo_row] = 'O';
    }
    //crea los comodines
    for(i=0; i<2; i++){
        bonus_col = rand() % (15 - 0);
        bonus_row = rand() % (15 - 0);
        tablero[bonus_col][bonus_row] = 'C';
    }
    
}

static void dibujarTablero(){
    //funcion para dibujar el tablero
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%c " ,tablero[i][j]);
            }
        printf("\n");
    }
}
static void Jugar(){
    int diff;
    srand(time(NULL));
    do{
        //movimientos de la tortuga
        
        //se actualiza la desaparicion de la tortuga, para que no queden rastros y la posicion quede actualizada
        tablero[tortuga][tortuga_col] = 'X';
        printf("\nturno de tortuga\nvidas: %d\nTirar dado!\n" ,tortuga_life);
        scanf("%d" ,&confirm);
        dado = rand() % (7 - 1);
        printf("tortuga avanza %d casillas\n" ,dado);
        printf("-----------------------------\n");
        //se autosuma la posicion de la tortuga segun el numero de dado
        tortuga = tortuga + dado;
        tablero[tortuga][tortuga_col] = 'T';
        //si la tortuga es mayor a 15, se hace la diferencia para posicionar en la siguiente columna
        if(tortuga >= 15){
            diff=tortuga - 15;
            tortuga_col = tortuga_col + 1;
            tortuga=diff;
        }
        //sistema de pozos y vida de la tortuga
        if(tortuga && tortuga_col == pozo_row & pozo_col){
            tortuga_life = tortuga_life - 1;
        }
        if(tortuga_life <= 0){
            printf("perdio la tortuga / gana la liebre");
            break;
        }
        if(tortuga >= 15 && tortuga_col >=15){
            printf("gana el juego la tortuga!");
            break;
        }
        
        
        //movimientos de la liebre
        tablero[liebre][liebre_col] = 'X';
        printf("\nturno de liebre\nvidas: %d\nTirar dado!\n" ,liebre_life);
        scanf("%d" ,&confirm);
        dado = rand() % (7 - 1);
        printf("liebre avanza %d casillas\n" ,dado);
        printf("-----------------------------\n");
        //se autosuma la posicion de la liebre segun el numero de dado
        liebre = liebre + dado*2;
        tablero[liebre][liebre_col] = 'L';
        //si la liebre es mayor a 15, se hace la diferencia para posicionar en la siguiente columna
        if(liebre >= 15){
            diff=liebre - 15;
            liebre_col = liebre_col + 1;
            liebre=diff;
        }
        //sistema de pozos y vida de la liebre
        if(liebre && liebre_col == pozo_row & pozo_col){
            liebre_life = liebre_life - 1;
        }
        if(liebre_life <= 0){
            printf("perdio la liebre / gana la tortuga");
            break;
        }
        if(liebre >= 15 && liebre_col >=15){
            printf("gana el juego la liebre!");
            break;
        }

        dibujarTablero();
    }while(confirm!=0);
}
    
int main(){
    int opc;
    //system("cls") sirve para que puedan verse los colores en ascii desde dev++
    system("cls");
        printf(AZUL_B "Juego del la liebre y la tortuga!\n" RESET);
    do{
        printf(VIOLETA_B "0-cerrar juego\n1-Crear Tablero\n2-Dibujar Tablero\n3-Empezar a Jugar\n: " RESET);
        scanf("%d" ,&opc);
    
        switch(opc){
            case 1:{
                inicializarTablero();
                break;
            }
            case 2:{
                dibujarTablero();
                break;
            }
            case 3:{
                Jugar();
                break;
            }
        }
    }while(opc !=0);
}