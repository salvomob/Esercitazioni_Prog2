#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

void coppie(string s,ostream& out);

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	for(int task = 0; task < 100 ; task++){
		string line;
		getline(in,line);
		istringstream iss(line);
		string parola;
		while(iss>>parola){
			coppie(parola,out);
		}
		out << endl;
	}
	in.close();
	out.close();
}

void coppie(string s,ostream& out){
	for(int i = 0; i< s.length();i++){
		if(s[i]<s[i+1]) out << i << " ";
	}
}
