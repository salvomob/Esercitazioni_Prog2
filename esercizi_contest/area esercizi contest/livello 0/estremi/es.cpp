#include<fstream>
#include<iostream>
using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	for(int task = 0; task < 100;task ++){
		int n1,n2,n3;
		string s1,s2,s3;
		in>>n1>>s1>>n2>>s2>>n3>>s3;
		int counter = 0;
		if(s1[0] == s1[n1-1]) counter +=1;
		if(s2[0] == s2[n2-1]) counter +=1;
		if(s3[0] == s3[n3-1]) counter +=1;
		out << counter << endl;
	}
	in.close();
	out.close();
}
