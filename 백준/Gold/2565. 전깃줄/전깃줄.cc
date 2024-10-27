#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[110];
pair<int, int> line[110];

bool com(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;
	for (int idx = 1; idx <= n; idx++) {
		int left, right;
		cin >> left >> right;
		line[idx] = { left, right };
	}

	int correct = 0;
	sort(line + 1, line + n + 1, com);
	for (int idx = 1; idx <= n; idx++) {
		dp[idx] = 1;
		for (int j = 1; j < idx; j++) {
			if (line[idx].second > line[j].second)
				dp[idx] = max(dp[idx], dp[j] + 1);
		}
		correct = max(correct, dp[idx]);
	}

	cout << n - correct << endl;


	return 0;
}