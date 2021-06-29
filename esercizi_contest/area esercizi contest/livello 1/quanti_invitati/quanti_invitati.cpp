#include<iostream>
#include<fstream>
#include<sstream>


using namespace std;

int countStrings(string str);

int main(){
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	for(int task = 0 ; task < 100 ; task++){
		string str;
		stringstream s(str);
		getline(in,str);
		int count = countStrings(str);
		out << count << endl;
	}
	in.close();
	out.close();
}




int countStrings(string str){ 
    // breaking input into word using string stream 
    stringstream s(str); // Used for breaking words 
    string word; // to store individual words 
  
    int count = 0; 
    while (s >> word) 
        count++; 
    return count; 
} 

