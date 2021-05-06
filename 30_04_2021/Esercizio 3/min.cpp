#include<fstream>

using namespace std;

template <class T> T min(T*,int);//uso dei template, posso passare anche oggetti dopo aver fatto l'0verloading dell'operatore che usa l'algoritmo per compararli

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	for(int task = 0; task < 1000; task++){
		int n;
		in>>n;
		int *arr;
		arr = new int[n];
		for(int i = 0; i < n; i++){
			in>>arr[i];
		}
		out << min(arr,n) << endl;	
		
	}
	in.close();
	out.close();
}

template <class T> T min(T* v, int n){
	T min = v[0];
	for(int i = 0; i < n; i++){
		if(min > v[i]) min = v[i];
	}
	return min;
}

