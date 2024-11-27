#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

stack<int> s;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;
	for (int idx = 0; idx < n; idx++) {
		int command;
		cin >> command;

		if (command == 1) {
			int x;
			cin >> x;
			s.push(x);
		}
		else if (command == 2) {
			if (!s.empty()) {
				cout << s.top() << "\n";
				s.pop();
			}
			else cout << -1 << "\n";
		}
		else if (command == 3) {
			cout << s.size() << "\n";
		}
		else if (command == 4) {
			if (!s.empty()) cout << 0 << "\n";
			else cout << 1 << "\n";

		}
		else if (command == 5) {
			if (!s.empty()) cout << s.top() << "\n";
			else cout << -1 << "\n";
		}
	}

	return 0;
}