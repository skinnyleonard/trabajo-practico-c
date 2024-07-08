#include <stdio.h>
#include <iostream>
using namespace std;

int matriz[10][6];
int i=0, j=0, n=10, m=6;

static void calcularMatriz(){
    srand(time(NULL));
    int random=0, sqrt2, sqrt3, incremento=0;
    random = rand() % (10 - 0);
    
    sqrt2 = random * random;
    sqrt3 = random * random * random;
    
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            matriz[i][j] = random;
        }
    }
    for(i=0; i<n; i++){
        incremento = incremento + 2;
        for(j=0; j<m; j++){
            matriz[i][2] = sqrt2;
            matriz[i][4] = sqrt2;
            matriz[i][6] = sqrt2;
            matriz[i][8] = sqrt2;
        }
    }
}
static void dibujarMatriz(){
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int opt;
    do{
        printf("\x1b[33m" "\npresione:\n1.Crear matriz\n2.Dibujar matriz\n0.Salir\n : " "\x1b[33m");
        scanf("%d" ,&opt);
        switch(opt){
            case 1:{
                calcularMatriz();
                break;
            }
            case 2:{
                dibujarMatriz();
                break;
            }
            default:{
                printf("opcion incorrecta");
                break;
            }
        }
    }while(opt !=0);
}