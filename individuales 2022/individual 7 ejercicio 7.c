#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

/* Diseño Preliminar */
/* Prototipos de funciones */
int newton_raphson(double (*f)(double x),double x0,double h,int n,double *x);
double derivada(double (*f)(double x), double x0, double h);
double f(double x);

/* Definiciones de funciones */
int main(){
	char c;
	double x0,h,x;
	int n,cod;

	do{ 	system("cls");
			printf("METODO DE NEWTON-RAPHSON PARA SOLUCION f(x)=0\n");
			printf("=============================================\n\n");
			printf("Introduzca valor inicial (x0): ");
			scanf(" %lf", &x0);
			do{ printf("Introduzca precision: ");
					scanf(" %lf",&h);
			}while(h<=0);
			do{	printf("Introduzca nº maximo de iteraciones: ");
					scanf(" %d",&n);
			}while(n<=0);
			cod=newton_raphson(f,x0,h,n,&x);
			switch(cod){
			case -1: printf("Encontrada derivada nula\n");
					printf("Ultima aproximacion encontrada: %.6lf\n",x);
					break;
			case 0: printf("Excedido nº maximo de iteraciones\n");
					printf("Ultima aproximacion encontrada: %.6lf\n",x);
					break;
			case 1: printf("Solucion aproximada: %.6lf",x);
					break;
			}
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
	return 0;
}

int newton_raphson(double (*f)(double x),double x0,double h,int n,double *x){
	double xi,xsig;
	double d;
	int i,cod;

	xi=x0;
	d=derivada(f,xi,h);
	if(d){
		xsig=xi-f(xi)/d;	
	}else{
		xsig=xi;
	}
	i=1;
	while(d&&(fabs(xi-xsig)>=h)&&(i<=n)){
		xi=xsig;
		d=derivada(f,xi,h);
		if (d){
			xsig=xi-f(xi)/d;
			++i;
		}
	}
	if(!d){
		cod=-1;
	}else{
		if (i>n){
			cod=0;
		}else{	cod=1;
		}
	}
	*x=xsig;
	return(cod);
}

double derivada(double (*f)(double x), double x0, double h){
	return((8*(f(x0+h)-f(x0-h))-(f(x0+2*h)-f(x0-2*h)))/(12*h));
}

double f(double x){
	//return (x*x*x-3*x*x+5);
	return(x*x-1);
	//return(x*x+1);
	//return (exp(-x*x));
	//return(sin(x)*exp(-x));
}