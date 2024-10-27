#include <iostream>
#include <algorithm>
using namespace std;

int nums[101];
long long dp[101][21];
int n;


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;
	for (int idx = 1; idx <= n; idx++)
		cin >> nums[idx];

	dp[1][nums[1]] = 1;

	for (int idx = 2; idx <= n - 1; idx++) {
		for (int idx2 = 0; idx2 <= 20; idx2++) {
			if (dp[idx - 1][idx2]) {
				if (idx2 + nums[idx] <= 20) dp[idx][idx2 + nums[idx]] += dp[idx - 1][idx2];
				if (idx2 - nums[idx] >= 0) dp[idx][idx2 - nums[idx]] += dp[idx - 1][idx2];
			}
		}
	}

	cout << dp[n - 1][nums[n]] << "\n";


	return 0;
}