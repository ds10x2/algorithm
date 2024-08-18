/*



*/

#include <iostream>
#include <algorithm>
using namespace std;

long long dp[41];
string s;


int main() {

	cin >> s;
	
	dp[0] = 1;
	for (int i = 1; i < s.length(); i++) {
		if (((s[i] - '0') + (s[i - 1] - '0') * 10) <= 34 && s[i - 1] != '0') {
			if (i == 1) dp[i] = 1;
			else dp[i] = dp[i - 2];
		}
		if (s[i] != '0') dp[i] += dp[i - 1];
	}
	
	cout << dp[s.length() - 1];

	return 0;
}