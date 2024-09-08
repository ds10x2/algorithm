#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
using namespace std;

int n;
int arr[201];
int dp[201];

bool com(int a, int b) {
	return a > b;
}


void input() {
	cin >> n;
	for (int i = 1; i < n + 1; i++)
		cin >> arr[i];
}

void solution(){
	for (int i = 1; i < n + 1; i++)
		dp[i] = 1;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	sort(dp, dp + n + 1, com);
	int ans = n - dp[0];
	cout << ans;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	input();
	solution();


	return 0;
}