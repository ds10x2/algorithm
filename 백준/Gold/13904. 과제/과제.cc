/*

*/



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[1001];
vector<pair<int, int>> v;

bool com(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main() {
    

    cin >> N;
    for (int i = 0; i < N; i++) {
        int d, w;
        cin >> d >> w;
        v.push_back({ d, w });
    }

    sort(v.begin(), v.end(), com);

    for (int i = 0; i < N; i++) {
        for (int j = v[i].first; j > 0; j--) {
            if (arr[j] == 0) {
                arr[j] = v[i].second;
                break;
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= 1000; i++)
        res += arr[i];
    cout << res << endl;

    return 0;
}


/*

*/