#include<iostream>
#include<fstream>
#include"arraylist.cpp"

using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	for(int task = 0; task < 100 ; task++){
		int n;
		in>>n;
		ArrayList<int> a;
		for(int i = 0; i < n; i++){
			int b;
			in>>b;
			a.ins(b);
		}
		a.print(out);
	}
	in.close();
	out.close();
}
