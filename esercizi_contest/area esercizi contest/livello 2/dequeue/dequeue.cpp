#include<iostream>
#include<fstream>
#include"coda.cpp"

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
            Queue<int> *s = new Queue<int>();
            for(int i = 0; i < operazioni ; i++){
                int a;
                in>>ops;
                if(ops=='i'){
                    in>>a;
                    s->enqueue(a);
                }
                else {
                    in>>ops>>ops>>ops>>ops>>ops>>ops;
                    s->dequeue();
                }
            }
            out << *s << endl;
        }
        if(tipo == "double"){
             Queue<double> *s = new Queue<double>();
            for(int i = 0; i < operazioni ; i++){
                double a;
                in>>ops;
                if(ops=='i'){
                    in>>a;
                    s->enqueue(a);
                }
                else {
                    in>>ops>>ops>>ops>>ops>>ops>>ops;
                    s->dequeue();
                }
            }
            out << *s << endl;
        }
        if(tipo == "bool"){
             Queue<bool> *s = new Queue<bool>();
            for(int i = 0; i < operazioni ; i++){
                bool a;
                in>>ops;
                if(ops=='i'){
                    in>>a;
                    s->enqueue(a);
                }
                else {
                    in>>ops>>ops>>ops>>ops>>ops>>ops;
                    s->dequeue();
                }
            }
            out << *s << endl;
        }
        if(tipo == "char"){
             Queue<char> *s = new Queue<char>();
            for(int i = 0; i < operazioni ; i++){
                char a;
                in>>ops;
                if(ops=='i'){
                    in>>a;
                    s->enqueue(a);
                }
                else {
                    in>>ops>>ops>>ops>>ops>>ops>>ops;
                    s->dequeue();
                }
            }
            out << *s << endl;
        }
    }
    in.close();
    out.close();
}

