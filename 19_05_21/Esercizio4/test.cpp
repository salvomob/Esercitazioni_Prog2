#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main(){
	ifstream in("output1.txt");
	ifstream in1("output.txt");
	double count = 0.0;
	for(int task  = 0; task < 1000;task++){
		string s,s1;
		getline(in,s);
		getline(in1,s1);
		if(s==s1) count+=0.1;
	}
	cout << "Tot : " << count<< endl;
	
}
