#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, less<int>> p_queue;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		if (x == 0) {
			if (p_queue.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << p_queue.top() << "\n";
				p_queue.pop();
			}
		}
		else {
			p_queue.push(x);
		}
	}

	return 0;
}