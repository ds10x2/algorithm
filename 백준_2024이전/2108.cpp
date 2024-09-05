#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
double sum = 0;
vector<pair<int, int>> cnt;
vector<int> v;

bool com(pair<int, int> a, pair<int, int> b) {
	if (a.first > b.first)
		return true;
	else if (a.first == b.first) {
		return a.second < b.second;
	}
	else return false;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	for (int i = -4000; i < 4001; i++) {
		cnt.push_back({ 0, i });
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		sum += x;
		cnt[x + 4000].first++;
	}

	sort(v.begin(), v.end());
	sort(cnt.begin(), cnt.end(), com);

	

	int mid = n / 2;
	int aver = round(sum / n);

	cout << aver << "\n";
	cout << v[mid] << "\n";

	if (cnt[0].first != cnt[1].first) cout << cnt[0].second << "\n";
	else cout << cnt[1].second << "\n";

	cout << v[n - 1] - v[0];
	



	return 0;
}