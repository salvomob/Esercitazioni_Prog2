#include<iostream>
#include<fstream>
using namespace std;

int binary_search(int *a, int n,int x);

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	for(int task = 0; task < 100; task++){
		int n;
		in>>n;
		int* array;
		array = new int[n];
		for(int i = 0; i < n ;i++){
			in>>array[i];
		}
		int x;
		in>>x;
		out << binary_search(array,n,x) << endl;
	}
	in.close();
	out.close();
}





int binary_search(int *a, int n,int x){
	int ret = 1;
	if(n==0) return 0;
	int m=n/2;
	if(a[m]==x) return 1;
	if(x < a[m])  return ret+binary_search(a,m,x);
	else return ret+binary_search(a+m+1,n-m-1,x);
}
