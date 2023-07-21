#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int dp[1001];

bool com(int a, int b) {
	return a > b;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i < n + 1; i++)
		cin >> arr[i];

	for (int i = 1; i < n + 1; i++)
		dp[i] = 1;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	sort(dp, dp + n + 1, com);
	cout << dp[0];

	return 0;
}