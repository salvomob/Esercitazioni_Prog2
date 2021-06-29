#include<iostream>
#include<fstream>
#include"BST.cpp"

using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    for(int task = 0; task < 100 ; task++){
        string tipo;
        int n;
        string visita;
        in>>tipo;
        in>>n;
        in>>visita;
        if(tipo == "int"){
            BST<int> *t = new BST<int>();
            for(int i = 0; i < n; i++ ){
                char c,b;
                in>>c;
                in>>b>>b>>b;
                if(c=='i'){
                    int *e = new int(0);
                    in>>*e;
                    t->ins(*e);
                }
                else{
                    in>>b;
                    int f;
                    in>>f;
                    t->canc(f);
                }
            }
            if(visita == "inorder") t->inorder(out);
            if(visita == "preorder") t->preorder(out);
            if(visita == "postorder") t->postorder(out);
        }
        if(tipo == "double"){
            BST<double> *t = new BST<double>();
             for(int i = 0; i < n; i++ ){
                char c,b;
                in>>c;
                in>>b>>b>>b;
                if(c=='i'){
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
            if(visita == "inorder") t->inorder(out);
            if(visita == "preorder") t->preorder(out);
            if(visita == "postorder") t->postorder(out);
        }
        if(tipo=="bool"){
            BST<bool> *t = new BST<bool>();
             for(int i = 0; i < n; i++ ){
                char c,b;
                in>>c;
                in>>b>>b>>b;
                if(c=='i'){
                    bool *e = new bool(0);
                    in>>*e;
                    t->ins(*e);
                }
                else{
                    in>>b;
                    bool f;
                    in>>f;
                    t->canc(f);
                }
            }
            if(visita == "inorder") t->inorder(out);
            if(visita == "preorder") t->preorder(out);
            if(visita == "postorder") t->postorder(out);
        }
        if(tipo == "char"){
            BST<char> *t = new BST<char>();
             for(int i = 0; i < n; i++ ){
                char c,b;
                in>>c;
                in>>b>>b>>b;
                if(c=='i'){
                    char *e = new char(0);
                    in>>*e;
                    t->ins(*e);
                }
                else{
                    in>>b;
                    char f;
                    in>>f;
                    t->canc(f);
                }
            }
            if(visita == "inorder") t->inorder(out);
            if(visita == "preorder") t->preorder(out);
            if(visita == "postorder") t->postorder(out);
        }
        out << endl;
    }
    
    in.close();
    out.close();
}
