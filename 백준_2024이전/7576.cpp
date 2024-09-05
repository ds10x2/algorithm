#include <iostream>
#include <queue>
using namespace std;

int N, M;
int tomato[1001][1001];
queue<pair<int, int>> tmt;
int cnt = 0;
int days = -1;

int dx[4]{ 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool visited[1001][1001] = { false, };


void date() {
	queue<pair<int, int>> q;

	while (!tmt.empty()) {

		int x = tmt.front().first;
		int y = tmt.front().second;

		tmt.pop();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int newX = x + dx[i];
				int newY = y + dy[i];

				if (newX < 1 || newX > N || newY < 1 || newY > M || visited[newX][newY]) continue;
				if (tomato[newX][newY] == -1) continue;
				//cout << newX << " " << newY << "\n";
				visited[newX][newY] = true;
				q.push({ newX, newY });
				cnt--;

			}
		}

		if (tmt.empty()) {
			days++;
			cout << days << " ";
			tmt = q;
			while (!q.empty()) q.pop();
		}

	}

}


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> M >> N;
	for (int i = 1; i < N+1; i++) {
		for (int j = 1; j < M+1; j++) {
			int x;
			cin >> x;
			tomato[i][j] = x;
			if (x == 0) cnt++;
			else if (x == 1) { 
				tmt.push({ i, j });
				visited[i][j] = true;
			}
		}
	}

	date();

	if (cnt == 0) cout << days;
	else cout << -1;

	return 0;
}