#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N, C;
map<int, int> m;
map<int, int> order;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return order[a.second] < order[b.second];
	return a.first > b.first;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> C;

	for (int i = 1; i < N + 1; i++) {
		int x;
		cin >> x;

		m[x]++;
		if (order[x] == 0) order[x] = i;

	}

	for (auto itr = m.begin(); itr != m.end(); itr++) {
		v.push_back({ itr->second, itr->first});
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].first; j++)
			cout << v[i].second << " ";
	}
	

	return 0;
}