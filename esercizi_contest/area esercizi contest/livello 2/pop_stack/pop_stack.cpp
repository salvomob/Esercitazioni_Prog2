#include<iostream>
#include<fstream>
#include"Stack.cpp"

using namespace std;

int main(){
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    for(int task = 0; task < 100 ; task++){
        string tipo;
        int operazioni;
        char ops;
        in>>tipo;
        in>>operazioni;
        if(tipo == "int"){
            Stack<int> *s = new Stack<int>();
            for(int i = 0; i < operazioni ; i++){
                int a;
                in>>ops;
                if(ops=='i'){
                    in>>a;
                    s->push(a);
                }
                else {
                    in>>ops>>ops;
                    s->pop();
                }
            }
            out << *s << endl;
        }
        if(tipo == "double"){
            Stack<double> *s = new Stack<double>(); 
            for(int i = 0 ; i < operazioni ; i++){
                double a;
                in>>ops;
                if(ops=='i'){
                    in>>a;
                    s->push(a);
                }
                else {
                    in>>ops>>ops;
                    s->pop();
                }   
            }
            out << *s << endl;
        }
        if(tipo == "bool"){
            Stack<bool> *s = new Stack<bool>();
            for(int i = 0; i < operazioni ; i++){
                bool a;
                in>>ops;
                if(ops=='i'){
                    in>>a;
                    s->push(a);
                }
                else {
                    in>>ops>>ops;
                    s->pop();
                }   
            }
            out << *s << endl;
        }
        if(tipo == "char"){
            Stack<char> *s = new Stack<char>();
            for(int i = 0; i < operazioni ; i++){
                char a;
                in>>ops;
                if(ops=='i'){
                    in>>a;
                    s->push(a);
                }
                else {
                    in>>ops>>ops;
                    s->pop();
                }   
            }
            out << *s << endl;
        }
    }
    in.close();
    out.close();
}

