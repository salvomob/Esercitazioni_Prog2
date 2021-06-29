#include<iostream>
#include<fstream>

using namespace std;

int main(){
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	for(int task = 0; task < 100; task++){
		int n;
		int x;
		int b=0;
		in>>n;
		in>>x;
		int* a; 
		a = new int[n];
		for(int i = 0; i < n; i++){
			in>>a[i];
		}
		for(int i = 0; i < n ; i++){
			if(a[i] > x) b++;
		}
		out << b << " ";
		for(int i = 0; i < n; i++){
			if(a[i] > x) out << a[i] << " ";
		}
		out << endl;	
	}
	in.close();
	out.close();
}


