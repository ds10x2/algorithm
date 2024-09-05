#include <iostream>
#include <deque>
using namespace std;

int N;
deque<pair<int, int>> dq;


int main(){
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i < N+1; i++) {
		int x;
		cin >> x;
		dq.push_back({ x, i });
	}


	while (!dq.empty()) {
		int n = dq.front().first;
		int idx = dq.front().second;
		cout << idx << " ";
		dq.pop_front();

		if (dq.empty()) break;

		if (n > 0) {

			for (int i = 0; i < n-1; i++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}

		}
		else {
			for (int i = 0; i < (-1) * n; i++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}


	}


	return 0;
}