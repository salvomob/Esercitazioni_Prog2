#include <iostream>

using namespace std;

void printMatrix(int **m, int n1, int n2);

int main(){
	int n1,n2;
	cout << "Inserisci dimesione 1 matrice";
	cin>>n1;
	cout << "Inserisci dimesione 2 matrice";
	cin>>n2;
	int **m;
	m = new int*[n1];
	for(int i = 0; i < n1; i++){
		m[i] = new int[n2];
	}
	
	for(int i = 0; i < n1; i++){
		for(int j = 0; j < n2 ; j++){
			int num;
			cout << "Inserisci il numero";
			cin>>num;
			m[i][j] = num;
		}
	}
	printMatrix(m,n1,n2);
}

void printMatrix(int **m, int n1, int n2){
	for(int i = 0; i < n1; i++){
		for(int j = 0; j < n2; j++){
			cout << m[i][j] << " " ; 
		}
		cout << endl;
	}
}
