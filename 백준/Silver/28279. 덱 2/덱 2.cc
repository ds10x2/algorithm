#include <iostream>
#include <deque>
using namespace std;

int N, command;
deque<int> dq;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	for (int idx = 0; idx < N; idx++) {
		cin >> command;

		if (command == 1) {
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if (command == 2) {
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (command == 3) {
			if (!dq.empty()) {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else cout << -1 << "\n";
		}
		else if (command == 4) {
			if (!dq.empty()) {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else cout << -1 << "\n";

		}
		else if (command == 5) {
			cout << dq.size() << "\n";
		}
		else if (command == 6) {
			if (!dq.empty()) cout << 0 << "\n";
			else cout << 1 << "\n";
		}
		else if (command == 7) {
			if (!dq.empty()) cout << dq.front() << "\n";
			else cout << -1 << "\n";
		}
		else if (command == 8) {
			if (!dq.empty()) cout << dq.back() << "\n";
			else cout << -1 << "\n";
		}
	}

	
	return 0;
}