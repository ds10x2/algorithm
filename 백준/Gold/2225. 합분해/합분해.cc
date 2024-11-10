#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
using namespace std;

int n, k;
long long dp[201][201];

void input() {
	cin >> n >> k;
}

void solution(){
	for (int i = 0; i < n + 1; i++) {
		dp[1][i] = 1;
	}
	for (int l = 2; l < k + 1; l++) {
		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < i + 1; j++) {
				dp[l][i] = dp[l][i] + dp[l - 1][j];
			}
			dp[l][i] = dp[l][i] % 1000000000;
		}
	}
	cout << dp[k][n];
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	input();

	solution();

}