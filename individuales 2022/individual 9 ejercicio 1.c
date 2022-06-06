#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define LB  100.0        /* Longitud del brazo      */
#define LA   75.0        /* Longitud del antebrazo  */
#define ANG_MAX  150.0   /* Angulo maximo antebrazo */

/* Diseño Preliminar */
/* Prototipos de funciones */
void leer_posicion_final(double rmin, double rmax, double *x, double *y);
void calcular_posicion_angular(double x, double y, double *a, double *b);
void cartesianas_polares(double x, double y, double *r, double *zeta);
double angulo_triangulo(double a, double b, double c);
void calcular_desplazamiento_angular(double *a0, double *b0, double a, double b, double *da, double *db);
void escribir_posicion_angular(double da, double db, double a, double b);

/* Diseño Detallado */
/* Definiciones de funciones */
int main(){
	char c;
	double a0,b0,a,b,da,db;
	double x,y;
	double rmin,rmax;

	a0=0;
	b0=0;
	rmin=sqrt(LA*LA+LB*LB+2*cos(ANG_MAX*M_PI/180)*LA*LB);
	rmax=LA+LB;
	do{ system("cls");
		printf("BRAZO ROBOT ARTICULADO\n");
		printf("======================\n\n");
		leer_posicion_final(rmin,rmax,&x,&y);
		calcular_posicion_angular(x,y,&a,&b);
		calcular_desplazamiento_angular(&a0,&b0,a,b,&da,&db);
		escribir_posicion_angular(da,db,a,b);
	}while(x||y);
	return 0;
}

void leer_posicion_final(double rmin, double rmax, double *x, double *y){
	double r;

	printf("Posicion final (0,0) para terminar: \n");
	printf("\tx: ");
	scanf(" %lf",x);
	printf("\ty: ");
	scanf(" %lf",y);
	r=sqrt((*x)*(*x)+(*y)*(*y));
	while(((r<rmin)||(r>rmax))&&((*x)||(*y))){
		printf("Posición final inalcanzable\n");	
		printf("Posicion final (0,0) para terminar: \n");
		printf("\tx: ");
		scanf(" %lf",x);
		printf("\ty: ");
		scanf(" %lf",y);
		r=sqrt((*x)*(*x)+(*y)*(*y));
	}
}

void calcular_posicion_angular(double x, double y, double *a, double *b){
	double r,zeta;
	if((x==0)&&(y==0)){
		*a=0;
		*b=0;
	}else{
		cartesianas_polares(x,y,&r,&zeta);
		*a=zeta-angulo_triangulo(LA,r,LB);
		*b=180-angulo_triangulo(r,LA,LB);
		if(*a<0){
			*a+=360;
		}
	}
}

void cartesianas_polares(double x, double y, double *r, double *zeta){
	*r=sqrt(x*x+y*y);
	if(*r){ *zeta=180*asin(y/(*r))/M_PI;
			if(x<0){
				*zeta=180-(*zeta);
			}
	}else{
		*zeta=0;
	}
}

double angulo_triangulo(double a, double b, double c){
	/*Devuelve el ángulo en grados opuesto al lado a */
	return(acos((b*b+c*c-a*a)/(2*b*c))*180/M_PI);
}

void calcular_desplazamiento_angular(double *a0, double *b0, double a, double b, double *da, double *db){
	*db=b-(*b0);
	*da=a-(*a0);
	if(*da>180){
		*da=*da-360;
	}else{
		if(*da<-180){
			*da=360+(*da);
		}
	}
	*a0=a;
	*b0=b;
}

void escribir_posicion_angular(double da, double db, double a, double b){
	printf("Desplazamiento angular:\n");
	printf("\tBrazo:      %7.3f\n",da);
	printf("\tAntebrazo:  %7.3f\n",db);
	printf("Posicion angular final:\n");
	printf("\tBrazo:      %7.3f\n",a);
	printf("\tAntebrazo:  %7.3f\n",b);
   getch();
}