#include<iostream>
#include<fstream>

using namespace std;

template <class T> T max(T* v,int n);

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    for(int task = 0; task < 100; task++){
        int *a;
        a = new int[26];
        for(int i = 0; i < 26 ; i++ ) a[i] = 0;
        string s;
        int n;
        getline(in,s);
        n = s.length();
        for(int i = 0; i < n ; i++){
            if(s[i] >= 'a' && s[i] <= 'z') {
                ++a[s[i]-'a'];
            }
        }
        char c;
        for(int i = 0; i < n; i++){
        	if(a[i] == max(a,26)) c= 'a'+i;
        }
        out << c << " " << max(a,26);
        out << endl;
    }
    in.close();
    out.close();
}

template <class T> T max(T* v,int n){
    T max = v[0];
    for(int i = 0; i < n ; i++){
        if(max < v[i]) max = v[i];
    }
    return max;
}


