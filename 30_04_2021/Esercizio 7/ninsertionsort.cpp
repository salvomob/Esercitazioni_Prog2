#include<fstream>

using namespace std;

template <class T> int insertionsort(T* , int);
template <class T> void scambia(T* , int , int);

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	for(int task = 0; task < 100; task++){
		int n;
		in>>n;
		int *arr;
		arr = new int[n];
		for(int i = 0; i < n; i++){
			in>>arr[i];
		}
		out << insertionsort(arr,n)<< endl;
	}
	in.close();
	out.close();
}

template <class T> int insertionsort(T* v, int n){
	int counter = 0;
	for(int i=0;i<n;i++){
		int j=i;
		while(j>0 && v[j-1]>v[j]){
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

