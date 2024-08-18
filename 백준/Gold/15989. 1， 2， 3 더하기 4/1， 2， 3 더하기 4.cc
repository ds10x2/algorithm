/*



*/

#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001][4];



int main() {

	dp[0][1] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= 10000; i++) {
		dp[i][1] = dp[i - 1][1];
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		if (i >= 3)
			dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];

	}

	int n, tc;
	cin >> tc;

	int cur = 3;
	for (int t = 0; t < tc; t++) {
		cin >> n;
		cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
	}

	return 0;
}