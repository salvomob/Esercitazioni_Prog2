#include<iostream>
#include<fstream>

using namespace std;


int main(){
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");
	for(int task=0;task<100;task++){
		int n;
		in>>n;
		int *a = new int[n];
		for(int i = 0; i < n ; i++){
			in>>a[i];
			if(a[i]%2!=0) out << a[i] << " ";
		}
		out<<endl;
	}
	in.close();
	out.close();
}


