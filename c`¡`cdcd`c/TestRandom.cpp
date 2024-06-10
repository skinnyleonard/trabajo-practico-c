#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	srand(time(NULL));
	int Bot, Yo, BotPT = 0, YoPT = 0, BotP = 0, YoP = 0, i, n = 3, m = 3, j;
	
	for (j = 0 ; j < n ; j++) //Bucles
	{
		for (i = 0 ; i < m ; i++)
		{
		Bot = 1 + rand() % (4 - 1);
		printf ("Juego: Jugador: %d - Bot: %d\n", YoPT, BotPT); //Muestra de puntuacion actual
		printf ("Ronda: Jugador: %d - Bot: %d\n", YoP, BotP);
		printf ("Piedra Papel o Tijeras (1-2-3) (Ronda %d - Round %d): ", j, i);
		scanf("%d", &Yo);
		
		//Verificar que sea valido, si no es, pierde por tramposo
		if (Yo < 1 || Yo > 3)
			{
			printf("Perdiste la ronda por tramposo\n");
			BotP = BotP + 1;
			}
		
		//Si el valor es valido.
		else
		{	
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
						printf("Empate, va de vuelta\n");
						i = i - 1;
						break;
						}	
						
						case 2: //Piedra - Papel
						{
						printf("Perdiste la ronda\n");
						BotP = BotP + 1;
						break;			
						}
						
						case 3: //Piedra - Tijera
						{
						printf("Ganaste la ronda\n");
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
						printf("Ganaste la ronda\n");
						YoP = YoP + 1;
						break;
						}	
						
						case 2: //Papel - Papel
						{
						printf("Empate, va de vuelta\n");
						i = i - 1;
						break;		
						}
						
						case 3: //Papel - Tijera
						{
						printf("Perdiste la ronda\n");
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
						printf("Perdiste la ronda\n");
						BotP = BotP + 1;
						break;
						}	
						
						case 2: //Tijera - Papel
						{
						printf("Ganaste la ronda\n");
						YoP = YoP + 1;
						break;			
						}
						
						case 3: //Tijera - Tijera
						{
						printf("Empate, va de vuelta\n");
						i = i - 1;
						break;
						}
					}
				break;
				}		
			}
		
		}
		//Chequeo de si gano el juego
		if (YoP == 2)
		{
			YoP == 0;
			BotP == 0;
			YoPT = YoPT + 1;
			printf ("Ganaste el juego");
			i = 3;
		}
		else if (BotP == 2)
			YoP == 0;
			BotP == 0;
			BotPT = BotPT + 1;
			printf ("Botberto gano el juego");
			i = 3;
		}
	if (YoPT == 3)
	{
	printf ("Ganaste la partida");	
	j = 3;
	}		
	else if (BotPT == 3)
	{
	printf ("El Botberto gano la partida");
	j = 3;	
	}		
			
	}
	
	}

	
