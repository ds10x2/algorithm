#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

/*



*/

string str;
bool dp[2501][2501];
int result[2501];

void print() {
	for (int i = 1; i < str.length(); i++) {
		for (int j = 1; j < str.length(); j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string temp = " ";

	cin >> str;

	str = temp + str;

	for (int idx = 1; idx < str.length(); idx++)
		dp[idx][idx] = true;

	for (int idx = 1; idx < str.length(); idx++) {
		if (str[idx] == str[idx + 1]) {
			dp[idx][idx + 1] = true;
		}
	}

	for (int i = str.length() - 2; i > 0; i--) {
		for (int j = i + 2; j <= str.length(); j++) {
			if (str[i] == str[j] && dp[i + 1][j - 1]) dp[i][j] = true;
		}
	}


	result[0] = 0;

	for (int i = 1; i < str.length(); i++) {
		result[i] = 2501;
		for (int j = 1; j <= i; j++)
			if (dp[j][i]) result[i] = min(result[i], result[j - 1] + 1);
	}




	cout << result[str.length() - 1] << "\n";
	
	return 0;
}