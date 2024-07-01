#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

char opt;
int i=0, n=9, j=0, k=10, P = 2, enemy[9][10];

static void dibujarMatriz()
{
system("cls");
{

for (i=0; i < n ; i++)
{
for (j = 0 ; j < k ; j++)
{
	if (j == 0 && i == 4 && P == 2)
	{
	printf ("\x1b[44m" "\x1b[34m" " P ");
	}	
	else if (j == 0 && i == 2 && P == 1)
	{
	printf ("\x1b[44m" "\x1b[34m" " P ");	
	}
	else if (j == 0 && i == 6 && P == 3)
	{
	printf ("\x1b[44m" "\x1b[34m" " P ");
	}
	else
	{
	printf ("\x1b[43m" "\x1b[33m" " X " "\x1b[0m");	
	}
}
printf ("\n");
}	

}

}

static void opcion()
{

printf ("Seleccione opcion W / S");
scanf ("%c", &opt);

switch (opt)
{
	case 'w':
		{
			if (P != 1)
			{
			P = P - 1;
			enemy = enemy  - 1;	
			break;
			}	
			else
			{
			printf ("Error\n");
			break;
			}
		}
	case 's':
		{
			if (P != 3)
			{
			P = P + 1;
			enemy = enemy  - 1;	
			break;
			}
			else
			{
			printf ("Error\n");
			break;
			}
		}

}
}





int main()
{

enemy[2][10] = 1;


while (true)
{

dibujarMatriz();

opcion();
}

}

