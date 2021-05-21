#include "fattoriale.hpp"

inline int fattoriale(int n)
{	
	if(n < 1) return -1;
	if(n == 1) return n;
	else return n*fattoriale(n-1);
	
}

inline int fattoriale1(int n)
{
	if(n < 1)
	{
		std::cout << "SEI UNO STUPIDOTTERO ! NON VOGLIO CALCOLARTI UNA SUCCESSIONE PERIODICA\n";
		return -1;
	}
	
	int ret=n;
	
	for(int i = n-1 ; i >= 1; i--)
	{
		ret*=(n-i);
	}
	return ret;
}

inline int fattoriale_osc(int n){
	if(n==0) return 0;
	if(n == 1) return 1;	
	if(n == -1) return -1;
	if(n>0) return fattoriale(n);
	else return n*fattoriale_osc(n+1);
}

