#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

deque<int> dq;
int N, M;
int cnt = 0;
int n;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> M;
	n = N;

	for (int i = 1; i <= N; i++)
		dq.push_back(i);


	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;

		int idx;

		for (int j = 0; j < N; j++) {
			if (dq[j] == x) {
				idx = j;
				break;
			}
		}

		if (idx < dq.size() / 2 + 1) {
			for (int j = 0; j < dq.size(); j++) {
				if (dq.front() == x) {
					dq.pop_front();
					break;
				}
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}
		}
		else {
			for (int j = 0; j < dq.size(); j++) {
				if (dq.front() == x) {
					dq.pop_front();
					break;
				}
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}