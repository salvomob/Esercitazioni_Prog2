#include<iostream>
using namespace std;



int search(int* v,int n,int x){
	if(n == 0) return -1;
	if(v[0] == x) return 0;
	else return 1+ search(v+1,n-1,x);
	
}







int main(){
	int a[]={2,5,7,8,9,12,15,16,21};
	cout << search(a,9,15) << endl;
}
