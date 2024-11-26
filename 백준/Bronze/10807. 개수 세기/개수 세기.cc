#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> m;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;
	for (int idx = 0; idx < n; idx++) {
		int x;
		cin >> x;
		m[x]++;
	}

	int v;
	cin >> v;

	cout << m[v];

	return 0;
}