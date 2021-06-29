#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    for(int task = 0 ; task < 100 ; task++){
        string *s;
        int n;
        string str;
        in>>n;
        s = new string[n];
        in>>str;
        for(int i = 0; i < n ; i++){
            in>>s[i];
        }
        
        for(int i = 0; i < n; i++){
            if(s[i].find(str)!=std::string::npos)
                out << s[i]<<" ";
        }
        out << endl;        
    }

    in.close();
    out.close();

}
