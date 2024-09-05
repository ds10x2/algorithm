#include <iostream>
#include <deque>
using namespace std;

int n;
deque<pair<char, int>> dq;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1) {
			char c;
			cin >> c;
			dq.push_back({ c, i });
			idx = 1;
		}
		else if (x == 2) {
			char c;
			cin >> c;
			dq.push_front({ c, i });
			idx = 2;
		}
		else if (x == 3) {
			if (dq.empty()) continue;
			
			if (dq.front().second > dq.back().second) dq.pop_front();
			else dq.pop_back();
		}

	}

	if (dq.size() == 0) cout << 0;
	else {
		while (!dq.empty()) {
			cout << dq.front().first;
			dq.pop_front();
		}
	}

	return 0;
}