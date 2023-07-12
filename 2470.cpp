#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pos;
priority_queue<int, vector<int>, less<int>> neg;
pair<int, int> n[3];


void number() {
	int tmp1, tmp2;

	tmp1 = -1000000000;
	tmp2 = -1000000000;

	tmp1 = neg.top();
	neg.pop();
	if (!neg.empty()) {
		tmp2 = neg.top();

		n[0] = { tmp1, tmp2 };
		neg.push(tmp1);
	}
	else {
		n[0] = { tmp1, tmp2 };
		neg.push(tmp1);
	}

	tmp1 = 1000000000;
	tmp2 = 1000000000;

	tmp1 = pos.top();
	pos.pop();
	if (!pos.empty()) {
		tmp2 = pos.top();

		n[1] = { tmp1, tmp2 };
		pos.push(tmp1);
	}
	else {
		n[1] = { tmp1, tmp2 };
		pos.push(tmp1);
	}

}
int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (x < 0) neg.push(x);
		else pos.push(x);
	}

	if (neg.empty()) {
		cout << pos.top() << " ";
		pos.pop();
		cout << pos.top();
		return 0;
	}
	if (pos.empty()) {
		cout << neg.top() << " ";
		neg.pop();
		cout << neg.top();
		return 0;
	}


	int x, y;
	int result = 2147483647;

	number();

	while (!neg.empty() && !pos.empty()) {
		if (result == 0) {
			cout << n[2].first << " " << n[2].second;
			return 0;
		}

		x = neg.top();
		y = pos.top();


		if (abs(x + y) < abs(result)) {
			result = x + y;
			n[2].first = x;
			n[2].second = y;
		}
		if (x + y < 0) {
			pos.pop();
		}
		else {
			neg.pop();
		}

	}

	if (abs(result) < abs(n[0].first + n[0].second) && abs(result) < abs(n[1].first + n[1].second))
		cout << n[2].first << " " << n[2].second;
	else if (abs(n[0].first + n[0].second) < abs(n[1].first + n[1].second))
		cout << n[0].second << " " << n[0].first;
	else
		cout << n[1].first << " " << n[1].second;

	return 0;
}