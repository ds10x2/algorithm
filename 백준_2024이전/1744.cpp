#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, less<int>> l_queue; //최대힙
priority_queue<int, vector<int>, greater<int>> g_queue; //최소힙 부모노드가 작음

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (x <= 0)
			g_queue.push(x);
		else
			l_queue.push(x);
	}

	int result = 0;

	while (l_queue.size() > 1) {
		int mult;
		mult = l_queue.top();
		l_queue.pop();
		if (l_queue.top() == 1)
			mult += l_queue.top();
		else 
			mult *= l_queue.top();
		l_queue.pop();
		result += mult;
	}

	while (g_queue.size() > 1) {
		int mult;
		mult = g_queue.top();
		g_queue.pop();
		mult *= g_queue.top();
		g_queue.pop();
		result += mult;
	}

	if (!l_queue.empty())
		result += l_queue.top();
	if (!g_queue.empty())
		result += g_queue.top();

	cout << result;
	
	return 0;
}