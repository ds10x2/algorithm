#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

#define MAX 1000000000;

/*

17404 RGB 거리2

1번 집의 색은 2번, N번 집의 색과 같지 않아야 함
N번 집의 색은 N-1번, 1번 집의 색과 같지 않아야 함
i번 집의 색은 i-1, i+1번 집의 색과 같지 않아야 함

*/

int N; //집의 수
int arr[1001][3];
int dp[1001][3];
int result = MAX;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int idx = 1; idx <= N; idx++) {
		cin >> arr[idx][0] >> arr[idx][1] >> arr[idx][2];
	}

	for (int idx = 0; idx < 3; idx++) {
		for (int i = 0; i < 3; i++) {
			if (i == idx)
				dp[1][i] = arr[1][i];
			else dp[1][i] = MAX;
		}

		for (int i = 2; i <= N; i++) {
			dp[i][0] = arr[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = arr[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = arr[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
		}

		for (int i = 0; i < 3; i++) {
			if (i == idx) continue;
			else result = min(result, dp[N][i]);
		}

	}
	cout << result;

	return 0;
}