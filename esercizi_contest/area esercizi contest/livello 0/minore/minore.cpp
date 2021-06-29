#include<fstream>
#include<iostream>
#include <sstream>
#include<string>

#define MAXL 10000

using namespace std;


int main(){
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	for(int task=0; task < 100 ; task++){
	   int mini = 0;
	   int value = 0;
	   string input="";
	   while(input!="STOP"){
	    in>>input;
	    if(input!="STOP") value = stoi(input);
	    if(mini == 0) mini = value;
	    if(mini >= value) mini = value;
	   }
	   out << mini << endl;
	}
	in.close();
	out.close();


}

