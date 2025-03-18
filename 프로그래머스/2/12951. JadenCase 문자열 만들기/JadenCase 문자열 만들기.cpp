#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";

    if(s[0]>= 'a' && s[0] <= 'z') s[0] -= 32;
    
    for(int idx = 1; idx < s.length(); idx++){
        if(s[idx] == ' '){
            while(s[idx] == ' '){
                idx++;
            }
            //대문자
            if(s[idx]>= 'a' && s[idx] <= 'z') s[idx] -= 32;
        }
        else{
            //소문자
            if(s[idx] >= 'A' && s[idx] <= 'Z') s[idx] += 32;
        }
    }
    
    cout << s << endl;
    
    return s;
}