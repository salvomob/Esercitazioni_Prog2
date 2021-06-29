#include <iostream>
#include<fstream>

using namespace std;


int longestPalSubstr(string str);

int main(){
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    for(int task = 0; task < 100; task++){
        string a;
        in>>a;
        out << longestPalSubstr(a) << endl;
    }
    in.close();
    out.close();
}

int longestPalSubstr(string str)
{
    // get length of input string
    int n = str.size();
 
    // All substrings of length 1
    // are palindromes
    int maxLength = 1, start = 0;
 
    // Nested loop to mark start and end index
    for (int i = 0; i < str.length(); i++) {
        for (int j = i; j < str.length(); j++) {
            int flag = 1;
 
            // Check palindrome
            for (int k = 0; k < (j - i + 1) / 2; k++)
                if (str[i + k] != str[j - k])
                    flag = 0;
 
            // Palindrome
            if (flag && (j - i + 1) > maxLength) {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }
 
  
 
    // return length of LPS
    return maxLength;
}
