double elongacion_maxima(double prec, double er){
	double elo,error;

	elo=0;
	error=0;
	while(error<er){
		elo+=prec;
		error=calcular_er(elo,1000);
	}
	elo-=prec;
   return(elo);
}