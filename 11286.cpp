#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int N;
priority_queue<int, vector<int>, less<int>> negative;
priority_queue<int, vector<int>, greater<int>> positive;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {

		long x;
		cin >> x;

		if (x > 0)
			positive.push(x);
		else if(x < 0)
			negative.push(x);
		else {
			
			if (positive.empty() && negative.empty()) {
				cout << 0 << "\n";
			}
			else if (negative.empty()) {
				cout << positive.top() << "\n";
				positive.pop();
			}
			else if (positive.empty()){
				cout << negative.top() << "\n";
				negative.pop();
			}
			else if (positive.top() < abs(negative.top())) {
				cout << positive.top() << "\n";
				positive.pop();
			}
			else if (abs(negative.top()) <= positive.top()) {
				cout << negative.top() << "\n";
				negative.pop();
			}
		}


	}


	return 0;
}
