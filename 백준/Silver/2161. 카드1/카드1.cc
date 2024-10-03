#include <iostream>
#include <queue>
using namespace std;


queue<int> q;
int N;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
		q.push(i + 1);

	int result;

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();

		if (q.empty())
			break;
		q.push(q.front());
		q.pop();
	}

	return 0;
}