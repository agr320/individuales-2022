#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

/* DISEÑO PRELIMINAR */
/* Nuevos tipos de datos */
typedef long tipo_contadores[6];
/* prototipos de funciones */
void inicializar_contadores(tipo_contadores v);
void simular_lanzamientos(tipo_contadores v,long n);
void escribir_resultados(tipo_contadores v,long n);

/* DISEÑO DETALLADO */
/* Definiciones de funciones */
int main(){
	char c;
	long n;
	tipo_contadores v;
	time_t t;

	srand((unsigned) time(&t));
	do{ system("cls");
		printf("LANZAMIENTO DE DADO\n");
		printf("===================\n\n");
		do{ printf("Introduzca nº de lanzamientos del dado: ");
			scanf(" %ld", &n);
		}while(n<=0);
		inicializar_contadores(v);
		simular_lanzamientos(v,n);
		escribir_resultados(v,n);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}

void inicializar_contadores(tipo_contadores v){
	int i;
	for(i=0;i<6;++i){
		v[i]=0;
	}
}

void simular_lanzamientos(tipo_contadores v,long n){
	long i;
	int j;
	for(i=0;i<n;++i){
		j=rand()%6;
		v[j]++;
	}
}

void escribir_resultados(tipo_contadores v,long n){
	int i;

	printf("\n\nPorcentaje de veces que ha salido cada numero:\n");
	for (i=0;i<6;++i){
		printf("Numero %d: %6.2lf\n",i+1,100.0*v[i]/n);
	}
