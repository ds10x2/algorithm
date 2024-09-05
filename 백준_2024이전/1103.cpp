#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
using namespace std;

int n, m;
int arr[51][51];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int dp[51][51];

int result = 0;
bool visited[51][51];


void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char x;
			cin >> x;
			if (x == 'H') { 
				arr[i][j] = 0; 
			}
			else
				arr[i][j] = x - '0';
		}
	}
}


int dfs(int x, int y) {

	if (x < 1 || y < 1 || x > n || y > m || arr[x][y] == 0) return 0;
	if (visited[x][y]) {
		cout << -1;
		exit(0);
	}
	if (dp[x][y] != -1) return dp[x][y];

	visited[x][y] = true;
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + (arr[x][y] * dx[i]);
		int ny = y + (arr[x][y] * dy[i]);
		dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
	}
	visited[x][y] = false;
	return dp[x][y];

}

void solution() {

	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++)
			dp[i][j] = -1;
	}
	result = dfs(1, 1);
	cout << result;

}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	input();
	solution();



	return 0;
}