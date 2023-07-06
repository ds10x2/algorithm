#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> computer[101];
int N, M;
int visited[101];
int cnt = 1;

queue<int> q;

void bfs() { //1번 컴퓨터가 감염
	visited[1] = true;
	q.push(1);

	while (!q.empty()) {
		int n = q.front();

		q.pop();

		for (int i = 0; i < computer[n].size(); i++) {
			int com = computer[n][i];

			if (visited[com]) continue;
			visited[com] = true;
			cnt++;
			q.push(com);
			cout << com << " ";
		}
	}
	

}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		computer[x].push_back(y);
		computer[y].push_back(x);
	}

	bfs();

	cout << cnt;

	return 0;
}

