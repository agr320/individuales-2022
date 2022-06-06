#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

/* Diseño Preliminar */
/* Prototipos de funciones */
double integral_definida(double (*f)(double x),double a,double b,double base);
double f(double x);

/* Definiciones de funciones */
int main(){
	char c;
	double a,b,base,area;

	do{ system("cls");
		printf("INTEGRAL DEFINIDA EN UN INTERVALO\n");
		printf("=================================\n\n");
		printf("Prueba función: f(x)\n\n");
		printf("Introduzca intervalo de integracion:\n");
		printf("\tlimite izquierdo: ");
		scanf(" %lf",&a);
		do{	printf("\tlimite derecho: ");
			scanf(" %lf",&b);
		}while(b<=a);
		do{	printf("Introduzca valor de incremento (base): ");
			scanf(" %lf", &base);
		}while ((base<=0)||(base>b-a));
		area=integral_definida(f,a,b,base);
		printf("\nIntegral definida: %.6lf",area);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}

double integral_definida(double (*f)(double x),double a,double b,double base){
	double x,suma,area;

	suma=0;
	x=a;
	while(x+base<b){
		area=base*(f(x)+f(x+base))/2;
		suma+=area;
		x+=base;
	}
	area=(b-x)*(f(x)+f(b))/2;
	suma+=area;
	return suma;
}

double f(double x){
	//return(x*x*x-3*x*x+5);
	//return(exp(-x*x));
	return(sin(x)*exp(-x));