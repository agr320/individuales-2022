void escribir_tabla(double elo, double prec){
	long int j;
	double ang;

	printf("%4s"," ");
	for(j=1;j<10000;j*=10){
		printf("%20d",j);
	}
	printf("\n");
	ang=0.0;
	while(ang<=elo){
		printf("%5.3f",ang);
		for(j=1;j<10000;j*=10){
			printf("%20.15f",calcular_er(ang,j));
		}
		printf("\n");
		ang+=prec;
	}