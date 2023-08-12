#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
bool visited[501][501] = { false, };
int art[501][501];
vector<pair<int, int>> v;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int result = 0;
int drawing = 0;


void Input() {
	cin >> n >> m;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			cin >> art[i][j];
			if (art[i][j] == 1) {
				visited[i][j] = true;
				v.push_back({ i, j });
			}
		}
	}
}

void bfs() {
	for (int i = 0; i < v.size(); i++) {

		if (!visited[v[i].first][v[i].second])
			continue;

		int cnt = 1;
		drawing++;

		queue<pair<int, int>> q;

		q.push({ v[i].first, v[i].second });

		visited[v[i].first][v[i].second] = false;

		while (!q.empty()) {

			int x = q.front().first;
			int y = q.front().second;

			q.pop();


			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];


				if (nx < 1 || nx > n || ny < 1 || ny > m)
					continue;
				if (!visited[nx][ny] || art[nx][ny] == 0)
					continue;

				cnt++;
				visited[nx][ny] = false;
				q.push({ nx, ny });

			}
			
		}
		result = max(result, cnt);


	}
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	Input();
	bfs();

	cout << drawing << "\n" << result;

	return 0;
}