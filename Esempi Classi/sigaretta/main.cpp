#include <iostream>
#include "sigaretta.hpp"
#include "sigaretta.cpp"

using namespace std;

int main()
{
	/*Sigaretta *s,*s1,*s2;
	
	s = new Sigaretta(0.01,0.008,0.0003,1,true,"MARLBORO");
	s1 = new Sigaretta();
	s2 = new Sigaretta(0.02,0.009,0.0005,1,false,"PUEBLO");
	cout << *s <<endl;
	delete s1;
	cout << *s1  << endl;
	cout << *s2 ;
	*/
	
	Sigaretta ** sigarette;
	
	sigarette = new Sigaretta*[3];
	
	sigarette[0] = new Sigaretta(0.01,0.008,0.0003,1,true,"MARLBORO");
	sigarette[1] = new Sigaretta();
	sigarette[2] = new Sigaretta(0.02,0.009,0.0005,1,false,"PUEBLO");
 	
	
	for(int i = 0; i < 3; i++)
	{
		cout << *sigarette[i] << endl;
		cout << "Questa e' la sigaretta N." << i+1 << "\n\n"; 
	}
	
	
}
