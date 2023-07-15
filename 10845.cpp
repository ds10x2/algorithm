#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	queue<int> q;

	int N;
	int X;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;

		cin >> str;

		if (str == "push") {
			cin >> X;
			q.push(X);

		}
		else if (str == "pop") {
			if (q.empty()) cout << -1 << "\n";
			else {
				int x;
				x = q.front();
				cout << x << "\n";
				q.pop();
			}

		}
		else if (str == "size") {
			cout << q.size() << "\n";

		}
		else if (str == "empty") {
			if (q.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";

		}
		else if (str == "front") {
			if (q.empty()) cout << -1 << "\n";
			else cout << q.front();

		}
		else if (str == "back") {
			if (q.empty()) cout << -1 << "\n";
			else cout << X << "\n";
		}
	}


	return 0;
}