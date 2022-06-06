/* Programa de prueba para los tres    */
/* ejercicios de cadenas de caracteres */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define N 50    /* longitud maxima de la cadena de entrada */

/* DISEÑO PRELIMINAR */
/* Nuevos tipos de datos */
typedef char cadena50[N+1];

/* Prototipos de funciones */
void leer_cadena(char *c, int n);
void leer_opcion_menu(char *c);
void invertir_cadena(char *cad);
void eliminar_no_alfabeticos(char *cad);
void eliminar_no_alfabeticos2(char *cad);
void listar_palabras(char *cad);

/* DISEÑO DETALLADO */
/* Definiciones de funciones */
int main(){
    char c;
    cadena50 cad,cad2;

    do{ system("cls");
        printf("EJERCICIOS DE CADENAS DE CARACTERES\n");
        printf("===================================\n\n");
        printf("Introduzca una cadena de caracteres: ");
        leer_cadena(cad,N);
        do{ leer_opcion_menu(&c);
            printf("\n\nCadena original:  %s\n",cad);
            strcpy(cad2,cad);
            switch(c){
            case '1': invertir_cadena(cad2);
                      printf("Cadena invertida: %s\n",cad2);
                      getch();
                      break;
            case '2': eliminar_no_alfabeticos2(cad2);
                      printf("Cadena modificada: %s\n",cad2);
                      getch();
                      break;
            case '3': listar_palabras(cad);
                      break;
            case '0': printf("FIN DE EJECUCION");
                      getch();
                      break;
            default: printf("\a");
            }
        }while(c!='0');
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}

void leer_cadena(char *cad, int n){
/* lee por teclado y devuelve una cadena de hasta n caracteres */
/* Nota: la cadena debe preveer una posicion adicional para la */
/* marca fin de cadena (\0) --> tamaño minimo n+1 caracteres   */
    int i,fin;
    char c;

    i=0;
    fin=0;
    while((i<n)&&(!fin)){
        c=getch();
        switch(c){
        case '\r': fin=1;
                   printf("\n"); 
                   break; 
        case '\b': if (i>0){
                     --i;
                     printf("\b \b");
                   }
                   break;
        default:   cad[i]=c;
                   ++i;
                   printf("%c",c);
                   break;
        }
    }
    cad[i]='\0';
    if (i==n) printf("\n");
}

void leer_opcion_menu(char *c){
	system("cls");
	printf("OPERACIONES CON CADENAS DE CARACTERES\n");
	printf("=====================================\n\n");
	printf("\t1.- Invertir cadena\n");
	printf("\t2.- Eliminar caracteres no alfabeticos de cadena\n");
	printf("\t3.- Listar palabras de una cadena\n");
	printf("\t0.- Finalizar\n\n");
	printf("\t\tIntroduzca opcion: ");
	*c=getch();
}

void invertir_cadena(char *cad){
	int i,n;
	char c;

	i=0;
	n=strlen(cad);
	while(i<n/2){
	  c=cad[i];
	  cad[i]=cad[n-1-i];
	  cad[n-1-i]=c;
	  i=i+1;
	}
}

void eliminar_no_alfabeticos(char *cad){
	int i,j;	/* contador de iteraciones y de caracteres alfabéticos */
	int n; 		/* Longitud dinámica de la cadena original				*/
	
	n=strlen(cad);
	i=0;
	j=0;
	while(i<n){
		if((cad[i]>='A')&&(cad[i]<='z')){
			cad[j]=cad[i];
			++j;
		}
		++i;
	}
	cad[j]='\0';
}

void eliminar_no_alfabeticos2(char *cad){
	int i,j;	/* contador de iteraciones y de caracteres alfabéticos */
	int n; 		/* Longitud dinámica de la cadena original				*/
	
	i=0;
	j=0;
	while(cad[i]!='\0'){
		if((cad[i]>='A')&&(cad[i]<='z')){
			cad[j]=cad[i];
			++j;
		}
		++i;
	}
	cad[j]='\0';
}

void listar_palabras(char *cad){
	int i;
	int cont;	/* Contador de palabras						*/
	int pal;	/* V: carácter de palabra, F: no alfabético	*/

	printf("\nCadena original: %s\n",cad);
	printf("Palabras diferentes:\n");
	i=0;
	cont=0;
	pal=0;
	while(cad[i]!='\0'){
		if(isalpha(cad[i])){
			printf("%c",cad[i]);
			if(!pal){
				pal=1;
				cont++;
			}
		}else{
			if(pal){
				printf("\n");
				pal=0;
			}
		}
		++i;
	}
	printf("\nNumero de palabras encontradas: %d\n",cont);
	getch();