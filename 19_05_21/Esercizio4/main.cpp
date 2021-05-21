#include<iostream>
#include<fstream>
#include "fattoriale.hpp"
#include "fattoriale.cpp"

using namespace std;

int main(){
	/*ifstream in("input.txt");
	ofstream out("output.txt");
	
	for(int task = 0; task < 1000; task++ )
	{
		int n;
		in>>n;
		for(int i = 0; i < n; i++)
		{
			int x;
			in>>x;
			out << fattoriale(x) << " ";
		}
		out << "\n";
	}
	in.close();
	out.close();*/
	
	int x = -6;
	cout << fattoriale_osc(x) << endl;
}
