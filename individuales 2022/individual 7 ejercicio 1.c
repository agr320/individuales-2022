#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

/* Diseño Preliminar */
/* Prototipos de funciones */
int suma_cifras(int n);
int suma_cifras2(int n);

/* Definiciones de funciones */
int main(){
	char c;
	int n;

	do{ system("cls");
		printf("SUMA DE DIGITOS NUMERO ENTERO\n");
		printf("=============================\n\n");
		do{	printf("Introduzca numero entero positivo: ");
			scanf(" %d", &n);
		}while(n<0);
		printf("\n\nSuma digitos (version recursiva):    %d",suma_cifras(n));
		printf("\n\nSuma digitos (version no recursiva): %d",suma_cifras2(n));
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}

int suma_cifras(int n){
	if(n<10)
		return(n);
	else return(n%10+suma_cifras(n/10));
}

int suma_cifras2(int n){
	int suma;

	suma=0;
	while(n>0){
		suma+=n%10;
		n=n/10;
	}
   return(suma);
}