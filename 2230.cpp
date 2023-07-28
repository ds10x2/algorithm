#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
vector<int> a;
int ans = 1000000000;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}

	sort(a.begin(), a.end());

	int start = 0, end = 0;
	while (start < n && end < n) {
		int result = a[end] - a[start];
		if (result < m)
			end++;
		else {
			ans = min(ans, result);
			start++;
		}
	}

	cout << ans;


}