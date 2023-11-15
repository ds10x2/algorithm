#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
using namespace std;

int arr[101][101];
int row, col;
vector<pair<int, int>> v;
int cheese = 0;
int result;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int cnt = 0;
bool visited[101][101];

void input() {

	cin >> row >> col;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				cheese++;
		}
	}
}

void bfs() {

	queue<pair<int, int>> q;

	q.push({ 1, 1 });

	visited[1][1] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();


		for (int i = 0; i < 4; i++) {
			int xNext = x + dx[i];
			int yNext = y + dy[i];

			if (visited[xNext][yNext])
				continue;

			if (xNext < 1 || xNext > row || yNext < 1 || yNext > col)
				continue;

			if (arr[xNext][yNext] == 0) {
				q.push({ xNext, yNext });
			}
			else if (arr[xNext][yNext] == 1) {
				cheese--;
				v.push_back({ xNext, yNext });
			}
			visited[xNext][yNext] = true;
		}
	}
}


void deleteCheese() {
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;

		arr[x][y] = 0;
	}
	v.clear();
}

void solution() {

	while (cheese > 0) {
		cnt++;

		result = cheese;

		bfs();
		deleteCheese();

		for (int i = 1; i < 101; i++) {
			for (int j = 1; j < 101; j++)
				visited[i][j] = false;
		}

	}
	cout << cnt << "\n" << result;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	input();
	solution();



	return 0;
}