#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    for(int task = 0; task < 100; task++){
        string s;
        getline(in,s);
        for(int i=0; i < s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                out << s[i] << 'f' << s[i];
            }
            else out << s[i];
        }
        out << endl;
    }
    in.close();
    out.close();
}
