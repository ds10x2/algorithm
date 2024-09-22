/*

*/



#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int sum_list[200001];
int n, k, num;
map<int, long long> m;

int main() {

    cin >> n >> k;
    
    long long cnt = 0;
    m[0] = 1;

    for (int idx = 1; idx <= n; idx++) {
        cin >> num;
        sum_list[idx] = sum_list[idx - 1] + num;

        cnt += m[sum_list[idx] - k];

        m[sum_list[idx]]++;
    }

    cout << cnt;

    return 0;
}

