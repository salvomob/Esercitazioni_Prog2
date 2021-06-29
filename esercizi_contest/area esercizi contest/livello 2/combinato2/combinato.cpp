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
			char c;
			int b;
			in>>c>>b;
			if(c=='i')
			a.ins(b);
			else if(c=='c')
			a.canc(b);
		}
		a.print(out);
	}
	in.close();
	out.close();
}
