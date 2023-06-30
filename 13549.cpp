#include <iostream>
#include <deque>
using namespace std;

#define MAXSIZE 100001 

deque<int> dq;
int visited[MAXSIZE] = { 0, };
int N, K;

int bfs() {

	dq.push_front(N);
	visited[N] = 1;

	int pos;

	while (1) {
		pos = dq.front();
		dq.pop_front();

		if (pos == K) return visited[pos] - 1;

		if (pos * 2 < MAXSIZE && !visited[pos * 2]) {
			dq.push_front(pos * 2);
			visited[pos * 2] = visited[pos];
		}

		if (pos - 1 < MAXSIZE && !visited[pos - 1]) {
			dq.push_back(pos - 1);
			visited[pos - 1] = visited[pos] + 1;
		}

		if (pos + 1 < MAXSIZE && !visited[pos + 1]) {
			dq.push_back(pos + 1);
			visited[pos + 1] = visited[pos] + 1;
		}



	
	}

}


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> K;

	int result = bfs();

	cout << result;

	return 0;
}