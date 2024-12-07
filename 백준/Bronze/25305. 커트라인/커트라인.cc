#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

vector<int> v;

bool comp(int a, int b) {
	return a > b;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	for (int idx = 0; idx < n; idx++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end(), comp);

	cout << v[k - 1];

	return 0;
}