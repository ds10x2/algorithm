#include <iostream>
#include <algorithm>
using namespace std;

long long mod[1001];

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, m, t;
	long long psum = 0, cnt = 0;
	cin >> n >> m;
	for (int idx = 1; idx <= n; idx++) {
		cin >> t;
		psum += t;
		mod[psum % m]++;
	}

	for (int idx = 0; idx <= m; idx++)
		cnt += ((mod[idx] * (mod[idx] - 1)) / 2);

	cout << mod[0] + cnt;


	return 0;
}