#include<iostream>
#include<fstream>

using namespace std;

template <class T> void insertionsort(T *v,int n);

template <class T> void scambia(T *v, int i, int j);


int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	for(int task = 0; task < 100 ; task++){
		int **matrix;
		int r,c;
		in>>r;
		in>>c;
		matrix = new int*[r];
		for(int i = 0; i < r;i++){
			matrix[i] = new int[c];
		}
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				in>>matrix[i][j];
			}
		}
		int v[r+c-1] = {0};

    for(unsigned int i = 0; i < r; ++i)
    {
        for(unsigned int j = 0; j < c; ++j)
        {
            v[r+j-i-1] += matrix[i][j];
        }
    }
    insertionsort(v,r+c-1);
    for(int i = 0; i < r+c-1; i++)out << v[i] << " ";
    out << endl;
    }
    
		//cout << somma << endl;
		
		//for(int i = 0; i < r ; i++) cout << sum[i] << endl;
		//insertionsort(sum,r);
		//for (int i = 0; i < r+c-1; i++ )cout << sum[i] << " ";
		//cout << endl;
	}
	

template <class T> void insertionsort(T *v,int n){
	//int counter = 0;
	for(int i=0;i<n;i++){
		int j=i;
		while(j>0 && v[j-1]>v[j]){
			scambia(v,j,j-1);
			//counter++;
			j--;		
		}
	}
	//return counter;
}


template <class T> void scambia(T *v, int i, int j){
	T tmp = v[j];
	v[j]=v[i];
	v[i]=tmp;
}
