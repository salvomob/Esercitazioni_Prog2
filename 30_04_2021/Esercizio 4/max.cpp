#include<fstream>

using namespace std;

int massimo(int* ,int );//base, senza template

int main(){
 	ifstream in("input.txt");
 	ofstream out("output.txt");
 	for(int task  = 0 ;task  < 1000 ; task++){
 		int n;
 		in>>n;
 		int *array =;
 		array = new int[n];
 		for(int i = 0; i < n ; i++){
 			int tmp;
 			in>>tmp;
 			array[i] = tmp;
 		}
 		out << massimo(array,n) << endl;
 	}
 	in.close();
 	out.close();
 }
 
 int massimo(int* pippo, int n){
 	int max = pippo[0];
 	for(int i = 0; i < n ; i++){
 		if(max<pippo[i]) max = pippo[i];
 	}
 	return max;
 }
