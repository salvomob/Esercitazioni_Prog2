#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    for(int task = 0; task < 100 ; task++){
        int n = 5;
        char *a;
        string b;
        a = new char[n];
        string s;
        char ab;
        in>>ab>>ab;
        in>>a[0];
        in>>ab>>ab;
        in>>a[1];
        in>>ab>>ab;
        in>>a[2];
        in>>ab>>ab;
        in>>a[3];
        in>>ab>>ab;
        in>>a[4];
        getline(in,s);
        for(int i = 0; i < s.length();i++){
            switch(s[i]){
                case 'a':
                    s[i] = a[0];
                    break;
                case 'e':
                    s[i] = a[1];
                    break;
                case 'i':
                    s[i] = a[2];
                    break;
                case 'o':
                    s[i] = a[3];
                    break;
                case 'u':
                    s[i] = a[4];
                    break;
            }
        }
       out << s << endl;
             
    }
    in.close();
    out.close();
}


