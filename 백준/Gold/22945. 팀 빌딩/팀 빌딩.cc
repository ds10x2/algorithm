#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> v;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;
	for (int idx = 0; idx < n; idx++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	int left = 0;
	int right = n - 1;
	int cnt = 0;

	while (left < right) {
		int dist = right - left - 1;
		int power = min(v[right], v[left]);
		cnt = max(cnt, dist * power);

		if (v[right] > v[left])left++;
		else right--;
	}

	cout << cnt;
		

	return 0;
}