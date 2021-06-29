#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
#define N 10000
using namespace std;

int convertBinaryToDecimal(int n);

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	for(int task  = 0 ;task < 100; task++){
		int n = 0;
		int num=0;
		int *val = new int[N];
		string line;
		getline(in,line);
		istringstream iss(line);
		while(iss>>num){
			val[n]= convertBinaryToDecimal(num);
			n++;
		}
		out << n << " ";
		for(int i = 0; i < n; i ++){
			out << val[i] << " ";
		}  
		out << endl;
	}
}

int convertBinaryToDecimal(int n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}
