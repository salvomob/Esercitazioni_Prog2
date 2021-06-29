#include<iostream>
#include<fstream>

using namespace std;

int check(string a);

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	for(int task = 0 ; task < 100; task++){
		string *a;
		int n;
		in>>n;
		int counter = 0;
		a = new string[n];
		for(int i = 0; i < n ; i++) in>> a[i];
		for(int i = 0; i < n ; i++) if(check(a[i])<=1) counter++;
		out << counter << " ";
		for(int i = 0; i < n ; i++) if(check(a[i])<=1) out << a[i] << " ";
		out << endl;
	}
}

int check(string a){
	int n = a.length();
	int counter = 0;
	for(int i = 0; i < n/2 ; i++){
		if(a[i]!=a[n-1-i]) counter++;
	}
	return counter;
}
