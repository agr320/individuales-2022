#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define MAX_CAP 100000.0 // Máximo capital prestamo
#define MAX_ANNOS 50	 // Máximo numero de años
#define MAX_INT 15.0     // Máximo interés (%)

/* Diseño Preliminar */
/* Prototipos de funciones */
void leer_datos(double *c, int *na, char *tc,double *ia);
void leer_capital(double *c);
void leer_annos(int *na);
void leer_tipo_cuota(char *c);
void leer_interes(double *ia);
void tabla_amortizacion(double c,int na,char tc,double ia);
int num_plazos_anno(char tc);
double cuota_plazo(double c, double i, int n);
void cabecera(double c,double ia,int na,int n);
void resumen_anual(int i,double sumac,double sumai,double totalc,double totali);

/* Diseño Detallado */
/* Definiciones de funciones */
int main(){
	char cc;
	double c,ia;
	int na;
	char tc;
	
	do{ system("cls");
		printf("Datos del prestamo:\n");
		printf("===================\n\n");
		leer_datos(&c,&na,&tc,&ia);
		tabla_amortizacion(c,na,tc,ia);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		cc=toupper(getch());
	}while(cc!='N');
	return 0;
}

void leer_datos(double *c, int *na, char *tc,double *ia){
	leer_capital(c);
	leer_annos(na);
	leer_tipo_cuota(tc);
	leer_interes(ia);
}

void leer_capital(double *c){
	do{	printf("\tCapital (0-%.0f): ",MAX_CAP);
		scanf(" %lf", c);
	}while((*c<=0)||(*c>MAX_CAP));
}

void leer_annos(int *na){
	do{	printf("\tNumero de años (1-%d): ",MAX_ANNOS);
		scanf(" %d", na);
	}while((*na<1)||(*na>MAX_ANNOS));
}

void leer_tipo_cuota(char *c){
	do{	printf("\tTipo de cuota: (A)nual, (S)emestral, (C)uatrimestral,\n");
		printf("\t              (T)rimestral, (M)ensual: ");
		scanf(" %c", c);
		*c=toupper(*c);
	}while((*c!='A')&&(*c!='S')&&(*c!='C')&&(*c!='T')&&(*c!='M'));
}

void leer_interes(double *ia){
	do{	printf("Tipo de interes anual (0-%.2f%%): ",MAX_INT);
		scanf(" %lf",ia);
	}while((*ia<0)||(*ia>MAX_INT));
}

double cuota_plazo(double c, double i, int n){
	double x;

	x=pow(1+i,n);
	return(c*i*x/(x-1));
}

int num_plazos_anno(char tc){
	int npa;

	switch(tc){
	case 'A':	npa=1;
				break;
	case 'S':	npa=2;
				break;
	case 'C':	npa=3;
				break;
	case 'T':	npa=4;
				break;
	case 'M':	npa=12;
				break;
	}
	return npa;
}

void tabla_amortizacion(double c,int na,char tc,double ia){
	double cuota,ip;
	int npa,n;
	double cap_pen,cap_amo,int_pag;
	double sumac,sumai,totalc,totali;
	int i,j;

	npa=num_plazos_anno(tc);
	ip=ia/(100*npa);
	n=na*npa;
	cuota=cuota_plazo(c,ip,n);
	cap_pen=c;
	totalc=totali=0;
	for(i=1;i<=na;++i){
		cabecera(c,ia,na,n);
		sumac=sumai=0;
		for(j=1;j<=npa;++j){
			int_pag=cap_pen*ip;
			cap_amo=cuota-int_pag;
			cap_pen=cap_pen-cap_amo;
			sumac+=cap_amo;
			sumai+=int_pag;
			printf("%8d %10.2f %10.2f %10.2f %13.2f\n",
		        j+(i-1)*npa,cuota,cap_amo,int_pag,cap_pen);
		}
		totalc+=sumac;
		totali+=sumai;
		resumen_anual(i,sumac,sumai,totalc,totali);
		getch();
	}
	getch();
}

void cabecera(double c,double ia,int na,int n){
	system("cls");
	printf("\t\tCapital:         %10.2f\n",c);
	printf("\t\tInteres anual:   %10.2f %%\n",ia);
	printf("\t\tNumero años:     %7d\n",na);
	printf("\t\tNumero plazos:   %7d\n\n",n);
	printf("Nº plazo      Cuota  Cap_amort  Intereses Cap_pendiente\n");
}

void resumen_anual(int i,double sumac,double sumai,double totalc,double totali){
	printf("\n\tAño nº: %d\n",i);
	printf("\t\tCapital amortizado: %10.2f\n",sumac);
	printf("\t\tIntereses pagados:  %10.2f\n",sumai);
	printf("\tCapital total amortizado:   %10.2f\n",totalc);
	printf("\tIntereses totales pagados:  %10.2f\n",totali);