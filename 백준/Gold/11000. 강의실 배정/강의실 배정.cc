/*

*/



#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> v;
int st, ed, n;

int main() {
    
    cin >> n;
    for (int idx = 0; idx < n; idx++) {
        cin >> st >> ed;
        v.push_back({ st, ed });
    }

    sort(v.begin(), v.end());

    for (int idx = 0; idx < v.size(); idx++) {
        pq.push(v[idx].second);
        if (pq.top() <= v[idx].first) pq.pop();
    }

    cout << pq.size();

    return 0;
}

