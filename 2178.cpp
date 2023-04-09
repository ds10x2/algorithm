#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[101][101];
bool visited[101][101] = { false, };
int dist[101][101];

int x_dir[4] = { -1,1,0,0 };
int y_dir[4] = { 0,0,-1,1 };

queue<pair<int, int>> q;

void BFS() {
	visited[1][1] = true;
	q.push({ 1, 1 });
	dist[1][1]++;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int x_new = x + x_dir[i];
			int y_new = y + y_dir[i];

			if ((x_new > 0 && x_new <= N) && (y_new > 0 && y_new <= M) 
				&& !visited[x_new][y_new] && arr[x_new][y_new] == 1) {
				
				visited[x_new][y_new] = true;
				q.push({ x_new, y_new });
				dist[x_new][y_new] = dist[x][y] + 1;

			}
		}
	}



}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string row;
		cin >> row;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = row[j-1] - '0';
		}
	}

	BFS();

	cout << dist[N][M];

	return 0;
}