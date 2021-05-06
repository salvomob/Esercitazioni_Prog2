#include<fstream>
#include"quadrato.h"

using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	for(int task = 1; task < 1001; task++){
		int n;
		in>>n;
		for(int i = 0; i < n; i++){
			int l;
			in>>l;
			Quadrato q(l);
			if(task%2==1) out << q.perimetro() << " ";
			else out << q.area() << " ";
		}
		out << endl;
	}
	in.close();
	out.close();
}
