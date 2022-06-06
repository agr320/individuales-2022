#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

/* Diseño Preliminar */
/* Prototipos de funciones */
int caminos_NE(int x1, int y1, int x2, int y2);

/* Definiciones de funciones */
int main(){
	char c;
	int x1,y1,x2,y2;

	do{ system("cls");
		printf("NUMERO DE CAMINOS NORDESTE\n");
		printf("==========================\n\n");
		printf("Introduzca A (x1,y1): ");
		scanf(" %d,%d",&x1,&y1);
		printf("Introduzca B (x2,y2): ");
		scanf(" %d,%d",&x2,&y2);
		printf("Numero de caminos nordeste: %d",caminos_NE(x1,y1,x2,y2));
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}

int caminos_NE(int x1, int y1, int x2, int y2){
	if(x1>x2){
		return(0);
	}else{
		if(x1==x2){
			if(y1>=y2){
				return(0);
			}else{
				return(1);
			}
		}else{
			if(y1>y2){
				return(0);
			}else{
				if(y1==y2){
					return(1);
				}else{
					return(caminos_NE(x1+1,y1,x2,y2)+
					       caminos_NE(x1,y1+1,x2,y2));
				}
			}
		}
	}