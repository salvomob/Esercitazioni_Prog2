#include<iostream>
#include<fstream>
#include"BST.cpp"

using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    for(int task = 0; task < 100 ; task++){
        string tipo;
        in>>tipo;
        int op;
        in>>op;
        int x;
        in>> x;
        if(tipo == "int"){
            BST<int> *t = new BST<int>();
            for(int i = 0; i < op ; i++){
                    char c,b;
                    in >> c;
                    in >> b;
                    in >> b;
                    in >> b;
                    if(c=='i') {
                        int *e = new int(0);
                        in >> *e;
                        t->ins(*e);
                    }
                    else {
                        in >> b;
                        int e;
                        in >> e;
                        t->canc(e);
                    }
                
           }     
                for(int i = 0 ; i < x ; i++){
                    int a;
                    in>> a;
                    if(t-> distSuccessore(a) == 0) out << "INF" << " ";
                    else out <<t-> distSuccessore(a) << " ";
                }
                out << endl;    
        }
        else{
            BST<double> *t = new BST<double>();
            for(int i = 0; i < op ; i++){
                    char c,b;
                    in >> c;
                    in >> b;
                    in >> b;
                    in >> b;
                    if(c=='i') {
                        double *e = new double(0);
                        in >> *e;
                        t->ins(*e);
                    }
                    else {
                        in >> b;
                        double e;
                        in >> e;
                        t->canc(e);
                    }
                
           }     
                for(int i = 0 ; i < x ; i++){
                    double a;
                    in>> a;
                    if(t-> distSuccessore(a) == 0) out << "INF" << " ";
                    else out <<t-> distSuccessore(a) << " ";
                }
                out << endl; 
        }
    }
    in.close();
    out.close();
}
