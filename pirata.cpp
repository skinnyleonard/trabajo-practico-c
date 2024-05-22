#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

#define RESET_COLOR    "\x1b[0m"
#define NEGRO_T        "\x1b[30m"
#define NEGRO_F        "\x1b[40m"
#define ROJO_T     "\x1b[31m"
#define ROJO_F     "\x1b[41m"
#define VERDE_T        "\x1b[32m"
#define VERDE_F        "\x1b[42m"
#define AMARILLO_T "\x1b[33m"
#define    AMARILLO_F  "\x1b[43m"
#define AZUL_T     "\x1b[34m"
#define    AZUL_F      "\x1b[44m"
#define MAGENTA_T  "\x1b[35m"
#define MAGENTA_F  "\x1b[45m"
#define CYAN_T     "\x1b[36m"
#define CYAN_F     "\x1b[46m"
#define BLANCO_T   "\x1b[37m"
#define BLANCO_F   "\x1b[47m"

using namespace std;
//declaro variables
char isla[8][8], movi;
int n=8, menu, columna_pirata, fila_pirata, columna_tesoro, fila_tesoro, columna_v, fila_v, j=0, i=0, mov=0, tm;

//Funcion para inicializar tablero

static void setColor(const string &color){
cout << color;
}
void resetColor(){
cout << "\033[0m";
}

static void inicializarTablero(){
srand(time(NULL));
printf("de que tamanio desea el tablero?(max 8): ");
scanf("%d" ,&tm);
n=tm;
//Lleno el tablero de X

for (i = 0; i < n; i++){
	for (j = 0; j < n; j++){
		isla[i][j] = 'X';
	}
}

//Colocacion de puentes
isla [0][0] = 'B';
isla [tm-1][tm-1] = 'B';

//Colocacion aleatoria del pirata
fila_pirata = rand() %  (n-2)+1;
columna_pirata = rand() % (n-2)+1;
isla[fila_pirata][columna_pirata]  = 'P';

//Colocacion aleatoria del tesoro hasta que no coincida con la posicion del pirata
    do {
    fila_tesoro = rand() %  (n-2)+1;
    columna_tesoro = rand() % (n-2)+1;
    } while (fila_tesoro == fila_pirata && columna_tesoro == columna_pirata);

//Colocacion de Agua
    for (i=0; i<n-1; i++){
      isla[0][i+1] = 'A';
    }
    for(i=0; i<n; i++){
      isla[i][8] = 'A';
    }
    for(i=0; i<n; i++){
      isla[tm-1][i-1] = 'A';
    }
    for(i=0; i<n; i++){
      isla[i-1][tm-1] = 'A';
    }
};
//Funcion para dibujar el tablero
static void dibujarTablero() {
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            switch (isla[i][j]) {
                case 'A':
                    setColor(AZUL_T);
                    setColor(AZUL_F);
                    break;
                case 'B':
                    setColor(MAGENTA_T);
                    setColor(MAGENTA_F);
                    break;
                case 'P':
                    setColor(ROJO_T);
                    setColor(ROJO_F);
                    break;
                default:
                    setColor(AMARILLO_T);
                    setColor(AMARILLO_F);
                    break;
            }
            printf("%c ", isla[i][j]);
        }
        resetColor(); // Restablecer el color al final de cada fila
        printf("\n");
    }
    resetColor(); // Restablecer el color al final de dibujar el tablero
}

//Funcion para empezar a buscar el tablero
//Funcion para empezar a buscar el tablero
int BuscarTesoro() {
    do {
        printf("A donde se quiere mover n (norte), s (sur), o (oeste), e (este): ");
        scanf(" %c", &movi);
        columna_v = columna_pirata;
        fila_v = fila_pirata;
        switch (movi) {
            case 'n':
                fila_pirata = fila_pirata - 1;
                isla[fila_pirata][columna_pirata] = 'P';
                isla[fila_v][columna_v] = 'X';
                dibujarTablero();
                break;
            case 's':
                fila_pirata = fila_pirata + 1;
                isla[fila_pirata][columna_pirata] = 'P';
                isla[fila_v][columna_v] = 'X';
                dibujarTablero();
                break;
            case 'o':
                columna_pirata = columna_pirata - 1;
                isla[fila_pirata][columna_pirata] = 'P';
                isla[fila_v][columna_v] = 'X';
                dibujarTablero();
                break;
            case 'e':
                columna_pirata = columna_pirata + 1;
                isla[fila_pirata][columna_pirata] = 'P';
                isla[fila_v][columna_v] = 'X';
                dibujarTablero();
                break;
            default:
                printf("Opcion no valida\n");
        }

        mov++;
        if (fila_tesoro == fila_pirata && columna_tesoro == columna_pirata) {
            printf("\nEncontraste el tesoro. ¡Felicitaciones, ganaste!\n");
            return 0;
        }
        // Caso de caer al agua
        else if (fila_pirata == 0 || fila_pirata == tm - 1 || columna_pirata == 0 || columna_pirata == tm - 1) {
            printf("\nTe caiste al agua, perdiste la partida\n");
            return 0;
        }
    } while (mov < 50);
    printf("Alcanzaste el limite de movimientos\n");
    return 0;
}

       
int main(){
//Bucle para mostrar el menu y ejecutar las opciones
do{
    printf ("\n1: Inicializar tablero\n2: Dibujar tablero\n3: Buscar tesoro\n0: Salir\nQue opcion desea escojer: ");
    scanf ("%d", & menu);
    switch (menu){
       case 1:{
           inicializarTablero(); //Iniciar el tablero
           break;
       }
       case 2:{
           dibujarTablero(); //Dibujar el tablero
           break;
       }
       case 3:{
           BuscarTesoro(); //Buscar el tesoro
           break;
       }
   }
   }while (menu != 0); //Repetir hasta que se seleccione la opcionde salida
}