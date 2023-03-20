#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> p_queue;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		p_queue.push(x);
	}

	int result = 0;

	while (p_queue.size() > 1) {
		int sum;
		sum = p_queue.top();
		p_queue.pop();
		sum += p_queue.top();
		p_queue.pop();
		p_queue.push(sum);
		result += sum;
	}

	cout << result;
	
	return 0;



}