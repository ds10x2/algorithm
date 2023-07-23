#include <iostream>
#include <queue>
#include <vector>
using namespace std;


priority_queue<int, vector<int>, greater<int>> q;

int n, m;
long long cnt = 0;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
		cnt += x;
	}

	for (int i = 0; i < m; i++) {
		long long f, s;
		f = q.top();
		q.pop();
		s = q.top();
		q.pop();
		cnt += f;
		cnt += s;
		q.push(f + s);
		q.push(f + s);
	}

	cout << cnt;

	return 0;
}