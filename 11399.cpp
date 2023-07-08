#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
int sum[1001];


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		q.push(m);
	}


	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + q.top();
		q.pop();
	}


	int result = 0;
	for (int i = 1; i <= n; i++)
		result += sum[i];

	cout << result;

	return 0;
}