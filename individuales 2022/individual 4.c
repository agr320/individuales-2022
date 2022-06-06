
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int main(){
	char c;
	double a11,a12,a13,a14,a21,a22,	/* Coeficientes y terminos           */
	       a23,a24,a31,a32,a33,a34;	/* independientes sistema inicial    */
	double x,y,z;					/* Soluciones del sistema            */
	double det;						/* determinante matriz de coef.      */
	double b11,b12,b13,b21,b22,b23, /* Coeficientes sistema 1ª reducción */
	       b31,b32,b33;
	double c11,c12,c21,c22,c31,c32;	/* Coeficientes sistema 2ª reducción */

	do{ system("cls");
		printf("RESOLUCION SISTEMA LINEAL DE ECUACIONES 3x3\n");
		printf("    (Metodo de reduccion)\n");
		printf("===========================================\n\n");
		printf("\ta11 * x + a12 * y + a13 * z = a14\n");
		printf("\ta21 * x + a22 * y + a23 * z = a24\n");
		printf("\ta31 * x + a32 * y + a33 * z = a34\n");
		printf("\nIntroduzca coeficientes: \n");
		printf("\ta11: ");
		scanf(" %lf",&a11);
		printf("\ta12: ");
		scanf(" %lf",&a12);
		printf("\ta13: ");
		scanf(" %lf",&a13);
		printf("\ta14: ");
		scanf(" %lf",&a14);
		printf("\ta21: ");
		scanf(" %lf",&a21);
		printf("\ta22: ");
		scanf(" %lf",&a22);
		printf("\ta23: ");
		scanf(" %lf",&a23);
		printf("\ta24: ");
		scanf(" %lf",&a24);
		printf("\ta31: ");
		scanf(" %lf",&a31);
		printf("\ta32: ");
		scanf(" %lf",&a32);
		printf("\ta33: ");
		scanf(" %lf",&a33);
		printf("\ta34: ");
		scanf(" %lf",&a34);
		det=a11*a22*a33+a12*a23*a31+a13*a21*a32
		    -a11*a23*a32-a12*a21*a33-a13*a22*a31;
		if(det==0){
			printf("\nSistema sin solucion unica (incompatible o compatible indeterminado)\n");
		}else{
			/* Eliminamos la variable x */
			b11=a21*a12-a11*a22;
			b12=a21*a13-a11*a23;
			b13=a21*a14-a11*a24;
			b21=a31*a12-a11*a32;
			b22=a31*a13-a11*a33;
			b23=a31*a14-a11*a34;
			b31=a31*a22-a21*a32;
			b32=a31*a23-a21*a33;
			b33=a31*a24-a21*a34;
			/* Eliminamos la variable y */
			c11=b21*b12-b11*b22;
			c12=b21*b13-b11*b23;
			c21=b31*b12-b11*b32;
			c22=b31*b13-b11*b33;
			c31=b31*b22-b21*b32;
			c32=b31*b23-b21*b33;
			/* Determinamos el valor de z */
			if(c11){
				z=c12/c11;
			}else{
				if(c21){
					z=c22/c21;
				}else{
					z=c32/c31;
				}
			}
			/* Determinamos el valor de y */
			if(b11){
				y=(b13-b12*z)/b11;
			}else{
				if(b21){
					y=(b23-b22*z)/b21;
				}else{
					y=(b33-b32*z)/b31;
				}
			}
			/* Determinamos el valor de x */
			if(a11){
				x=(a14-a12*y-a13*z)/a11;
			}else{
				if(a21){
					x=(a24-a22*y-a23*z)/a21;
				}else{
					x=(a34-a32*y-a33*z)/a31;
				}
			}
			/* Presentacion de resultados */
			printf("\n\nSoluciones:\n");
			printf("\tx = %15.2f\n",x);
			printf("\ty = %15.2f\n",y);
			printf("\tz = %15.2f\n",z);
		}
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}
