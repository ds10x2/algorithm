#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int N, M;


void find() {
	cin >> N >> M;

	queue<pair<int, int>> q;
	priority_queue<int> pq;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		q.push({ x, i });
		pq.push(x);
	}

	int cnt = 0;

	while (!q.empty()) {

		int priority = q.front().first;
		int order = q.front().second;

		int max_priority = pq.top();

		if (priority == max_priority) {
			if (order != M) {
				q.pop();
				pq.pop();
				cnt++;
			}
			else {
				cnt++;
				break;
			}
		}
		else if (priority < max_priority) {
			q.pop();
			q.push({ priority, order });
		}
	}

	cout << cnt << "\n";
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> T;
	for (int k = 0; k < T; k++) {
		find();
	}

	return 0;
}