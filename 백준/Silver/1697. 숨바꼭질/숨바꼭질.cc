#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int N, K;

queue<pair<int, int>> q;
int visited[100001];

bool can_move(int x, int cnt) {
	if (x < 0 || x > 100000) return true;

	//방문한 적이 없음
	if (visited[x] == 0) return false;

	return true;
}

void move(int x, int cnt) {
	q.push({ x, cnt });
	visited[x] = cnt;
}

void BFS() {

	if (N == K) {
		cout << 0 << "\n";
		return;
	}

	q.push({ N, 0 });
	visited[N] = -1;

	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (now - 1 == K || now + 1 == K || 2 * now == K) {
			cout << cnt + 1 << "\n";
			break;
		}

		//x-1로 이동
		if (!can_move(now - 1, cnt + 1)) move(now - 1, cnt + 1);

		//x+1로 이동
		if (!can_move(now + 1, cnt + 1)) move(now + 1, cnt + 1);

		//2*x로 이동
		if (!can_move(2 * now, cnt + 1)) move(2 * now, cnt + 1);

	}
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> K; //수빈이와 동생의 위치를 입력 받음

	BFS();

	return 0;
}