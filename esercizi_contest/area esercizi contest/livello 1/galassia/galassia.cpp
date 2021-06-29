#include<iostream>
#include<fstream>

using namespace std;

int massimo(string *s,int n);
int nmls(string* s , int n);

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	for(int task = 0; task < 100 ; task++){
		int n;
		in>>n;
		string *s = new string[n];
		for(int i = 0; i < n; i++){
			in>>s[i];
			//cout << s[i] << " ";
		}
		int a =  nmls(s,n);
		string *ab = new string[a];
		for(int i = 0; i < a ; i++){
			cout << ab[i] << " ";
		}
		
		
	}
	in.close();
	out.close();
}

int massimo(string* s, int n){
	int mas = 0;
	for(int i = 0; i < n; i++){
		int a = s[i].length();
		if(mas < a) mas = a;
	}
	return mas;
}

int nmls(string* s , int n){
	int a = massimo(s,n);
	int c = 0;
	for(int i = 0; i < n;i++){
		if(s[i].length() == a) c++;
	}
	return c;
}

string *mls(string *s,int n){
	int b = massimo(s,n);
	int a = nmls(s,n);
	int d = 0;
	string *ret = new string[a];
	for(int i = 0; i < n; i++){
		if(s[i].length() == b) ret[++d] = s[i];
	}
	return ret;
}
