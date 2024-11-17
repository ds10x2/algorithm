#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000000

int n, r, c;
int arr[501];
int matrix[501][2];
int dp[501][501];

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;
	for (int idx = 1; idx <= n; idx++) {
		cin >> matrix[idx][0];
		cin >> matrix[idx][1];
	}

	for (int row = 1; row < n; row++) {
		for (int col = 1; col + row <= n; col++) {
			dp[col][row + col] = INF;
			for (int k = col; k <= row + col; k++) {
				dp[col][row + col] = min(dp[col][row + col], dp[col][k] + dp[k + 1][row + col] + matrix[col][0] * matrix[k][1] * matrix[row + col][1]);
			}
		}
	}

	cout << dp[1][n];

	return 0;
}