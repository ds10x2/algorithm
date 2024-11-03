#include <iostream>
#include <algorithm>
using namespace std;

string str1, str2;
int result;
int dp[4001][4001];

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> str1 >> str2;

	for (int row = 0; row < str1.length(); row++) {
		for (int col = 0; col < str2.length(); col++) {
			if (str1[row] == str2[col]) {
				dp[row][col] = 1;
				if (row >= 1 && col >= 1) dp[row][col] += dp[row - 1][col - 1];
				result = max(result, dp[row][col]);
			}
		}
	}

	cout << result;

	return 0;
}