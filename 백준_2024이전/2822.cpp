#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, less<int>> q;
priority_queue<int, vector<int>, greater<int>> problem;
int score[151];

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	for (int i = 1; i < 9; i++) {
		int x;
		cin >> x;
		q.push(x);
		score[x] = i;
	}

	int cnt = 0;

	for (int i = 0; i < 5; i++) {
		cnt += q.top();
		problem.push(score[q.top()]);
		q.pop();
	}

	cout << cnt << "\n";
	for (int i = 0; i < 5; i++) {
		cout << problem.top() << " ";
		problem.pop();
	}

	return 0;
}