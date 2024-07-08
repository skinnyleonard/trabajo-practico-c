#include <stdio.h>
#include <iostream>
using namespace std;
//Fernandez Jesus compilado en onlinegdb
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
    ejercicio2();
}