#include "studenti.cpp"
#include"classe.cpp"
#include<iostream>

using namespace std;

int main(){
	Studente s1("Salvo","Mobilia",23);
	Studente s2("Pippo","Cocaina",99);
	Studente s3("Fumo", "Marijuana", 420);
	
	Studente *stud;
	stud = new Studente[3];
	stud[0] = s1;
	stud[1] = s2;
	stud[2] = s3;
	
	
	/*
	 swap degli studenti in pos 0 e in pos 1
	Studente tmp = stud[0];
	stud[0] = stud[1];
	stud[1] = tmp;
	*/
	
	Classe classe(10);
	for(int i = 0; i < 3 ; i++){
		classe.setStudente(stud[i]);
	}

	
	classe.show();
}
