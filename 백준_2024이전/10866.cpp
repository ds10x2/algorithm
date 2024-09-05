#include <iostream>
#include <deque>
using namespace std;


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	deque<int> dq;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (str == "push_front") {
			int x;
			cin >> x;
			dq.push_front(x);

		}
		else if (str == "push_back") {
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (str == "pop_front") {
			if (dq.empty()) cout << -1 << "\n";
			else {
				int x;
				x = dq.front();
				cout << x << "\n";
				dq.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (dq.empty()) cout << -1 << "\n";
			else {
				int x;
				x = dq.back();
				cout << x << "\n";
				dq.pop_back();
			}
		}
		else if (str == "size") {
			cout << dq.size() << "\n";
		}
		else if (str == "empty") {
			if (dq.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";

		}
		else if (str == "front") {
			if (dq.empty()) cout << -1 << "\n";
			else cout << dq.front() << "\n";
		}
		else if (str == "back") {
			if (dq.empty()) cout << -1 << "\n";
			else cout << dq.back() << "\n";
		}
	}

	
	return 0;
}