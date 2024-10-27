#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1500001];
pair<int, int> input[1500001];
int result;


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n; 
	for (int idx = 0; idx < n; idx++)
		cin >> input[idx].first >> input[idx].second;

	int curmax = 0;
	for (int idx = 0; idx <= n; idx++) {
		curmax = max(curmax, dp[idx]);
		if (idx + input[idx].first > n) continue;

		dp[idx + input[idx].first] = max(curmax + input[idx].second, dp[idx + input[idx].first]);
		result = max(result, dp[idx + input[idx].first]);
	}
	cout << result;

	return 0;
}