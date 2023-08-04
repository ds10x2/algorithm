#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;
vector<pair<int, int>> v;
int s = 0;

queue<pair<int, int>> q;
int trash[101][101] = { 0, }; //0이면 쓰레기 없음, 1이면 쓰레기가 있지만 탐색x, 2면 쓰레기 있고 탐색 완료
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs() {

	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;

		if (trash[x][y] == 2) continue;

		int tmp = 0;

		q.push({ x, y });

		while (!q.empty()) {
			int a = q.front().first;
			int b = q.front().second;

			q.pop();
			for (int i = 0; i < 4; i++) {
				int newA = a + dx[i];
				int newB = b + dy[i];

				if (newA < 1 || newA > n || newB < 1 || newB > m) continue;
				if (trash[newA][newB] == 1) {
					tmp++;
					q.push({ newA, newB });
					trash[newA][newB]++;
				}
			}
		}

		if (tmp > s) s = tmp;
	}

}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		v.push_back({ r, c });
		trash[r][c] = 1;
	}

	bfs();

	cout << s;


}