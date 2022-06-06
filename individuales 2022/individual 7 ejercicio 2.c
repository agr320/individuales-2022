#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

/* Diseño Preliminar */
/* Prototipos de funciones */
void escribir_binario(int n);

/* Definiciones de funciones */
int main(){
	char c;
	int n;

	do{ system("cls");
		printf("CONVERSION DECIMAL --> BINARIO\n");
		printf("==============================\n\n");
		do{	printf("Introduzca entero positivo: ");
			scanf(" %d",&n);
		}while(n<0);
		escribir_binario(n);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}

void escribir_binario(int n){
	if(n<2){
			printf("%d",n);
	}else{	escribir_binario(n/2);
			printf("%d",n%2);
	}