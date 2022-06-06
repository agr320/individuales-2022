#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

/* Diseño Preliminar */
/* prototipos de funciones */
double f(double x,double y);
double integral_doble(double (*f)(double x,double y),double xmin,double xmax,
							 double ymin,double ymax,int m,int n);

/* Definiciones de funciones */
int main(){
	char c;
	double xmin,xmax,ymin,ymax;
	int m,n;

	do{ system("cls");
		printf("INTEGRAL DOBLE\n");
		printf("==============\n\n");
		printf("Introduzca limites del rectangulo:\n");
		printf("\txmin: ");
		scanf(" %lf",&xmin);
		do{	printf("\txmax: ");
			scanf(" %lf",&xmax);
		}while(xmax<=xmin);
		printf("\tymin: ");
		scanf(" %lf",&ymin);
		do{	printf("\tymax: ");
			scanf(" %lf",&ymax);
		}while(ymax<=ymin);
		do{	printf("Nº de divisiones x: ");
			scanf(" %d", &m);
		}while(m<=0);
		do{	printf("Nº de divisiones y: ");
			scanf(" %d", &n);
		}while(n<=0);
		printf("\nVolumen encerrado: %.15f",integral_doble(f,xmin,xmax,ymin,ymax,m,n));
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
	return 0;
}

double integral_doble(double (*f)(double x,double y),double xmin,double xmax,
							 double ymin,double ymax,int m,int n){
	double vol;
	int i, j;
	double hx,hy;
	double xi,yi;

	hx=(xmax-xmin)/m;
	hy=(ymax-ymin)/n;
	vol=0;
	xi=xmin+0.5*hx;
	for(i=0;i<m;++i){
		yi=ymin+0.5*hy;
		for(j=0;j<n;++j){
			vol+=f(xi,yi);
			yi+=hy;
		}
		xi+=hx;
	}
	return(vol*hx*hy);
}

double f(double x,double y){
	//return(log(x+2*y));
	//return 1;
	//return (x+y);
	return (x*x+y*y);
}