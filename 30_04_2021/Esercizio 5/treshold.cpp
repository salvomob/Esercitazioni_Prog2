#include<fstream>

using namespace std;


int main(){
 	ifstream in("input.txt");
 	ofstream out("output.txt");
 	for(int task  = 0 ;task  < 1000 ; task++){
 		int soglia;
 		in>>soglia;
 		int n;
 		in>>n;
 		for(int i = 0; i < n ; i++){
 			string str;
 			in>>str;
 			int l = str.length();
 			if(l>=soglia) out << str << " ";
 		}
 		out << endl;
 	}
 	in.close();
 	out.close();
 }
 

