#include <stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	srand(time(NULL));
	int Bot, Yo, BotPT=0, YoPT=0, BotP=0, YoP=0, i=0, n=5, m=3, j=0;
	
	for (j=0; j<n; j++) //Bucles Juegos
	{
		for (i=0; i<m; i++){ //Bucles Rounds
		Bot = 1 + rand() % (4 - 1);
		printf ("\nJuego: Jugador: %d - Bot: %d\n", YoPT, BotPT); //Muestra de puntuacion actual
		printf ("Ronda: Jugador: %d - Bot: %d\n", YoP, BotP);
		printf ("Piedra Papel o Tijeras (1-2-3) (Juego %d): ", j+1);
		scanf("%d", &Yo);
		
		//Verificar que sea valido, si no es, pierde por tramposo
		if (Yo < 1 || Yo > 3){
		    printf("Perdiste la ronda por tramposo\n");
			BotP = BotP + 1;
		}
		
		//Si el valor es valido.
		else{	
		//Dialogo (para meterle mas inmersion y ver mejor la situacion)
		switch (Yo) 
		{	//Dialogo Jugador
			case 1:
			{
			printf("Vos: Piedra\n");
			break;
			}
			case 2:
			{
			printf("Vos: Papel\n");
			break;
			}
			case 3:
			printf("Vos: Tijera\n");
			break;
		}
		
		switch(Bot) //Dialogo Bot
		{
			case 1:
			{
			printf("Botberto: Piedra\n");
			break;
			}
			case 2:
			{
			printf ("Botberto: Papel\n");
			break;
			}
			case 3:
			{
			printf ("Botberto: Tijera\n");
			break;	
			}
		}
			switch(Yo)
			{
			//Ruta tomada	
				case 1: //Piedra
				{
					switch(Bot)
					{
						case 1: //Piedra - Piedra
						{
						printf("- Empate, va de vuelta -\n");
						i = i - 1;
						break;
						}	
						
						case 2: //Piedra - Papel
						{
						printf("- Perdiste la ronda -\n");
						BotP = BotP + 1;
						break;			
						}
						
						case 3: //Piedra - Tijera
						{
						printf("- Ganaste la ronda -\n");
						YoP = YoP + 1;
						break;
						}
					}
				break;
				}
				case 2: //Papel
				{
					switch(Bot)
					{
						case 1: //Papel - Piedra
						{
						printf("- Ganaste la ronda -\n");
						YoP = YoP + 1;
						break;
						}	
						
						case 2: //Papel - Papel
						{
						printf("- Empate, va de vuelta -\n");
						i = i - 1;
						break;		
						}
						
						case 3: //Papel - Tijera
						{
						printf("- Perdiste la ronda -\n");
						BotP = BotP + 1;
						break;
						}
					}
				break;
				}
				case 3: //Tijera
				{
					switch(Bot)
					{
						case 1: //Tijera - Piedra
						{
						printf("- Perdiste la ronda -\n");
						printf("--------------------\n");
						BotP = BotP + 1;
						break;
						}	
						
						case 2: //Tijera - Papel
						{
						printf("- Ganaste la ronda -\n");
						printf("--------------------\n");
						YoP = YoP + 1;
						break;			
						}
						
						case 3: //Tijera - Tijera
						{
						printf("- Empate, va de vuelta -\n");
						printf("--------------------\n");
						i = i - 1;
						break;
						}
					}
				break;
				}		
			}
		
		}
		//Chequeo de si gano el juego
		if (YoP == 2){
			YoP = 0;
			BotP = 0;
			YoPT = YoPT + 1;
			printf ("+ Ganaste el juego +\n");
			printf("--------------------\n");
			i = 3;
		}
		else if (BotP == 2){
			YoP = 0;
			BotP = 0;
			BotPT = BotPT + 1;
			printf ("+ Botberto gano el juego +\n");
			printf("--------------------\n");
			i = 3;
		}
	}
	if (YoPT == 3){
    	printf ("Ganaste la partida");	
    	j = 5;
    	break;
	}		
	else if (BotPT == 3){
    	printf ("El Botberto gano la partida");
    	j = 5;
		break;	
	}		
			
	}
	
	}

	
