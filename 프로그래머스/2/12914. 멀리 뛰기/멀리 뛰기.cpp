#include <string>
#include <vector>

using namespace std;
/**
1: 1
2: 2
3: 3
4: 5
5: 8
6: 13 ...
**/

long long solution(int n) {
    vector<long long> v;
    v.push_back(1);
    v.push_back(2);
    for(int idx = 2; idx < n; idx++){
        v.push_back((v[idx - 2] + v[idx - 1]) % 1234567);
    }
    
    long long answer = v[n-1];
    return answer;
}