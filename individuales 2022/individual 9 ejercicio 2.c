double calcular_er(double a, long int n){
	double suma;
	double x,y;
	long int i;

	suma=0;
	x=1;
	a=a*PI/180;
	y=sin(a/2)*sin(a/2);
	for(i=1;i<=n;++i){
		x=x*(2.0*i-1)*(2.0*i-1)/(4.0*i*i)*y;
    	suma+=x;
	}
	return(suma);
}
