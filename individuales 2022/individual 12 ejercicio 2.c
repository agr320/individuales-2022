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