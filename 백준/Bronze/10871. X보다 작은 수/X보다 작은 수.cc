#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, x;
	cin >> n >> x;
	for (int idx = 0; idx < n; idx++) {
		int a;
		cin >> a;
		if (a < x) v.push_back(a);
	}

	for (int idx = 0; idx < v.size(); idx++)
		cout << v[idx] << " ";

	return 0;
}