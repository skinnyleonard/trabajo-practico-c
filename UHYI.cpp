#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

char matriz[10][10], opt;
int i=0, n=10, j=0, player=0;

static void iniciarJuego(){
	//diseñar la matriz
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			matriz[i][j] = 'X';
		}
	}
	//posicionar personaje
	for(i=0;i<n;i++){
		matriz[player][player] = 'P';
		matriz[player][player+1] = 'P';
		matriz[player+1][player] = 'P';
		matriz[player+1][player+1] = 'P';
	}
}
static void dibujarTablero(){
	//system("cls") sirve para que puedan verse los colores en ascii desde dev++
	system("cls");
	//dibujar y colorear la matriz
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			switch(matriz[i][j]){
				case 'X':{
					cout << "\x1b[33m";
					cout << "\x1b[43m";
					break;
				}
				case 'P':{
					cout << "\x1b[34m";
					cout << "\x1b[44m";
					break;
				}
			}
			printf("%c ", matriz[i][j]);
		}
		printf("\n");
		cout << "\x1b[0m";
	}
}
static void jugar(){
	printf("arriba = W // abajo = S\n");
	scanf("%c" ,&opt);
	switch(opt){
		case 'w':{
			break;
		}
		case 's':{
			for(i=0; i<n; i++){
				for(j=0; j<n; j++){
					matriz[i][j] = 'X';
				}
			}
			for(i=0;i<n;i++){
				matriz[player+1][player] = 'P';
				matriz[player+2][player] = 'P';
				matriz[player+1][player+1] = 'P';
				matriz[player+2][player+1] = 'P';
			}
			dibujarTablero();
			break;
		}
	}
}

int main(){
	system("cls");
	iniciarJuego();
	dibujarTablero();
	jugar();
}
