void listar_palabras(char *cad){
	int i;
	int cont;	/* Contador de palabras			*/
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
}