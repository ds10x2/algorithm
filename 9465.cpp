#include <iostream>
#include <cmath>
using namespace std;

int T;
int dp[2][100001];
int st[2][100001];

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> T;

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;

		for (int j = 0; j < 2; j++) {
			for (int k = 1; k < n+1; k++)
				cin >> st[j][k];
		}

		dp[0][0] = 0;
		dp[1][0] = 0;
		dp[0][1] = st[0][1];
		dp[1][1] = st[1][1];

		for (int j = 2; j < n + 1; j++) {
			dp[0][j] = max(dp[1][j - 2], dp[1][j - 1]) + st[0][j];
			dp[1][j] = max(dp[0][j - 2], dp[0][j - 1]) + st[1][j];
			cout << dp[0][j] << " " << dp[1][j] << "\n";
		}

		cout << max(dp[0][n], dp[1][n]) << "\n";

	}


	return 0;
}