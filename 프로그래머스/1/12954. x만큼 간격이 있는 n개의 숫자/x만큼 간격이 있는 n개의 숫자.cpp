#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    for(long long idx = 0; idx< n; idx++){
        answer.push_back(x+(x*idx));
    }
    return answer;
}