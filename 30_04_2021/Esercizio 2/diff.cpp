#include<fstream>

using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	for(int task = 0; task < 1000; task++){
		int n;
		in>>n;
		int val;
		in>>val;
		for(int i = 0; i < n; i++){
			int x;
			in>>x;
			val-=x;
		}
		out << val << endl;	
		
	}
	in.close();
	out.close();
}

