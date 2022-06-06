#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int main(){
	char c;
	int a;		/* Ancho						*/
	int h;		/* Altura						*/
	int z;		/* Profundidad					*/
	int i,j;	/* Contadores de iteraciones	*/
	int eb;		/* Espacios en blanco			*/

	do{	system("cls");
		printf("ARISTAS VISIBLES PARALELEPIPEDO CON ASTERISCOS\n");
		printf("==============================================\n\n");
		/* Lectura y validacion dimensiones del paralelepipedo */
		do{	printf("Introduzca ancho [3-20]: ");
			scanf(" %d",&a);
		}while((a<3)||(a>20));
		do{	printf("Introduzca alto [3-10]: ");
			scanf(" %d",&h);
		}while((h<3)||(h>10));
		do{	printf("Introduzca profundidad [3-10]: ");
			scanf(" %d",&z);
		}while((z<3)||(z>10));
		printf("\n\n");
		/* CARA SUPERIOR */
		/* Arista superior */
		j=z-1;			/* Espacios en blanco */
		while(j>0){
			printf("  ");   
			--j;
		}
		i=1;			/* Asteriscos de la arista superior*/
		while(i<=a){
			printf(" *");
			++i;
		}
		printf("\n");
		/* Aristas laterales (cara superior)*/
		/* + Arista derecha (cara derecha)  */
		eb=0;
		i=2;
		while(i<z){           /* Líneas caras superior+derecha */
			j=z-i;
			while(j>0){        /* Espacios en blanco */
				printf("  "); 
				--j;
			}
			printf(" *");      /* Asterisco arista izquierda cara superior */
			j=2;
			while(j<a){        /* Espacios en blanco */
				printf("  ");
				++j;
			}
			printf(" *");      /* Asterisco arista derecha cara superior */   
			j=1;
			while(j<=eb){       /* Especios en blanco */
				printf("  "); 
				++j;
			}
			printf(" *\n");     /* Asterisco arista derecha cara derecha */
			if(i<h){           /* Ajuste espacios en blanco final de línea */
				eb++;
			}
			++i;
		}
		/* CARA FRONTAL  */
		/* Arista superior */
		/* + Arista derecha (cara derecha)  */
		i=1;
		while(i<=a){          /* asteriscos de la arista */
			printf(" *");
			++i;
		}
		j=1;			
		while(j<=eb){         /* Espacios en blanco */
			printf("  "); 
			++j;
		}
		printf(" *\n");      /* Asterisco arista derecha cara derecha */
		if(z>=h){            /* Ajuste espacios en blanco final de línea */
			eb--;
		}
		/* CARA FRONTAL     */
		/* Aristas laterales */
		/* + Arista derecha (cara derecha)  */
		i=2;
		while(i<h){           /* Líneas caras frontal+derecha */
			printf(" *");     /* Asterisco arista izquierda cara frontal */
			j=2;
			while(j<a){       /* Espacios en blanco */
				printf("  ");
				++j;
			}
			printf(" *");     /* Asterisco arista derecha cara frontal */
			j=1;
			while(j<=eb){     /* Espacios en blanco */
				printf("  ");  
				++j;
			}
			printf(" *\n");    /* Asterisco arista derecha cara derecha */
			if(i+z-1>=h){      /* Ajuste espacios en blanco final de línea */
				--eb;
			}
			++i;
		}
		/* CARA FRONTAL */
		/* Arista inferior */
		i=1;
		while(i<=a){         /* asteriscos de la arista */
			printf(" *");
			++i;
		}
		printf("\n");
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}