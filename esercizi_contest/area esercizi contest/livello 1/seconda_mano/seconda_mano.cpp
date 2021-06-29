#include<fstream>
#include<iostream>

using namespace std;

int earned(int *a,int *b, int n, int m);

int main(){
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	for(int task = 0 ; task < 100 ; task++){
		int n,m;
		in>>n;
		in>>m;
		int *a,*b;
		a = new int[n];
		b = new int[m];
		for(int i = 0; i < n ; i++){
			in>>a[i];
		}
		for(int i = 0; i < m ; i++){
			in>>b[i];
		}
		out << earned(a,b,n,m);
		out << endl;
	}
	in.close();
	out.close();
}

int earned(int *a,int *b, int n, int m){
	int ret = 0;
	for(int i = 0; i < n;i++){
		for(int j = 0; j < m ; j++){
			if(b[j] == a[i]) ret = ret+5;
		}
	}
	return ret;
}
