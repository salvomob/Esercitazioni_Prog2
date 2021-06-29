#include<iostream>
#include<fstream>
#include"BST.cpp"

using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    for(int task  = 0 ; task < 100 ; task++){
        string tipo;
        int op;
        in>>tipo>>op;
        if(tipo == "int"){
            BST<int> *t = new BST<int>();
            for(int i = 0; i < op; i++){
                char c,b;
                in>>c;
                in>>b>>b>>b;
                if(c == 'i'){
                    int *e = new int(0);
                    in>>*e;
                    t->ins(*e);
                }
                else {
                    in>>b;
                    int f;
                    in>>f;
                    t->canc(f);
                }
            }
            int size = t->size();
            int *d = t->depth();
            for(int i = 0; i < size; i++) out << d[i] << " ";
            out << endl;            
        }
        else{
            BST<double> *t = new BST<double>();
            for(int i = 0; i < op; i++){
                char c,b;
                in>>c;
                in>>b>>b>>b;
                if(c == 'i'){
                    double *e = new double(0);
                    in>>*e;
                    t->ins(*e);
                }
                else{
                    in>>b;
                    double f;
                    in>>f;
                    t->canc(f);
                }
            }
            int size = t->size();
            int *d = t->depth();
            for(int i = 0; i < size ;i++) out << d[i] << " ";
            out << endl;
        }
    }
    in.close();
    out.close();   
}
