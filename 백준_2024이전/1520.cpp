#include <iostream>
#include <vector>
using namespace std;

int m, n;
int Map[501][501];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int visited[501][501];

int dfs(int x, int y) {

	if (x == m && y == n) {
		cout << "\n";
		return 1;
	}

	if (visited[x][y] == -1) {
		visited[x][y] = 0;
		for (int i = 0; i < 4; i++) {
			int newX = x + dx[i];
			int newY = y + dy[i];
			if (Map[newX][newY] != 0 && Map[newX][newY] < Map[x][y]) {
				cout << newX << " " << newY << " " << Map[newX][newY] << "\n";
				visited[x][y] += dfs(newX, newY);
			}
		}
	}
	return visited[x][y];
}


int main(){
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> m >> n;
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++)
			cin >> Map[i][j];
	}

	memset(visited, -1, sizeof(visited));

	cout << dfs(1, 1);


	return 0;
}