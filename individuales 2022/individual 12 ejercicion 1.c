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