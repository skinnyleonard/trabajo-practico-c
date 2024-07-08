#include <stdio.h>
#include <iostream>
using namespace std;


static void ejercicio1(){
    srand(time(NULL));
    
    int matriz[10][6];
    int i=0, j=0, n=10, m=6, random=0, sqrt2, sqrt3, incremento=0;
    
    random = rand() % (10 - 0);
    
    sqrt2 = random * random;
    sqrt3 = random * random * random;
    
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            matriz[i][j] = random;
        }
    }
    for(i=0; i<n; i++){
        // incremento = incremento + 2;
        for(j=0; j<m; j++){
            matriz[2][j] = sqrt2;
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("sqrt2 %d, sqrt3 %d", sqrt2, sqrt3);
    
}
static void ejercicio2(){
    int matriz[4][3];
    int i=0, j=0, n=4, m=3, num=0, incremento=0, num2=0;
    
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("Ingrese un numero : ");
            scanf("%d" ,&num);
            num2 = num;
            matriz[i][j] = num2;
        }
    }
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    printf("----------------------\n");
    //primera fila
    printf("primera fila\n");
    for(i=0; i<1; i++){
        for(j=0; j<n; j++){
            printf("%d ",matriz[0][j]);
        }
        printf("\n");
    }
    //ultima fila
    printf("----------------------\n");
    printf("segunda fila\n");
    for(i=0; i<1; i++){
        for(j=0; j<n; j++){
            printf("%d ",matriz[2][j]);
        }
        printf("\n");
    }
}

int main(){
    ejercicio1();
}
