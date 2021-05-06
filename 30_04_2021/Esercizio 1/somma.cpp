#include<fstream>

using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	for(int task = 0; task < 1000; task++){
		int n;
		in>>n;
		int somma = 0;
		for(int i = 0; i < n; i++){
			int x;
			in>>x;
			somma+=x;
		}
		out << somma << endl;	
		
	}
	in.close();
	out.close();
}

