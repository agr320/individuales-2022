#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define MAX 5

/* Diseño Preliminar */
/* Nuevos tipos de datos */
typedef double tipo_vector[MAX];

/* Prototipos de funciones */
void leer_opcion(char *c);
void insertar_punto(tipo_vector x,tipo_vector y,int *n);
void leer_punto(double *x, double *y);
void imprimir_puntos(tipo_vector x,tipo_vector y,int n);
void eliminar_punto(tipo_vector x,tipo_vector y,int *n);
void leer_entero_rango(int a,int b,int *m);
void imprimir_recta_regresion(tipo_vector x,tipo_vector y,int n);

/* Diseño Detallado */
/* Definiciones de funciones */
int main(){
	char c;
	tipo_vector x,y;
	int n;

	n=0;
	do{	leer_opcion(&c);
		switch(c){
		case '1': 	insertar_punto(x,y,&n);
					break;
		case '2': 	imprimir_puntos(x,y,n);
					getch();
					break;
		case '3': 	eliminar_punto(x,y,&n);
					break;
		case '4': 	imprimir_recta_regresion(x,y,n);
					break;
		case '0': 	printf("\n\nFIN DE EJECUCION\n");
					getch();
					break;
		default: 	printf("\a");
					break;
		}
	}while (c!='0');
	return 0;
}

void leer_opcion(char *c){
	system("cls");
	printf("MENU OPCIONES PARA RECTA REGRESION\n");
	printf("==================================\n\n");
	printf("\t1.- Insertar un nuevo punto experimental\n");
	printf("\t2.- Imprimir en pantalla listado numerado de puntos\n");
	printf("\t3.- Eliminar un punto\n");
	printf("\t4.- Recta de regresion\n");
	printf("\t0.- Finalizar programa\n\n");
	printf("\t\tIntroduzca opcion: ");
	*c=getch();
}

void insertar_punto(tipo_vector x,tipo_vector y,int *n){
	char c;

	do{	system("cls");
		printf("INSERCION DE PUNTOS\n");
		printf("===================\n\n");
		if((*n)==MAX){
			printf("\nVector lleno\n");
			getch();
		}else{ 
			leer_punto(&x[*n],&y[*n]);
			(*n)++;
			if((*n)<MAX){
				printf("\n\nDesea introducir mas puntos (s/n)? ");
				c=toupper(getch());
			}
		}
	}while(((*n)<MAX)&&(c=='S'));
}

void leer_punto(double *x, double *y){
	printf("\nIntroduzca nuevo punto:\n");
	printf("\tVariable x: ");
	scanf(" %lf",x);
	printf("\tVariable y: ");
	scanf(" %lf",y);
}

void imprimir_puntos(tipo_vector x,tipo_vector y,int n){
	int i;

	system("cls");
	printf("Listado de puntos:\n");
	printf("==================\n\n");
	for(i=0;i<n;++i){
		printf("\t%3d.- (%.2lf,%.2lf)\n",i+1,x[i],y[i]);
	}
	printf("\n\n");
}

void eliminar_punto(tipo_vector x,tipo_vector y,int *n){
	int i,j;
	char c;

	do{	system("cls");
		printf("Eliminacion de puntos\n");
		printf("=====================\n\n");
		if(*n){
			imprimir_puntos(x,y,*n);
			printf("Introduzca nº punto a eliminar:\n");
			leer_entero_rango(1,*n,&j);
			for(i=j;i<(*n);++i){
				x[i-1]=x[i];
				y[i-1]=y[i];
			}
			(*n)--;
			if(*n){
				printf("\n\nDesea eliminar otro punto (s/n)? ");
				c=toupper(getch());
			}
		}else{	
			printf("\nVector vacio\n");
			getch();
		}
	}while((*n)&&(c=='S'));
}

void leer_entero_rango(int a,int b,int *m){
    int aux;

    if(a>b){
        aux=a;
        a=b;
        b=aux;
    }
    do{ printf("\tIntroduzca entero [%d,%d]: ",a,b);
        scanf(" %d",m);
    }while((*m<a)||(*m>b));
}

void imprimir_recta_regresion(tipo_vector x,tipo_vector y,int n){
	int i;
	double sx,sy,sxy,sx2,sy2,a,b,r;
	double denx,deny,num;

	system("cls");
	sx=sy=sxy=sx2=sy2=0;
	printf("RECTA DE REGRESION\n");
	printf("==================\n\n");
	if(n>1){ 
		for(i=0;i<n;++i){
			sx+=x[i];
			sy+=y[i];
			sxy+=x[i]*y[i];
			sx2+=x[i]*x[i];
			sy2+=y[i]*y[i];
		}
		denx=n*sx2-sx*sx;
		deny=n*sy2-sy*sy;
		if(denx){
			if(deny){ 
				num=n*sxy-sx*sy;
				b=num/denx;
				a=sy/n-b*sx/n;
				r=num/sqrt(denx*deny);
				printf("Recta de regresion: y = %.2lf + %.2lf * x\n",a,b);
				printf("r = %.2lf\n",r);
			}else{ 
				printf("Recta de regresion: y=%.2lf\n",y[0]);
				printf("r indeterminado\n");
			}
		}else{ 
			if(deny){ 
				printf("Recta de regresion: x=%.2lf\n",x[0]);
				printf("r indeterminado\n");
			}else{
				printf("Todos los puntos son iguales\n");
				printf("r indeterminado\n");
			}
		}
	}else{
		if(n){ 
			printf("Solo hay un punto experimental\n");
		}else{ 
			printf("Ningun punto introducido\n");
		}
	}
	getch();