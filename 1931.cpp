//4963
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;

void f() {

}


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int st, ed;
		cin >> st >> ed;
		v.push_back({ ed, st });
	}

	sort(v.begin(), v.end());

	int t = v[0].first;
	int cnt = 1;

	for (int i = 1; i < N; i++) {
		if (t <= v[i].second) {
			cnt++;
			t = v[i].first;
		}
	}


	cout << cnt;

	return 0;
}