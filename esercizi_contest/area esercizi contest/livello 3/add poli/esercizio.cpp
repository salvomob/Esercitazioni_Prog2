#include<iostream>
#include<fstream>
#include"polinomio.cpp"

using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	for(int task = 0; task < 100 ; task ++){
		int n;
		in>>n;
		Polinomio<int> **p = new Polinomio<int>*[n];
		for(int i = 0; i < n; i++){
			p[i] = new Polinomio<int>();
			char c;
			in>>c;
			int coeff;
			in>>coeff;
			in>>c;
			if(c != ')'){
				in>>c;
				int grado;
				in>>grado;
				p[i]->ins(coeff,grado);	
			}
			for(int i = 0; i < n ; i++){
				cout << *p[i] << endl;
			}
		}
		
	}
	in.close();
	out.close();
}
