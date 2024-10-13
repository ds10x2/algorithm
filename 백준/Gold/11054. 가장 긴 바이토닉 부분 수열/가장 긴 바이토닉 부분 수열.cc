#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int dp[1001];
int reverse_dp[1001];
int result;

bool com(int a, int b) {
	return a > b;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i < n + 1; i++)
		cin >> arr[i];

	for (int i = 1; i < n + 1; i++) {
		dp[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	for (int i = n; i >= 1; i--) {
		reverse_dp[i] = 1;
		for (int j = n; j >= i; j--) {
			if (arr[i] > arr[j] && reverse_dp[j] + 1 > reverse_dp[i])
				reverse_dp[i] = reverse_dp[j] + 1;
		}
	}

	for (int i = 0; i <= n; i++)
		if (result < dp[i] + reverse_dp[i] - 1) result = dp[i] + reverse_dp[i] - 1;

	cout << result;

	return 0;
}