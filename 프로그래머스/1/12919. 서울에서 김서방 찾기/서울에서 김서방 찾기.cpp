#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    for(int idx = 0; idx < seoul.size(); idx++){
        if(seoul[idx] == "Kim"){
            answer += (to_string(idx));
            break;
        }
    }
    answer += "에 있다";
    return answer;
}