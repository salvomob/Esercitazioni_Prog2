#include<iostream>
#include<fstream>

using namespace std;

template <class T> int insertionsort(T *v,int n);
template <class T> void scambia(T *v, int i, int j);
template <class T> int backInsertionSort(T *v,int n);

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	for(int task = 0; task <100 ; task++){
		int n ;
		in>>n;
		int *arr = new int[n];
		int *arr1 = new int[n];
		for(int i = 0; i < n;i++){
			in>>arr[i];
			arr1[i] = arr[i]; 
		}
		out << insertionsort(arr,n) << " " << backInsertionSort(arr1,n) << endl;
		//backInsertionSort(arr1,n);
		//for(int i =0; i < n;i++) cout << arr1[i] << " ";
		//cout << endl;
		
	}
	in.close();
	out.close();
}


template <class T> int backInsertionSort(T* v,int n){
	int ret = 0;
	for(int i = 0; i < n; i++){
		int j = i;
		while(j>0 && v[j]<v[j-1]){
			scambia(v,j,j-1);
			j--;
			ret++;
		}
	}
	return ret;
}



template <class T> int insertionsort(T *v,int n){
	int counter = 0;
	for(int i=n-1;i>=0;i--){
		int j=i;
		while(j>0 && v[j-1]<v[j]){
			scambia(v,j,j-1);
			counter++;
			j--;		
		}
	}
	return counter;
}

template <class T> void scambia(T *v, int i, int j){
	T tmp = v[j];
	v[j]=v[i];
	v[i]=tmp;
}
