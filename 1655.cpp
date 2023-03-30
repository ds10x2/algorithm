#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, less<int>> Max;
priority_queue<int, vector<int>, greater<int>> Min;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		if (Max.size() == Min.size())
			Max.push(x);
		else
			Min.push(x);

		if (!Max.empty() && !Min.empty() && Max.top() > Min.top()) {
			int temp = Max.top();
			Max.pop();
			Max.push(Min.top());
			Min.pop();
			Min.push(temp);
		}

		cout << Max.top() << "\n";

	}
	
	return 0;

}
