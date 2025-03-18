#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> check_stack;
    
    for(int idx = 0; idx < s.length(); idx++){
        if(s[idx] == '(') check_stack.push(s[idx]);
        else{
            if(!check_stack.empty()) check_stack.pop();
            else answer = false;
        }
    }
    if(!check_stack.empty()) answer = false;

    return answer;
}