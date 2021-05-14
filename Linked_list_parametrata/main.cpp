#include<iostream>
#include"linkedlist.cpp"

int main(){
	/*test stupido*/
	
	List<int> *l = new List<int>(false);
	l->ins(10).ins(2).ins(15).ins(12).ins(23);
	
	cout << *l << endl;
	
	l->canc(2).canc(15);
	
	cout << *l << endl;
}

