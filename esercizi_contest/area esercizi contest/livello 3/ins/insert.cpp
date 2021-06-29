#include<iostream>
#include<fstream>
#include"BST.cpp"

using namespace std;


int main() {

    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");

    for(int task=0; task<100; task++) {
        string tipo;
        in >> tipo;
        int n;
        in >> n;
        string visita;
        in>>visita;
        if(tipo=="int") {
            BST<int>* t = new BST<int>();
            for(int i=0; i<n; i++) {
                int *e = new int(0);
                in >> *e;
                t->ins(*e);
            }
            if(visita == "inorder") t->inorder(out);
            if(visita == "postorder") t->postorder(out);
            if(visita == "preorder") t->preorder(out);
            
        }
        else if(tipo == "double") {
            BST<double>* t = new BST<double>();
            for(int i=0; i<n; i++) {
                double *e = new double(0);
                in >> *e;
                t->ins(*e);
            }
            if(visita == "inorder") t->inorder(out);
            if(visita == "postorder") t->postorder(out);
            if(visita == "preorder") t->preorder(out);
        }
        else if(tipo == "char"){
          BST<char> *t = new BST<char>();
            for(int i = 0; i< n;i++){
                char *e = new char(0);
                in>> *e;
                t->ins(*e);
            }
            if(visita == "inorder") t->inorder(out);
            if(visita == "postorder") t->postorder(out);
            if(visita == "preorder") t->preorder(out);
        }
        else if(tipo == "bool"){
            BST<bool> *t = new BST<bool>();
            for(int i = 0; i< n;i++){
                bool *e = new bool(0);
                in>> *e;
                t->ins(*e);
            }
            if(visita == "inorder") t->inorder(out);
            if(visita == "postorder") t->postorder(out);
            if(visita == "preorder") t->preorder(out);
      }
      out << endl; 
    }
    
    in.close();
    out.close();
}

