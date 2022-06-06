include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define N 20

/* DISEÑO PRELIMINAR */
/* Nuevos tipos de datos */
typedef struct{
	int dia;
	int mes;
	int anno;
}tipo_fecha;
typedef tipo_fecha tipo_vector[N];
/* prototipos de funciones */
void inicializar_vector(tipo_vector v);
void copiar_vector(tipo_vector v, tipo_vector v2);
void ordenar_vector(tipo_vector v);
void ordenacion_inversa(tipo_vector v);
void escribir_vector(tipo_vector v);
int es_anterior(tipo_fecha f1,tipo_fecha f2);
int es_posterior(tipo_fecha f1,tipo_fecha f2);


/* DISEÑO DETALLADO */
/* Definiciones de funciones */
int main(){
	char c;
	tipo_vector v,v2;
	time_t t;

	srand((unsigned) time(&t));
	do{ system("cls");
		printf("CLASIFICACION DE UN VECTOR DE REGISTROS POR FECHA\n");
		printf("=================================================\n\n");
		inicializar_vector(v);
		printf("\nVector original:\n");
		escribir_vector(v);
		copiar_vector(v,v2);
		ordenar_vector(v2);
		printf("\nVector ordenado:\n");
		escribir_vector(v2);
		copiar_vector(v,v2);
		ordenacion_inversa(v2);
		printf("\nVector original:\n");
		escribir_vector(v);		
		printf("\nVector orden inverso:\n");
		escribir_vector(v2);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}

void inicializar_vector(tipo_vector v){
	int i;

	for(i=0;i<N;++i){
		v[i].dia=rand()%31+1;
		v[i].mes=rand()%12+1;
		v[i].anno=rand()%21+2000;
	}
}

void copiar_vector(tipo_vector v, tipo_vector v2){
	int i;
	for(i=0;i<N;++i)
		v2[i]=v[i];
}

void ordenar_vector(tipo_vector v){
	int i,j,k;
	tipo_fecha x;

	for(i=0;i<N-1;++i){
		k=i;
		for(j=i+1;j<N;++j)
			if(es_anterior(v[j],v[k]))
				k=j;
		x=v[i];
		v[i]=v[k];
		v[k]=x;
	}
}

void ordenacion_inversa(tipo_vector v){
	int i,j,k;
	tipo_fecha x;

	for(i=0;i<N-1;++i){
		k=i;
		for(j=i+1;j<N;++j)
			if(es_posterior(v[j],v[k]))
				k=j;
		x=v[i];
		v[i]=v[k];
		v[k]=x;
	}
}

int es_anterior(tipo_fecha f1,tipo_fecha f2){
	int res;

	res=0;
	if(f1.anno<f2.anno)
		res=1;
	else 	if (f1.anno==f2.anno)
				if(f1.mes<f2.mes)
					res=1;
				else	if(f1.mes==f2.mes)
							if(f1.dia<f2.dia)
								res=1;
	return res;
}

int es_posterior(tipo_fecha f1,tipo_fecha f2){
	int res;

	res=0;
	if(f1.anno>f2.anno)
		res=1;
	else 	if (f1.anno==f2.anno)
				if(f1.mes>f2.mes)
					res=1;
				else	if(f1.mes==f2.mes)
							if(f1.dia>f2.dia)
								res=1;
	return res;
}

void escribir_vector(tipo_vector v){
	int i;
	for(i=0;i<N;++i){
		printf("\t%2d-%2d-%4d\n",v[i].dia,v[i].mes,v[i].anno);
	}
	getch();
}