#include<fstream>
#include"rettangolo.h"// N.B. se è una classe o libreria che abbiamo creato noi, il nome fra virgolette altrimenti le parentesi angolari -> <iostream> VS "rettangolo.h"
using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	for(int task = 1; task<1001; task++){
		int n;
		in>>n;
		for(int i = 0; i < n; i++){
			char s;
			in>>s; //parentesi sx
			int n1,n2;
			in>>n1>>n2;
			in>>s; // parentesi dx
			Rettangolo r(n1,n2);
			if(task%2==1) out << r.perimetro() << " ";
			else out << r.area() << " "; 
		}
		out << endl;
	}
	in.close();
	out.close();
}

