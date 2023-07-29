#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n;
vector<long long> v;
int cnt = 0;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;

		v.push_back(x);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		long long num = v[i];

		int start = 0, end = n - 1;
		bool flag = false;
		while (start < end) {

			if (start == i) {
				start++;
				continue;
			}
			if (end == i) {
				end--;
				continue;
			}

			if (v[start] + v[end] == num) {
				flag = true;
				break;
			}

			int mid = (start + end) / 2;
			

			if (v[start] + v[end] > num) {
				end--;
			}
			if (v[start] + v[end] < num) {
				start++;
			}
		}

		if (flag) cnt++;
	}

	cout << cnt;

	return 0;
}