#include<iostream>
#include<fstream>

using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	for(int task  = 0; task < 100 ; task++){
		int n1,n2,n3;
		in>>n1;
		char *nome1,*nome2,*nome3;
		nome1 = new char[n1];
		for(int i=0; i < n1;i++){
			in>>nome1[i];
		}
		in>>n2;
		nome2 = new char[n2];
		for(int i = 0; i < n2; i++){
			in>>nome2[i];
		}
		in>>n3;
		nome3 = new char[n3];
		for(int i = 0; i < n3; i++){
			in>>nome3[i];
		}
		nome1[0]=toupper(nome1[0]);
		nome2[0]=toupper(nome2[0]);
		nome3[0]=toupper(nome3[0]);
		for(int i = 0; i < n1;i++){
			out << nome1[i];
		}
		cout << " ";
		for(int i = 0; i < n2; i++){
			out << nome2[i];
		}
		cout << " ";
		for(int i = 0; i < n3; i++){
			out << nome3[i];
		}
		cout <<endl;
	}
	in.close();
	out.close();
}
