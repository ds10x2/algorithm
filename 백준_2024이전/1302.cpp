#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N;
map<string, int> m;

bool com(pair<string, int> a, pair<string, int> b) {

	bool result;

	if (a.second > b.second) {
		result = true;
	}
	else if (a.second == b.second) {
		result = (a.first < b.first);
	}
	else result = false;

	return result;

}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		m[str]++;
	}
	vector<pair<string, int>> v(m.begin(), m.end());

	sort(v.begin(), v.end(), com);

	cout << v[0].first;


	return 0;
}