#include <iostream>
#include "studente.hpp"
#include "studente.cpp"

using namespace std;

int main()
{
	Studente *s1 = new Studente("Marco","Isidoro",'M',1996,"Ragusa","X81000123");
	Studente *s2 = new Studente("Sonia","Schiliro'",'F',1998,"Bronte/Adrano","X81000???");
	Studente *s3 = new Studente("Giulia","Monteleone",'F',1993,"Niscemi","X81000???");
	Studente *s4 = new Studente("Salvatore","Mobilia",'M',1997,"Malvagna","X81000882");
	Studente *s5 = new Studente("Martina","Chairanda'",'F',1996,"Caltagirone","X81000???");
	Studente *s6 = new Studente("Marcello","Lorenzetti",'M',1989,"Palermo","X81000??");
	
	Studente ** sa = new Studente*[6];
	
	sa[0] = s1;
	sa[1] = s2;
	sa[2] = s3;
	sa[3] = s4;
	sa[4] = s5;
	sa[5] = s6;
	
	for(int i = 0; i < 6; i++)
	{
		cout <<  *sa[i]  << endl;
	}
	
	
}
