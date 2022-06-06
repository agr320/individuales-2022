include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

/* DISEÑO PRELIMINAR */
/* Nuevos tipos de datos */
typedef long tipo_contadores[3];
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
		printf("LANZAMIENTO DE DOS MONEDAS\n");
		printf("==========================\n\n");
		do{	printf("Introduzca nº de lanzamientos de las dos monedas: ");
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
	for(i=0;i<3;++i){
		v[i]=0;
	}
}

void simular_lanzamientos(tipo_contadores v,long n){
	long i;
	int j;
	for(i=0;i<n;++i){
		j=rand()%2;
		j+=rand()%2;
		v[j]++;
	}
}

void escribir_resultados(tipo_contadores v,long n){
	int i;

	printf("\n\nPorcentaje de veces que ha salido:\n");
	for (i=0;i<3;++i){
		printf("%d caras: %.2lf\n",i,100.0*v[i]/n);
	}