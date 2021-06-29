#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

void printIndex(string s,char a,ostream& out);
int check(string s,char a);

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    for(int task = 0 ; task < 100; task++){
        char a;
        in>>a;
        string b;
        getline(in,b);
        string word;
        istringstream iss(b,istringstream::in);
        
        if(check(b,a)!=0){
            while(iss>>word){
                printIndex(word,a,out);
            }
            out << endl;
        }
        else 
            out << "none" << endl;
    }
    in.close();
    out.close();
}

int check(string s,char a){
    int c = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i]==a){
          //  out << i << " ";
            c++;
        }
    }
     return c;
}

void printIndex(string s, char a ,ostream& out){
    for(int i = 0; i < s.length(); i++){
        if(s[i]==a){
            out << i << " ";
        }
    }
   
}
