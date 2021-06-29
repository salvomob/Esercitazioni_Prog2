#include<iostream>
#include<fstream>
#include"BST.cpp"

using namespace std;

int main(){
   ifstream in("input.txt");
   ofstream out("output.txt");
   for(int task = 0 ; task < 100 ; task++){
        string tipo;
        int n;
        
        in>>tipo;
        in>>n;
        
        if(tipo == "int"){
            BST<int> *tree = new BST<int>();
            for(int i = 0; i < n; i++){
                char c,b;
                in>>c;
                in>>b>>b>>b;
                if(c=='i'){
                    int *num = new int(0);
                    in>> *num;
                    tree->ins(*num);
                }
                else {
                    in>>b;
                    int num;
                    in>>num;
                    tree->canc(num);
                }
            }
            int k;
            in>>k;
            out << tree->peso(k);
        }
        else{
            BST<double> *tree = new BST<double>();
            for(int i = 0; i < n; i++){
                char c,b;
                in>>c;
                in>>b>>b>>b;
                if(c=='i'){
                    double *num = new double(0);
                    in>> *num;
                    tree->ins(*num);
                }
                else{
                    in>>b;
                    double num;
                    in>>num;
                    tree->canc(num);
                }
            }
            double k;
            in>>k;
            out << tree->peso(k);
        }
        out << endl;
   }
   in.close();
   out.close();
}
