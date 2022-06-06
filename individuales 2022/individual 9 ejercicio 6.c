#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define PI (4*atan(1))

/* Diseño Preliminar */
/* Prototipos de funciones */
double calcular_er(double a, long int n);
double elongacion_maxima(double prec, double er);
void escribir_tabla(double elo, double prec);

/* Diseño Detallado */
/* Definiciones de funciones */
int main(){
	char c;
	double prec,er,elo;

	do{	system("cls");
		printf("ERRORES RELATIVOS PERIODO OSCILACION PENDULO SIMPLE\n");
		printf("===================================================\n\n");
		do{	printf("Error relativo maximo: ");
			scanf(" %lf", &er);
		}while(er<=0);
		do{	printf("Precision: ");
			scanf(" %lf",&prec);
		}while(prec<=0);
		elo=elongacion_maxima(prec,er);
		printf("\n\nLa maxima elongacion es: %.3f   Error relativo: %.5f\n",elo,er);
		escribir_tabla(elo,prec);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}

double elongacion_maxima(double prec, double er){
	double elo,error;

	elo=0;
	error=0;
	while(error<er){
		elo+=prec;
		error=calcular_er(elo,1000);
	}
	elo-=prec;
   return(elo);
}

void escribir_tabla(double elo, double prec){
	long int j;
	double ang;

	printf("%4s"," ");
	for(j=1;j<10000;j*=10){
		printf("%20d",j);
	}
	printf("\n");
	ang=0.0;
	while(ang<=elo){
		printf("%5.3f",ang);
		for(j=1;j<10000;j*=10){
			printf("%20.15f",calcular_er(ang,j));
		}
		printf("\n");
		ang+=prec;
	}
}

double calcular_er(double a, long int n){
	double suma;
	double x,y;
	long int i;

	suma=0;
	x=1;
	a=a*PI/180;
	y=sin(a/2)*sin(a/2);
	for(i=1;i<=n;++i){
		x=x*(2.0*i-1)*(2.0*i-1)/(4.0*i*i)*y;
    	suma+=x;
	}
	return(suma);