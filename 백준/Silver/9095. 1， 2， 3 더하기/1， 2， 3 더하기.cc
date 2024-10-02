#include <iostream>
using namespace std;

/*

백준 9095

*/

int dp[12];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int idx = 4; idx <= 11; idx++)
		dp[idx] = dp[idx - 1] + dp[idx - 2] + dp[idx - 3];

	int n;
	for (int idx = 0; idx < tc; idx++) {
		cin >> n;
		cout << dp[n] << "\n";
	}


	return 0;
}