#include<iostream>

using namespace std;
template <class T> int binarySearch(T* v,int n ,int x) ;
int main(){
	int v[] = {1,4,5,6,7,8,9};
	cout << binarySearch(v,7,90);
}

template <class T> int binarySearch(T* v,int n ,int x) {
	if(n==0) return 0;
	if(n==1) return v[0]==x;
	int m = n/2;
	if(v[m]>x) return binarySearch(v,m,x);
	else return binarySearch(v+m,n-m,x);
}

int palindroma (char *s,int n)
{
	if(n<=1) return 1;
	return ((s[0]==s[n-1]) && palindroma(s+1,n-2)) ;
	
}

int posMax(int *v,int n){
	int pos = 0; 
	for(int i = 0; i < n; i++){
		if(v[i]>v[pos]) pos = i;
		return pos;
	}
}


int selectionsort(int *v, int n){
	if(n<=1) return;
	swap(v,posmMax(v,n),n-1);
	selectionsort(v,n-1);
}

void swap(int *v,int i,int j){
	int t = v[i];
	v[i] = v[j];
	v[j]=t;
}


int insertion_sort(int *v,int n){
	int ret = 0;
	for(int i = 0; i < n; i++){
		int j = i;
		while(j>0 && v[j]<v[j-1]){
			swap(v,j,j-1);
			j--;
			ret++;
		}
	}
	return ret;
}

int insertion_sort
