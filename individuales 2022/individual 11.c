#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define MP 3	/* Numero de monoplazas */
#define MV 4	/* Numero maximo de vueltas */
#define MS 3	/* Numero de sesiones de entrenamiento */

/* Diseño Preliminar */
/* Nuevos tipos de datos */
typedef double tipo_tabla[MS][MV];
typedef tipo_tabla tipo_cubo[MP];

/* prototipos de funciones */
void leer_tiempos(tipo_cubo v);
void escribir_tiempos(tipo_cubo v);
void escribir_mejores_tiempos(tipo_cubo v);
void escribir_tabla_tiempos(tipo_cubo v);

/* Diseño Detallado */
/* Definiciones de funciones */
int main(){
	char c;
	tipo_cubo v;

	do{ system("cls");
		printf("SESIONES LIBRES DE ENTRENAMIENTO\n");
		leer_tiempos(v);
		escribir_tiempos(v);
		escribir_mejores_tiempos(v);
		escribir_tabla_tiempos(v);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}

void leer_tiempos(tipo_cubo v){
	int i,j,k;

	system("cls");
	printf("REGISTRO DE TIEMPOS\n");
	printf("===================\n\n");
	for(i=0;i<MP;++i){
		printf("\tPrototipo nº %d\n",i+1);
		for(j=0;j<MS;++j){
			printf("\t\tSesion nº %d\n",j+1);
			for(k=0;k<MV;++k){
				do{	printf("\t\t\tVuelta nº %d: ",k+1);
					scanf(" %lf", &v[i][j][k]);
				}while(v[i][j][k]<0);
			}
		}
	}
}

void escribir_tiempos(tipo_cubo v){
	int i,j,k;

	system("cls");
	printf("REGISTRO DE TIEMPOS\n");
	printf("===================\n\n");
	for(i=0;i<MP;++i){
		printf("\tPrototipo nº %d\n",i+1);
		for(j=0;j<MS;++j){
			printf("\t\tSesion nº %d\n",j+1);
			for(k=0;k<MV;++k){
				printf("\t\t\tVuelta nº %d: %10.2f\n",k+1,v[i][j][k]);
			}
		}
	}
	getch();
}

void escribir_mejores_tiempos(tipo_cubo v){
	int i,j,k;
	float min;
	int jmin,kmin;

	system("cls");
	printf("MEJORES TIEMPOS REGISTRADOS\n");
	printf("===========================\n\n");
	printf("Prototipo  Tiempo minimo  Nº sesion  Nº vuelta\n");
	printf("=========  =============  =========  =========\n");
	for(i=0;i<MP;++i){
		min=1e300;
		jmin=0;
		kmin=0;
		for(j=0;j<MS;++j){
			for(k=0;k<MV;++k){
				if((v[i][j][k])&&(v[i][j][k]<min)){
					min=v[i][j][k];
					jmin=j;
					kmin=k;
				}
			}
		}
		if(min<1e300){
			printf("%9d %13.2f  %9d  %9d\n",i+1,v[i][jmin][kmin],jmin+1,kmin+1);
		}else{ printf("%9d Sin datos registrados\n",i+1);
		}
	}
	getch();
}

void escribir_tabla_tiempos(tipo_cubo v){
	int i,j,k,cont,contt;
	float suma,media,sumat;

	system("cls");
	printf("TABLA RESUMEN TIEMPOS MEDIOS POR VUELTA\n");
	printf("=======================================\n\n");
	printf("Prototipo             Nº Sesion\n");
	printf("%10s"," ");
	for(i=0;i<MS;++i){
		printf("%10d",i+1);
	}
	printf("%10s\n","TOTAL");
	for(i=0;i<MP;++i){
		printf("%5d%5s",i+1," ");
		sumat=0;
		contt=0;
		for(j=0;j<MS;++j){
			suma=0;
			cont=0;
			for(k=0;k<MV;++k){
				if(v[i][j][k]!=0){
					suma+=v[i][j][k];
					++cont;
				}
			}
			contt+=cont;
			sumat+=suma;
			if(cont){
				media=suma/cont;
				printf("%10.3f",media);
			}else{
				printf("%10s","S.D. ");
			} 	
		}
		if(contt){
			media=sumat/contt;
			printf("%10.3f",media);
		}else{
			printf("%10s","S.D. ");
		}
		printf("\n");
	}
	getch();
}